/*
 * TOP_K_BFPRT.cpp
 *
 *  Created on: 2017年11月2日
 *      Author: Administrator
 */




/**
* BFPRT算法（前K小数问题）
*
* author    刘毅（Limer）
* date      2017-01-25
* mode      C++
*/

#include<iostream>
#include<algorithm>
#include "TOP_K_BFPRT.h"
using namespace std;

/*
int InsertSort(int  array[], int left, int right);                 //插入排序，返回中位数下标
int GetPivotIndex(int  array[], int left, int right);              //返回中位数的中位数下标
int Partition(int array[], int left, int right, int pivot_index);  //利用中位数的中位数的下标进行划分，返回分界线下标
int BFPRT(int array[], int left, int right, const int & k);        //求第k小，返回其位置的下标
*/

int  mainTopK()
{
    int k = 5;
    int array[] = { 1,1,2,3,1,5,-1,7,8,-10 ,6,8,40,15,16,0,20, -5};

    int length = sizeof(array)/sizeof(array[0]);
    cout << "mainTopK =========== start"<< std::endl;
    for (int i = 0; i < length; i++)
        cout << array[i] << " ";
    cout << endl;

    cout << "第" << k << "小值为：" << array[BFPRT(array, 0, length -1, k)] << endl;

    cout << "变换后的数组：";
    for (int i = 0; i < length; i++)
        cout << array[i] << " ";
    cout << endl;
    cout << "mainTopK ===========end："<<std::endl;
    cout << endl;
    return 0;
}

/* 插入排序，返回中位数下标 */
int InsertSort(int array[], int left, int right)
{
    int temp;
    int j;
    for (int i = left + 1; i <= right; i++)
    {
        temp = array[i];
        j = i - 1;
        while (j >= left && array[j] > temp)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
    return ((right - left) >> 1) + left;
}



int InsertSortLPF(int array[], int left, int right)
{

    for(int  index = left+1 ; index <=right; index ++)
    {
        for(int i = index-1;  i>= left && array[i] > array[i+1]; i--  )
        {
            swap(  array [i+1],  array [i]);
        }
    }

    return ((right - left) >> 1) + left;
}


/* 返回中位数的中位数下标 */
int GetPivotIndex(int array[], int left, int right)
{
    if (right - left < 5)
        return InsertSortLPF(array, left, right);

    int sub_right = left - 1;
    for (int i = left; i + 4 <= right; i += 5)
    {
        int index = InsertSortLPF(array, i, i + 4);  //找到五个元素的中位数的下标
        swap(array[++sub_right], array[index]);   //依次放在左侧
    }

    return BFPRT(array, left, sub_right, ((sub_right - left + 1) >> 1) + 1);
}

/* 利用中位数的中位数的下标进行划分，返回分界线下标 */
int Partition(int array[], int left, int right, int pivot_index)
{
    swap(array[pivot_index], array[right]);  //把基准放置于末尾

    int divide_index = left;  //跟踪划分的分界线
    for (int i = left; i < right; i++)
    {
        if (array[i] < array[right])
            swap(array[divide_index++], array[i]);  //比基准小的都放在左侧
    }

    swap(array[divide_index], array[right]);  //最后把基准换回来
    return divide_index;
}

int BFPRT(int array[], int left, int right, const int & k)
{
    int pivot_index = GetPivotIndex(array, left, right);            //得到中位数的中位数下标
    int divide_index = Partition(array, left, right, pivot_index);  //进行划分，返回划分边界
    int num = divide_index - left + 1;
    if (num == k)
        return divide_index;
    else if (num > k)
        return BFPRT(array, left, divide_index - 1, k);
    else
        return BFPRT(array, divide_index + 1, right, k - num);
}
