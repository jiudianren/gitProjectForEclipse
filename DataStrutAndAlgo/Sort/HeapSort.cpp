/*
 * HeapSort.cpp
 *
 *  Created on: 2017年11月1日
 *      Author: Administrator
 */


#include <iostream>
#include "HeapSort.h"
/**
 * 堆排序：C++
 *
 * 算法之堆排序（最大堆c++实现）
 *
 *
 * https://blog.csdn.net/lyl771857509/article/details/78853448
 *
 * 算法之堆排序（最大堆c++实现）
 *
 */

#include <iostream>
using namespace std;

/*
 * (最大)堆的向下调整算法
 *
 * 注：数组实现的堆中，第N个节点的左孩子的索引值是(2N+1)，右孩子的索引是(2N+2)。
 *     其中，N为数组下标索引值，如数组中第1个数对应的N为0。
 *
 * 参数说明：
 *     a -- 待排序的数组
 *     start -- 被下调节点的起始位置(一般为0，表示从第1个开始)
 *     end   -- 截至范围(一般为数组中最后一个元素的索引)
 */
void maxHeapDown(int* a, int start, int end)
{
	int c = start;            // 当前(current)节点的位置
	int l = 2*c + 1;        // 左(left)孩子的位置
	int tmp = a[c];            // 当前(current)节点的大小
	for (; l <= end; c=l,l=2*l+1)  //继续循环
	{
		// "l"是左孩子，"l+1"是右孩子
		if ( l < end && a[l] < a[l+1])
			l++;        // 左右两孩子中选择较大者，即m_heap[l+1]

		if (tmp >= a[l])
			break;        // 调整结束
		else            // 交换值
		{
			a[c] = a[l];
			a[l]= tmp;
		}
	}
}

/*
 * 堆排序(从小到大)
 *
 * 参数说明：
 *     a -- 待排序的数组
 *     n -- 数组的长度
 */
void heapSortAsc(int* a, int length)
{
	int i,tmp;

	// 从(n/2-1) --> 0逐次遍历。遍历之后，得到的数组实际上是一个(最大)二叉堆。
	for (i = length / 2 - 1; i >= 0; i--)
		maxHeapDown(a, i, length -1);  //需要调整  length / 2 - 1

	// 从最后一个元素开始对序列进行调整，不断的缩小调整的范围直到第一个元素
	for (i = length - 1; i > 0; i--)
	{
		// 交换a[0]和a[i]。交换后，a[i]是a[0...i]中最大的。
		tmp = a[0];
		a[0] = a[i];
		a[i] = tmp;
		// 调整a[0...i-1]，使得a[0...i-1]仍然是一个最大堆。
		// 即，保证a[i-1]是a[0...i-1]中的最大值。
		maxHeapDown(a, 0, i-1);   //调整的时候，是从顶端 0开始调整的，调整一次就可以了
	}
}

/*
 * (最小)堆的向下调整算法
 *
 * 注：数组实现的堆中，第N个节点的左孩子的索引值是(2N+1)，右孩子的索引是(2N+2)。
 *     其中，N为数组下标索引值，如数组中第1个数对应的N为0。
 *
 * 参数说明：
 *     a -- 待排序的数组
 *     start -- 被下调节点的起始位置(一般为0，表示从第1个开始)
 *     end   -- 截至范围(一般为数组中最后一个元素的索引)
 */
void minHeapDown(int* a, int start, int end)
{
	int c = start;            // 当前(current)节点的位置
	int l = 2*c + 1;        // 左(left)孩子的位置
	int tmp = a[c];            // 当前(current)节点的大小
	for (; l <= end; c=l,l=2*l+1)
	{
		// "l"是左孩子，"l+1"是右孩子  l < end 保证有右孩子
		if ( l < end && a[l] > a[l+1])
			l++;        // 左右两孩子中选择较小者
		if (tmp <= a[l])
			break;        // 调整结束
		else            // 交换值
		{
			a[c] = a[l];
			a[l]= tmp;
		}
	}
}

/*
 * 堆排序(从大到小)
 *
 * 参数说明：
 *     a -- 待排序的数组
 *     n -- 数组的长度
 */
void heapSortDesc(int* a, int length)
{
	int i,tmp;

	// 从(n/2-1) --> 0逐次遍历每。遍历之后，得到的数组实际上是一个最小堆。
	for (i = length / 2 - 1; i >= 0; i--)
		minHeapDown(a, i, length-1);

	// 从最后一个元素开始对序列进行调整，不断的缩小调整的范围直到第一个元素
	for (i = length - 1; i > 0; i--)
	{
		// 交换a[0]和a[i]。交换后，a[i]是a[0...i]中最小的。
		tmp = a[0];
		a[0] = a[i];
		a[i] = tmp;
		// 调整a[0...i-1]，使得a[0...i-1]仍然是一个最小堆。
		// 即，保证a[i-1]是a[0...i-1]中的最小值。
		minHeapDown(a, 0, i-1);
	}
}

void mainHeapSort()
{
	int i;
	int a[] = {20,30,90,40,70,110};
	int ilen = (sizeof(a)) / (sizeof(a[0]));

	cout << "before sort:";
	for (i=0; i<ilen; i++)
		cout << a[i] << " ";
	cout << endl;

	heapSortAsc(a, ilen);            // 升序排列
	//heapSortDesc(a, ilen);        // 降序排列

	cout << "after  sort:";
	for (i=0; i<ilen; i++)
		cout << a[i] << " ";
	cout << endl;
}



#include <iostream>
#include <algorithm>

using namespace std;
void HeapAdjust(int *a,int i,int size)  //调整堆
{
	int lchild= 2*i +1;       //i的左孩子节点序号
	int rchild= lchild+1;     //i的右孩子节点序号
	int max=i;            //临时变量
	if(i<=size/2)          //如果i是叶节点就不用进行调整
	{
		if( lchild<=size&&a[lchild]>a[max])
		{
			max=lchild;
		}
		if(rchild<=size&&a[rchild]>a[max])
		{
			max=rchild;
		}

		if(max!=i)
		{
			swap(a[i],a[max]);
			HeapAdjust(a,max,size);    //避免调整之后以max为父节点的子树不是堆
		}
	}
}

void BuildHeap(int *a,int size)    //建立堆
{
	for(int i=size/2 -1; i>=0 ; i--)    //非叶节点最大序号值为size/2
	{
		HeapAdjust(a,i,size);
	}
}

void HeapSort(int *a,int size)    //堆排序
{
	BuildHeap(a,size);
	for(int i=size-1; i>=0; i--)
	{
		swap(a[0],a[i]);           //交换堆顶和最后一个元素，即每次将剩余元素中的最大者放到最后面
		HeapAdjust(a,0,i-1);      //重新调整堆顶节点成为大顶堆
	}
}

int main(int argc, char *argv[])
{
	int a[100];
	int size;
	while(scanf("%d",&size)==1&&size>0)
	{
		int i;
		for(i=1;i<=size;i++)
			cin>>a[i];

		HeapSort(a,size);
		for(i=1;i<=size;i++)
			cout<<a[i]<<"";
	}
}



