#include <stdio.h>
#include "CircleList.h"
//��� ��������û�лػ�
/*
 * ����һ��
 * ��������������A->B->C->D->B->C->D�� ���������ڵ�D��ʱ��
 * ������Ҫ�Ƚϵ���֮ǰ�Ľڵ�A��B��C��
 * ��������ͬ�ڵ㡣��ʱ��Ҫ��������һ���½ڵ���B��
 * B֮ǰ�Ľڵ�A��B��C��D��ǡ��Ҳ����B�����B���������Σ��жϳ������л���
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
	if( pHead == nullptr || pHead->pNext != nullptr)
	{
		return false;
	}

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


/* �� circleList���ཻ��  �����ĳ��� �� ǰ��ֱ�ߵĳ���  */
