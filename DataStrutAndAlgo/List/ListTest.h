

#ifndef  _LIST_TEST_H_
#define  _LIST_TEST_H_
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


bool CheckCircleList();
bool HasCircle();
void mainListTEST();


#endif
