/*
 * CircularQueue.cpp
 *
 *  Created on: 2017年11月9日
 *      Author: Administrator
 */

#include "CircularQueue.h"
#include <stdio.h>
#include <string.h>

/*lpf
 * 这里 ，每次只是插入，删除一个，
 * 可以优化，
 * 如果开头和结尾 有没有跨越 0 这个位置，如果tai< head则锁定，跨越了，这时候，可以用 每次删除一个的函数
 * 如果 tail> head ,则说明和正常队列无异，可以一次去除若干过，（小于当前个数）
 *
 * */


//初始化循环队列
void InitQue(PT_QUEUE ptQue)
{
    memset(ptQue, 0, sizeof(*ptQue));
}

//向循环队列中插入元素
void EnterQue(PT_QUEUE ptQue, int dwElem)
{
    if(IsQueFull(ptQue))
    {
        printf("Elem %d cannot enter Queue %p(Full)!\n", dwElem, ptQue);
        return;
    }
    ptQue->aData[ptQue->dwTail]= dwElem;
    //lpf it is important
    ptQue->dwTail = (ptQue->dwTail + 1) % QUEUE_SIZE;
}

//从循环队列中取出元素
int LeaveQue(PT_QUEUE ptQue)
{
    if(IsQueEmpty(ptQue))
    {
        printf("Queue %p is Empty!\n", ptQue);
        return -1;
    }
    int dwElem = ptQue->aData[ptQue->dwHead];
    ptQue->dwHead = (ptQue->dwHead + 1) % QUEUE_SIZE;
    return dwElem;
}

//从队首至队尾依次显示队中元素值
void DisplayQue(PT_QUEUE ptQue)
{
    if(IsQueEmpty(ptQue))
    {
        printf("Queue %p is Empty!\n", ptQue);
        return;
    }

    printf("Queue Element: ");
    int dwIdx = ptQue->dwHead;
    while((dwIdx % QUEUE_SIZE) != ptQue->dwTail)
        printf("%d ", ptQue->aData[(dwIdx++) % QUEUE_SIZE]);

    printf("\n");
}




//判断循环队列是否为空
int IsQueEmpty(PT_QUEUE ptQue)
{
    return ptQue->dwHead == ptQue->dwTail;
}

//判断循环队列是否为满
int IsQueFull(PT_QUEUE ptQue)
{
    return (ptQue->dwTail + 1) % QUEUE_SIZE == ptQue->dwHead;
}

//获取循环队列元素数目
int QueDataNum(PT_QUEUE ptQue)
{
    return (ptQue->dwTail - ptQue->dwHead + QUEUE_SIZE) % QUEUE_SIZE;
}

//获取循环队列队首位置
int GetQueHead(PT_QUEUE ptQue)
{
    return ptQue->dwHead;
}
//获取循环队列队首元素
int GetQueHeadData(PT_QUEUE ptQue)
{
    return ptQue->aData[ptQue->dwHead];
}
//获取循环队列队尾位置
int GetQueTail(PT_QUEUE ptQue)
{
    return ptQue->dwTail;
}




static T_QUEUE gtQueue;
void CircularQueueTest(void)
{
    printf("CircularQueueTest start ==========.\n");
    InitQue(&gtQueue);
    printf("Enter Queue 1,2,3,4,5...\n");
    EnterQue(&gtQueue, 1);
    EnterQue(&gtQueue, 2);
    EnterQue(&gtQueue, 3);
    EnterQue(&gtQueue, 4);
    EnterQue(&gtQueue, 5);
    printf("Queue Status: Empty(%d), Full(%d)\n", IsQueEmpty(&gtQueue), IsQueFull(&gtQueue));
    printf("Queue Elem Num: %u\n", QueDataNum(&gtQueue));
    printf("Head: %u(%d)\n", GetQueHead(&gtQueue), GetQueHeadData(&gtQueue));
    printf("Tail: %u\n", GetQueTail(&gtQueue));
    DisplayQue(&gtQueue);

    printf("\nLeave Queue...\n");
    printf("Leave %d\n", LeaveQue(&gtQueue));
    printf("Leave %d\n", LeaveQue(&gtQueue));
    printf("Leave %d\n", LeaveQue(&gtQueue));
    DisplayQue(&gtQueue);

    printf("\nEnter Queue 6,7...\n");
    EnterQue(&gtQueue, 6);
    EnterQue(&gtQueue, 7);
    DisplayQue(&gtQueue);

    printf("\nLeave Queue...\n");
    printf("Leave %d\n", LeaveQue(&gtQueue));
    printf("Leave %d\n", LeaveQue(&gtQueue));
    printf("Leave %d\n", LeaveQue(&gtQueue));
    DisplayQue(&gtQueue);

    printf("CircularQueueTest end==========.\n");
}
