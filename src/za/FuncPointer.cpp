/*
 * FuncPointer.cpp
 *
 *  Created on: 2017��3��31��
 *      Author: Administrator
 */




#include "FuncPointer.h"
#include <iostream>
#include<iostream>
#include<string>
#include<vector>
# include <stdio.h>

using namespace std;
void sum1(int a,int b)
{
    cout<<"sum1: "<<(a+b)<<endl;
}
void sum2(int a,int b)
{
    cout<<"sum2: "<<(a+b)<<endl;
}
FunctionPointer::FunctionPointer():a(1),b(1),isum(sum1)
{
}


FunctionPointer::FunctionPointer(int ia,SUM):a(ia),b(2),isum(sum2)
{

}

int MMax(int x, int y)  //����Max����
{
    int z;
    if (x > y)
    {
        z = x;
    }
    else
    {
        z = y;
    }
    return z;
}

int mainTestPoint(void)
{
    int(*p)(int, int);  //����һ������ָ��
    int a, b, c;
    p = MMax;  //�Ѻ���Max����ָ�����p, ʹpָ��Max����
    printf("please enter a and b:");

    int a=10, b=12;

    c = (*p)(a, b);  //ͨ������ָ�����Max����
    printf("a = %d\nb = %d\nmax = %d\n", a, b, c);
    return 0;
}

void mainFP()
{
    FunctionPointer fp1;
    FunctionPointer fp2(3);
    fp1.isum(1,1);
    fp2.isum(2,2);
}
