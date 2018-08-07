/*
 * ModelCommand.h
 *
 *  Created on: 2017��7��9��
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
 * Command������ִ�в����Ľӿڣ�
ConcreteCommand����һ�������߶������һ��������֮�󣬵��ý�������Ӧ�Ĳ�������ʵ��Execute�������Ӧ�����
Client������һ������������󣬵��ǲ�û���趨���Ľ����ߣ�
Invoker��Ҫ�������ִ���������
Receiver��֪�����ʵʩ��ִ��һ��������صĲ������κ��඼������Ϊһ�������ߡ�

������Щ�����ǰ�������ķ�ʽ����Э���ģ�

1.Client����һ��ConcreteCommand������󣬲�ָ������Receiver����
2.Invoker����洢��ConcreteCommand����
3.��Invokerͨ������Command�����Execute�������ύһ���������������������ǿ��Գ����ģ�ConcreteCommand��ִ��Execute����֮ǰ�洢��ǰ״̬������ȡ������������
4.ConcreteCommand�������Receiver��һЩ������ִ�и�����
 * */

/*����ʦ��*/
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



/* ����Ҫ��������ִ����*/
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


/* ������
 *
 * ������ �����԰�������ʦ��
 * ����ʱ��Ҫ��ʦ����û�п�
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

/*����*/
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
