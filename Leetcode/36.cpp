/*
 *
 * 判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。


 *
 * */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {

		//行 检查
		for( int i=0; i< 9 ; i++)
		{

			vector<char> &inner= board[i];

			vector<char> temp;
			for(int j=0 ;j<9 ;j ++)
			{
				if( inner[j] != '.')
				{
					temp.push_back(inner[j]);
				}
			}
			if( ! checkdup(temp))
			{
				return false;
			}

		}


		//列 检查
		for( int i=0; i< 9 ; i++)
		{
			vector<char> temp;
			for(int j=0 ;j<9 ;j ++)
			{
				vector<char> &inner= board[j];
				if( inner[i] != '.')
				{
					temp.push_back(inner[i]);
				}
			}
			if( ! checkdup(temp))
			{
				return false;
			}

		}



		//小方格检查

		for(int i =0; i<3; i++)
		{
			for (int j =0 ; j<3; j++)
			{
				vector<char> temp;
				for(int m=0; m <3; m++)
				{
					auto inner= board[i*3+m];
					for(int n=0; n <3; n++)
					{
						auto tc= inner[j*3+n];

						if( tc[i] != '.')
						{
							temp.push_back( tc);
						}
						temp.push_back(inner);
					}
				}
				if( ! checkdup(temp))
				{
					return false;
				}


			}

		}

		return true;

	}


	bool checkdup( vector<char> & temp)
	{


		for(auto it: temp)
		{
			cout<< *it <<",";
		}
		cout<<endl;
		std::sort(temp.begin(),temp.back());

		auto it =std::adjacent_find(temp.begin(),temp.end());
		if(it != temp.end())
		{
			return false;
		}
		else
		{
			return true;
		}

	}
};

