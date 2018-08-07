/*
 * BST.h
 *
 *  Created on: 2018��6��3��
 *      Author: Administrator
 */

#ifndef DATASTRUTANDALGO_TREE_BST_H_
#define DATASTRUTANDALGO_TREE_BST_H_

#include "BinaryTree.h"


/*
 * ���������
 *
 *Binary Search Tree(BST)
 *
 *ֻ�������ӽڵ�Ĵ�С��Ҫ��Ķ�����
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

	/**���Ҫɾ���ļ�ֻ��һ���ӽ�����û���ӽ�㣬���԰�����������ɾ�����������Ҫɾ���Ľ��������ӽ���������ӽ���أ�
	ɾ����Ҫͬʱ�����������������Ǳ�ɾ�����ĸ����ֻ��ճ�һ�����ӳ�����
	�����Ƕ����룬���������������������о���������ļ��ϣ�����ɾ���˸ý�㣬�����øý��ĺ�̻���ǰ�����ȡ������
	�������Ǵ����ú�̽��ȡ����ɾ������λ�á�
	���岽������
	1�����ɾ���Ľ��ֻ��һ���ӽ�����û���ӽ�㣬���类ɾ�����Ϊx���丸���Ϊt��
	��xû��������t.left = x.right������xû���ҽ����t.right = x.left��

	2 �����ɾ���Ľ���������ӽ�㡣�Ƚ���ɾ���Ľ�㱣��Ϊt�������ӽ��Ϊt.right��
 	 	 Ȼ���ҵ��������е���С��㣬�ý����Ǳ�ɾ�����t�ĺ�̽�㣬��Ϊx��t��x֮��������������
	����xȡ��t��λ�ú��޳�x���t�������������н����Ȼ����x������ֻ����x�������������޳�m���t����������m������������t�����������ɡ�
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

			/*����  = ������*/
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
