/*
 * SimpleTreeNode.cpp
 *
 *  Created on: 2018Äê10ÔÂ25ÈÕ
 *      Author: Administrator
 */

#ifndef DATASTRUTANDALGO_TREE_SIMPLETREENODE_CPP_
#define DATASTRUTANDALGO_TREE_SIMPLETREENODE_CPP_

#include <stdio.h>

struct TreeNode
{
    int value;
    TreeNode * left;
    TreeNode * right;
    TreeNode() : value(0), left(NULL), right(NULL){}
    TreeNode(int x) : value(x), left(NULL), right(NULL){}



void  free() {
	freeSubNode();
	delete this;
}
void freeSubNode()
{

	if(this->left != nullptr)
	{
		this->left->freeSubNode();
		delete this->left;
	}
	if(this->right != nullptr)
	{
		this->right->freeSubNode();
		delete this->right;
	}
}

};


#endif /* DATASTRUTANDALGO_TREE_SIMPLETREENODE_CPP_ */
