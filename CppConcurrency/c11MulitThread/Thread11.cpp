/*
 * Thread11.cpp
 *
 *  Created on: 2017年6月12日
 *      Author: Lian
 */


#include "../c11MulitThread/Thread11.h"

#include <string>
#include <iostream>
#include <thread>
#include <iostream>       // std::cout
#include <future>         // std::async, std::future
#include <chrono>         // std::chrono::milliseconds

using namespace std;



int SimpThread::m_i=0;



void threadSwap(void){
	int a = 1;
	thread t( [](int* pa){
		for(;;){
			*pa = (*pa * 33) % 0x7fffffff;
			if ( ( (*pa) >> 30) & 1) break;
		}
	}, &a);

	thread t2;

	cout << "before swap: t=" << t.get_id()
		 << ", t2=" << t2.get_id() << endl;
	swap(t, t2);
	cout << "after swap : t=" << t.get_id()
		 << ", t2=" << t2.get_id() << endl;
	t2.join();
	cout << "a=" << a << endl;
}


//void threadYield(void){
//	unsigned int procs = thread::hardware_concurrency(), // 获取物理线程数目
//			i = 0;
//	thread* ta = new thread( [](){
//		struct timeval t1, t2;
//		gettimeofday(&t1, NULL);
//		for(int i = 0, m = 13; i < COUNT; i++, m *= 17){
//			this_thread::yield();
//		}
//		gettimeofday(&t2, NULL);
//		print_time(t1, t2, " with yield");
//	} );
//	thread** tb = new thread*[ procs ];
//	for( i = 0; i < procs; i++){
//		tb[i] = new thread( [](){
//			struct timeval t1, t2;
//			gettimeofday(&t1, NULL);
//			for(int i = 0, m = 13; i < COUNT; i++, m *= 17){
//				do_nothing();
//			}
//			gettimeofday(&t2, NULL);
//			print_time(t1, t2, "without yield");
//		});
//	}
//	ta->join();
//	delete ta;
//	for( i = 0; i < procs; i++){
//		tb[i]->join();
//		delete tb[i];
//	};
//	delete tb;
//}

void mainThread11(void )
{

	threadSwap();

	SimpThread st3;
	st3.init(3);
	SimpThread st4;
	st4.init(4);

	st3.m_thread.detach();
	st4.m_thread.detach();

	SimpThread::m_i=30;

	SimpThread st;
	st.init(1);
	SimpThread st1;
	st1.init(2);
	st.m_thread.join();
	SimpThread::m_i=50;
	//	st1.m_thread.join();
	//如果线程没有被 join 或者detach 那么线程执行结束，进程也会被结束掉
	st1.m_thread.detach();


}
