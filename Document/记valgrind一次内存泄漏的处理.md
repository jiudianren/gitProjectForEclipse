#内存泄漏


在项目中，性能测试的时候，有内存泄漏 ，通过valgrind的查看内存泄漏：

	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --trace-children=yes --num-callers=200 --log-file=./valgrind.log   ./SM-SR 
	

valgrind.log:



##情况 1
	2 bytes in 1 blocks are definitely lost in loss record 7 of 636
	......
	by 0x9DE5BBB: Private::_TMySqlQuery::SetParameter(char const*, char const*, bool) (TMySql.cpp:1276)
	.....



看到 

	
                delete[] m_pTParmList[i].m_StrBuf;
                m_pTParmList[i].m_StrBuf = NULL;
                unsigned long iLen = strlen(sParamValue);
                m_pTParmList[i].m_StrBuf = new char[iLen + 1];
                m_pTParmList[i].m_StrBuf[iLen] = '\0';

注意到 申请内存，之前，有释放之前的内存。

原则：内存谁管理，谁释放

所以，可能性，就是程序结束的时候，没有释放。

查看析构函数，没有呀释放



##情况 2

	==4978== 122 bytes in 1 blocks are definitely lost in loss record 476 of 636
	==4978==    at 0x4A069EE: malloc (vg_replace_malloc.c:270)
	==4978==    by 0x9A042B0: ASN1_item_i2d (in /home/ztesoft/rspm2m/tools/runtime/lib/libcrypto.so.1.1)
	==4978==    by 0x9A6510C: i2d_ECPrivateKey (in /home/ztesoft/rspm2m/tools/runtime/lib/libcrypto.so.1.1)
	==4978==    by 0x5CF377A: _ZNK7OpenSSL13CertsX509Read13get_PriKeyDERB5cxx11Ev (CertsX509Read.cpp:1144)
	==4978==    by 0x5CF0A05: OpenSSL::CertsX509Read::load_prikey(_IO_FILE*, int, char const*) (CertsX509Read.cpp:378)
	
	
	
	
	
code:

	const std::string &CertsX509Read::get_PriKeyDER() const noexcept
	{
	    if (m_derPriKey.empty())
	    {
	        if (!m_PriKey)
	        {
	            return m_derPriKey;
	        }
	        unsigned char *pBuf = nullptr;
	        int len = i2d_PrivateKey(m_PriKey.get(), &pBuf);//申请的内存，需要我们主动释放 1144
	        if (len > 0)
	        {
	            OPENSSL_AUTO_FREE(uint8_t, OPENSSL_free, buf, (uint8_t *)OPENSSL_malloc((size_t) len));
	            if (buf)
	            {
	                pBuf = buf.get();
	                i2d_PrivateKey(m_PriKey.get(), &pBuf);
	
	                m_derPriKey = std::string(reinterpret_cast<const char *>(buf.get()), (size_t) len);
	            }
	        }
	    }
	    return m_derPriKey;
	}

	
	
i2d_PrivateKey 第二个参数，返回了 数据。紧接着 下面一次i2d_PrivateKey 调用，并没有提示内存没有释放。


对比两次，可以看到第二次的内存，并没有提醒 内存泄漏，因为其被智能指针管理。
i2d_PrivateKey，第二个参数接管的参数，需要自己释放。

而暂时第二个参数，不需要，第一次调用只是为了得到len。
所以 

  int len = i2d_PrivateKey(m_PriKey.get(), &pBuf);//申请的内存，需要我们主动释放 1144
修改成
  int len = i2d_PrivateKey(m_PriKey.get(), nullptr);//申请的内存，需要我们主动释放 1144



## 情况3 

==4978== 480 bytes in 480 blocks are definitely lost in loss record 586 of 636
==4978==    at 0x4A075BC: operator new(unsigned long) (vg_replace_malloc.c:298)
==4978==    by 0x7AD142C: get_phy_auto_commit(TMySqlDatabase*) (PhyAutoCommit.cpp:58)



