//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题53（一）：数字在排序数组中出现的次数
// 题目：统计一个数字在排序数组中出现的次数。例如输入排序数组{1, 2, 3, 3,
// 3, 3, 4, 5}和数字3，由于3在这个数组中出现了4次，因此输出4。


int GetFirstIndex(const int* data, int length, int k, int start, int end);
int GetLastIndex(const int* data, int length, int k, int start, int end);
int NumberOfK(const int * arr, int length , int k)
{

	int iConter = 0 ;

	if(arr != nullptr && length != 0 )
	{
		 int iFirst = GetFirstIndex(arr, length, k ,0 , length -1);

		 if(iFirst != -1)
		 {
			 int iLast = GetLastIndex(arr, length, k , iFirst , length -1);
			 if(  iLast  > -1)
			 {
				 iConter =  iLast - iFirst + 1;
			 }
		 }
	}

	return iConter;
}


int GetFirstIndex(const int* data, int length, int k, int start, int end)
{

	if( start > end)
	{
		return -1;
	}

	int iMidLoc = (start + end)/2;
	int iMidVal = data[iMidLoc];

	if( iMidVal == k )
	{
		if((iMidLoc > 0 && data[iMidLoc - 1] != k) || iMidLoc == 0)
		{
			return iMidLoc;
		}
		else
		{
			end  = iMidLoc - 1;
		}
	}
	else if ( iMidVal  < k)
	{
		start = iMidLoc + 1;
	}
	else
	{
		end = iMidLoc -1;
	}
	return GetFirstIndex(  data,  length,  k,  start,  end);
}
