/*
 * FuncPointer.h
 *
 *  Created on: 2017��3��31��
 *      Author: Administrator
 */

#ifndef FUNCPOINTER_H_
#define FUNCPOINTER_H_


/*����ָ��Ĭ��ֵ*/

typedef void (*SUM)(int a,int b);
void sum1(int a ,int b);
void sum2(int a ,int b);

int MMax(int, int);  //��������
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
