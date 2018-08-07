/*
 * BST.h
 *
 *  Created on: 2018年6月3日
 *      Author: Administrator
 */

#ifndef DATASTRUTANDALGO_TREE_BST_H_
#define DATASTRUTANDALGO_TREE_BST_H_

#include "BinaryTree.h"


/*
 * 二叉查找树
 *
 *Binary Search Tree(BST)
 *
 *只对左右子节点的大小有要求的二叉树
 *
 *
 *http://www.cnblogs.com/sun-haiyu/p/7682618.html
 * */
template <class T>
class BST {


public:
	int Size()
	{
		return  Size( &root);
	};

	BinaryTreeNode<T> *  Get(T t){
		return Get(&root , t);
	};

	T Min();
	T Max();
	void DeleteMin();
	void DeleteMax();


	T select(int k);
	int Rank(T t);

	/**如果要删除的键只有一个子结点或者没有子结点，可以按照上述方法删除，但是如果要删除的结点既有左子结点又有右子结点呢？
	删除后将要同时处理两棵子树，但是被删除结点的父结点只会空出一条链接出来。
	换个角度想想，二叉查找树的中序遍历序列就是有序键的集合，所以删除了该结点，可以用该结点的后继或者前驱结点取代它。
	这里我们打算用后继结点取代被删除结点的位置。
	具体步骤如下
	1如果被删除的结点只有一个子结点或者没有子结点，比如被删除结点为x，其父结点为t。
	若x没有左结点则t.left = x.right，或者x没有右结点则t.right = x.left。

	2 如果被删除的结点有左右子结点。先将被删除的结点保存为t，其右子结点为t.right，
 	 	 然后找到右子树中的最小结点，该结点就是被删除结点t的后继结点，设为x。t和x之间再无其他键，
	所以x取代t的位置后，剔除x后的t的右子树中所有结点仍然大于x，所以只需让x的右子树连接剔除m后的t的右子树，m的左子树连接t的左子树即可。
~*/
	void Delete(BinaryTreeNode<T> * root,  T t)
	{
		if (root == NULL) {
			return ;
		}

		T cmp = root->GetData()  - T;
		if( cmp < 0)
		{
			Delete( root->GetRightChild(), t);
		}
		else if ( cmp >0)
		{
			Delete( root->GetLeftChild() , t);
		}else
		{
			if ( root->GetLeftChild() == NULL && root->GetRightChild() == NULL  )
			{
				root = NULL;
			}

			if ( root->GetLeftChild() == NULL) {
				// free  root->GetData();
				root = root->GetRightChild();
			}

			if ( root->GetRightChild() == NULL) {
				// free  root->GetData();
				root = root->GetLeftChild();
			}

			BinaryTreeNode<T> * tMin = Min( root->GetRightChild() );

			DeleteMin( root->GetRightChild() ) = NULL;
			tMin->GetLeftChild() = root->GetLeftChild();
			tMin->GetRightChild() = root->GetRightChild();
			// free  root->GetData();

			/*重载  = 操作符*/
			root = tMin;
		}

	};


	void Insert( T t)
	{
		BinaryTreeNode<T> tNode(t);
		Insert(&root , &tNode );
	};

	void Insert( BinaryTreeNode<T> * root ,  BinaryTreeNode<T> * node )
	{
		if( root == NULL)
		{
			root = node;
			return;
		}

		BinaryTreeNode<T>  * pRNode = root;
		BinaryTreeNode<T> * pPreRNode = NULL;

		while( pRNode != NULL)
		{
			pPreRNode = pRNode;
			if( node->GetData() == pRNode->GetData())
			{
				return;
			}
			if( node->GetData() < pRNode->GetData() )
			{
				pRNode = pRNode->GetLeftChild();
			}
			else{
				pRNode = pRNode->GetRightChild();
			}
		}

		if(pPreRNode->GetData() < node->GetData())
		{
			pPreRNode->GetRightChild() = node;
		}
		else
		{
			pPreRNode->GetLeftChild() = node;
		}
	};
private:
	BinaryTreeNode<T> root;
	BinaryTreeNode<T> *  Get( BinaryTreeNode<T> * root,  T t){

		if( root == NULL)
		{
			return NULL;
		}

		T cmp = root->GetData() -T;
		if( cmp < 0)
		{
			return Get( root->GetRightChild(), t);
		}
		else if ( cmp >0)
		{
			return Get( root->GetLeftChild(),t);

		}else
		{
			return root;
		}
	};
	int Size( BinaryTreeNode<T> * root)
	{
		if(root==NULL){
			return 0;
		}
		else
		{
			return Size(root->GetLeftChild())+  1+Size(root->GetRightChild());
		}
	};

	BinaryTreeNode<T> *   Min( BinaryTreeNode<T> * root );

	BinaryTreeNode<T> * DeleteMin( BinaryTreeNode<T> * root);
};



#endif /* DATASTRUTANDALGO_TREE_BST_H_ */
