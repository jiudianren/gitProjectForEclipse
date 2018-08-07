/*
 * skiplist.cpp
 *
 *  Created on: 2017��4��10��
 *      Author: Administrator
 */




#include<stdio.h>
#include<stdlib.h>
#include "skiplist.h"
#define MAX_LEVEL1 10 //������
typedef int KeyType;
typedef int ValType;
 struct node
{
	KeyType key;
	ValType value;
//	struct node * forward;
	   struct node *forward[1];
	//ע�������ߵ�����
};
//����
typedef  struct sList
{
	int level;
	node *header;
}sList;


//�����ڵ�
node * creatNode1(int level,KeyType key,ValType vl)
{
	node * pn=(node *)malloc(sizeof(node)+level*sizeof(node *));
	pn->key=key;
	pn->value=vl;
	return pn;
}

//��ʼ������
sList * creatSList()
{

	sList * sl=(sList *) malloc(sizeof(sList));
	//��ʼlevelΪ0;
	sl->level=0;
	sl->header=creatNode1(MAX_LEVEL1,0,0);

	//��������׽ڵ��forwardȫ��ָ��NIL
	for(int i=0;i<MAX_LEVEL1;i++)
	{
		sl->header->forward[i]=NULL;
	}
	return sl;
}

//�����������
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

	//����һ��node���飬��¼��ÿһ���У���Ҫ����ڵ��ǰһ���ڵ�
	node * bInsert[MAX_LEVEL1];
	//��ʼ���ҵĽڵ�
	node * startNode =sl->header;

	int curLevle=sl->level;
	//�ҵ�Ҫ�����λ��
	printf("sl->level:%d \n",sl->level);
	for(int i = curLevle-1; i >= 0; i--)
	{
		//ͬһ������,����i��
		node * nextNode;
		while( ( nextNode= startNode->forward[i]) && nextNode->key <  key)
		{
			startNode=nextNode;
		}
		//���nextnodeΪnull˵������Ҫ����һ�㣬����ѭ����
		//���nextnode��key>key,����Ҫ����һ�㣬���Ų��ң�����һ��ĵ�ǰλ�ú��棬����û��С��key��node
		//ֱ�����ҵ���ײ����Ϊֹ
		//ÿһ��Ľ�Ҫ�����λ�õ�ǰһ���ڵ�
		bInsert[i]=startNode;
		//ע�����ﲻ�� bInsert=startNode
		printf("i:%d ",i);
	}

	printf("\n ");
	//���һ��ѭ�����϶������һ��
	//���key�Ѿ����ڣ����ܲ���
	if( (startNode->forward[0]= NULL) && startNode->forward[0]->key == key )
	{
		rFlag = false;
	}

	//�����������
	int newLevle = randomLevel1();
	printf("newLevle:%d ,key:%d ,value:%d,sl-level:%d\n ",newLevle,key,vl,sl->level);

	if(curLevle < newLevle)
	{
		//����ԭ���Ĳ�����û���µĲ����࣬���ڶ������Щ�������佫Ҫ����Ľڵ��ǰһ���ڵ㣬ָ�����׽ڵ�
		for(int i=curLevle;i<newLevle;i++)
		{
			bInsert[i]=sl->header;
			printf("anthor i:%d ",i);
		}
		sl->level=newLevle;
	}
	node * insertNode=creatNode1(newLevle,key,vl);

    // ��㽻����Ҫ����ڵ��ǰһ���ڵ��forward��ָ��ͽ�Ҫ����Ľڵ��forwardָ��
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
    //����߲㿪ʼ��ӡ
    node * startNode,* nextNode=NULL;

    //����߲㿪ʼ��
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
