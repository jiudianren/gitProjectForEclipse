#new的三种用法详细解析

C++ new关键字深入理解
https://blog.csdn.net/bbs375/article/details/53202079

https://blog.csdn.net/wangkai_123456/article/details/75091270

#1 new operator，
也叫new表达式；new表达式比较常见，也最常用，例如：
	
	string* ps = new string("abc");
上面这个new表达式完成了两件事情：申请内存和初始化对象。

#2 operator new，
也叫new操作符。这两个英文名称起的也太绝了，很容易搞混，那就记中文名称吧。new操作符类似于C语 言中的malloc，只是负责申请内存，例如：

	void* buffer = operator new(sizeof(string));

注意: 这里多了一个operator。这是new的第二个用法，也算比较常见吧。

#3 placement new，
它用于在给定的内存中初始化对象，也就是说你手中已有一块闲置的内存，例如：

	void* buffer = operator new(sizeof(string));//那么现在buffer是你所拥有闲置内存的指针
	buffer = new(buffer) string("abc"); //调用了placement new，在buffer所指向的内存中初始化string类型的对象，初始值是"abc"

事实上，placement new也是new表达式的一种，但是比普通的new表达式多了一个参数，当然完成的操作和返回值也不同。

因此上面new的第一种用法可以分解两个 动作，分别为后面的两种用法。


与new对应的delete没有三种语法，它只有两种，分别是`delete operator和operator delete`，也称为delete表达式和delete操作符。
delete表达式和new表达式对应，完成对象的析构和内存的释放操作。
而delete 操作符只是用于内存的释放，和C语言中的free相似。例如：

 

	string* ps = new string("abc");
	...
	delete ps; //调用delete表达式，先析构再释放
	void* buffer = operator new(sizeof(string));
	...
	operator delete(buffer); //释放

那么为什么没有和 placement new对应的那个delete呢？其实是有的。

placement new是在指定位置初始化对象，也就是调用了构造函数，
因此与之对应的就是析构函数了，只不过它不叫placement　delete而已


	void *pv = operator new(sizeof(vector<int>));
	pv = new(pv) vector<int>(8, 0);
	...
	static_cast<vector<int>* >(pv)->~vector(); // call destruct function
	operator delete(pv); // free memory
	pv = NULL;
	//先调用析构，然后在调用operator delete 释放掉内存
	
	
	


### new opeartor的过程

	class A
	{
	   int i;
	public:
	   A(int _i) :i(_i*_i) {}
	   void Say()  { printf("i=%d\n", i); }
	};
	//调用new：
	A* pa = new A(3);

那么上述动态创建一个对象的过程大致相当于以下三句话（只是大致上）：

	A* pa = (A*)malloc(sizeof(A));
	pa->A::A(3);
	return pa;
	
new operator就是我们平时所使用的new，其行为就是前面所说的三个步骤，我们不能更改它。

但具体到某一步骤中的行为，如果它不满足我们的具体要求时，我们是有可能更改它的。

三个步骤中最后一步只是简单的做一个指针的类型转换，没什么可说的，并且在编译出的代码中也并不需要这种转换，
只是人为的认识罢了。但前两步就有些内容了。

new operator的第一步分配内存实际上是通过调用operator new来完成的，这里的new实际上是像加减乘除一样的操作符，因此也是可以重载的。
operator new默认情况下首先调用分配内存的代码，尝试得到一段堆上的空间，如果成功就返回，如果失败，则转而去调用一个new_hander，然后继续重复前面过程。
如果我们对这个过程不满意，就可以重载operator new，来设置我们希望的行为。例如：
	
	class A
	{
	public:
	   void* operator new(size_t size)
	   {
	       printf("operator new called\n");
	       return ::operator new(size);
	   }
	};
	 
	A* a = new A();
	
这里通过::operator new调用了原有的全局的new，实现了在分配内存之前输出一句话。全局的operator new也是可以重载的，但这样一来就不能再递归的使用new来分配内存，而只能使用malloc了：

	void* operator new(size_t size)
	{
	   printf("global new\n");
	   return malloc(size);
	}
	

placement new :

	#include <new.h>
	void main()
	{
	   char s[sizeof(A)];
	   A* p = (A*)s;
	   new(p) A(3); //p->A::A(3);
	   p->Say();
	}
	
对头文件<new>或<new.h>的引用是必须的，这样才可以使用placement new。这里“new(p) A(3)”这种奇怪的写法便是placement new了，它实现了在指定内存地址上用指定类型的构造函数来构造一个对象的功能，后面A(3)就是对构造函数的显式调用。这里不难发现，这块指定的地址既可以是栈，又可以是堆，placement对此不加区分。但是，除非特别必要，不要直接使用placement new ，这毕竟不是用来构造对象的正式写法，只不过是new operator的一个步骤而已。使用new operator地编译器会自动生成对placement new的调用的代码，因此也会相应的生成使用delete时调用析构函数的代码。如果是像上面那样在栈上使用了placement new，则必须手工调用析构函数，这也是显式调用析构函数的唯一情况：

	p->~A();
当我们觉得默认的new operator对内存的管理不能满足我们的需要，而希望自己手工的管理内存时，placement new就有用了。STL中的allocator就使用了这种方式，借助placement new来实现更灵活有效的内存管理。



#处理内存分配异常
正如前面所说，operator new的默认行为是请求分配内存，
	
	如果成功则返回此内存地址，如果失败则调用一个new_handler，然后再重复此过程。
于是，想要从operator new的执行过程中返回，则必然需要满足下列条件之一：

	分配内存成功
	new_handler中抛出bad_alloc异常
	new_handler中调用exit()或类似的函数，使程序结束
于是，我们可以假设默认情况下operator new的行为是这样的

	void* operator new(size_t size)
	{
	   void* p = null
	   while(!(p = malloc(size)))
	   {
	       if(null == new_handler)
	          throw bad_alloc();
	       try
	       {
	          new_handler();
	       }
	       catch(bad_alloc e)
	       {
	          throw e;
	       }
	       catch(…)
	       {}
	   }
	   return p;
	}


在默认情况下，
		
		new_handler的行为是抛出一个bad_alloc异常，因此上述循环只会执行一次。

但如果我们不希望使用默认行为，可以自定义一个new_handler，并使用std::set_new_handler函数使其生效。在自定义的new_handler中，我们可以抛出异常，可以结束程序，也可以运行一些代码使得有可能有内存被空闲出来，从而下一次分配时也许会成功，也可以通过set_new_handler来安装另一个可能更有效的new_handler。例如：

	void MyNewHandler()
	{
	   printf(“New handler called!\n”);
	   throw std::bad_alloc();
	}
	 
	std::set_new_handler(MyNewHandler);

	
	
##STL 的内存分配与 traits 技巧

todo
