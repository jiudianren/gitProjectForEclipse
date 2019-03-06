
#include <iostream>
#include "ListTest.h"
using namespace std;

void TestList() {

	cout<<"InsertTest===============start"<<endl;
	MListNode  * frist =  new MListNode ;
	frist->pNext= NULL;
	int iA[5]={4,5,2,6,8};
	for(int i=0;i<5;i++ )
	{
	    InsertList( frist ,iA[i]);
	}
	MListNode  * temp = frist;
	while(temp->pNext != NULL)
	{
		cout<<temp->pNext->iM<<endl;
		temp=temp->pNext;
	}

	DestoryList(frist );
	cout<<"InsertTest===============end"<<endl;
}



MListNode * ReversList( MListNode * head)
{
    if(head == NULL)
    {
        return head;
    }

    MListNode * curNode = head;
    MListNode  * preNode = NULL;

    while( curNode != NULL)
    {
        MListNode * pNext  = curNode->pNext;
        curNode->pNext = preNode;
        preNode = curNode;
        curNode = pNext;
    }

    return preNode;
}


/*todo
 *
 * 一个链表中的倒数第k个节点
 * */
MListNode * LastKNode(const  MListNode * head, int n )
{
	MListNode * before = head;
	MListNode * ret = head;
	while( n >0 && before != nullptr)
	{
		before = before->pNext;
		n--;
	}
	if(before ==nullptr)
	{
		return nullptr;
	}

	while(before != nullptr)
	{
		before= before->pNext;
		ret= ret->pNext;
	}
	return ret;
}

void TestReverlist() {

    cout<<"TestReverlist===============start"<<endl;
    MListNode  * frist =  new MListNode ;
    frist->pNext= NULL;
    frist->iM = 100;

    for(int i= 0 ; i<5 ;i++ )
    {
        InsertList( frist ,i);
    }
    MListNode  * temp = frist;
    while( temp != NULL)
    {
        cout<< temp->iM <<endl;
        temp=temp->pNext;
    }

    cout<<" ===============1"<<endl;

    MListNode * reversHead = ReversList( frist);
    while(reversHead != NULL)
    {
        cout<< reversHead->iM<<endl;
        reversHead = reversHead->pNext;
    }


    DestoryList( frist );
    cout<<"TestReverlist===============end"<<endl;
}
