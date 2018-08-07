/*
 * ModelCommand.h
 *
 *  Created on: 2017年7月9日
 *      Author: Lian
 */

#ifndef SRC_MODELTEST_MODELCOMMAND_H_
#define SRC_MODELTEST_MODELCOMMAND_H_

#include <iostream>
#include <vector>
using namespace std;


/*
 *
 * http://www.cnblogs.com/lizhanwu/p/4435359.html
 *
 * Command：声明执行操作的接口；
ConcreteCommand：将一个接收者对象绑定于一个动作，之后，调用接收者相应的操作，以实现Execute来完成相应的命令；
Client：创建一个具体命令对象，但是并没有设定它的接收者；
Invoker：要求该命令执行这个请求；
Receiver：知道如何实施与执行一个请求相关的操作，任何类都可能作为一个接收者。

以上这些对象是按照下面的方式进行协作的：

1.Client创建一个ConcreteCommand命令对象，并指定它的Receiver对象；
2.Invoker对象存储该ConcreteCommand对象；
3.该Invoker通过调用Command对象的Execute操作来提交一个请求。如果这个命令请求是可以撤销的，ConcreteCommand就执行Execute操作之前存储当前状态以用于取消该命令请求；
4.ConcreteCommand对象调用Receiver的一些操作以执行该请求。
 * */

/*烤肉师傅*/
class Barbecuer
{

public:
	void BakeMutton(){
		cout<<"bake mutton"<<endl;
	}
	void BakeWing()
	{
		cout<<"bake wing"<<endl;
	}

};



/* 命令要关联到起执行者*/
class Command
{
public:
	Command():ba(NULL){};
	Command(Barbecuer * ba){this->ba =ba;};
	virtual ~Command(){}
	virtual void Execute() =0;
	Barbecuer * GetCooker(){
		return ba;
	}

private:
	Barbecuer * ba;
};


/* 烤羊肉
 *
 * 烤羊肉 ，可以安排两个师傅
 * 烤的时候，要看师傅有没有空
 *
 * */
class BMuttonComm:public Command
{
public :
	BMuttonComm(){};
	BMuttonComm(Barbecuer * ba):Command(ba){};
	~ BMuttonComm(){};
	void Execute(){
		GetCooker()->BakeMutton();
	};

};

/*烤翅*/
class BWingComm:public Command
{
public :
	BWingComm(){};
	BWingComm(Barbecuer *ba ):Command(ba){};
	void Execute(){
		GetCooker()->BakeWing();
	};
};



class Waiter
{
public:
	void SetOrder(Command * cm){ m_vecComm.push_back(cm);};

	void Notify()
	{
		for(auto i =m_vecComm.begin();i!= m_vecComm.end();)
		{
			(*i)->Execute();
			i=m_vecComm.erase(i);
		}
	}
private:
	vector<Command * > m_vecComm;

};



void mainModelComm();
#endif /* SRC_MODELTEST_MODELCOMMAND_H_ */
