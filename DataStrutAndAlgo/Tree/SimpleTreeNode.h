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
};


#endif /* DATASTRUTANDALGO_TREE_SIMPLETREENODE_CPP_ */
