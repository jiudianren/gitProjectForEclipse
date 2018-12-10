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
 * ˼·�����һ�����������л�����һ��ָ��ȥ��������Զ���������
 * ���Կ���������ָ�룬һ��ָ��һ����һ��
��һ��ָ��һ����������������ڻ�����������ָ����ڻ���������
ʱ�临�Ӷ�ΪO(n)*/

bool HasCircle( const MListNode * pHead)
{
    if( pHead == nullptr )
    {
        return false;
    }

    MListNode * pFast = pHead; // ��ָ��ÿ��ǰ������
    MListNode * pSlow = pHead; // ��ָ��ÿ��ǰ��һ��
    while(pFast != NULL && pFast->pNext != NULL)
    {
        pFast = pFast->pNext->pNext;
        pSlow = pSlow->pNext;
        if(pSlow == pFast) // ���������ڻ�
            return true;
    }
    return false;
}


/* �� circleList���ཻ��  �����ĳ��� �� ǰ��ֱ�ߵĳ���
 *
           n6---------n5
           |           |
    n1--- n2---n3--- n4|

    ������Ȼ����ʹ������ָ��fast��slow��fast��������slow��һ�����ж��Ƿ��л���
���л��غ�֮��Ʃ��������n5�غ��ˣ���ô��εõ�n2�أ�
��������֪����fastÿ�α�slow����һ����
�����غϵ�ʱ��fast�ƶ��ľ�����slot
�����������Ǽ���n1��n2����Ϊa��
n2��n5����Ϊb��n5��n2����Ϊc��fast�߶���
��Ϊ a + b + c + b ����slowΪ a + b ��
�з��� a + b + c + b = 2 x (a +
b) ������֪�� a = c ��
��������ֻ��Ҫ���غ�֮��һ��ָ���n1������һ��
ָ���n5����ÿ����һ������ô�Ϳ�����n2�غ��ˡ�
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
