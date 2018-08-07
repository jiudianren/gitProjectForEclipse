//#define __cplusplus 201103L


#include "../c11MulitThread/AutomicFlagTest.h"

#include <string>
#include <thread>
#include <atomic>
#include  <iostream>
#include <vector>
#include <chrono>

using namespace std;

std::atomic<bool> ready(false);
std::atomic_flag winner = ATOMIC_FLAG_INIT;

void count1m(int x)
{
    std::cout << "thread #" << x << " in \n";
    while(!ready)
    {
//        std::cout << "thread #" << x << " yield \n";
        std::this_thread::yield();
    }
    for(int i=0 ;i<100;i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
    if (!winner.test_and_set()) {
        std::cout << "thread #" << x << " won!\n";
    }
}





void mainAutomicTest()
{

    cout<<"mainAutomicTest=================start"<<endl;
    winner.clear();
    vector<std::thread> vs;
    for(int i=0 ; i<=10; i ++)
    {
        vs.push_back(std::thread(count1m,i));
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(2));
    ready=true;
    for(auto & th: vs)
    {
        th.join();
    }
    cout<<"mainAutomicTest=================end"<<endl;

}
