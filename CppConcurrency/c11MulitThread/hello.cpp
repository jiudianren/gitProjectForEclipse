
#include <iostream>
#include <thread> //①
void hello() //②
{
	std::cout << "Hello Concurrent World\n";
}
int main()
{
	std::thread t(hello); //③
	t.join(); //④

	/*
	 *
	 * 新的线程启动之后③，初始线程继续执行。如果它不等待新线程结束，它就将自顾自地继续运
行到main()的结束，从而结束程序——有可能发生在新线程运行之前。这就是为什么在④这里
调用 join() 的原因——详见第2章，这会导致调用线程(在main()中)等待与 std::thread 对象
相关联的线程，即这个例子中的t*/
}
