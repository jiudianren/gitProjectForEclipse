
#include <iostream>
#include "ListTest.h"
using namespace std;

void TestList() {

	cout<<"InsertTest===============start"<<endl;
	MList  * frist =  new MList ;
	frist->pNext= NULL;
	int iA[5]={4,5,2,6,8};
	for(int i=0;i<5;i++ )
	{
	    InsertList( frist ,iA[i]);
	}
	MList  * temp = frist;
	while(temp->pNext != NULL)
	{
		cout<<temp->pNext->iM<<endl;
		temp=temp->pNext;
	}

	DestoryList(frist );
	cout<<"InsertTest===============end"<<endl;
}



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
