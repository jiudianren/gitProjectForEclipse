/*
 * shellsort.h
 *
 *  Created on: 2018年10月13日
 *      Author: Administrator
 */

#ifndef DATASTRUTANDALGO_SORT_SHELLSORT_H_
#define DATASTRUTANDALGO_SORT_SHELLSORT_H_



#include<stdio.h>
//    进行插入排序
//    初始时从dk开始增长，每次比较步长为dk

void ShellSort(int *a,int len)
{
	int i, j, h;
	int r, temp;
	int x = 0;
	for (r=len/2;r>=1;r/=2)//r>=1保证至少有两个可以比较的数，r/=2确定序列对
	{
		for (i=r;i<len;i++)//插入排序算法
		{
			temp = a[i];
			j = i - r;
			while (j>=0&&temp<a[j])//对配对的两个数进行比较
			{
				a[j + r] = a[j];
				j -= r;
			}
			a[j + r] = temp;
		}
		x++;
		printf("第%d步的排序结果：",x);
		for (h=0;h<len;h++)
		{
			printf("%d ",a[h]);
		}
		printf("\n");
	}
}


#endif /* DATASTRUTANDALGO_SORT_SHELLSORT_H_ */
