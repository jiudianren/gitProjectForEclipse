/*
 * FuncPointer.cpp
 *
 *  Created on: 2017年3月31日
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

int MMax(int x, int y)  //定义Max函数
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
    int(*p)(int, int);  //定义一个函数指针
    int a, b, c;
    p = MMax;  //把函数Max赋给指针变量p, 使p指向Max函数
    printf("please enter a and b:");

    int a=10, b=12;

    c = (*p)(a, b);  //通过函数指针调用Max函数
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
