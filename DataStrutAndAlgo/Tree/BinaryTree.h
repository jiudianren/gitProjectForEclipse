/*
 * BinaryTree.h
 *
 *  Created on: 2017Äê7ÔÂ30ÈÕ
 *      Author: Lian
 */


#include <stddef.h>

template <class T>
class BinaryTreeNode
{

public:

    BinaryTreeNode(){
        leftChild= rightChild= NULL;
        height =0;
    };

    BinaryTreeNode(const T & a)
    {
        data = a;
        leftChild= rightChild= NULL;
        height =0;
    };
    BinaryTreeNode(const T & a, BinaryTreeNode * r, BinaryTreeNode l)
    {
        data = a;
        leftChild=l;
        rightChild= r;
        height =0;
    };


    T  GetData()
    {
        return data;
    };

    BinaryTreeNode<T> * GetLeftChild()
    {
        return leftChild;
    };

    BinaryTreeNode<T> * GetRightChild()
    {
        return rightChild;
    };

private:
    int height; //for AVL
    T data;
    BinaryTreeNode<T> * leftChild;
    BinaryTreeNode<T> * rightChild;
};
