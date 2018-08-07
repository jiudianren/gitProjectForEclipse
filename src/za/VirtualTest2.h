/*
 * VirtualTest2.h
 *
 *  Created on: 2017年6月12日
 *      Author: Administrator
 */

#ifndef VIRTUALTEST2_H_
#define VIRTUALTEST2_H_
#include <string>
#include <iostream>
using namespace std ;

class IIGx
{
public:
	//纯虚函数可以有默认实现
	virtual void FunGx() { std::cout<<"virtual void FunGx()"<<endl;};
};


class IISy
{
public:
	virtual void FunSy() = 0;
};


class TTGx : public IIGx
{
public:
	void FunGx()
	{
		std::cout<<"FunGx"<<endl;


		iOneTime ++;
		if(iOneTime == 1)
		{
			GetGx().FunGx();
		}

	};


private:
	int iOneTime =0 ;
	virtual  IIGx&   GetGx() const =0;
};


class TTSy : public  IISy
{
public:
	void FunSy()
	{
		std::cout<<"FunSy"<<endl;
		iOneTime ++;
		if(iOneTime == 1)
		{
			GetSy().FunSy();
		}
	};

private:
	int iOneTime =0 ;
	virtual  IISy&  GetSy() const =0;
};


class TTPoint : public  TTSy, public TTGx
{
public:


private :

	IIGx& GetGx() const
	{
		cout<<"TPoint::GetGx"<<endl;
		return const_cast<IIGx&>(static_cast<const IIGx &>(*this));
	};


	IISy& GetSy() const
	{
		cout<<"TPoint::GetSy"<<endl;
		return const_cast<IISy&>(static_cast<const IISy &>(*this));
	};
};


void mainVirtual2();

#endif /* VIRTUALTEST2_H_ */
