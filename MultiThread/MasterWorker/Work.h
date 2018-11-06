/*
 * Work.h
 *
 *  Created on: 2017Äê12ÔÂ20ÈÕ
 *      Author: Administrator
 */

#ifndef MULTITHREAD_MASTERWORKER_WORK_H_
#define MULTITHREAD_MASTERWORKER_WORK_H_

#include <string>
#include <map>
#include <list>
#include <stdio.h>
#include "Task.h"

#include <memory>

typedef struct
{
bool bDone;
int iResult;
}  TResult;

#define RESULTMAP std::list<std::shared_ptr<TResult>>


class Work
{
public:
    virtual ~ Work(){};

    void SetTaskList( std::list<Task>   *listTask )
    {
        this->listTask = listTask;
    }

    void SetResultMap( RESULTMAP * mapResult)
    {
        this->mapResult = mapResult;
    }

    void Run();

    void SetMutex(   pthread_mutex_t * pMutex)
    {
        this->pMutex =pMutex;
    }

    void SetWorkName(string name )
    {
        this->sWorkName =name;
    }
    string GetWorkName()
    {
       return  this->sWorkName;
    }
    static void * ThreadFnc(void * args);
    virtual void  Handle( Task & task, std::shared_ptr<TResult > & result);


private:
    std::list<Task> * listTask;
    RESULTMAP  * mapResult;


    pthread_t  pThread ;
    pthread_mutex_t * pMutex;
    string sWorkName;
};




#endif /* MULTITHREAD_MASTERWORKER_WORK_H_ */
