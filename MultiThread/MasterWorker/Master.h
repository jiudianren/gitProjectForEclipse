/*
 * Master.h
 *
 *  Created on: 2017年12月20日
 *      Author: Administrator
 */

#ifndef MULTITHREAD_MASTERWORKER_MASTER_H_
#define MULTITHREAD_MASTERWORKER_MASTER_H_


#include "Task.h"
#include <string>
#include <map>
#include <list>
#include "Work.h"


class Master
{
public:
    Master( int WorkType, int iWorkNumber);
    //用于提交任务
     void submit(Task task);
     void releaseResult();
     void execute();
     bool isComplete();
     void getResult();
private :
    //tasklist
    std::list<Task> listTask;
    //threadid and result
    RESULTMAP mapResult;
    //work集合
    std::map<string, Work> mapWork ;

    pthread_mutex_t MUTEX;
};



#endif /* MULTITHREAD_MASTERWORKER_MASTER_H_ */
