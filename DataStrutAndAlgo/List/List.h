#ifndef DATASTRUTANDALGO_LIST_LIST_H_
#define DATASTRUTANDALGO_LIST_LIST_H_
#include <stdio.h>

class MList
{
public :
    int iM;
    MList * pNext;
    ~MList()
    {
        iM=0;
        pNext=NULL;
    };
};

MList *  InsertList( MList * head, int value);
void DestoryList( MList * head);


#endif /* DATASTRUTANDALGO_LIST_LIST_H_ */
