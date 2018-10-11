gtest gmock的使用

perl生成，按照现在的目录层级，生成所有类的mock类

[TestCaseName，TestName]，而我对这两个参数的定义是：[TestSuiteName，TestCaseName]，在下一篇我们再来看为什么这样定义

class为suit member为 case



	
	class TEST_TCdrInDbStatInfo_Suit : public ::testing::Test  { 
	     //可以为suitcast设置一些启动资源，结束的时候清理资源
	protected:
	
	    static void SetUpTestCase()
	    {
	    
	
	    }
	
	    static void TearDownTestCase()
	    {
	    }
	
	    static std::vector<TBalInfo> m_vecBalInfo;
	
	};
	
	TEST( CLASS , member) //suit 和case 
	TEST(TEST_TCdrInDbStatInfo, SetCdrInDBStatMode_01)
	{
	    TCdrInDbStatInfo tObj;
	
	    bool bPara = true;
	    tObj.SetStaticOrNot( bPara);
	    EXPECT_EQ( bPara,  tObj.GetCdrInDBStatMode());
	}
	

    1. EXPECT_*  失败时，案例继续往下执行。

    2. ASSERT_* 失败时，直接在当前函数中返回，当前函数中ASSERT_*后面的语句将不会执行。

### 断言
http://www.cnblogs.com/coderzh/archive/2009/04/06/1430364.html

  
##事件机制：
http://www.cnblogs.com/coderzh/archive/2009/04/06/1430396.html
    
gtest提供了多种事件机制，非常方便我们在案例之前或之后做一些操作。总结一下gtest的事件一共有3种：

1. 全局的，所有案例执行前后。
2. TestSuite级别的，在某一批案例中第一个案例前，最后一个案例执行后。

3. TestCase级别的，每个TestCase前后。


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
	

	
这样还不够，我们还需要告诉gtest添加这个全局事件，我们需要在main函数中通过testing::AddGlobalTestEnvironment方法将事件挂进来，也就是说，我们可以写很多个这样的类，然后将他们的事件都挂上去。

	int _tmain(int argc, _TCHAR* argv[])
	{
	    testing::AddGlobalTestEnvironment(new FooEnvironment);
	    testing::InitGoogleTest(&argc, argv);
	    return RUN_ALL_TESTS();
	}
	
	
	三、TestSuite事件
我们需要写一个类，继承testing::Test，然后实现两个静态方法

1. SetUpTestCase() 方法在第一个TestCase之前执行

2. TearDownTestCase() 方法在最后一个TestCase之后执行


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

在编写测试案例时，我们需要使用TEST_F这个宏，第一个参数必须是我们上面类的名字，代表一个TestSuite。


	TEST_F(FooTest, Test1)
	 {
	    // you can refer to shared_resource here 
	}
	TEST_F(FooTest, Test2)
	 {
	    // you can refer to shared_resource here 
	}

四、TestCase事件 
TestCase事件是挂在每个案例执行前后的，实现方式和上面的几乎一样，不过需要实现的是SetUp方法和TearDown方法：

1. SetUp()方法在每个TestCase之前执行
2. TearDown()方法在每个TestCase之后执行


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

	
	
	
	
	
# 参数化

二、旧的方案
为了对比，我还是把旧的方案提一下。首先我先把被测函数IsPrime帖过来(在gtest的example1.cc中)，这个函数是用来判断传入的数值是否为质数的。


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

 

假如我要编写判断结果为True的测试案例，我需要传入一系列数值让函数IsPrime去判断是否为True（当然，即使传入再多值也无法确保函数正确，呵呵），因此我需要这样编写如下的测试案例：


	TEST(IsPrimeTest, HandleTrueReturn)
	{
	    EXPECT_TRUE(IsPrime(3));
	    EXPECT_TRUE(IsPrime(5));
	    EXPECT_TRUE(IsPrime(11));
	    EXPECT_TRUE(IsPrime(23));
	    EXPECT_TRUE(IsPrime(17));
	}

 

我们注意到，在这个测试案例中，我至少复制粘贴了4次，假如参数有50个，100个，怎么办？同时，上面的写法产生的是1个测试案例，里面有5个检查点，假如我要把5个检查变成5个单独的案例，将会更加累人。

接下来，就来看看gtest是如何为我们解决这些问题的。 

三、使用参数化后的方案
1. 告诉gtest你的参数类型是什么

你必须添加一个类，继承testing::TestWithParam<T>，其中T就是你需要参数化的参数类型，比如上面的例子，我需要参数化一个int型的参数
	
	class IsPrimeParamTest : public::testing::TestWithParam<int>
	{
	
	};
 

2. 告诉gtest你拿到参数的值后，具体做些什么样的测试

这里，我们要使用一个新的宏（嗯，挺兴奋的）：TEST_P，关于这个"P"的含义，Google给出的答案非常幽默，就是说你可以理解为”parameterized" 或者 "pattern"。我更倾向于 ”parameterized"的解释，呵呵。在TEST_P宏里，使用GetParam()获取当前的参数的具体值。

	TEST_P(IsPrimeParamTest, HandleTrueReturn)
	{
	    int n =  GetParam();
	    EXPECT_TRUE(IsPrime(n));
	}
	 

嗯，非常的简洁！

3. 告诉gtest你想要测试的参数范围是什么

 使用INSTANTIATE_TEST_CASE_P这宏来告诉gtest你要测试的参数范围：

	INSTANTIATE_TEST_CASE_P(TrueReturn, IsPrimeParamTest, testing::Values(3, 5, 11, 23, 17));
	

## 也可以不写main函数，直接在编译的时候链接libgtest_main.a库