/*
 * containerTopK.cpp
 *
 *  Created on: 2018��11��22��
 *      Author: lian.pengfei
 */




//std::nth_element

//�Լ�ʵ�� nth_element ģ�庯�����������汾


#include <vector>
#include <algorithm>
std::vector<int> Topk( std::vector<int> in ,int k)
{

	if( in.size() <=0)
	{
		std::vector<int> rt;
		return rt;
	}

	std::sort(in.begin(), in.end(), [](int a,int b){ return b>a;});

	if(in.size() <= k)
	{
		std::vector<int> rt(in.begin(),in.end());
		return rt;
	}
	else
	{
		std::vector<int> rt(in.begin(),in.begin()+k);
		return rt;
	}
}
