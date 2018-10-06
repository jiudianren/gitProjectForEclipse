#oop 和模板的区别

oop与模板编程，都能处理在编写程序时，不知道类型的情况。不同之处：
oop能处理类型在程序运行之前都未知的情况。
泛型编程中，在编译时就获知类型了。

泛型编程中，在编译的时候就能获知类型了
模板是一种蓝图或者公式，比如在使用vector 或者find这样的泛型编程时，能够将
模板转化成特定的类，或者函数， 重点是，这种转换时编译的时候，确定的
#函数模板
#模板参数列表 模板参数
在模板定义中，模板参数列表不能为空

#非类型模板参数

非类型参数，可以是整形，或者指向对象或函数类型的指针或者 左值引用 ，
指针或者引用必须具有静态生存期

用户提供，或者编译推断出的常量，或者常量表达式


#实例化函数模板


#模板程序应该尽量减少对实参类型的要求


#模板编译：

编译器遇到模板定义时候，并不生成代码。
实例化 和 使用的
只有当实例化出模板的一个特例的时候，编译器才会生成代码
 如何组织代码，如何检测错误

#大多数编译错误在实例化期间报告

#保证传递给模板的实参支持模板要求的所有操作，以及这些操作能在模板中能正确的工作，是调用者的责任


#类模板和函数模板
编译器不能为类模板推断推断模板参数类型
可以为函数模板推断参数类型

#为了生成一个实例，编译器需要掌握函数模板或者类模板的成员的成员函数，因此模板头文件通常既包含 定义，也包含实现

#function template
模板 参数列表
模板参数
模板类型参数
非类型模板参数: 整形 ，或者一个指针，或者一个引用 （静态生存期）

	template<usigned M ,usigned N>
	bool compare( const (&p) [M],const (&Q) [N], )
	{
		if( t1> t2)
		{
			return true;
		}
	}
	
	使用
	compare( "hello", "world");
	
模板实参
模板函数参数

    template<typename t>
	int compare( T t1, T t2)
	{
		if( t1> t2)
		{
			return true;
		}
	}
	
T的类型，可以显示或者隐式的指定
其中T的实际类型,需要在编译时期根据其使用确定。

确定时期，是在编译时期就确定了的
 
比如使用 cout<<compare(1,0)<<endl;时，
编译器推断出 模板参数，将模板函数 实例化 一个特定版本的函数。
这些编译生成的版本，称为模板的实例

#class template


模板里面使用 别处的模板的时候，如何处理


    template<T> class Bol
    {
    	public:
    	std::shared_ptr<vector<T>> date;
    }

模板的每个实例都是一个独立的类

比如  Bol<int> abol; Bol<string>  sbol; 两者并没有关系
但如果是同一模板实参类型，比如 Bol<int> abol1; Bol<int> abol2; 
这个时候，生成的两个类，之间有关联吗？ 即会生成一个实例，还是两个实例？

类模板的成员函数的实例化，只有当程序使用到这个成员函数的时候，才会实例化

#模板作用域内引用模板


#类模板与友元 
1友元 非模板
2 友元 模板
3 友元  是模板实例

#模板声明，必须包含模板参数
#默认模板实参


#成员模板
一个类可以包含本身是模板的成员函数，这种成员称为成员模板

普通类的成员模板

class A
{
public:
  template <typename T> opearate()(T * p) const
  {
  	delete p;
  }
};

double * pd= new double(0);
A()(dp);


模板类的成员模板  
类和成员 各自有自己的。独立的模板参数

声明：
template <typename T> class B
{
  template<typename it> B(it b ,it e);
  
}
定义
template<typename  T> template<typename it>
B(it b,it e):data(std::make_shared<std::vectore<T>(b, e)>){}





#控制实例化 避免 实例化在编译过程中的开销
实例化声明 
extern template declaration; //表明别处有定义
实例化定义
template declaration ;
当编译器遇到实例化定义时，会为其实例化

实例化定义会定义所有成员


#模板实参 推断
##类型转换 末班类型参数

    template <T> obj(T,T)
    string a("s");
    const string b("dd");
    obj(a ,b) //ok obj(string ,string )
    
    
数组和函数指针转换： 对引用类型的模板参数 转换无效
##函数模板 显式形参
##尾置返回类型 与类型转换


    template <class T> 
    auto func(it beg,it end) -->decltype( *beg)
    {
    	return *beg;
    	}
## 函数指针和实参推断
##***模板实参推断和引用***
从左值引用函数参数 ，推断类型
    
    template<class T> f1(T & t)
	int a=10;
	const int ca=10;
	
	f1(  a )  //T int
	f1(ca)    //T const int
	f1(10)   //wrong
	
	  template<class T> f2(const T & t)
	f2(a)  // T int
	f2(ca)  //T int
	f2(10)   //T int


从左值引用函数参数 ，推断类型
    
    	  template<class T> f3( T && t)
    	  f3( 42) //T is int
    	  int a=90
    	  f3(a) //T is int & 

######  引用折叠与右值引用参数

	int b=90
	f3(b)  // 规则1  T is int &
	
## std::move的定义以及其工作 原理

能够将 左值，和右值，都能 move成一个右值引用
static_cast 可以显示的将一个左值，转化为一个 右值引用


## 转发

某些函数希望将一个或多个实参，连同其类型不变第转发给其他函数

这就需要完美转发

# 完美转发  在模板中的实际推导过程
	不完美
	template<typdef F , class T1 ,class T2>
	void flip(F f, T1 && t1, T2 && t2)
	 {
	 	f( t2,t1);
	 }
	 
	完美的是
	
	template<typdef F , class T1 ,class T2>
	void flip(F f, T1 && t1, T2 && t2)
	 {
	 	f( std::forward<T2>t2, std::forward<T1> t1);
	 }
	
	

#多个重载模板 对同一调用都匹配，则选择最特化的版本

#同一函数，如果函数模板和非函数模板都很好的匹配，则选择非模板版本


#16.4.2 包括展


# 模板特化
目的：
编写单一模板，对所有的模板实参都适合，都能实例化，这并不总是能办到。
某些情况下， 通用模板定义对某些定义不合适：通用模板定义可能编译失败，或者不正确，或者有更高效率的版本，可以替换   

当我们不能或者不希望使用 模板版本时 ，可以定义类或者函数模板的一个特例化版本


    template <typedef T> int cmp( T t1, T2 t2)
    {
    }
    
    特化
    template<> int cmp( const char* const t1, const char* const t2)
    {
    }


特化版本，实际上时模板函数的一个实例，并非重载
当特例话一个模板时，必须为模板的每个参数都提供实参


类模板的特化
类模板的部分特化 又称 偏特化 
类模板不必为所有的模板参数提供实参， 我们可以指定一部分而非所有的模板参数  
一个类的部分特化本身，是一个模板，使用时，用户还需要为在特例化版本中未指定的模板参数提供实参  



https://blog.csdn.net/zwjzwj108108/article/details/79122711


    template <T> struct remove_reference
    {
    	typedef T type;
    }
     //部分特化
      template <T> struct remove_reference<T & >
    {
    	typedef T type;
    }
          template <T> struct remove_reference<T && >
    {
    	typedef T type;
    }
    
    
特化成员，而不是类的方法


# 默认模板参数 是一个模板类 的时候，如何设置





# and so on
