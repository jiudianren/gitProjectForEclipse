/*
 * virtualFuction.h
 *
 *  Created on: 2017��5��24��
 *      Author: Lian
 */

#ifndef VIRTUALFUCTION_H_
#define VIRTUALFUCTION_H_
#include <iostream>
#include <string>
using namespace std;

/*�麯�� �����麯����ʱ����Ȼ�ڸ����е��ã������ǻ��������� ����׷��  */


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
		// �麯������Ҫ������ʱ������ȷ����Ҳ�������������ĵ��øĸú�������ô����������ĺ���ʵ��
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
