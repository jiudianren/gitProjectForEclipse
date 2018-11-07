/*
 * 66.cpp
 *
 *  Created on: 2018Äê11ÔÂ6ÈÕ
 *      Author: Administrator
 */


#include <vector>

using namespace std;

void myltiply(const vector<double> & in, const vector<double> & out)
{

	int len1= in.size();
	int len2= out.size();

	if( len1== len2 && len1 >1)
	{
		out[0] = 1;
		for(int i =1; i< len1; i++)
		{
			out[i]= out[i-1]*in[i-1];

		}

		int temp =1;
		for(int i = len1-2 ; i>=0;--1)
		{
			temp *= in[i+1];
			out[i] *= temp;
		}
	}

}