code:

	std::unique_ptr<bool, std::function<void(bool *)> > get_phy_auto_commit(TDBDatabase *link)
	{
	    std::unique_ptr<bool, std::function<void(bool *)> > commit(new bool(false), [=](bool *p)
	    {
	        try
	        {
	            if (*p == false)
	            {
	                link->Rollback();
	            }
	            else
	            {
	                link->Commit();
	            }
	        }
	        catch(std::exception &e)
	        {
	
	        }
	        catch(...)
	        {
	  
	        }
	    });
	    return commit;
	}
	
	


可以看到 ，unique_ptr ,智能指针，申请了内存，并且，赋值了，指针的释放函数。


检查释放函数。

看到 对 *p，并没有释放的地方。

所以 修改成：

	        if (*p == false)
            {
                delete p;
                link->Rollback();
            }
            else
            {
                delete p;
                link->Commit();
            }
            
            
       
       
## 情况4

==4978== 641 bytes in 1 blocks are definitely lost in loss record 604 of 636
==4978==    at 0x4A069EE: malloc (vg_replace_malloc.c:270)
==4978==    by 0x9A042B0: ASN1_item_i2d (in /home/ztesoft/rspm2m/tools/runtime/lib/libcrypto.so.1.1)
==4978==    by 0x5CF3374: _ZNK7OpenSSL13CertsX509Read11get_CertDERB5cxx11Ev (CertsX509Read.cpp:1098)
==4978==    by 0x5CF05C8: OpenSSL::CertsX509Read::load_cert(_IO_FILE*, int, char const*, char const*) (CertsX509Read.cpp:328)
==4978==    by 0x5D21CA9: SRCertsMgr::LoadAllCerts(TRSPCertificates const&) (SRCertsMgr.cpp:204)
==4978==    by 0x5D1F4BC: SRCertsMgr::__Initialize(int) (SRCertsMgr.cpp:46)


code:

	bool CertsX509Read::load_cert(const unsigned char *in, long len)
	{
	    ClearCert();
	
	    if (len <= 0)
	    {
	        return false;
	    }
	
	    const unsigned char *pIn = in;
	    OPENSSL_AUTO_FREE(X509, X509_free, pX509, d2i_X509(nullptr, &pIn, len));  //line 328
	
	    if (pX509 == nullptr)
	    {
	        throw_load_cert_error("certificate");
	    }
	    else
	    {
	        m_pX509 = std::move(pX509);
	        m_derCert = std::string(reinterpret_cast<const char *>(in), (size_t) len);
	    }
	
	    get_CertDER();
	    get_CertPEM();
	
	    return true;
	}


看到 328 的内存，申请了之后，内存泄漏


阅读代码，内存申请之后，std::move给了智能指针。
说明智能指针，没有释放内存。

智能指针，不释放内存，极大的可能是，对指针的用法错误。


阅读代码，对 该只能指针，


	void CertsX509Read::ClearCert()
	{
	    m_ECKeyForVerify = nullptr;
	    m_iKeyAlgParamNID = NID_undef;
	    m_strSubjectSN.clear();
	    m_strRegisteredID.clear();
	    m_derCert.clear();
	    m_pemCert.clear();
	
	    m_pX509.release()();
	}
	

对该指针，释放的时候，调用了release

release函数： 清空 智能指针，并返回 管理的指针，其并不释放内存。造成内存泄漏
处理 改成reset()


	void CertsX509Read::ClearCert()
	{
	    m_ECKeyForVerify = nullptr;
	    m_iKeyAlgParamNID = NID_undef;
	    m_strSubjectSN.clear();
	    m_strRegisteredID.clear();
	    m_derCert.clear();
	    m_pemCert.clear();
	
	    m_pX509.reset();
	}
	
# 其他

通过观察 var*.log 发现内存泄漏，全部都是以上的情况，所以，修复后，继续性能测试。 继续观察问题：


