/*
 * TypeInfo.cpp
 *
 *  Created on: 2017年7月6日
 *      Author: Administrator
 */




#include <iostream>
#include <typeinfo>
#include "TypeInfo.h"
using namespace std;

class Base {
public:
	virtual void f(){};
	virtual ~Base(){};

};
class Derived: public Base {
public:
    ~Derived(){};
};

void testTypeInfo1()
{

	Base b, *pb;
	pb = NULL;
	Derived d;


	cout << typeid(int).name() << endl
			<< typeid(unsigned).name() << endl
			<< typeid(long).name() << endl
			<< typeid(unsigned long).name() << endl
			<< typeid(char).name() << endl
			<< typeid(unsigned char).name() << endl
			<< typeid(float).name() << endl
			<< typeid(double).name() << endl
			<< typeid(string).name() << endl
			<< typeid(Base).name() << endl
			<< typeid(b).name()<<endl
			<< typeid(pb).name()<<endl
			<< typeid(Derived).name() << endl
			<< typeid(d).name()<<endl
			<< typeid(type_info).name() << endl;


	Base *pb2 = dynamic_cast<Base *>(new Derived);
	Base &b2 = d;
	Base *pb3 = &d;
	cout<<"========"<<endl;
	cout << typeid(pb2).name() <<endl//输出Base *
			<< typeid(b2).name()<<endl //输出Derived
			<< typeid(pb3).name()<<endl//输出Base *
			<< typeid(*pb3).name()<<endl;//输出Derived
}

void mainTypeInfo()
{

	cout<<"mainTypeInfo   ==================start"<<endl;
	testTypeInfo1();
	//
	cout<<"mainTypeInfo ==================end"<<endl;
}
