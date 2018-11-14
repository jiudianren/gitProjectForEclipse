/*
 * BinaryTree.h
 *
 *  Created on: 2018��11��7��
 *      Author: lian.pengfei
 */

#ifndef DATASTRUTANDALGO_TREE_BINARYTREE_H_
#define DATASTRUTANDALGO_TREE_BINARYTREE_H_

#include "SimpleTreeNode.h"
#include <vector>

//�ݹ�汾
void proOrder( TreeNode *root) ;
void inOrder( TreeNode *root)  ;
void postOrder( TreeNode *root);


//�ǵݹ�
void PreOrder_Nor(TreeNode * root);
void InOrder_Nor(TreeNode *root) ;
void postOrder_Nor(TreeNode *root) ;

//���
int Depth(TreeNode *root);

//����α���
void ListNodeByLevel(TreeNode*  root);
int PrintNodeAtLevel(TreeNode*  root, int level);

//����α�����������
void getSolution(std::vector<std::vector<int>> & ret, TreeNode*  root, int level);
std::vector<std::vector<int>> levelOrder(TreeNode *root) ;
//�ö��� ʵ�� ���ɱ���


/*�������Զ�������ڵ�ľ���*/
int MostFar(TreeNode*pNode, int&nMaxDistance);
void TestMax();

/*�������Ŀ�� */
int WidthOfBinaryTree(TreeNode * pNode);


/*·�� ��Ϊ ĳ��ֵ*/

void  FindPath(TreeNode * root , std::vector<int>  path , int curSum, int sum );
void  FindPath(TreeNode * root , int Sum);



#endif /* DATASTRUTANDALGO_TREE_BINARYTREE_H_ */
