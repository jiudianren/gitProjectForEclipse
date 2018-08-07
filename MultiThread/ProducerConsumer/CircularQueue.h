/*
 * CircularQueue.h
 *
 *  Created on: 2017��11��9��
 *      Author: Administrator
 */

#ifndef DATASTRUTANDALGO_CIRCULARQUEUE_H_
#define DATASTRUTANDALGO_CIRCULARQUEUE_H_


//ѭ������

#define QUEUE_SIZE   50 //�����������QUEUE_SIZE-1��Ԫ��

typedef struct{
    int aData[QUEUE_SIZE];  //����Ԫ��
    int dwHead;  //ָ�����Ԫ��
    int dwTail;  //ָ���βԪ�ص���һ��Ԫ��
}T_QUEUE, *PT_QUEUE;

//��������

//��ʼ��ѭ������
void InitQue(PT_QUEUE ptQue);

//��ѭ�������в���Ԫ��
void EnterQue(PT_QUEUE ptQue, int dwElem);

//��ѭ��������ȡ��Ԫ��
int LeaveQue(PT_QUEUE ptQue);

//�Ӷ�������β������ʾ����Ԫ��ֵ
void DisplayQue(PT_QUEUE ptQue);


//��������
//�ж�ѭ�������Ƿ�Ϊ��
int IsQueEmpty(PT_QUEUE ptQue);
//�ж�ѭ�������Ƿ�Ϊ��
int IsQueFull(PT_QUEUE ptQue);

//��ȡѭ������Ԫ����Ŀ
int QueDataNum(PT_QUEUE ptQue);

//��ȡѭ�����ж���λ��
int GetQueHead(PT_QUEUE ptQue);

//��ȡѭ�����ж���Ԫ��
int GetQueHeadData(PT_QUEUE ptQue);

//��ȡѭ�����ж�βλ��
int GetQueTail(PT_QUEUE ptQue);


void CircularQueueTest(void);
#endif /* DATASTRUTANDALGO_CIRCULARQUEUE_H_ */
