/*
 * Permutations.h
 *
 *  Created on: 2018年11月15日
 *      Author: lian.pengfei
 */

#ifndef DATASTRUTANDALGO_BACKTRACKING_PERMUTATIONSANDSUBSETS_H_
#define DATASTRUTANDALGO_BACKTRACKING_PERMUTATIONSANDSUBSETS_H_

#include <vector>
#include <algorithm>
using namespace std;



/*
 *
 *
 * [1,2,3]的排列
 *
 * 1 2 3
 * 1 3 2
 * 2 1 3
 * 2 3 1
 * 3 1 2
 * 3 2 1
 * */

class PermSolution {
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


	void backTracking( vector<vector<int>>& ret,
			vector<int>  & curr,
			vector<bool> &  isVisited,
			const vector<int> & In  )
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


/*
 *
 *
 * [1,2]的子集，并按顺序排列
 * 【】
 * 【1】
 * 【2】
 * 【1,2】
 * */

/*组合*/
class SubSetSolution {
public:
	vector<vector<int> > res;
	vector<vector<int> > subsets( const vector<int> & S) {
		if(S.empty()) {
			return res;
		}

		std::sort(S.begin(), S.end());
		//别忘了空集合
		res.push_back(vector<int>());
		vector<int> v;
		auto input=   [S](vector<int> in)
        				{
			S.push_back(in);
        				};
		generate(0, v, S);
		return res;
	}
	void generate(int start, vector<int>& v,  const vector<int>&S) {

		if( start == S.size()) {
			return;
		}
		for(int i = start; i < S.size(); i++) {
			v.push_back(S[i]);
			res.push_back(v);
			generate(i + 1, v, S);
			v.pop_back();
		}
	}

	void generate(int start, vector<int>& v,  std::function<void(vector<int>) func>) {

		if( start == S.size()) {
			return;
		}
		for(int i = start; i < S.size(); i++) {
			v.push_back(S[i]);
			func(v);
			generate(i + 1, v, S);
			v.pop_back();
		}
	}
};



#endif /* DATASTRUTANDALGO_BACKTRACKING_PERMUTATIONSANDSUBSETS_H_ */
