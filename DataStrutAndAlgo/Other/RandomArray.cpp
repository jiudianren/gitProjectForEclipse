/*
 * RandomArray.cpp
 *
 *  Created on: 2019年3月18日
 *      Author: lian.pengfei
 */




//如何将一个数组随机打乱

/*
题目是如何将一个数据随机打乱：
方案一：
直观能想到一种算法是循环遍历数组，每一次产生一个随机的小标数，将这个下标所在的位置移出去，然后将这个值存到另外一个新的数组里，直到最后还有一个元素为止。这样的随机取出来的数组成的数组是随机。
改算法伪代码：
看出来方案一的时间复杂度是O(N^2) ，辅助空间N;
*/


void method1(vector<int> a)
{
    int j=0;
    int size = a.size();
    for(int i=0;i < size ;i++)
        auto index = rand() % size - 1;
        b[j++]=a[index];
        for(k=index;k < size-1;k++)
            a[k]=a[k+1];
        size--;

}


/*
方案二：
Fisher and Yates’ 提出了时间复杂度O(N)，辅助空间1，的随机打乱算法具体算法伪代码如下：
*/

void method2()
{
    for(i=n-1;i>=0;i--)
        index= rand(i+1)%i+1  //generate random index 0<=index<=i
        if(i != index)
            exchange(i,index)
}
