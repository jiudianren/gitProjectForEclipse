/*
 * ModeState.h
 *
 *  Created on: 2017��7��8��
 *      Author: Lian
 */

#ifndef SRC_MODESTATE_H_
#define SRC_MODESTATE_H_

/*
 * http://www.cnblogs.com/wanggary/archive/2011/04/21/2024117.html
 *
 *CLiftState������״̬������

CCloseingState�������Źر�

COpenningState�������Ŵ�

CRunningState����������

CStoppingState������ֹͣ

CContext�����ݵĿ������



5. ģʽ�ܽ�

����5.1 �ŵ�

��������5.1.1 ״̬ģʽ�����ض�״̬��ص���Ϊ�ֲ��������ҽ���ͬ״̬����Ϊ�ָ����

��������5.1.2 ����״̬��صĴ��붼������ĳ��ConcereteState�У�����ͨ�������µ���������׵������µ�״̬��ת����

��������5.1.3 ״̬ģʽͨ���Ѹ���״̬ת���߼��ֲ���State������֮�䣬�������໥���������

����5.2 ȱ��

��������5.2.1 ���½϶��ConcreteState����

����5.3 ���ó���

��������5.3.1 ��һ���������Ϊȡ��������״̬������������������ʱ�̸���״̬�ı�������Ϊʱ���Ϳ��Կ���ʹ��״̬ģʽ����

��������5.3.2 һ�������к����Ӵ�ķ�֧�ṹ��������Щ��֧�����ڶ����״̬��



 *
 * */

#include <iostream>

using namespace std;

//#define  CLOSED  0
//#define  OPEN   1
//#define  RUNING 2
//#define  STOP  3



enum LiftStat
{
	CLOSED  = 0,
	OPEN    = 1,
	RUNING  = 2,
	STOP    = 3,
};

typedef enum LiftStat  STATE;
class OldLift
{
public :
	OldLift(){ m_state = CLOSED;};
	~OldLift(){};
public:
	void setStat(STATE stat){m_state= stat; };
	void Open();
	void Close();
	void Run();
	void Stop();
private:
	STATE m_state;
	void OprOpen(){cout << "�����ſ���..." << endl;};
	void OprClose(){cout << "�����Źر�..." << endl;};
	void OprRun(){cout << "������������..." << endl;};
	void OprStop(){cout << "������ͣ��..." << endl;};


};

class NewLift;
class IStat
{
public:
	IStat(): mNewLift(NULL){};
	virtual ~IStat(){};

	virtual void open()=0;
	virtual void close()=0;
	virtual void run()=0;
	virtual void stop()=0;
	void setLift(NewLift * nl){
		mNewLift= nl;
	};

protected:
	NewLift * mNewLift;

};



class OpenStat:public IStat
{

public:
	OpenStat(){};
	~OpenStat(){};
	void open();
	void close();
	void run();
	void stop();
};

class CloseStat:public IStat
{

public:
	CloseStat(){};
	~CloseStat(){};

	void open();
	void close();
	void run();
	void stop();
};

class RunStat:public IStat
{

public:
	RunStat(){};
	~RunStat(){};
	void open();
	void close();
	void run();
	void stop();

};

class StopStat:public IStat
{

public:
	StopStat(){};
	~StopStat(){};
	void open();
	void close();
	void run();
	void stop();
};


class NewLift
{

public:
	NewLift();

	~ NewLift();

	void setStat(IStat * stat)
	{
		mStat = stat;
		mStat->setLift(this);
	};
	IStat * getStat(){ return mStat;};
	void open();
	void close();
	void run();
	void stop();

	static OpenStat *mOpenStat;
	static CloseStat * mCloseStat;
	static RunStat  * mRunStat;
	static StopStat * mStopStat;
private:
	IStat * mStat;

};

void TestOldStat();
void TestNewStat();
void mainTestStatMod();
#endif /* SRC_MODESTATE_H_ */
