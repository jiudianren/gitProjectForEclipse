/*
 * skiplist.cpp
 *
 *  Created on: 2017年4月10日
 *      Author: Administrator
 */




#include<stdio.h>
#include<stdlib.h>
#include "skiplist.h"
#define MAX_LEVEL1 10 //最大层数
typedef int KeyType;
typedef int ValType;
 struct node
{
	KeyType key;
	ValType value;
//	struct node * forward;
	   struct node *forward[1];
	//注意这两者的区别
};
//跳表
typedef  struct sList
{
	int level;
	node *header;
}sList;


//创建节点
node * creatNode1(int level,KeyType key,ValType vl)
{
	node * pn=(node *)malloc(sizeof(node)+level*sizeof(node *));
	pn->key=key;
	pn->value=vl;
	return pn;
}

//初始化跳表
sList * creatSList()
{

	sList * sl=(sList *) malloc(sizeof(sList));
	//初始level为0;
	sl->level=0;
	sl->header=creatNode1(MAX_LEVEL1,0,0);

	//将跳表的首节点的forward全部指向NIL
	for(int i=0;i<MAX_LEVEL1;i++)
	{
		sl->header->forward[i]=NULL;
	}
	return sl;
}

//随机产生层数
int randomLevel1()
{
	int k=1;
	while (rand()%2)
		k++;
	k=(k<MAX_LEVEL1)?k:MAX_LEVEL1;
	return k;
}
bool insert1(sList *sl,KeyType key,ValType vl)
{
	bool rFlag=true;

	//构造一个node数组，记录在每一层中，将要插入节点的前一个节点
	node * bInsert[MAX_LEVEL1];
	//开始查找的节点
	node * startNode =sl->header;

	int curLevle=sl->level;
	//找到要插入的位置
	printf("sl->level:%d \n",sl->level);
	for(int i = curLevle-1; i >= 0; i--)
	{
		//同一层间查找,就是i层
		node * nextNode;
		while( ( nextNode= startNode->forward[i]) && nextNode->key <  key)
		{
			startNode=nextNode;
		}
		//如果nextnode为null说明，需要向下一层，接着循环，
		//如果nextnode的key>key,则需要向下一层，接着查找，在下一层的当前位置后面，还有没有小于key的node
		//直到查找到最底层结束为止
		//每一层的将要插入的位置的前一个节点
		bInsert[i]=startNode;
		//注意这里不是 bInsert=startNode
		printf("i:%d ",i);
	}

	printf("\n ");
	//最后一次循环，肯定是最后一层
	//如果key已经存在，则不能插入
	if( (startNode->forward[0]= NULL) && startNode->forward[0]->key == key )
	{
		rFlag = false;
	}

	//随机产生层数
	int newLevle = randomLevel1();
	printf("newLevle:%d ,key:%d ,value:%d,sl-level:%d\n ",newLevle,key,vl,sl->level);

	if(curLevle < newLevle)
	{
		//由于原来的层数并没有新的层数多，对于多出的那些层数，其将要插入的节点的前一个节点，指向了首节点
		for(int i=curLevle;i<newLevle;i++)
		{
			bInsert[i]=sl->header;
			printf("anthor i:%d ",i);
		}
		sl->level=newLevle;
	}
	node * insertNode=creatNode1(newLevle,key,vl);

    // 逐层交换将要插入节点的前一个节点的forward的指针和将要插入的节点的forward指针
    for(int i=0;i<newLevle;i++)
    {
        insertNode->forward[i]=bInsert[i]->forward[i];
        bInsert[i]->forward[i]= insertNode;
    }

    printf("\n ");
	return rFlag;
}


void printSL1(sList *sl)
{
    //从最高层开始打印
    node * startNode,* nextNode=NULL;

    //从最高层开始搜
    int levels=sl->level;
    for(int i=levels; i >= 0; i--)
    {
        startNode=sl->header;
        while( nextNode = startNode->forward[i])
        {
//            printf("%d -> ",p->value);
        	printf("%d (key:%d,level:%d)->",startNode->value,startNode->key,i);
            startNode=nextNode;
        }
        printf("\n");
    }
    printf("\n");
}


int mainSkipList1()
{
	sList* sl=creatSList();
	for(int i=1;i<=19;i++)
	{
		insert1(sl,i,i*2);
	}
	printSL1(sl);

	return 0;
}
