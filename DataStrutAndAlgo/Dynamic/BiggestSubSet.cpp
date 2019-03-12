/*
 * BiggestSubSet.cpp
 *
 *  Created on: 2019��3��10��
 *      Author: Administrator
 */


/*https://www.cnblogs.com/allzy/p/5162815.html*/


/*
 *
 * һ�����������е�Ԫ�������и����ڸ��������ҳ�һ �����������飬
 * Ҫ��������������и�Ԫ�صĺ����
 * �������������㱻����������������顣
 * ��������{2,4,-7,5,2,-1,2,-4,3}���������������Ϊ{5,2,-1,2}��
 * �������������ĺ�Ϊ5+2-1+2=8��
 * �����������һ�����飬���������ġ���������������͡���

˼·����
������������������������ֲ�ͬʱ�临�Ӷȵ��㷨��
����ģ����Ȼ�������ģ���Ӧ�ö�̬�滮˼�룬
���Եõ�һ��O(N)���������ʱ���㷨�������Ļ�������΢���Σ�
���Եõ�һ����������ʽ��
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
        /*����ۼӺͳ���С��0�������
           ������������п϶������ܰ���ǰ���Ԫ�أ�
           ��ʱ���ۼӺ���0�����¸�Ԫ�����¿�ʼ�ۼ�  */
        else if(ThisSum< 0)
            ThisSum= 0;
    }
    return MaxSum;
}

