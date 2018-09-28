/*
 * BFPRT.h
 *
 *  Created on: 2017年10月30日
 *      Author: Administrator
 */

#ifndef SRC_DATASTRUTANDALGO_BFPRT_H_
#define SRC_DATASTRUTANDALGO_BFPRT_H_

/*
 *
http://blog.csdn.net/laojiu_/article/details/54986553

*/

int InsertSort(int  array[], int left, int right);                 //插入排序，返回中位数下标
int GetPivotIndex(int  array[], int left, int right);              //返回中位数的中位数下标
int Partition(int array[], int left, int right, int pivot_index);  //利用中位数的中位数的下标进行划分，返回分界线下标
int BFPRT(int array[], int left, int right, const int & k);        //求第k小，返回其位置的下标

int  mainTopK();
#endif /* SRC_DATASTRUTANDALGO_BFPRT_H_ */
