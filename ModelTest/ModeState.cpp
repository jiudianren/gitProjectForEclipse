/*
 * ModeState.cpp
 *
 *  Created on: 2017��7��8��
 *      Author: Lian
 */


#include "ModeState.h"


/*
 *
 * http://www.cnblogs.com/wanggary/archive/2011/04/21/2024117.html
 * */
void OldLift::Open()
{

	switch(this->m_state)
	{
	case CLOSED:
		OprOpen();
		setStat(OPEN);
		break;
	default:
		cout<<"Stat Erro "<<endl;
	}
}
void OldLift::Close()
{
	switch(this->m_state)
	{
	case OPEN:
		OprClose();
		setStat(CLOSED);
		break;
	case RUNING:
		OprRun();
		setStat(RUNING);
		break;
	default:
		cout<<"Stat Erro "<<endl;
	}
}


void OldLift::Run()
{
	switch(this->m_state)
	{
	case CLOSED:
		OprRun();
		setStat(RUNING);
		break;
	default:
		cout<<"Stat Erro "<<endl;
	}
}


void OldLift::Stop()
{
	switch(this->m_state)
	{
	case RUNING:
		OprStop();
		setStat(STOP);
		break;
	default:
		cout<<"Stat Erro "<<endl;
	}
}

void OpenStat::open()
{
	cout << "�����ſ���..." << endl;
}
void OpenStat::close()
{
	this->IStat::mNewLift->setStat(NewLift::mCloseStat);
	this->IStat::mNewLift->getStat()->close();
}


void OpenStat::run()
{
	cout<<"Stat Erro "<<endl;
}

void OpenStat::stop()
{
	cout<<"Stat Erro "<<endl;
}


void CloseStat::open()
{
	this->IStat::mNewLift->setStat(NewLift::mOpenStat);
	this->IStat::mNewLift->getStat()->open();

}

void CloseStat::close()
{
	cout << "�����Źر�..." << endl;
}


void CloseStat::run()
{

	this->IStat::mNewLift->setStat(NewLift::mRunStat);
	this->IStat::mNewLift->getStat()->run();
}

void CloseStat::stop()
{

	this->IStat::mNewLift->setStat(NewLift::mStopStat);
	this->IStat::mNewLift->getStat()->stop();
}

void RunStat::open()
{
	cout<<"Stat Erro "<<endl;
}
void RunStat::close()
{
	cout<<"Stat Erro "<<endl;
}


void RunStat::run()
{
	cout<<"������������ "<<endl;
}

void RunStat::stop()
{

	this->IStat::mNewLift->setStat(NewLift::mStopStat);
	this->IStat::mNewLift->getStat()->stop();
}

void StopStat::open()
{

	this->IStat::mNewLift->setStat(NewLift::mOpenStat);
	this->IStat::mNewLift->getStat()->open();

}

void StopStat::close()
{
	this->IStat::mNewLift->setStat(NewLift::mCloseStat);
	this->IStat::mNewLift->getStat()->close();
}

void StopStat::run()
{
	this->IStat::mNewLift->setStat(NewLift::mRunStat);
	this->IStat::mNewLift->getStat()->run();
}


void StopStat::stop()
{
	cout<<"���� ֹͣ���� "<<endl;
}


OpenStat *  NewLift::mOpenStat = NULL;
StopStat * NewLift::mStopStat = NULL;
RunStat * NewLift::mRunStat = NULL;
CloseStat * NewLift::mCloseStat =NULL;

NewLift::NewLift()
{
	mStat =NULL;
	mOpenStat =new OpenStat();
	mCloseStat =new CloseStat();
	mRunStat =new RunStat();
	mStopStat =new  StopStat();

}

NewLift::~NewLift()
{
	if(mOpenStat!=NULL)
	{
		delete mOpenStat;
	}
	if(mCloseStat!=NULL)
	{
		delete mCloseStat;
	}
	if(mStopStat!=NULL)
	{
		delete mStopStat;
	}
	if(mRunStat!=NULL)
	{
		delete mRunStat;
	}

}

void NewLift::open()
{
	this->getStat()->open();
}

void NewLift::stop()
{
	this->getStat()->stop();
}

void NewLift::run()
{
	this->getStat()->run();
}

void NewLift::close()
{
	this->getStat()->close();
}



void TestOldStat()
{

	OldLift oldlift;
	oldlift.setStat(CLOSED);
	oldlift.Open();
	oldlift.Close();
	oldlift.Run();
	oldlift.Stop();

}



void TestNewStat()
{

  NewLift newlift;
  newlift.setStat(NewLift::mStopStat);
  newlift.open();
  newlift.close();
  newlift.run();
  newlift.stop();
}

void mainTestStatMod()
{

	TestOldStat();
	cout<<"---======----"<<endl;
	TestNewStat();

}
