/*
 * FuncPointer.cpp
 *
 *  Created on: 2017Äê3ÔÂ31ÈÕ
 *      Author: Administrator
 */




#include "FuncPointer.h"
#include <iostream>
#include<iostream>
#include<string>
#include<vector>
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

void mainFP()
{
    FunctionPointer fp1;
    FunctionPointer fp2(3);
    fp1.isum(1,1);
    fp2.isum(2,2);
}
