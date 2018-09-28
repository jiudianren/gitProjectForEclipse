/*
 * skiplist.cpp
 *
 *  Created on: 2017��4��10��
 *      Author: lianpengfei
 */

#include "skiplist.h"

#include<stdio.h>
#include<stdlib.h>
#define MAX_LEVEL 10 //������


/* ����Ļ���ԭ��
 *
 * https://www.cnblogs.com/a8457013/p/8251967.html
 * */

//�����key-values��key�ܹ�����value���൱��hash���е�hashֵ

//�ڵ� ά������һ���ڵ��λ�ú͵�ǰ�ڵ��key��value
typedef  struct nodeStructure
{
	int key;
	int value;
	//lpf��������һ��ָ�룬������һ��ֻ����һ��Ԫ�ص�����
	struct nodeStructure *forward[1];
}nodeStructure;

//���� ����ṹ ά���˲���  ��ÿһ�� ��һ��Ԫ��
typedef  struct skiplist
{
	int level;
	nodeStructure *header;
}skiplist;

//�����ڵ�
nodeStructure* createNode(int level,int key,int value)
{
	//lpf  һ���ڵ㣬һ���ڵ㣬��һ��keyֵ����һ��value������Keyֵ�൱������ţ���value�൱�ڴ洢��ֵ
	//keyֵ�൱��Ҫ
	//ռ��һ�У�һ���У������ж�㣬��ÿһ�㣬�����и��Ե���һ���ڵ��ָ��
	nodeStructure *ns=(nodeStructure *)malloc(sizeof(nodeStructure)+level*sizeof(nodeStructure*));
	ns->key=key;
	ns->value=value;
	return ns;
}

//��ʼ������
skiplist* createSkiplist()
{
	skiplist *sl=(skiplist *)malloc(sizeof(skiplist));
	//lpf  ���ֻ��һ��
	sl->level=0;
	sl->header=createNode(MAX_LEVEL-1,0,0);

	//lpf һ���ոճ�ʼ���������ûһ��ĵ�forward��ָ���β����β��һ��Max_Level���NULLָ��
	for(int i=0;i<MAX_LEVEL;i++)
	{
		sl->header->forward[i]=NULL;
	}
	return sl;
}

//�����������
int randomLevel()
{
	int k=1;
	while (rand()%2)
		k++;
	k=(k<MAX_LEVEL)?k:MAX_LEVEL;
	return k;
}

//����ڵ�
bool insert(skiplist *sl,int key,int value)
{

	//��¼������Ҫָ�������Ľڵ�� �ڵ���Ϣ
	nodeStructure *beforeInsert[MAX_LEVEL];
	nodeStructure *p, *q = NULL;
	p=sl->header;
	int  iCurLevel=sl->level;
	//lpf ��Ҫ�ǽ������²���
	//����߲����²�����Ҫ�����λ��
	//���update
	printf("sl->level:%d \n",sl->level);
	for(int i= iCurLevel -1; i >= 0; i--){
		//p->forward[i]�����ڵ�ʱ�򣬱�ʾ�ò��Ѿ����ҵ��˽�β����
		while((q=p->forward[i]) && (q->key< key ) )
		{
			p=q;
		}
		//beforeInsertΪ��ǰ��Ҫ����λ�õ�ǰһ���ڵ�
		beforeInsert[i]=p;
		printf("i:%d ",i);
	}
	//��ײ㣬��q��key��ӽ�Ҫ�����key
	//���ܲ�����ͬ��key
	if(q&&q->key==key)
	{
		return false;
	}

	//����һ���������K
	//�½�һ��������ڵ�q
	//һ��һ�����
	int insertLevel=randomLevel();
	printf("the info of insert node: insertLevel:%d ,key:%d ,value:%d,sl-level:%d\n ",insertLevel,key,value,sl->level);
	//���������level
	/*lpf �����headerҲ��������Ľ�β������Ľ�β��������������һ��Ԫ��
	 * �Ե�����Ľڵ��level��������ĵ�ǰlevel��ʱ��
	 * �Ե�ǰ��Ҫ����ڵ��λ�õ�ǰһ��λ�õĳ���level�Ĳ��ָ�ֵΪ����Ľ�β
	 * */
	if( insertLevel >  iCurLevel )
	{
		for(int i=iCurLevel; i < insertLevel; i++){

			beforeInsert[i] = sl->header;
		}
		sl->level= insertLevel ;
	}

	q=createNode(insertLevel ,key,value);
	//�����½ڵ��ָ�룬����ͨ�б����һ��
	for(int i=0;i< insertLevel ;i++)
	{
		q->forward[i]=beforeInsert[i]->forward[i];
		beforeInsert[i]->forward[i]=q;
	}
	return true;
}

//����ָ��key��value
int search(skiplist *sl,int key)
{
	nodeStructure *p,*q=NULL;
	p=sl->header;
	//����߲㿪ʼ��
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

//ɾ��ָ����key
bool deleteSL(skiplist *sl,int key)
{

	//����ָ��Ҫɾ���Ľڵ�Ľڵ���Ϣ ������裬ͬinsert��һ�µ�
	nodeStructure *update[MAX_LEVEL];
	nodeStructure *p,*q=NULL;
	p=sl->header;
	//����߲㿪ʼ��
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
		//���ɾ��������ͨ�б�ɾ��һ��
		for(int i=0; i<sl->level; i++)
		{

			if(update[i]->forward[i]==q)
			{
				update[i]->forward[i]=q->forward[i];
			}
		}
		free(q);
		//���ɾ����������Ľڵ㣬��ô��Ҫ����ά�������
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
	//����߲㿪ʼ��ӡ
	nodeStructure *p,*q=NULL;

	//����߲㿪ʼ��
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
	//����
	int serchKey=4;
	int value=search(sl,serchKey);
	printf("value is %d of the key:%d \n", value, serchKey);
	//ɾ��
	bool b=deleteSL(sl,4);
	if(b)
		printf("ɾ���ɹ�\n");
	printSL(sl);
	system("pause");
	return 0;
}
