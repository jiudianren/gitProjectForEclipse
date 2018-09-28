#include "List.h"


MList *  InsertList( MList * head, int value)
{
    MList *  node  = new MList;
    node->iM = value;
    node->pNext = head->pNext;
    head->pNext = node;
    return head;
}
void DestoryList( MList * head)
{
    if( head == NULL)
    {
        return ;
    }

    while( head->pNext != NULL)
    {
        MList * deleteNode = head->pNext;
        head->pNext = deleteNode->pNext;
        delete deleteNode;
    }

    delete head;
}
