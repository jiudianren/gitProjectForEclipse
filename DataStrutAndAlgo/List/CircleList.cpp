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

bool CheckCircleList( const MListNode * pFirst)
{
    bool bRet = false;
    if( pFirst ==NULL && pFirst->pNext == NULL)
    {
        return bRet;
    }

    MListNode * aftertmp = pFirst;
    MListNode * tmp = pFirst->pNext;
    while ( tmp != NULL)
    {

        for( MListNode * pInner = pFirst; pInner != aftertmp;pInner =pInner->pNext )
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

bool HasCircle( const MListNode * pHead)
{
    if( pHead == nullptr )
    {
        return false;
    }

    MListNode * pFast = pHead; // 快指针每次前进两步
    MListNode * pSlow = pHead; // 慢指针每次前进一步
    while(pFast != NULL && pFast->pNext != NULL)
    {
        pFast = pFast->pNext->pNext;
        pSlow = pSlow->pNext;
        if(pSlow == pFast) // 相遇，存在环
            return true;
    }
    return false;
}


/* 求 circleList的相交点  ，环的长度 和 前面直线的长度
 *
           n6---------n5
           |           |
    n1--- n2---n3--- n4|

    我们仍然可以使用两个指针fast和slow，fast走两步，slow走一步，判断是否有环，
当有环重合之后，譬如上面在n5重合了，那么如何得到n2呢？
首先我们知道，fast每次比slow多走一步，
所以重合的时候，fast移动的距离是slot
的两倍，我们假设n1到n2距离为a，
n2到n5距离为b，n5到n2距离为c，fast走动距
离为 a + b + c + b ，而slow为 a + b ，
有方程 a + b + c + b = 2 x (a +
b) ，可以知道 a = c ，
所以我们只需要在重合之后，一个指针从n1，而另一个
指针从n5，都每次走一步，那么就可以在n2重合了。
 */


MListNode *detectCycle(MListNode *head) {
    if(head == NULL || head->pNext == NULL) {
        return NULL;
    }
    MListNode* fast = head;
    MListNode* slow = head;
    while(fast->pNext != NULL && fast->pNext->pNext !=
            NULL) {
        fast = fast->pNext->pNext;
        slow = slow->pNext;
        if(fast == slow) {
            slow = head;
            while(slow != fast) {
                fast = fast->pNext;
                slow = slow->pNext;
            }
            return slow;
        }
    }

    return NULL;
}
