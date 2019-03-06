/*
 * touzi.cpp
 *
 *  Created on: 2018��11��6��
 *      Author: Administrator
 */


/*
 * n�� ���� �����Ͷ��������������֮�͵ĸ��ʡ�
 *
 * ˼·����������
 * */


#include <assert.h>
#include <math.h>
#include <iostream>

int g_MaxValue=6;

void ProbalbilityInner(int orignal, int curNumber, int sum , int * probability )
{

    if( curNumber ==1)
    {
        probability[ sum - orignal] ++;
    }
    else
    {
        for(int i = 1  ; i <= g_MaxValue; i++)
        {
            ProbalbilityInner( orignal, curNumber -1  , sum+i ,probability) ;
        }
    }
}



void Probalbility(int orignal, int *  probability)
{
    for(int i = 1  ; i <= g_MaxValue; i++)
    {
        ProbalbilityInner( orignal, orignal ,i ,probability) ;
    }
}

void PrintProbability(int number)
{
    assert( number>0);

    int maxSum = number * g_MaxValue;
    int * probability = new int[ maxSum - number +1];


    for(int i = number; i< maxSum; i++)
    {
        probability[ i-number] =0;
    }

    Probalbility( number , probability);

    double total = pow( (double )number, g_MaxValue );

    for(int i = number; i< maxSum ; i++)
    {
        std::cout<< " Value: " << i << ", probalbity : " <<  probability[ i - number ]/total;
    }

    delete [] probability;
}


