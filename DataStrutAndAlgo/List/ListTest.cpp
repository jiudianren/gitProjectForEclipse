
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
