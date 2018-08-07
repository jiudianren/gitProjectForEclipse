/*
 * ProducerConsumer.cpp
 *
 *  Created on: 2017��12��19��
 *      Author: lianpengfei
 */



#include "CircularQueue.h"
#include <stdio.h>

#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
/*
 *�����ߣ�����������

 ���� ʹ�õ����������� ��
 ��
 *�����ߣ�����������
 * */


pthread_mutex_t MUTEX = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t CON_NOT_FULL  = PTHREAD_COND_INITIALIZER;
pthread_cond_t CON_NOT_EMPTY = PTHREAD_COND_INITIALIZER;

void * Producer( void * args)
{
    static T_QUEUE * pQueue = (T_QUEUE *) args;
    pthread_t tid = pthread_self();
    printf(" Producer Thread id [%u].\n " , (unsigned int) tid );

    while(1)
    {
        tid = pthread_self();

        pthread_mutex_lock( &MUTEX );
        if( IsQueFull( pQueue))
        {
            printf(" Thread %u is full ,waiting for consumer. \n" , (unsigned int)(tid) );
            pthread_cond_wait( &CON_NOT_FULL  , & MUTEX  );
            //�ͷ����󣬳����������������ȴ��ź� ���Ȼ���źź����»�ȡ��
            //�ȴ��������Ѷ�������
            sleep(2);
        }
        else
        {
            int iValue =1;
            //�ӿն��п�ʼ����ʱ��
            if( IsQueEmpty( pQueue) )
            {
                // ���� ÿ������һ��
                EnterQue( pQueue , iValue);
                printf("Thread %u --->Produce:%d . size is[%d] \n" ,(unsigned int)(tid) , iValue , QueDataNum(pQueue) );
                printf(" Thread %u produce one , notify Consumer:not Empty now.\n " , (unsigned int)(tid)  );
                pthread_cond_signal( &CON_NOT_EMPTY);
            }
            else
            {
                // ���� ÿ������һ��
                EnterQue( pQueue , iValue);
                printf("Thread %d --->Produce:%d . size is[%d] \n" ,(unsigned int)(tid) , iValue , QueDataNum(pQueue) );
            }
        }
        pthread_mutex_unlock( &MUTEX );
        sleep(1);
    }
    return ((void * ) 0);
}


void * Consumer( void * args)
{
    static T_QUEUE * pQueue = (T_QUEUE *) args;

    pthread_t tid = pthread_self();
    printf(" Consumer Thread id [%u].\n " , (unsigned int) tid );

    while(1)
    {
        tid = pthread_self();

        pthread_mutex_lock( &MUTEX );

        if( IsQueEmpty( pQueue) )
        {
            //�ȴ��������Ѷ�������
            printf(" Thread %u is empty ,waiting for producer. \n" , (unsigned int)(tid) );
            pthread_cond_wait( & CON_NOT_EMPTY  , & MUTEX  );

            //�ȴ��������Ѷ�������
            sleep(2);
        }
        else
        {
            if( IsQueFull( pQueue) )
            {
                int iValue = LeaveQue( pQueue );
                printf("Thread %u <--- Comsumer:%d . size is[%d] \n" ,(int)(tid), iValue , QueDataNum(pQueue));
                printf(" Thread %u consumer one , notify Producer:not Full now. \n" , (unsigned int)(tid) );
                //����һ�� ����֪ͨ����ǰ�����Ѿ�����
                pthread_cond_signal( &CON_NOT_FULL);
            }
            else
            {
                int iValue = LeaveQue( pQueue );
                printf("Thread %u <--- Comsumer:%d .size is[%d]  \n" ,(unsigned int)(tid) , iValue , QueDataNum(pQueue));

            }
        }
        pthread_mutex_unlock( &MUTEX );
        sleep(2);//����һ ��������ѭ��������
    }

    return ((void * ) 0);
}

int main(void)
{
    //����ѭ������
    static T_QUEUE gtQueue;
    printf("CircularQueueTest start ==========.\n");
    InitQue(&gtQueue);

    EnterQue( &gtQueue , 1);

    pthread_t pProduThread1, pProduThread2, pProduThread3;

    //����2�������� �߳�
    int ret = pthread_create( &pProduThread1, NULL, Producer, (void *) &gtQueue);
    if( ret !=0)
    {
        printf("pthread_create erro %d  \n",ret );
        exit(0);
    }
    sleep(1);
    ret = pthread_create( &pProduThread2, NULL, Producer, (void *) &gtQueue);
    if( ret !=0)
    {
        printf("pthread_create erro %d  \n",ret );
        exit(0);
    }
    sleep(1);

    //����2���������߳�
    pthread_t pConsumerThread1, pConsumerThread2;
    ret = pthread_create( &pConsumerThread1, NULL, Consumer, (void *) &gtQueue);
    if( ret !=0)
    {
        printf("pthread_create erro %d  \n",ret );
        exit(0);
    }
    sleep(1);
    ret = pthread_create( &pConsumerThread2, NULL, Consumer, (void *) &gtQueue);
    if( ret !=0)
    {
        printf("pthread_create erro %d  \n",ret );
        exit(0);
    }
    sleep(1);

//    pthread_join(pProduThread1 ,NULL);
//    pthread_join(pProduThread2,NULL);
//    pthread_join(pConsumerThread1,NULL);
//    pthread_join(pConsumerThread2,NULL);

    sleep(500);
    printf("CircularQueueTest end ==========.\n");
    return 0;
}
