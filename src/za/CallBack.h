
#ifndef CALLBACK_H_
#define CALLBACK_H_

#include <iostream>
#include <string>
#include <functional>

using namespace std;
//typedef void (_stdcall *MyFun)(int n, string str);
typedef void ( *MyFun)(int n, string str);


/*
 * �����ߣ�֪����ʱ��ʲô�£�����������
 * ���������ߣ�֪����ô��������֪����ʱ����
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
    void (CalledClass::*pmyFun )(int n, string str);  //�����Ƚ���ʹ
    std::function<void( int n,string str)>  functional;

public:
    void SetFun(MyFun _myFun)
    {
        cout<<"some body knows the answer,i will ask him"<<endl;
        cout<<" ��������"<<endl;
        myFun = _myFun;
    }

    void LetRun(int n, string str)
    {
        cout<<"run callback func"<<endl;
        myFun(n, str);
    }


    void SetFun2( std::function<void( void )> functional3 )
    {
        cout<<" c++ 11  �������� 1"<<endl;
        functional3();
    }

    //��ͳ�ĵ��÷���
    void SetFun3(CalledClass * pclass,void (CalledClass::*pFun )(int n, string str))
    {
        cout<<"some body knows the answer,i will ask him"<<endl;
        cout<<" ��Ա�������� "<<endl;
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
        cout<<" c++ 11  �������� 2"<<endl;
        functional = func;
    }

    void SetFun5(  std::function<void( int n,string str)>   func )
    {
        cout<<" c++ 11  �������� 3"<<endl;
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
