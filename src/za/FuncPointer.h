/*
 * FuncPointer.h
 *
 *  Created on: 2017年3月31日
 *      Author: Administrator
 */

#ifndef FUNCPOINTER_H_
#define FUNCPOINTER_H_


/*函数指针默认值*/

typedef void (*SUM)(int a,int b);
void sum1(int a ,int b);
void sum2(int a ,int b);

int MMax(int, int);  //函数声明
void mainFP();
class FunctionPointer
{
private:
    int a;
    int b;

public:
    SUM isum;
    FunctionPointer();
    FunctionPointer(int ia,SUM=sum2);


};

#endif /* FUNCPOINTER_H_ */
