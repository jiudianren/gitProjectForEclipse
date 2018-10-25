/*
 * TraversalTree.cpp
 *
 *  Created on: 2018��10��13��
 *      Author: Administrator
 */


#include <vector>

#include "SimpleTreeNode.h"


using namespace std;



/* ����*/

vector<int >  inorderTraversal( TreeNode * root){

	vector<int> val;

	if( root == NULL)
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
