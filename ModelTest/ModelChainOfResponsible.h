/*
 * ModelChainOfResponsible.h
 *
 *  Created on: 2017Äê7ÔÂ9ÈÕ
 *      Author: Lian
 */

#ifndef SRC_MODELTEST_MODELCHAINOFRESPONSIBLE_H_
#define SRC_MODELTEST_MODELCHAINOFRESPONSIBLE_H_
#include <iostream>
#include <string>
using namespace std;
class Ask
{
public:
	Ask(): sallary(0){};
	Ask(int a):sallary(a){};

	int GetSallary(){return sallary;};
private:
	int sallary;
};


class Manager
{
public:
	Manager(string name):name(name),topper(NULL){};
	virtual ~Manager(){};
	void SetTopper(Manager * top)
	{
		this->topper=top;
	};

	virtual void DealAsk(Ask * ask)=0;

	Manager*  GetTop(){ return topper;};
	string GetName(){return name;};
private:
	string name;
	Manager * topper;
};


class Top3Manger:public Manager
{
public:
	Top3Manger(string name):Manager(name){};
	void DealAsk(Ask * ask )
	{
		if( 0<ask->GetSallary()  && ask->GetSallary()<100 )
		{
			cout<<GetName()<<" has deal your ask, and your ask is :"<<ask->GetSallary()<<endl;
		}
		else
		{
			GetTop()->DealAsk(ask);
		}
	}

};


class Top2Manger:public Manager
{
public:

	Top2Manger(string name):Manager(name){};
	void DealAsk(Ask * ask )
	{
		if( 200<ask->GetSallary()  && ask->GetSallary()<300 )
		{
			cout<<GetName()<<" has deal your ask, and your ask is :"<<ask->GetSallary()<<endl;
		}
		else
		{
			cout<<GetName()<<": sorry ,i have to ask topper"<<endl;
			GetTop()->DealAsk(ask);
		}
	}

};

class Boss:public Manager
{
public:
	Boss(string name):Manager(name){};
	void DealAsk(Ask * ask )
	{
		if( 200<ask->GetSallary()  && ask->GetSallary()<500 )
		{
			cout<<GetName()<<" has deal your ask, and your ask is :"<<ask->GetSallary()<<endl;
		}
		else
		{
			cout<<GetName()<<" say: you ask too many! "<<endl;
		}
	};

};


	void mainChainOfRes();
#endif /* SRC_MODELTEST_MODELCHAINOFRESPONSIBLE_H_ */
