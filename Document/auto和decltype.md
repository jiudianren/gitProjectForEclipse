参考c++ primer



#decltype  
用途：
	需要使用其类型，但并不想使用其值来初始化变量 


	decltype( add() ) sum =x ; //使用  add()的返回值 来声明sum的类型

decltype 不忽略const和引用修饰符

#auto

编译器根据 初始化值，自动推断 变量类型

auto忽略顶层const ,忽略应用