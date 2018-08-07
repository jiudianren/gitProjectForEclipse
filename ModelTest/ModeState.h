/*
 * ModeState.h
 *
 *  Created on: 2017年7月8日
 *      Author: Lian
 */

#ifndef SRC_MODESTATE_H_
#define SRC_MODESTATE_H_

/*
 * http://www.cnblogs.com/wanggary/archive/2011/04/21/2024117.html
 *
 *CLiftState，电梯状态抽象类

CCloseingState，电梯门关闭

COpenningState，电梯门打开

CRunningState，电梯运行

CStoppingState，电梯停止

CContext，电梯的控制面板



5. 模式总结

　　5.1 优点

　　　　5.1.1 状态模式将与特定状态相关的行为局部化，并且将不同状态的行为分割开来。

　　　　5.1.2 所有状态相关的代码都存在于某个ConcereteState中，所以通过定义新的子类很容易地增加新的状态和转换。

　　　　5.1.3 状态模式通过把各种状态转移逻辑分不到State的子类之间，来减少相互间的依赖。

　　5.2 缺点

　　　　5.2.1 导致较多的ConcreteState子类

　　5.3 适用场景

　　　　5.3.1 当一个对象的行为取决于它的状态，并且它必须在运行时刻根据状态改变它的行为时，就可以考虑使用状态模式来。

　　　　5.3.2 一个操作中含有庞大的分支结构，并且这些分支决定于对象的状态。



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
	void OprOpen(){cout << "电梯门开启..." << endl;};
	void OprClose(){cout << "电梯门关闭..." << endl;};
	void OprRun(){cout << "电梯门运行中..." << endl;};
	void OprStop(){cout << "电梯门停了..." << endl;};


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
