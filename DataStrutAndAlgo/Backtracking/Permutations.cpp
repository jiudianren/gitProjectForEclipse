
/*
 *
 *
 * [1,2,3]╣дееап
 *
 * 1 2 3
 * 1 3 2
 * 2 1 3
 * 2 3 1
 * 3 1 2
 * 3 2 1
 * */

#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > permute( const vector<int> & In) {
		vector<vector<int>> permutations;
		if(In.size() == 0) //invalid corner case check
			return permutations;
		vector<int> curr;
		vector<bool> isVisited(In.size(), false);
		//using this bool type array to check whether or not the elments has been visited
		backTracking(permutations,curr,isVisited,In);
		return permutations;
	}


	void backTracking( vector<vector<int>>& ret, vector<int>  & curr, vector<bool> &  isVisited, const vector<int> & In  )
	{
		if(curr.size() == In.size())
		{
			ret.push_back(curr);
			return;
		}
		for(int i = 0; i < In.size(); ++i)
		{
			if(isVisited[i] == false)
			{
				isVisited[i] = true;
				curr.push_back(In[i]);

				backTracking(ret,curr,isVisited,In);

				isVisited[i] = false;
				curr.pop_back();
			}
		}
	}
};
