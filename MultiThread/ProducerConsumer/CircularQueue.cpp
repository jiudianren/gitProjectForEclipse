/*
 * CircularQueue.cpp
 *
 *  Created on: 2017��11��9��
 *      Author: Administrator
 */

#include "CircularQueue.h"
#include <stdio.h>
#include <string.h>

/*lpf
 * ���� ��ÿ��ֻ�ǲ��룬ɾ��һ����
 * �����Ż���
 * �����ͷ�ͽ�β ��û�п�Խ 0 ���λ�ã����tai< head����������Խ�ˣ���ʱ�򣬿����� ÿ��ɾ��һ���ĺ���
 * ��� tail> head ,��˵���������������죬����һ��ȥ�����ɹ�����С�ڵ�ǰ������
 *
 * */


//��ʼ��ѭ������
void InitQue(PT_QUEUE ptQue)
{
    memset(ptQue, 0, sizeof(*ptQue));
}

//��ѭ�������в���Ԫ��
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

//��ѭ��������ȡ��Ԫ��
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

//�Ӷ�������β������ʾ����Ԫ��ֵ
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




//�ж�ѭ�������Ƿ�Ϊ��
int IsQueEmpty(PT_QUEUE ptQue)
{
    return ptQue->dwHead == ptQue->dwTail;
}

//�ж�ѭ�������Ƿ�Ϊ��
int IsQueFull(PT_QUEUE ptQue)
{
    return (ptQue->dwTail + 1) % QUEUE_SIZE == ptQue->dwHead;
}

//��ȡѭ������Ԫ����Ŀ
int QueDataNum(PT_QUEUE ptQue)
{
    return (ptQue->dwTail - ptQue->dwHead + QUEUE_SIZE) % QUEUE_SIZE;
}

//��ȡѭ�����ж���λ��
int GetQueHead(PT_QUEUE ptQue)
{
    return ptQue->dwHead;
}
//��ȡѭ�����ж���Ԫ��
int GetQueHeadData(PT_QUEUE ptQue)
{
    return ptQue->aData[ptQue->dwHead];
}
//��ȡѭ�����ж�βλ��
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
