/*
 * shellsort.h
 *
 *  Created on: 2018��10��13��
 *      Author: Administrator
 */

#ifndef DATASTRUTANDALGO_SORT_SHELLSORT_H_
#define DATASTRUTANDALGO_SORT_SHELLSORT_H_



#include<stdio.h>
//    ���в�������
//    ��ʼʱ��dk��ʼ������ÿ�αȽϲ���Ϊdk

void ShellSort(int *a,int len)
{
	int i, j, h;
	int r, temp;
	int x = 0;
	for (r=len/2;r>=1;r/=2)//r>=1��֤�������������ԱȽϵ�����r/=2ȷ�����ж�
	{
		for (i=r;i<len;i++)//���������㷨
		{
			temp = a[i];
			j = i - r;
			while (j>=0&&temp<a[j])//����Ե����������бȽ�
			{
				a[j + r] = a[j];
				j -= r;
			}
			a[j + r] = temp;
		}
		x++;
		printf("��%d������������",x);
		for (h=0;h<len;h++)
		{
			printf("%d ",a[h]);
		}
		printf("\n");
	}
}


#endif /* DATASTRUTANDALGO_SORT_SHELLSORT_H_ */
