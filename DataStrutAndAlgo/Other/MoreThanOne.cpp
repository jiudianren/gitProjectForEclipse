/*
 * MoreThanOne.cpp
 *
 *  Created on: 2019-5-27
 *      Author: 10259187
 */



#include <iostream>
#include <random>
#include <chrono>
#include "MoreThanOne.h"
using  namespace std;

static void  MoreThanOneSolution::TestCase()
{
	std::vector<int> collect;

	std::default_random_engine engine(time(nullptr));
	std::uniform_int_distribution<> dis(1, 100);
	int iCount = dis(engine);

	for( int i = 0 ; i < iCount ; i++)
	{
		collect.push_back(i);
	}

	std::uniform_int_distribution<> dis2(1, iCount);
	int iAim = dis2(engine);

	for( int i = 0 ; i < iCount ; i++)
	{
		std::uniform_int_distribution<> dis2(1, collect.size());
		int iPose = dis2(engine);
		std::vector<int>::iterator it = collect.begin() + iPose;
		collect.insert(it,iAim);
	}

	for( auto it : collect)
	{
		cout <<  *it << ",";
	}
	cout << std::endl;


	auto iTestAim = choose( collect);

	if( iTestAim == iAim)
	{
		cout << "Sucess" << std::endl;
	}
	else
	{
		cout << "Fail" << std::endl;
	}
}

/*默认数据符合要求*/
int MoreThanOneSolution::choose(const std::vector<int>  in)
{
	double cnt;
	int  iBe  = in[0];

	for( auto it : in[1])
	{
		if( iBe == it)
		{
			cnt++;
		}
		else
		{
			if(cnt >=1)
			{
				cnt --;
			}
			else
			{
				cnt =0 ;
				iBe = it;
			}
		}
	}
	return iBe;
}
