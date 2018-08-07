
#ifndef CALLBACK_H_
#define CALLBACK_H_

#include <iostream>
#include <string>
#include <functional>

using namespace std;
//typedef void (_stdcall *MyFun)(int n, string str);
typedef void ( *MyFun)(int n, string str);


/*
 * 调用者，知道何时做什么事，但不会做，
 * 被调用者者，知道怎么做，但不知道何时做。
 *
 * */


class CalledClass
{
private:
    string s;
public:

    CalledClass():s("i know the answer but you don't "){};

    void CalledFun(int n ,std::string str)
    {
        cout<<str<<endl;
        cout<<s<<": "<<n<<endl;
    };
};


class Call
{
private:
    MyFun myFun;
    CalledClass * pCalledClass;
    void (CalledClass::*pmyFun )(int n, string str);  //声明比较特使
    std::function<void( int n,string str)>  functional;

public:
    void SetFun(MyFun _myFun)
    {
        cout<<"some body knows the answer,i will ask him"<<endl;
        cout<<" 函数调用"<<endl;
        myFun = _myFun;
    }

    void LetRun(int n, string str)
    {
        cout<<"run callback func"<<endl;
        myFun(n, str);
    }


    void SetFun2( std::function<void( void )> functional3 )
    {
        cout<<" c++ 11  函数调用 1"<<endl;
        functional3();
    }

    //传统的调用方法
    void SetFun3(CalledClass * pclass,void (CalledClass::*pFun )(int n, string str))
    {
        cout<<"some body knows the answer,i will ask him"<<endl;
        cout<<" 成员函数调用 "<<endl;
        pCalledClass=pclass;
        pmyFun= pFun;
    }

    void LetRun3(int n, string str)
    {
        cout<<"run callback func"<<endl;
        ( (*pCalledClass).*pmyFun)(n,str);
    }


    void SetFun4(  std::function<void( int n,string str)>  & func )
    {
        cout<<" c++ 11  函数调用 2"<<endl;
        functional = func;
    }

    void SetFun5(  std::function<void( int n,string str)>   func )
    {
        cout<<" c++ 11  函数调用 3"<<endl;
        functional = func;
    }

    void LetRun4(int n, string str)
    {
        cout<<"run callback func"<<endl;
        functional(n,str);
    }
};


void mainCallBack();

#endif /* CALLBACK_H_ */
