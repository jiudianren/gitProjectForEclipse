/*
 * Subsets.cpp
 *
 *  Created on: 2018年10月13日
 *      Author: Administrator
 */


/*
 *
 *
 * [1,2]的子集，并按顺序排列
 * 【】
 * 【1】
 * 【2】
 * 【1,2】
 * */

#include <vector>
using namespace std;


/*组合*/
class Solution {
public:
	vector<vector<int> > res;
	vector<vector<int> > subsets( const vector<int> &S) {
		if(S.empty()) {
			return res;
		}

		sort(S.begin(), S.end());
		//别忘了空集合
		res.push_back(vector<int>());
		vector<int> v;
		generate(0, v, S);
		return res;
	}
	void generate(int start, vector<int>& v, vector<int>&S) {
		if(start == S.size()) {
			return;
		}
		for(int i = start; i < S.size(); i++) {
			v.push_back(S[i]);
			res.push_back(v);
			generate(i + 1, v, S);
			v.pop_back();
		}
	}
};



/*排列*/
