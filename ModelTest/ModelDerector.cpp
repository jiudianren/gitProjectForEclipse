#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
#include "ModelDerector.h"
using namespace std;
//����������
class Phone
{
public:
    Phone() {}
    virtual ~Phone() {}
    virtual void ShowDecorate() {}
};

//Ӧ�ý�calling   �������
//������ֻ���
class iPhone : public Phone
{
private:
    string m_name; //�ֻ�����
public:
    iPhone(string name): m_name(name){}
    //��������
    void  calling() { cout<<"call iphone"<<endl; }
    ~iPhone() {}
    void ShowDecorate() { cout<<m_name<<"��װ��"<<endl;}
};


//������ֻ���
class NokiaPhone : public Phone
{
private:
    string m_name;
public:
    string aa;
    NokiaPhone(string name): m_name(name),aa(name){}

    void calling() { cout<<"call nokia"<<endl; }
    ~NokiaPhone() {}
    void ShowDecorate() { cout<<m_name<<"��װ��"<<endl;}
};



//װ����  �����ʱ����Ҫ����һ��phone
class DecoratorPhone : public Phone
{
private:
    Phone *m_phone;  //Ҫװ�ε��ֻ�
public:
    DecoratorPhone(Phone *phone): m_phone(phone) {}
    virtual void ShowDecorate() { m_phone->ShowDecorate(); }
};
//�����װ����
class DecoratorPhoneA : public DecoratorPhone
{
public:
    DecoratorPhoneA(Phone *phone) : DecoratorPhone(phone) {}
    void ShowDecorate() { DecoratorPhone::ShowDecorate(); AddDecorate(); }
private:
    void AddDecorate() { cout<<"���ӹҼ�"<<endl; } //���ӵ�װ��
};
//�����װ����
class DecoratorPhoneB : public DecoratorPhone
{
public:
    DecoratorPhoneB(Phone *phone) : DecoratorPhone(phone) {}
    void ShowDecorate() { DecoratorPhone::ShowDecorate(); AddDecorate(); }
    void calling() { cout<<" lalala :  call nokia"<<endl; }
private:
    void AddDecorate() { cout<<"��Ļ��Ĥ"<<endl; } //���ӵ�װ��
};


void  mainDerector()
{
    Phone *iphone = new NokiaPhone("6300");
    Phone *dpa = new DecoratorPhoneA(iphone); //װ�Σ����ӹҼ�
    Phone *dpb = new DecoratorPhoneB(dpa);    //װ�Σ���Ļ��Ĥ
    dpb->ShowDecorate();
    //װ���Ժ�ͨ��ǿ��ת������Ӱ�� NokiaPhone�е�callling�������ʹ�ã�����Ҫǿ��ת��һ��
   ((DecoratorPhoneB *) dpb)->calling();
   //���delete �е����� Ӧ������b��a�� iphone
    delete dpa;
    delete dpb;
    delete iphone;
}



