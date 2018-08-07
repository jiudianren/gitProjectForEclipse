#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
#include "ModelDerector.h"
using namespace std;
//公共抽象类
class Phone
{
public:
    Phone() {}
    virtual ~Phone() {}
    virtual void ShowDecorate() {}
};

//应该将calling   抽象出来
//具体的手机类
class iPhone : public Phone
{
private:
    string m_name; //手机名称
public:
    iPhone(string name): m_name(name){}
    //新增方法
    void  calling() { cout<<"call iphone"<<endl; }
    ~iPhone() {}
    void ShowDecorate() { cout<<m_name<<"的装饰"<<endl;}
};


//具体的手机类
class NokiaPhone : public Phone
{
private:
    string m_name;
public:
    string aa;
    NokiaPhone(string name): m_name(name),aa(name){}

    void calling() { cout<<"call nokia"<<endl; }
    ~NokiaPhone() {}
    void ShowDecorate() { cout<<m_name<<"的装饰"<<endl;}
};



//装饰类  构造的时候需要传入一个phone
class DecoratorPhone : public Phone
{
private:
    Phone *m_phone;  //要装饰的手机
public:
    DecoratorPhone(Phone *phone): m_phone(phone) {}
    virtual void ShowDecorate() { m_phone->ShowDecorate(); }
};
//具体的装饰类
class DecoratorPhoneA : public DecoratorPhone
{
public:
    DecoratorPhoneA(Phone *phone) : DecoratorPhone(phone) {}
    void ShowDecorate() { DecoratorPhone::ShowDecorate(); AddDecorate(); }
private:
    void AddDecorate() { cout<<"增加挂件"<<endl; } //增加的装饰
};
//具体的装饰类
class DecoratorPhoneB : public DecoratorPhone
{
public:
    DecoratorPhoneB(Phone *phone) : DecoratorPhone(phone) {}
    void ShowDecorate() { DecoratorPhone::ShowDecorate(); AddDecorate(); }
    void calling() { cout<<" lalala :  call nokia"<<endl; }
private:
    void AddDecorate() { cout<<"屏幕贴膜"<<endl; } //增加的装饰
};


void  mainDerector()
{
    Phone *iphone = new NokiaPhone("6300");
    Phone *dpa = new DecoratorPhoneA(iphone); //装饰，增加挂件
    Phone *dpb = new DecoratorPhoneB(dpa);    //装饰，屏幕贴膜
    dpb->ShowDecorate();
    //装饰以后，通过强制转换并不影响 NokiaPhone中的callling的主题的使用，不过要强制转换一下
   ((DecoratorPhoneB *) dpb)->calling();
   //这个delete 有点问题 应该是先b后a后 iphone
    delete dpa;
    delete dpb;
    delete iphone;
}



