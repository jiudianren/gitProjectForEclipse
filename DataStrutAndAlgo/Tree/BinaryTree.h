/*
 * BinaryTree.h
 *
 *  Created on: 2018年11月7日
 *      Author: lian.pengfei
 */

#ifndef DATASTRUTANDALGO_TREE_BINARYTREE_H_
#define DATASTRUTANDALGO_TREE_BINARYTREE_H_

#include "SimpleTreeNode.h"
#include <vector>

//递归版本
void proOrder( TreeNode *root) ;
void inOrder( TreeNode *root)  ;
void postOrder( TreeNode *root);


//非递归
void PreOrder_Nor(TreeNode * root);
void InOrder_Nor(TreeNode *root) ;
void postOrder_Nor(TreeNode *root) ;

//深度
int Depth(const TreeNode *root);

//按层次遍历
void ListNodeByLevel(TreeNode*  root);
int PrintNodeAtLevel(TreeNode*  root, int level);

//按层次遍历，容器法
void getSolution(std::vector<std::vector<int>> & ret, const TreeNode*  root, int level);
std::vector<std::vector<int>> levelOrder(const TreeNode *root) ;
//用队列 实现 按成遍历
void levels_showBT(const TreeNode * root);


/*相距离最远的两个节点的距离*/
int MostFar(const TreeNode*pNode, int&nMaxDistance);
void TestMax();

/*二叉树的宽度 */
int WidthOfBinaryTree(const TreeNode * pNode);


/*路径 和为 某个值*/
void  FindPath(TreeNode * root , std::vector<int>  path , int curSum, int sum );
void  FindPath(TreeNode * root , int Sum);



#endif /* DATASTRUTANDALGO_TREE_BINARYTREE_H_ */
