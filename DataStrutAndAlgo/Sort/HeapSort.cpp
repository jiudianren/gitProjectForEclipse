/*
 * HeapSort.cpp
 *
 *  Created on: 2017��11��1��
 *      Author: Administrator
 */


#include <iostream>
#include "HeapSort.h"
/**
 * ������C++
 *
 * @author skywang
 * @date 2014/03/11
 */

#include <iostream>
using namespace std;

/*
 * (���)�ѵ����µ����㷨
 *
 * ע������ʵ�ֵĶ��У���N���ڵ�����ӵ�����ֵ��(2N+1)���Һ��ӵ�������(2N+2)��
 *     ���У�NΪ�����±�����ֵ���������е�1������Ӧ��NΪ0��
 *
 * ����˵����
 *     a -- �����������
 *     start -- ���µ��ڵ����ʼλ��(һ��Ϊ0����ʾ�ӵ�1����ʼ)
 *     end   -- ������Χ(һ��Ϊ���������һ��Ԫ�ص�����)
 */
void maxHeapDown(int* a, int start, int end)
{
    int c = start;            // ��ǰ(current)�ڵ��λ��
    int l = 2*c + 1;        // ��(left)���ӵ�λ��
    int tmp = a[c];            // ��ǰ(current)�ڵ�Ĵ�С
    for (; l <= end; c=l,l=2*l+1)  //����ѭ��
    {
        // "l"�����ӣ�"l+1"���Һ���
        if ( l < end && a[l] < a[l+1])
            l++;        // ������������ѡ��ϴ��ߣ���m_heap[l+1]

        if (tmp >= a[l])
            break;        // ��������
        else            // ����ֵ
        {
            a[c] = a[l];
            a[l]= tmp;
        }
    }
}

/*
 * ������(��С����)
 *
 * ����˵����
 *     a -- �����������
 *     n -- ����ĳ���
 */
void heapSortAsc(int* a, int length)
{
    int i,tmp;

    // ��(n/2-1) --> 0��α���������֮�󣬵õ�������ʵ������һ��(���)����ѡ�
    for (i = length / 2 - 1; i >= 0; i--)
        maxHeapDown(a, i, length -1);  //��Ҫ����  length / 2 - 1

    // �����һ��Ԫ�ؿ�ʼ�����н��е��������ϵ���С�����ķ�Χֱ����һ��Ԫ��
    for (i = length - 1; i > 0; i--)
    {
        // ����a[0]��a[i]��������a[i]��a[0...i]�����ġ�
        tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;
        // ����a[0...i-1]��ʹ��a[0...i-1]��Ȼ��һ�����ѡ�
        // ������֤a[i-1]��a[0...i-1]�е����ֵ��
        maxHeapDown(a, 0, i-1);   //������ʱ���ǴӶ��� 0��ʼ�����ģ�����һ�ξͿ�����
    }
}

/*
 * (��С)�ѵ����µ����㷨
 *
 * ע������ʵ�ֵĶ��У���N���ڵ�����ӵ�����ֵ��(2N+1)���Һ��ӵ�������(2N+2)��
 *     ���У�NΪ�����±�����ֵ���������е�1������Ӧ��NΪ0��
 *
 * ����˵����
 *     a -- �����������
 *     start -- ���µ��ڵ����ʼλ��(һ��Ϊ0����ʾ�ӵ�1����ʼ)
 *     end   -- ������Χ(һ��Ϊ���������һ��Ԫ�ص�����)
 */
void minHeapDown(int* a, int start, int end)
{
    int c = start;            // ��ǰ(current)�ڵ��λ��
    int l = 2*c + 1;        // ��(left)���ӵ�λ��
    int tmp = a[c];            // ��ǰ(current)�ڵ�Ĵ�С
    for (; l <= end; c=l,l=2*l+1)
    {
        // "l"�����ӣ�"l+1"���Һ���  l < end ��֤���Һ���
        if ( l < end && a[l] > a[l+1])
            l++;        // ������������ѡ���С��
        if (tmp <= a[l])
            break;        // ��������
        else            // ����ֵ
        {
            a[c] = a[l];
            a[l]= tmp;
        }
    }
}

/*
 * ������(�Ӵ�С)
 *
 * ����˵����
 *     a -- �����������
 *     n -- ����ĳ���
 */
void heapSortDesc(int* a, int length)
{
    int i,tmp;

    // ��(n/2-1) --> 0��α���ÿ������֮�󣬵õ�������ʵ������һ����С�ѡ�
    for (i = length / 2 - 1; i >= 0; i--)
        minHeapDown(a, i, length-1);

    // �����һ��Ԫ�ؿ�ʼ�����н��е��������ϵ���С�����ķ�Χֱ����һ��Ԫ��
    for (i = length - 1; i > 0; i--)
    {
        // ����a[0]��a[i]��������a[i]��a[0...i]����С�ġ�
        tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;
        // ����a[0...i-1]��ʹ��a[0...i-1]��Ȼ��һ����С�ѡ�
        // ������֤a[i-1]��a[0...i-1]�е���Сֵ��
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

    heapSortAsc(a, ilen);            // ��������
    //heapSortDesc(a, ilen);        // ��������

    cout << "after  sort:";
    for (i=0; i<ilen; i++)
        cout << a[i] << " ";
    cout << endl;

}

