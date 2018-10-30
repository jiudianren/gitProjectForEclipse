/*
 * ReversList.cpp
 *
 *  Created on: 2018Äê9ÔÂ28ÈÕ
 *      Author: Administrator
 */


#include "ReversList.h"
#include <iostream>
using namespace std;

MList * ReversList( MList * head)
{
    if(head == NULL)
    {
        return head;
    }

    MList * curNode = head;
    MList  * preNode = NULL;

    while( curNode != NULL)
    {
        MList * pNext  = curNode->pNext;
        curNode->pNext = preNode;
        preNode = curNode;
        curNode = pNext;
    }

    return preNode;
}



void TestReverlist() {

    cout<<"TestReverlist===============start"<<endl;
    MList  * frist =  new MList ;
    frist->pNext= NULL;
    frist->iM = 100;

    for(int i= 0 ; i<5 ;i++ )
    {
        InsertList( frist ,i);
    }
    MList  * temp = frist;
    while( temp != NULL)
    {
        cout<< temp->iM <<endl;
        temp=temp->pNext;
    }

    cout<<" ===============1"<<endl;

    MList * reversHead = ReversList( frist);
    while(reversHead != NULL)
    {
        cout<< reversHead->iM<<endl;
        reversHead = reversHead->pNext;
    }


    DestoryList( frist );
    cout<<"TestReverlist===============end"<<endl;
}
