/*
 * Subsets.cpp
 *
 *  Created on: 2018��10��13��
 *      Author: Administrator
 */


/*
 *
 *
 * [1,2]���Ӽ�������˳������
 * ����
 * ��1��
 * ��2��
 * ��1,2��
 * */

#include <vector>
using namespace std;


/*���*/
class Solution {
public:
	vector<vector<int> > res;
	vector<vector<int> > subsets( const vector<int> &S) {
		if(S.empty()) {
			return res;
		}

		sort(S.begin(), S.end());
		//�����˿ռ���
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



/*����*/
