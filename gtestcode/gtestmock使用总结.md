gtest gmock��ʹ��

perl���ɣ��������ڵ�Ŀ¼�㼶�������������mock��

[TestCaseName��TestName]�����Ҷ������������Ķ����ǣ�[TestSuiteName��TestCaseName]������һƪ����������Ϊʲô��������

classΪsuit memberΪ case



	
	class TEST_TCdrInDbStatInfo_Suit : public ::testing::Test  { 
	     //����Ϊsuitcast����һЩ������Դ��������ʱ��������Դ
	protected:
	
	    static void SetUpTestCase()
	    {
	    
	
	    }
	
	    static void TearDownTestCase()
	    {
	    }
	
	    static std::vector<TBalInfo> m_vecBalInfo;
	
	};
	
	TEST( CLASS , member) //suit ��case 
	TEST(TEST_TCdrInDbStatInfo, SetCdrInDBStatMode_01)
	{
	    TCdrInDbStatInfo tObj;
	
	    bool bPara = true;
	    tObj.SetStaticOrNot( bPara);
	    EXPECT_EQ( bPara,  tObj.GetCdrInDBStatMode());
	}
	

    1. EXPECT_*  ʧ��ʱ��������������ִ�С�

    2. ASSERT_* ʧ��ʱ��ֱ���ڵ�ǰ�����з��أ���ǰ������ASSERT_*�������佫����ִ�С�

### ����
http://www.cnblogs.com/coderzh/archive/2009/04/06/1430364.html

  
##�¼����ƣ�
http://www.cnblogs.com/coderzh/archive/2009/04/06/1430396.html
    
gtest�ṩ�˶����¼����ƣ��ǳ����������ڰ���֮ǰ��֮����һЩ�������ܽ�һ��gtest���¼�һ����3�֣�

1. ȫ�ֵģ����а���ִ��ǰ��
2. TestSuite����ģ���ĳһ�������е�һ������ǰ�����һ������ִ�к�

3. TestCase����ģ�ÿ��TestCaseǰ��


	class FooEnvironment : public testing::Environment
	{
	public:
	    virtual void SetUp()
	    {
	        std::cout << "Foo FooEnvironment SetUP" << std::endl;
	    }
	    virtual void TearDown()
	    {
	        std::cout << "Foo FooEnvironment TearDown" << std::endl;
	    }
	};
	

	
���������������ǻ���Ҫ����gtest������ȫ���¼���������Ҫ��main������ͨ��testing::AddGlobalTestEnvironment�������¼��ҽ�����Ҳ����˵�����ǿ���д�ܶ���������࣬Ȼ�����ǵ��¼�������ȥ��

	int _tmain(int argc, _TCHAR* argv[])
	{
	    testing::AddGlobalTestEnvironment(new FooEnvironment);
	    testing::InitGoogleTest(&argc, argv);
	    return RUN_ALL_TESTS();
	}
	
	
	����TestSuite�¼�
������Ҫдһ���࣬�̳�testing::Test��Ȼ��ʵ��������̬����

1. SetUpTestCase() �����ڵ�һ��TestCase֮ǰִ��

2. TearDownTestCase() ���������һ��TestCase֮��ִ��


	class FooTest : public testing::Test {
	 protected:
	  static void SetUpTestCase() {
	    shared_resource_ = new ;
	  }
	  static void TearDownTestCase() {
	    delete shared_resource_;
	    shared_resource_ = NULL;
	  }
	  // Some expensive resource shared by all tests.
	  static T* shared_resource_;
	};

�ڱ�д���԰���ʱ��������Ҫʹ��TEST_F����꣬��һ��������������������������֣�����һ��TestSuite��


	TEST_F(FooTest, Test1)
	 {
	    // you can refer to shared_resource here 
	}
	TEST_F(FooTest, Test2)
	 {
	    // you can refer to shared_resource here 
	}

�ġ�TestCase�¼� 
TestCase�¼��ǹ���ÿ������ִ��ǰ��ģ�ʵ�ַ�ʽ������ļ���һ����������Ҫʵ�ֵ���SetUp������TearDown������

