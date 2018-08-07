/*
 * virtualFuction.h
 *
 *  Created on: 2017年5月24日
 *      Author: Lian
 */

#ifndef VIRTUALFUCTION_H_
#define VIRTUALFUCTION_H_
#include <iostream>
#include <string>
using namespace std;

/*虚函数 调用虚函数的时候，虽然在父类中调用，但还是会向子类中 进行追溯  */


void mainVir();
class ViA
{

public:

	virtual void  funInner()
	{
		cout<<"via funinner"<<__func__<<endl;
	};
	virtual void funOut(){

		cout<<"via fucnOut "<<__func__<<std::endl;
		// 虚函数，需要在运行时，才能确定，也就是如果是子类的调用改该函数，那么将调用子类的函数实现
		funInner();
//		ViA()::funInner();
	};

	virtual ~ViA(){};
};



class ViASon:public ViA
{
public:

	virtual void funInner()
	{
		cout <<"Viason :: funInner"<<__func__<<endl;
	};

	virtual ~ViASon(){};
};

#endif /* VIRTUALFUCTION_H_ */
