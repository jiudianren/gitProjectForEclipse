/*
 * skiplist.cpp
 *
 *  Created on: 2017年4月10日
 *      Author: lianpengfei
 */

#include "skiplist.h"

#include<stdio.h>
#include<stdlib.h>
#define MAX_LEVEL 10 //最大层数


/* 跳表的基本原理
 *
 * https://www.cnblogs.com/a8457013/p/8251967.html
 * */

//这里的key-values中key能够代表value，相当于hash表中的hash值

//节点 维护了下一个节点的位置和当前节点的key和value
typedef  struct nodeStructure
{
	int key;
	int value;
	//lpf：这里是一个指针，并不是一个只包含一个元素的数组
	struct nodeStructure *forward[1];
}nodeStructure;

//跳表 跳表结构 维护了层数  和每一层 第一个元素
typedef  struct skiplist
{
	int level;
	nodeStructure *header;
}skiplist;

//创建节点
nodeStructure* createNode(int level,int key,int value)
{
	//lpf  一个节点，一个节点，有一个key值，和一个value，其中Key值相当于列序号，而value相当于存储的值
	//key值相当重要
	//占用一列，一列中，可能有多层，但每一层，可能有各自的下一个节点的指向
	nodeStructure *ns=(nodeStructure *)malloc(sizeof(nodeStructure)+level*sizeof(nodeStructure*));
	ns->key=key;
	ns->value=value;
	return ns;
}

//初始化跳表
skiplist* createSkiplist()
{
	skiplist *sl=(skiplist *)malloc(sizeof(skiplist));
	//lpf  最初只有一层
	sl->level=0;
	sl->header=createNode(MAX_LEVEL-1,0,0);

	//lpf 一个刚刚初始化的跳表的没一层的的forward都指向结尾，结尾是一个Max_Level层的NULL指针
	for(int i=0;i<MAX_LEVEL;i++)
	{
		sl->header->forward[i]=NULL;
	}
	return sl;
}

//随机产生层数
int randomLevel()
{
	int k=1;
	while (rand()%2)
		k++;
	k=(k<MAX_LEVEL)?k:MAX_LEVEL;
	return k;
}

//插入节点
bool insert(skiplist *sl,int key,int value)
{

	//记录了所有要指向待插入的节点的 节点信息
	nodeStructure *beforeInsert[MAX_LEVEL];
	nodeStructure *p, *q = NULL;
	p=sl->header;
	int  iCurLevel=sl->level;
	//lpf 主要是阶梯向下查找
	//从最高层往下查找需要插入的位置
	//填充update
	printf("sl->level:%d \n",sl->level);
	for(int i= iCurLevel -1; i >= 0; i--){
		//p->forward[i]不存在的时候，表示该层已经查找到了结尾部分
		while((q=p->forward[i]) && (q->key< key ) )
		{
			p=q;
		}
		//beforeInsert为当前需要插入位置的前一个节点
		beforeInsert[i]=p;
		printf("i:%d ",i);
	}
	//最底层，的q的key最接近要插入的key
	//不能插入相同的key
	if(q&&q->key==key)
	{
		return false;
	}

	//产生一个随机层数K
	//新建一个待插入节点q
	//一层一层插入
	int insertLevel=randomLevel();
	printf("the info of insert node: insertLevel:%d ,key:%d ,value:%d,sl-level:%d\n ",insertLevel,key,value,sl->level);
	//更新跳表的level
	/*lpf 跳表的header也就是跳表的结尾，跳表的结尾并不是跳表的最后一个元素
	 * 对当插入的节点的level超过跳表的当前level的时候，
	 * 对当前需要插入节点的位置的前一个位置的超过level的部分赋值为跳表的结尾
	 * */
	if( insertLevel >  iCurLevel )
	{
		for(int i=iCurLevel; i < insertLevel; i++){

			beforeInsert[i] = sl->header;
		}
		sl->level= insertLevel ;
	}

	q=createNode(insertLevel ,key,value);
	//逐层更新节点的指针，和普通列表插入一样
	for(int i=0;i< insertLevel ;i++)
	{
		q->forward[i]=beforeInsert[i]->forward[i];
		beforeInsert[i]->forward[i]=q;
	}
	return true;
}

//搜索指定key的value
int search(skiplist *sl,int key)
{
	nodeStructure *p,*q=NULL;
	p=sl->header;
	//从最高层开始搜
	int k=sl->level;
	for(int i=k-1; i >= 0; i--){
		while((q=p->forward[i])&&(q->key<=key))
		{
			if(q->key == key)
			{
				return q->value;
			}
			p=q;
		}
	}
	return 0;
}

//删除指定的key
bool deleteSL(skiplist *sl,int key)
{

	//所有指向将要删除的节点的节点信息 这个步骤，同insert是一致的
	nodeStructure *update[MAX_LEVEL];
	nodeStructure *p,*q=NULL;
	p=sl->header;
	//从最高层开始搜
	int k=sl->level;
	for(int i=k-1; i >= 0; i--){
		while((q=p->forward[i])&&(q->key<key))
		{
			p=q;
		}
		update[i]=p;
	}

	if(q&&q->key==key)
	{
		//逐层删除，和普通列表删除一样
		for(int i=0; i<sl->level; i++)
		{

			if(update[i]->forward[i]==q)
			{
				update[i]->forward[i]=q->forward[i];
			}
		}
		free(q);
		//如果删除的是最大层的节点，那么需要重新维护跳表的
		for(int i=sl->level - 1; i >= 0; i--){

			if(sl->header->forward[i]==NULL)
			{
				sl->level--;
			}
		}
		return true;
	}
	else
	{
		return false;
	}

}

void printSL(skiplist *sl)
{
	printf("print the skiplist .\n");
	//从最高层开始打印
	nodeStructure *p,*q=NULL;

	//从最高层开始搜
	int k=sl->level;
	for(int i=k-1; i >= 0; i--)
	{
		p=sl->header;
		printf("%d (key:%d,level:%d)->",p->value,p->key,i);
		while( q= p->forward[i])
		{
			//            printf("%d -> ",p->value);
			printf("%d (key:%d,level:%d)->",q->value,q->key,i);
			p=q;
		}
		printf("\n");
	}
	printf("\n");
}

int mainSkipList()
{
	skiplist *sl=createSkiplist();
	for(int i=1;i<=10;i++)
	{
		insert(sl,i,i*2);
	}
	printSL(sl);
	//搜索
	int serchKey=4;
	int value=search(sl,serchKey);
	printf("value is %d of the key:%d \n", value, serchKey);
	//删除
	bool b=deleteSL(sl,4);
	if(b)
		printf("删除成功\n");
	printSL(sl);
	system("pause");
	return 0;
}
