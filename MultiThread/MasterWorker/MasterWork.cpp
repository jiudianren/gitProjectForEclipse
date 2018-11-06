/*
 *
 *  Created on: 2017��12��19��
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

��ʮ��Master-Workerģʽ


master-workerģʽ��һ�ֲ��м���ģʽ��
��Ϊmaster���̺�worker�����������֣�
master�ǵ����ܹܽ�ɫ��worker����ִ�о�������ĵط���


    Master �ƿ��� ���worker �߳� ��
 *  https://www.cnblogs.com/code-java/p/6901439.html
 * */


#define TASK_NUM 10
int main(void)
{
    printf("MasterWork Model start ==========.\n");

    Master master ( 4, 5);

    int taskNumer = TASK_NUM;
    for( int i=0 ;i <taskNumer;i++)
    {
        Task task;
        task.setId(i);

        string sStr="task_" + std::to_string(i);

        task.setName(sStr);
        task.setPrice(i);

        master.submit( task);
    }


    master.execute();

    int iSleepTime = 0;
    while( ! master.isComplete() )
    {
        cout<<"sleep time:"<< iSleepTime++ <<endl;
        sleep( 3);
    }
    master.getResult();


    //�ͷ���Դ
    master.releaseResult();
    printf("MasterWork Model end ==========.\n");
    return 0;
}
