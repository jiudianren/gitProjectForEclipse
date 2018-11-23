#include <stdio.h>
#include "CircleList.h"
//检查 链表中有没有回环
/*
 * 方法一：
 * 例如这样的链表：A->B->C->D->B->C->D， 当遍历到节点D的时候，
 * 我们需要比较的是之前的节点A、B、C，
 * 不存在相同节点。这时候要遍历的下一个新节点是B，
 * B之前的节点A、B、C、D中恰好也存在B，因此B出现了两次，判断出链表有环。
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
 * 思路：如果一个单链表中有环，用一个指针去遍历，永远不会结束，
 * 所以可以用两个指针，一个指针一次走一步
另一个指针一次走两步，如果存在环，则这两个指针会在环内相遇，
时间复杂度为O(n)*/

bool HasCircle(MList * pHead)
{
	if( pHead == nullptr || pHead->pNext != nullptr)
	{
		return false;
	}

    MList * pFast = pHead; // 快指针每次前进两步
    MList * pSlow = pHead; // 慢指针每次前进一步
    while(pFast != NULL && pFast->pNext != NULL)
    {
        pFast = pFast->pNext->pNext;
        pSlow = pSlow->pNext;
        if(pSlow == pFast) // 相遇，存在环
            return true;
    }
    return false;
}


/* 求 circleList的相交点  ，环的长度 和 前面直线的长度  */
