#include <iostream>
#include <string>
#include "CallBack.h"
#include <functional>
#include <typeinfo>
using namespace std;


/*回调函数的作用：
 *
 * 调用方需要完成某些动作，而该动作需要一些额外的信息，这些额外的信息，调用方完全不知道，而被调用方知道这些信息，
 * 但被调用方不知道何时执行被调函数，只能通过调用方的主动调用被调函数，被调函数执行，来完成这些工作。
 * 1，有些信息调用方不知道，而被调用方知道。
 * 2，但被调用方，不知道何时执行该函数。
 *
 *	比如Gx 收到CCR_i ，挂起
 *	SySp   收到SLA后，告知 Gx处理 挂起的 CCR_i
 *
 *	这里就可以用一个回调
 *
 * */


//Test 是背调函数，
// LetRun是调用函数，当调用函数执行的时候，被调函数，执行，单被调函数，执行的时候，需要调用函数，传入额外的信息。
void  Test(int n, string str)
{
    cout<<" function called "<<str<<endl;
    cout<<n<<" "<<str<<endl;
}

void mainCallBack()
{
    Call call;
    CalledClass called;
    call.SetFun((MyFun)Test);    //调回调函数的接口，并传入一个函数作为参数
    call.LetRun(10,"1+1=?");

    //	std::bind(&Test::callback,this,_1,_2);

    //	Fun fun=std::bind(&Test::callback,this,_1,_2);
    //类成员函数里面有一个this指针，所以需要一些手段才能转换成  回调函数的 的指针
    //	MyFun cfun=(MyFun) &called.CalledFun;

    auto cfun= std::bind(&CalledClass::CalledFun,called,std::placeholders::_1,std::placeholders::_2);
    cfun(1,"what is the quesitino");

    std::function<void(int,string)> functional = std::bind(&CalledClass::CalledFun,called,std::placeholders::_1,std::placeholders::_2);
    //    call.SetFun((MyFun) functional);    //调回调函数的接口，并传入一个函数作为参数
    //    call.LetRun(10,"1+1=?");
    functional(1,"tell me the anwser");


    std::function<void(void)> functional1=std::bind(&CalledClass::CalledFun,called,(int)1000,"tell me the anwser ");
    call.SetFun2(functional1);


    call.SetFun3( &called,& CalledClass::CalledFun);
    call.LetRun3(1, "tell me the anwser");



    std::function<void(int n ,string str)> functional2=std::bind(&CalledClass::CalledFun,called,std::placeholders::_1,std::placeholders::_2);
    call.SetFun4( functional2);
    call.LetRun4(1, "tell me the anwser");


    call.SetFun5( functional2);
    call.LetRun4(1, "tell me the anwser");

}
