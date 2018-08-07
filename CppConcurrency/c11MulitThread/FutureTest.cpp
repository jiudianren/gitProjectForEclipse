#include "../c11MulitThread/FutureTest.h"

#include <string>
#include <iostream>
#include <thread>
#include <iostream>       // std::cout
#include <future>         // std::async, std::future
#include <chrono>         // std::chrono::milliseconds

// a non-optimized way of checking for prime numbers:
bool is_prime (int x) {
	for (int i=2; i<x; ++i){};
	for (int i=2; i<x; ++i){};
	for (int i=2; i<x; ++i){};
	for (int i=2; i<x; ++i) if (x%i==0) return false;
	return true;
}

void do_print_ten(char c, int ms)
{
	for (int i = 0; i < 10; ++i) {
		std::this_thread::sleep_for(std::chrono::milliseconds(ms));
		std::cout << c;
	}
}

void  FuturExm ()
{
	// call function asynchronously:
	//	  std::future<bool> fut = std::async (std::launch::async,is_prime,700020007);

	std::future<bool> fut = std::async (std::launch::async,is_prime,700020007);

	// do something while waiting for function to set future:
	std::cout << "checking, please wait";

	std::chrono::milliseconds span (100);
	/* wait_for:
	 * If the shared state contains a deferred function (such as future objects returned by async),
	 * the function does not block,
	 * returning immediately with a value of future_status::deferred.
	 *
	 * 如果共享状态包含一个延迟函数，那么 wait_for 返回   future_status::deferred ，
	 * 延迟函数：比如  std::async中去  std::launch::deferred*/
	while (fut.wait_for(span) == std::future_status::timeout)
	{
		std::cout << '.';
	}

	std::cout<<std::endl;
	bool x = fut.get();


	std::future<bool> futdefe = std::async (std::launch::deferred,is_prime,700020007);
	std::cout << "checking, please wait"<<std::endl;
	while (futdefe.wait_for(span) == std::future_status::deferred)
	{
		std::cout << '.'<<std::endl;
		std::cout <<"this is a defferred asy"<<std::endl;
		break;
	}

	/*
	 * Once the value of the shared state is retrieved with future::get,
	 * calling this function returns false (unless move-assigned a new valid future).
	 * 一旦 future.get结果以后， 那它的valid返回就会为false;
	 * */

	std::cout<<"futdefe.valid() is : "<<futdefe.valid()<<std::endl;

	bool x2 = futdefe.get();
	std::cout << "\n700020007 " << (x?"is":"is not") << " prime.\n" <<"x2"<<x2;
	std::cout<<"futdefe.valid() is : "<<futdefe.valid()<<std::endl;
}


void FuEx(){
	std::cout << "with launch::async:\n";
	std::future < void >foo =
			std::async(std::launch::async, do_print_ten, '*', 100);
	std::future < void >bar =
			std::async(std::launch::async, do_print_ten, '@', 200);
	// async "get" (wait for foo and bar to be ready):
	foo.get();
	bar.get();
	std::cout << "\n\n";

	std::cout << "with launch::deferred:\n";
	foo = std::async(std::launch::deferred, do_print_ten, '*', 100);
	bar = std::async(std::launch::deferred, do_print_ten, '@', 200);
	// deferred "get" (perform the actual calls):
	foo.get();
	bar.get();
	std::cout << '\n';
}


void mainFuture(void )
{
	std::cout << "mainFuture=====================start"<<std::endl;
	FuturExm ();
	FuEx();
	std::cout << "mainFuture=====================end"<<std::endl;
}
