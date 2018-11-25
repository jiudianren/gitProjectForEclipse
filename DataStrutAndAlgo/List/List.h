#ifndef DATASTRUTANDALGO_LIST_LIST_H_
#define DATASTRUTANDALGO_LIST_LIST_H_
#include <stdio.h>

class MListNode
{
public :
    int iM;
    MListNode * pNext;

    MListNode(){
        iM=0;
        pNext= nullptr;
    }
    ~MListNode()
    {
        iM=0;
        pNext= nullptr;
    };
};

MListNode *  InsertList( MListNode * head, int value);
void DestoryList( MListNode * head);


/*·´×ªÁ´±í*/
MListNode * ReversList( MListNode * head);
void TestReverlist();


#endif /* DATASTRUTANDALGO_LIST_LIST_H_ */
