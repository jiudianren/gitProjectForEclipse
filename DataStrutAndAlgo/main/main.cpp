
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <string>
#include <iostream>

#include "../Skiplist/skiplist.h"

#include "ListTest.h"
#include "../List/ReversList.h"
#include "MergerSort.h"
#include "HeapSort.h"
#include "QuickSort.h"
#include "TOP_K_BFPRT.h"
#include "CircularQueue.h"
#include "DynamicPlanning.h"
#include "Dynamic_beibao.h"
#include "MyStack.h"


using namespace std;
int main( int argc, char **argv)
{

	cout<<"main"<<endl;

	TestReverlist();

	TestMyStack();

	//排序算法
	mainMergSort();
//	mainQuickSort();
//	mainHeapSort();
//
//	//topk
//	mainTopK();
//	//
//// test 数据结构
//	mainListTEST();
////循环队列
//	 CircularQueueTest();
//
////动态规划
//	 mainDynmaicPlan();
//	 mainBeiBao();
	return 1;
}
