/*
 * Master.h
 *
 *  Created on: 2017��12��20��
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
    //�����ύ����
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
    //work����
    std::map<string, Work> mapWork ;

    pthread_mutex_t MUTEX;
};



#endif /* MULTITHREAD_MASTERWORKER_MASTER_H_ */
