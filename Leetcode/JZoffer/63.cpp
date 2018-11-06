/*
 * 63.cpp
 *
 *  Created on: 2018Äê11ÔÂ6ÈÕ
 *      Author: Administrator
 */


int MaxDiff( const int * number, unsigned length)
{

	if(number == nullptr || length <2)
	{
		return 0;
	}

	int min= number[0];
	int maxDif= number[1]- min;
	for(int i =2; i < length ;i ++)
	{

		if( number[i-1] <min)
		{
			min = number[i-1];
		}

		int curDif= number[i]- min;
		if(curDif > maxDif)
		{
			maxDif= curDif;
		}
	}

	return maxDif;
}
