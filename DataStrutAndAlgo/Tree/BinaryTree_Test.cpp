
#include "BinaryTree.h"
#include "iostream"

using namespace std;




//�ݹ�汾
void proOrder( BinaryTreeNode<int> *root)     //�ݹ�ǰ�����
 {
    if(root!=NULL)
    {
        cout<< root->GetData()<<" ";
        proOrder( root->GetLeftChild() );
        proOrder( root->GetRightChild() );
    }
 }


/*
 * ����ջ�ṹ������ ��ǰ�ı����Ľڵ�ѹ��ջ��
 *
 * */
#if 0
void preOrder2( BinaryTreeNode<int> *root)     //�ǵݹ�ǰ�����
{
    std::stack<BinaryTreeNode<int> *> s;
    BinaryTreeNode<int> *p=root;
    while(p!=NULL||!s.empty())
    {
        while(p!=NULL)
        {
            cout<<p->data<<" ";
            s.push(p);
            p=p->lchild;
        }
        if(!s.empty())
        {
            p=s.top();
            s.pop();
            p=p->rchild;
        }
    }
}

#endif


int PrintNodeAtLevel(BinaryTreeNode<int> root, int level)
{
    if(!root || level < 0)
        return 0;
    else if(level == 0)
    {
        cout << root->data << endl;
        return 1;
    }
    else
        return PrintNodeAtLevel(root->left, level - 1) + PrintNodeAtLevel(root->right, level - 1);
}

/*https://www.cnblogs.com/kaituorensheng/p/3558645.html
 * */
// ������ ���ղ����
void ListNodeByLevel(BinaryTreeNode<int> root)
{

    for(int i = 0; i < Height(root); ++i)
    {
        PrintNodeAtLevel(root, i);
        cout << "_____________________________" << endl;
    }
}


void TestBinaryMain()
{

    BinaryTreeNode<int> root();




}
