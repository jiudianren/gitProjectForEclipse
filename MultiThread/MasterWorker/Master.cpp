/*
 * Master.cpp
 *
 *  Created on: 2017年12月20日
 *      Author: Administrator
 */

#include <map>
#include <stdio.h>
#include <iostream>
#include "Master.h"
#include "Work.h"
#include "Task.h"
using namespace std;

Master:: Master( int WorkType, int iWorkNumber)
{
    //WorkType 暂时不用
    MUTEX = PTHREAD_MUTEX_INITIALIZER;

    for(int i= iWorkNumber; i>0; i--)
    {
        Work work;
        work.SetResultMap( &this->mapResult);
        work.SetTaskList( & this->listTask);
        work.SetMutex( &MUTEX);

        string workName="Work_";
        workName += i;

        work.SetWorkName( workName);

        //cout<< taskName<<std::endl;
        this->mapWork.insert( std::pair<string, Work>(workName, work));
    }
}

void Master::submit(Task task)
{
    this->listTask.push_back(task);

}


void Master::getResult()
{
    for (auto ref : mapResult)
    {
        if( ref->bDone == true)
        {
            cout<<"result is "<< ref->iResult <<endl;
        }
    }
}

void Master::releaseResult()
{
    for (auto ref : mapResult)
    {
        delete ( ref);
    }
}
bool Master::isComplete()
{
    bool bRet = true;

    if( mapResult.size() == 0)
    {
        bRet= false;
        return bRet;
    }

    for (auto ref : mapResult)
    {
        if( ref->bDone == false)
        {
            bRet =false;
            break;
        }
    }
    return bRet ;
}

void Master::execute()
{
    std::map<string, Work>::iterator iter;
    for(iter=mapWork.begin(); iter!=mapWork.end(); iter++)
    {
        cout<<"Master::execute: "<< iter->first<<" going to start"<<std::endl;
        Work * work = &(iter->second);
        work->Run();
    }

}
