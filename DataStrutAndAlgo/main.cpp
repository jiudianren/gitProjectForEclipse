
/*
 * ubuntu 提示找不到 io.h头文件
 *  find /usr/include -name "io.h"
/usr/include/x86_64-linux-gnu/sys/io.h

access 的头文件是#include <unistd.h> 不是 io.h
/usr/include下没有，但是在/usr/include/sys下有，我把io.h复制到了/usr/include下，就行了

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

	//排序算法
	mainMergSort();
	mainQuickSort();
	mainHeapSort();

	//topk
	mainTopK();
	//
// test 数据结构
	mainListTEST();
//循环队列
	 CircularQueueTest();

//动态规划
	 mainDynmaicPlan();
	 mainBeiBao();
	return 1;
}
