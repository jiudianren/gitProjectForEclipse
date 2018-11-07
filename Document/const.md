https://blog.csdn.net/m0_37338590/article/details/61195131
https://blog.csdn.net/wangkai_123456/article/details/76598917

const的用法大致可分为以下几个方面：

(1)const修饰基本数据类型
(2)const应用到函数中
(3)const在类中的用法
(4)const修饰类对象，定义常量对象




##1.const修饰一般常量及数组??

	const?int?a=10;???????????????等价的书写方式：?????int?const?a=10;
	const?int?arr[3]={1,2,3};????????????????????????int?const?arr[3]={1,2,3};

 对于类似这些基本数据类型，修饰符const可以用在类型说明符前，也可以用在类型说明符后，其结果是一样的。在使用这些常量的时候，只要不改变这些常量的值便好。

##2.const修饰指针变量*及引用变量

　　(1)只有一个const，如果const位于*左侧，表示指针所指数据是常量，不能通过解引用修改该数据；指针本身是变量，可以指向其他的内存单元。

例如：const type 指针变量名 = 对象地址；//指常对象的指针变量
 其含义是指针所指向的常对象，指针本身是变量。如：

	 int d1 = 1,d2;//定义两个整形变量
	const int * p = &d1;//定义一个指向常对象的指针变量；
	 *p=2;//错误，不可以改变指针所指向的常对象的值
	 p = &d2;//指针可修改初始化后所指向的对象的地址

　　(2)只有一个const，如果const位于*右侧，表示指针本身是常量，不能指向其他内存地址；指针所指的数据可以通过解引用修改。
例如：type const 指针变量名 = 对象地址；//常指针
 其含义是这样的指针始终保持其初值，程序中不可修改其指向。如：

	int d1 = 1,d2;//定义两个整形变量
	int *const p = &d1;//定义一个常指针指向d1；
	 *p=2;//改变常指针所指向的变量的值
	p = &d2;//错误，常指针不可修改初始化后所指向的对象的地址


如果const位于星号*的左侧，则const就是用来修饰指针所指向的变量，即指针指向为常量；
如果const位于星号的右侧，const就是修饰指针本身，即指针本身是常量。



#二、const应用到函数中

	1.作为参数的const修饰符
	2.作为函数返回值的const修饰符

其实，不论是参数还是返回值，道理都是一样的，参数传入时候和函数返回的时候，初始化const变量
##1修饰参数的const，如 void fun0(const A* a ); void fun1(const A& a);
调用函数的时候，用相应的变量初始化const常量，则在函数体中，按照const所修饰的部分进行常量化，如形参为const A* a，
 则不能对传递进来的指针的内容 进行改变，保护了原指针所指向的内容；如形参为const A& a，则不能对传递进来的引用对象进行改变，

????? 保护了原对象的属性。
???? [注意]：参数const通常用于参数为指针或引用的情况;?

##2修饰返回值的const，如const A fun2( ); const A* fun3( );

 这样声明了返回值后，const按照"修饰原则"进行修饰，起到相应的保护作用。

const Rational operator*(const Rational& lhs, const Rational& rhs)
{
return Rational(lhs.numerator() * rhs.numerator(),
lhs.denominator() * rhs.denominator());
}
 返回值用const修饰可以防止允许这样的操作发生:

Rational a,b;
Radional c;
(a*b) = c;

一般用const修饰返回值为对象本身（非引用和指针）的情况多用于二目操作符重载函数并产生新对象的时候。
类中的成员函数：A fun4()const; 其意义上是不能修改所在类的的任何变量。?

三、类中定义常量（const的特殊用法）

四、const定义常量对象，以及常量对象的用法?

	?class test
	{
	public:
	  test():x(1)
	??? {
	??????? y=2;
	??? }
	??? ~test()
	??? {}
	??? void set(int yy)
	??? {
	??????? y=yy;
	??? }
	??? int getx() const
	??? {
	??????? return x;
	??? }
	//protected:
	??? const int x;
	??? int y;
	};
	void main()
	{
	const test t;
	t.set(33);//error
	t.getx();
	}

常量对象只能调用常量函数，别的成员函数都不能调用。?

五、使用const的一些建议
	?? <1>要大胆的使用const，这将给你带来无尽的益处，但前提是你必须搞清楚原委；
	?? <2> 要避免最一般的赋值操作错误，如将const变量赋值，具体可见思考题；
	?? <3> 在参数中使用const应该使用引用或指针，而不是一般的对象实例，原因同上；
	?? <4> const在成员函数中的三种用法（参数、返回值、函数）要很好的使用；
	?? <5>不要轻易的将函数的返回值类型定为const;
	?? <6>除了重载操作符外一般不要将返回值类型定为对某个对象的const引用;?
