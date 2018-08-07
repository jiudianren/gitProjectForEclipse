/*
 * CircularQueue.h
 *
 *  Created on: 2017年11月9日
 *      Author: Administrator
 */

#ifndef DATASTRUTANDALGO_CIRCULARQUEUE_H_
#define DATASTRUTANDALGO_CIRCULARQUEUE_H_


//循环队列

#define QUEUE_SIZE   50 //队列最大容纳QUEUE_SIZE-1个元素

typedef struct{
    int aData[QUEUE_SIZE];  //队列元素
    int dwHead;  //指向队首元素
    int dwTail;  //指向队尾元素的下一个元素
}T_QUEUE, *PT_QUEUE;

//操作队列

//初始化循环队列
void InitQue(PT_QUEUE ptQue);

//向循环队列中插入元素
void EnterQue(PT_QUEUE ptQue, int dwElem);

//从循环队列中取出元素
int LeaveQue(PT_QUEUE ptQue);

//从队首至队尾依次显示队中元素值
void DisplayQue(PT_QUEUE ptQue);


//辅助函数
//判断循环队列是否为空
int IsQueEmpty(PT_QUEUE ptQue);
//判断循环队列是否为满
int IsQueFull(PT_QUEUE ptQue);

//获取循环队列元素数目
int QueDataNum(PT_QUEUE ptQue);

//获取循环队列队首位置
int GetQueHead(PT_QUEUE ptQue);

//获取循环队列队首元素
int GetQueHeadData(PT_QUEUE ptQue);

//获取循环队列队尾位置
int GetQueTail(PT_QUEUE ptQue);


void CircularQueueTest(void);
#endif /* DATASTRUTANDALGO_CIRCULARQUEUE_H_ */
