//============================================================================
// Name        : ����.cpp
// Author      : lian
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "ListTest.h"
using namespace std;


//��� ��������û�лػ�
/*
 * ����һ��
 * ��������������A->B->C->D->B->C->D�� ���������ڵ�D��ʱ��
 * ������Ҫ�Ƚϵ���֮ǰ�Ľڵ�A��B��C��
 * ��������ͬ�ڵ㡣��ʱ��Ҫ��������һ���½ڵ���B��
 * B֮ǰ�Ľڵ�A��B��C��D��ǡ��Ҳ����B�����B���������Σ��жϳ������л���
 * */

/*http://blog.jobbole.com/106227/
 * https://www.cnblogs.com/ghimtim/p/4882916.html
 * */
bool CheckCircleList(MList * pFirst)
{
	bool bRet = false;
	if( pFirst ==NULL && pFirst->pNext == NULL)
	{
		return bRet;
	}
	MList * aftertmp = pFirst;
	MList * tmp = pFirst->pNext;
	while ( tmp != NULL)
	{

		for( MList * pInner = pFirst; pInner != aftertmp;pInner =pInner->pNext )
		{
			if(pInner == tmp )
			{
				return true;
			}
		}
		aftertmp = tmp;
		tmp = tmp->pNext;
	}
	return bRet;
}

/*
 * ˼·�����һ�����������л�����һ��ָ��ȥ��������Զ���������
 * ���Կ���������ָ�룬һ��ָ��һ����һ��
��һ��ָ��һ����������������ڻ�����������ָ����ڻ���������
ʱ�临�Ӷ�ΪO(n)*/

bool HasCircle(MList * pHead)
{
	MList * pFast = pHead; // ��ָ��ÿ��ǰ������
	MList * pSlow = pHead; // ��ָ��ÿ��ǰ��һ��
    while(pFast != NULL && pFast->pNext != NULL)
    {
        pFast = pFast->pNext->pNext;
        pSlow = pSlow->pNext;
        if(pSlow == pFast) // ���������ڻ�
            return true;
    }
    return false;
}



void mainListTEST() {

	cout<<endl;
	cout<<"mainListTEST===============start"<<endl;
	MList frist;
	frist.pNext= NULL;
	int iA[5]={4,5,2,6,8};
	for(int i=0;i<5;i++ )
	{
		MList *  mem = new MList;
		mem->iM=iA[i];

		mem->pNext=frist.pNext;
		frist.pNext= mem;
	}
	MList temp=frist;
	while(temp.pNext != NULL)
	{
		cout<<temp.pNext->iM<<endl;
		temp=*temp.pNext;
	}

	cout<<"mainListTEST===============end"<<endl;
}
