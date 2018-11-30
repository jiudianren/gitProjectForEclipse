/*
 * LeftRightRoat.cpp
 *
 *  Created on: 2018Äê11ÔÂ28ÈÕ
 *      Author: Administrator
 */


/*todo */

#include "LeftRightRoat.h"
#include <stack>
#include <queue>

void Exchange(TreeNode *root)
{

	if( root == nullptr)
	{
		return ;
	}

	TreeNode *  temp = root->left;
	root->left = root->right;
	root->right = temp;

	if( root->left)
	{
		Exchange( root->left);
	}

	if( root->right)
	{
		Exchange(root->right);
	}

};


void Exchange_NR(TreeNode *root)
{
	if(root  == nullptr)
	{ return ;}

	std::queue<TreeNode * > pQueue;

	pQueue.push(root);

	while(! pQueue.empty())
	{
		TreeNode * cur = pQueue.pop();
		auto temp = cur->left;
		cur->left =cur->right;
		cur->right = temp;

		if( cur->left )
		{
			pQueue.push( cur->left);
		}

		if( cur->right )
		{
			pQueue.push( cur->right);
		}

	}
}


