#�ڴ�й©


����Ŀ�У����ܲ��Ե�ʱ�����ڴ�й© ��ͨ��valgrind�Ĳ鿴�ڴ�й©��

	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --trace-children=yes --num-callers=200 --log-file=./valgrind.log   ./SM-SR 
	

valgrind.log:



##��� 1
	2 bytes in 1 blocks are definitely lost in loss record 7 of 636
	......
	by 0x9DE5BBB: Private::_TMySqlQuery::SetParameter(char const*, char const*, bool) (TMySql.cpp:1276)
	.....



���� 

	
                delete[] m_pTParmList[i].m_StrBuf;
                m_pTParmList[i].m_StrBuf = NULL;
                unsigned long iLen = strlen(sParamValue);
                m_pTParmList[i].m_StrBuf = new char[iLen + 1];
                m_pTParmList[i].m_StrBuf[iLen] = '\0';

ע�⵽ �����ڴ棬֮ǰ�����ͷ�֮ǰ���ڴ档

ԭ���ڴ�˭����˭�ͷ�

���ԣ������ԣ����ǳ��������ʱ��û���ͷš�

�鿴����������û��ѽ�ͷ�



##��� 2

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
	        int len = i2d_PrivateKey(m_PriKey.get(), &pBuf);//������ڴ棬��Ҫ���������ͷ� 1144
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

	
	
i2d_PrivateKey �ڶ��������������� ���ݡ������� ����һ��i2d_PrivateKey ���ã���û����ʾ�ڴ�û���ͷš�


�Ա����Σ����Կ����ڶ��ε��ڴ棬��û������ �ڴ�й©����Ϊ�䱻����ָ�����
i2d_PrivateKey���ڶ��������ӹܵĲ�������Ҫ�Լ��ͷš�

����ʱ�ڶ�������������Ҫ����һ�ε���ֻ��Ϊ�˵õ�len��
���� 

  int len = i2d_PrivateKey(m_PriKey.get(), &pBuf);//������ڴ棬��Ҫ���������ͷ� 1144
�޸ĳ�
  int len = i2d_PrivateKey(m_PriKey.get(), nullptr);//������ڴ棬��Ҫ���������ͷ� 1144



## ���3 

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
	
	


���Կ��� ��unique_ptr ,����ָ�룬�������ڴ棬���ң���ֵ�ˣ�ָ����ͷź�����


����ͷź�����

���� �� *p����û���ͷŵĵط���

���� �޸ĳɣ�

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
            
            
       
       
## ���4

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


���� 328 ���ڴ棬������֮���ڴ�й©


�Ķ����룬�ڴ�����֮��std::move��������ָ�롣
˵������ָ�룬û���ͷ��ڴ档

����ָ�룬���ͷ��ڴ棬����Ŀ����ǣ���ָ����÷�����


�Ķ����룬�� ��ֻ��ָ�룬


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
	

�Ը�ָ�룬�ͷŵ�ʱ�򣬵�����release

release������ ��� ����ָ�룬������ �����ָ�룬�䲢���ͷ��ڴ档����ڴ�й©
���� �ĳ�reset()


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
	
# ����

ͨ���۲� var*.log �����ڴ�й©��ȫ���������ϵ���������ԣ��޸��󣬼������ܲ��ԡ� �����۲����⣺