1. SetUp()������ÿ��TestCase֮ǰִ��
2. TearDown()������ÿ��TestCase֮��ִ��


	class FooCalcTest:public testing::Test
	{
	protected:
	    virtual void SetUp()
	    {
	        m_foo.Init();
	    }
	    virtual void TearDown()
	    {
	        m_foo.Finalize();
	    }
	
	    FooCalc m_foo;
	};
	
	TEST_F(FooCalcTest, HandleNoneZeroInput)
	{
	    EXPECT_EQ(4, m_foo.Calc(12, 16));
	}
	
	TEST_F(FooCalcTest, HandleNoneZeroInput_Error)
	{
	    EXPECT_EQ(5, m_foo.Calc(12, 16));
	}

	
	
	
	
	
# ������

�����ɵķ���
Ϊ�˶Աȣ��һ��ǰѾɵķ�����һ�¡��������Ȱѱ��⺯��IsPrime������(��gtest��example1.cc��)����������������жϴ������ֵ�Ƿ�Ϊ�����ġ�


	// Returns true iff n is a prime number.
	bool IsPrime(int n)
	{
	    // Trivial case 1: small numbers
	    if (n <= 1) return false;
	
	    // Trivial case 2: even numbers
	    if (n % 2 == 0) return n == 2;
	
	    // Now, we have that n is odd and n >= 3.
	
	    // Try to divide n by every odd number i, starting from 3
	    for (int i = 3; ; i += 2) {
	        // We only have to try i up to the squre root of n
	        if (i > n/i) break;
	
	        // Now, we have i <= n/i < n.
	        // If n is divisible by i, n is not prime.
	        if (n % i == 0) return false;
	    }
	    // n has no integer factor in the range (1, n), and thus is prime.
	    return true;
	}

 

������Ҫ��д�жϽ��ΪTrue�Ĳ��԰���������Ҫ����һϵ����ֵ�ú���IsPrimeȥ�ж��Ƿ�ΪTrue����Ȼ����ʹ�����ٶ�ֵҲ�޷�ȷ��������ȷ���Ǻǣ����������Ҫ������д���µĲ��԰�����


	TEST(IsPrimeTest, HandleTrueReturn)
	{
	    EXPECT_TRUE(IsPrime(3));
	    EXPECT_TRUE(IsPrime(5));
	    EXPECT_TRUE(IsPrime(11));
	    EXPECT_TRUE(IsPrime(23));
	    EXPECT_TRUE(IsPrime(17));
	}

 

����ע�⵽����������԰����У������ٸ���ճ����4�Σ����������50����100������ô�죿ͬʱ�������д����������1�����԰�����������5�����㣬������Ҫ��5�������5�������İ���������������ˡ�

����������������gtest�����Ϊ���ǽ����Щ����ġ� 

����ʹ�ò�������ķ���
1. ����gtest��Ĳ���������ʲô

��������һ���࣬�̳�testing::TestWithParam<T>������T��������Ҫ�������Ĳ������ͣ�������������ӣ�����Ҫ������һ��int�͵Ĳ���
	
	class IsPrimeParamTest : public::testing::TestWithParam<int>
	{
	
	};
 

2. ����gtest���õ�������ֵ�󣬾�����Щʲô���Ĳ���

�������Ҫʹ��һ���µĺ꣨�ţ�ͦ�˷ܵģ���TEST_P���������"P"�ĺ��壬Google�����Ĵ𰸷ǳ���Ĭ������˵��������Ϊ��parameterized" ���� "pattern"���Ҹ������� ��parameterized"�Ľ��ͣ��Ǻǡ���TEST_P���ʹ��GetParam()��ȡ��ǰ�Ĳ����ľ���ֵ��

	TEST_P(IsPrimeParamTest, HandleTrueReturn)
	{
	    int n =  GetParam();
	    EXPECT_TRUE(IsPrime(n));
	}
	 

�ţ��ǳ��ļ�࣡

3. ����gtest����Ҫ���ԵĲ�����Χ��ʲô

 ʹ��INSTANTIATE_TEST_CASE_P���������gtest��Ҫ���ԵĲ�����Χ��

	INSTANTIATE_TEST_CASE_P(TrueReturn, IsPrimeParamTest, testing::Values(3, 5, 11, 23, 17));
	

## Ҳ���Բ�дmain������ֱ���ڱ����ʱ������libgtest_main.a��