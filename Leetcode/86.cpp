/*
 * 86.cpp
 *
 *  Created on: 2018年8月2日
 *      Author: Administrator
 *
 *      86. 分隔链表
 */


struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

/**
 * Definition for singly-linked list.
;
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        int vale =0;
        ListNode *  curNode = GetXNode(  head ,x );
        if( findLess( curNode ,x,vale))
        {

        }
    }
    ListNode * GetXNode( ListNode* head ,int x)
    {
        ListNode *  curNode =NULL;
        curNode = head;
        while( curNode != NULL)
        {
            if(curNode->val != x)
            {
                curNode = curNode->next;
            }
        }
        return curNode;
    }

    bool findLess( ListNode* head , int x, int & vale )
    {
        ListNode* next =  head->next;
        if( next == NULL)
            return false;

        if( next->val < x )
        {
            vale = next->val;
            head->next = next->next;
            next->next = NULL;
            delete  next;
            return true;
        }
        else
        {
            head =  next;
            next =head->next;
        }

    }

    void insert( ListNode* head , int & vale)
    {
        ListNode * preNode =NULL;
        ListNode * curNode = head;
        if( vale <  curNode->val )
        {

        }
    }

};
