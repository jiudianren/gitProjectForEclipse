/*
 * BiggestSubSet.cpp
 *
 *  Created on: 2019年3月10日
 *      Author: Administrator
 */


/*https://www.cnblogs.com/allzy/p/5162815.html*/


/*
 *
 * 一个整数数组中的元素有正有负，在该数组中找出一 个连续子数组，
 * 要求该连续子数组中各元素的和最大，
 * 这个连续子数组便被称作最大连续子数组。
 * 比如数组{2,4,-7,5,2,-1,2,-4,3}的最大连续子数组为{5,2,-1,2}，
 * 最大连续子数组的和为5+2-1+2=8。
 * 问题输入就是一个数组，输出该数组的“连续子数组的最大和”。

思路分析
　　这个问题我所见的有四种不同时间复杂度的算法。
暴力模拟显然是最慢的，而应用动态规划思想，
可以得到一个O(N)级别的线性时间算法，再它的基础上稍微变形，
可以得到一个更简洁的形式。
 *
 * */

int MaxSubsequenceSum1(const int A[],int N)
{
    int ThisSum=0 ,MaxSum=0,i,j,k;
    for(i=0;i<N;i++)
        for(j=i;j<N;j++)
        {
            ThisSum=0;
            for(k=i;k<=j;k++)
                ThisSum+=A[k];

            if(ThisSum>MaxSum)
                MaxSum=ThisSum;
        }
        return MaxSum;
}



int MaxSubsequenceSum2(const int A[],int N)
{
    int ThisSum=0,MaxSum=0,i,j,k;
    for(i=0;i<N;i++)
    {
        ThisSum=0;
        for(j=i;j<N;j++)
        {
            ThisSum+=A[j];
            if(ThisSum>MaxSum)
                MaxSum=ThisSum;
        }
    }
    return MaxSum;
}



int MaxSubSum(int arr[],int len)
{
    int i;
    int MaxSum = 0;
    int ThisSum= 0;
    for(i=0;i<len;i++)
    {
        ThisSum+= arr[i];
        if(ThisSum > MaxSum)
            MaxSum = ThisSum;
        /*如果累加和出现小于0的情况，
           则和最大的子序列肯定不可能包含前面的元素，
           这时将累加和置0，从下个元素重新开始累加  */
        else if(ThisSum< 0)
            ThisSum= 0;
    }
    return MaxSum;
}

