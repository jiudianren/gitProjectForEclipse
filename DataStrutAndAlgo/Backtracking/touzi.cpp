/*
 * touzi.cpp
 *
 *  Created on: 2018年11月6日
 *      Author: Administrator
 */


/*
 * n个 骰子 ，随机投掷，求所有数字之和的概率。
 * * 思路就是求排列
 * */


#include <assert.h>
#include <math.h>
#include <iostream>

int g_MaxValue=6;

void ProbalbilityInner( int curNumber, int sum , int * temprobility )
{

    if( curNumber == 1)
    {
    	temprobility[sum] ++;
    }
    else
    {
        for(int i = 1; i <= g_MaxValue; i++)
        {
            ProbalbilityInner( curNumber -1  , sum+i ,temprobility);
        }
    }
}



void Probalbility(int orignal, int *  probability)
{
	int * temprobility = probability+6;
    for(int i = 1; i <= g_MaxValue; i++)
    {
        ProbalbilityInner( orignal, i, temprobility) ;
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
