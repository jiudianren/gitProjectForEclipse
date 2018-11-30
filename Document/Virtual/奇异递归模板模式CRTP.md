/*
https://blog.csdn.net/daniel_ustc/article/details/73699378
*/


	template <typename T>
	class Base
	{
	    ...
	};
	 // use the derived class itself as a template parameter of the base class
	class Derived : public Base<Derived>
	{
	    ...
	};
