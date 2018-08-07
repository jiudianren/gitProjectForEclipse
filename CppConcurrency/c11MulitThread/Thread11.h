/*
 * Thread11.h
 *
 *  Created on: 2017Äê6ÔÂ12ÈÕ
 *      Author: Lian
 */

#ifndef THREADTEST_THREAD11_H_
#define THREADTEST_THREAD11_H_
#include <string>
#include <iostream>
#include <thread>
#include  <chrono>
#include <mutex>
using namespace std;

// 11 thread

static std::mutex mtx;
enum
{


};


class SimpThread
{

public:

	std::thread m_thread;
	static int m_i;
	std::thread::id m_id;
//	std::mutex mtx;
	void RunThread()
	{
//		m_thread=std::thread(&mythread, this);
	}
	void init(int id)
	{
		cout<<__func__<< id<<endl;
		//for linux
//		m_thread=std::thread(&mythread, this,id);
		cout<<__func__<<id <<" end"<<endl;
	}

	void mythread ( int thead_id)
	{
//		std::thread::id threadid=std::this_thread::get_id();
		std::this_thread::sleep_for(std::chrono::microseconds(500));
		while( m_i < 100)
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));
			mtx.lock();
			m_i++;
			mtx.unlock();
			cout<<"thread_id "<<thead_id <<" m_i: "<<m_i<<endl;
		}
		if(m_i >=100)
		{
			cout<<"thread_id "<<thead_id <<" out of 100 "<<endl;
		}
	}
};

void  mainThread11();
void threadSwap(void);


#endif /* THREADTEST_THREAD11_H_ */
