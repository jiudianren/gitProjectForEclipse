/*
 *
 *  Created on: 2017年12月19日
 *      Author: lian.pengfei
 */



#include <stdio.h>

#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include  <iostream>

#include "Master.h"

using namespace std;
/*

（十）Master-Worker模式


master-worker模式是一种并行计算模式，
分为master进程和worker进程两个部分，
master是担任总管角色，worker才是执行具体任务的地方。


    Master 掌控有 多个worker 线程 ，
 *  https://www.cnblogs.com/code-java/p/6901439.html
 * */
int main(void)
{
    printf("MasterWork Model start ==========.\n");

    Master master ( 4, 5);

    int taskNumer=100;
    for( int i=0 ;i <taskNumer;i++)
    {
        Task task;
        task.setId(i);

        string sStr="task_";
        sStr +=i ;

        task.setName(sStr);
        task.setPrice(i);

        master.submit( task);
    }


    master.execute();

    int iSleepTime = 0;
    while( ! master.isComplete() )
    {

        cout<<"sleep time:"<< iSleepTime++ <<endl;
        sleep( 5);
    }
    master.getResult();


    //释放资源
    master.getResult();

    master.releaseResult();
    printf("MasterWork Model end ==========.\n");
    return 0;
}
