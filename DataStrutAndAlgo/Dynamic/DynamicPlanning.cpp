/*
 * DynamicPlanning.cpp
 *
 *  Created on: 2018Äê1ÔÂ7ÈÕ
 *      Author: Administrator
 */



#include "DynamicPlanning.h"

#include <iostream>

using namespace  std;

int GetClimbWays(int n)
{

	if( n ==1)
	{
		return 1;
	}

	if(n==2)
	{
		return 2;
	}
	return  GetClimbWays(n-1)+GetClimbWays(n-2);

}

int GetClimbWays3(int n)
{
	static std::map<int ,int >  & alreadMap  ;
	if( n ==1)
	{
		return 1;
	}

	if(n==2)
	{
		return 2;
	}
	std::map<int,int>::iterator  it= alreadMap.find( n);
	if( it!= alreadMap.end())
	{
		return it->second;
	}
	else
	{
		int ret = GetClimbWays2(n-1, alreadMap) +GetClimbWays2(n-1, alreadMap);
		alreadMap.insert(std::pair<int ,int> (n,ret));
		return ret;
	}
}
int GetClimbWays2(int n, std::map<int ,int >  & alreadMap  )
{

	if( n ==1)
	{
		return 1;
	}

	if(n==2)
	{
		return 2;
	}
	std::map<int,int>::iterator  it= alreadMap.find( n);
	if( it!= alreadMap.end())
	{
		return it->second;
	}
	else
	{
		int ret = GetClimbWays2(n-1, alreadMap) +GetClimbWays2(n-1, alreadMap);
		alreadMap.insert(std::pair<int ,int> (n,ret));
		return ret;
	}
}




void mainDynmaicPlan()
{

	int getways =10;
	std::map<int,int> alreadMap;
	cout<<"get step: "<< GetClimbWays( getways )<<std::endl;
	cout<<"get step2: "<<GetClimbWays2( getways,alreadMap )<<std::endl;
}






