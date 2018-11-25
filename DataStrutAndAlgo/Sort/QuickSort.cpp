/*
 * QuickSort.cpp
 *
 *  Created on: 2017年10月30日
 *      Author: Administrator
 */


/*快速排序
 *
 *快速排序首先选一个轴值(pivot，也有叫基准的)，将待排序记录划分成独立的两部分，左侧的元素均小于轴值，
 右侧的元素均大于或等于轴值，然后对这两部分再重复，直到整个序列有序

过程是和二叉搜索树相似，就是一个递归的过程
 * */
#include<iostream>
using namespace std;
void quickSort(int a[],int,int);
int mainQuickSort()
{
    int array[]={34,65,12,43,67,5,78,10,3,70},k;
    int len=sizeof(array)/sizeof(int);
    cout<<"The orginal arrayare:"<<endl;
    for(k=0;k<len;k++)
        cout<<array[k]<<",";
    cout<<endl;
    quickSort(array,0,len-1);
    cout<<"The sorted arrayare:"<<endl;
    for(k=0;k<len;k++)
        cout<<array[k]<<",";
    cout<<endl;
    return 0;
}

void quickSort( int s[], int l, int r)
{
    if (l < r)
    {
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j]>= x) // 从右向左找第一个小于x的数
                j--;

            if(i < j)
                s[i++] = s[j];


            while(i < j && s[i]< x) // 从左向右找第一个大于等于x的数
                i++;
            if(i < j)
                s[j--] = s[i];
        }

        s[i] = x;
        quickSort(s, l, i - 1); // 递归调用
        quickSort(s, i + 1, r);
    }
}
