
/*
 * ubuntu ��ʾ�Ҳ��� io.hͷ�ļ�
 *  find /usr/include -name "io.h"
/usr/include/x86_64-linux-gnu/sys/io.h

access ��ͷ�ļ���#include <unistd.h> ���� io.h
/usr/include��û�У�������/usr/include/sys���У��Ұ�io.h���Ƶ���/usr/include�£�������

  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <string>
#include <iostream>


#include "ListTest.h"
#include "skiplist.h"
#include "MergerSort.h"
#include "HeapSort.h"
#include "QuickSort.h"
#include "TOP_K_BFPRT.h"
#include "CircularQueue.h"
#include "DynamicPlanning.h"
#include "Dynamic_beibao.h"

using namespace std;
int main( int argc, char **argv)
{

	cout<<"main"<<endl;

	//�����㷨
	mainMergSort();
	mainQuickSort();
	mainHeapSort();

	//topk
	mainTopK();
	//
// test ���ݽṹ
	mainListTEST();
//ѭ������
	 CircularQueueTest();

//��̬�滮
	 mainDynmaicPlan();
	 mainBeiBao();
	return 1;
}
