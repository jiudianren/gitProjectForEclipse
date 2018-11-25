#include "List.h"


MListNode *  InsertList( MListNode * head, int value)
{
    MListNode *  node  = new MListNode;
    node->iM = value;
    node->pNext = head->pNext;
    head->pNext = node;
    return head;
}
void DestoryList( MListNode * head)
{
    if( head == NULL)
    {
        return ;
    }

    while( head->pNext != NULL)
    {
        MListNode * deleteNode = head->pNext;
        head->pNext = deleteNode->pNext;
        delete deleteNode;
    }

    delete head;
}
