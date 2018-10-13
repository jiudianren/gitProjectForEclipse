/*
 * TraversalTree.cpp
 *
 *  Created on: 2018年10月13日
 *      Author: Administrator
 */


#include <vector>

using namespace std;
struct TreeNode
{

	int value;


	TreeNode * left;
	TreeNode * right;

	TreeNode(int x) : value(x), left(null), right(null){}

};


/* 迭代*/

vector<int >  inorderTraversal( TreeNode * root){

	vector<int> val;

	if( root = NULL)
	{
		return val;
	}

	vector<TreeNode * > nodes;
	TreeNode * p = root;
	while( p || ! nodes.empty())
	{

		while (p)
		{

			nodes.push_back(p);
			p= p->left;
		}

		if( ! nodes.empty())
		{
			p=nodes.back();
			val.push_back(p->value);
			nodes.pop_back();

			p = p->right;
		}

	}

	return val;
}
