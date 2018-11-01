/*
 * �����Ŀ��
 * */

/* �������Ŀ��      ����һ�������ɺ���һ������нڵ��Ѿ��ŵ������У���ʱ�����е�Ԫ�ظ���������һ��Ŀ��*/
/************************************************************************/

#include "SimpleTreeNode.h"
#include <deque>

int WidthOfBinaryTree(TreeNode * pNode){
    if (pNode == NULL)
    {
        return 0;
    }
    std::deque<TreeNode*> dequeTreeNode;//˫�˶���
    int maxWidth = 1;//���Ŀ��,���ڵ�ֻ��һ���ڵ�ʱ�򷵻�1
    dequeTreeNode.push_back(pNode);//ͷ������
    while (true)
    {

        int length = dequeTreeNode.size();//��ǰ��ڵ�ĸ���
        if ( length == 0)//��ǰ��û�нڵ㣬����ѭ��
        {
            break;
        }
        while ( length > 0)//�����ǰ�㻹�нڵ�
        {
            TreeNode* pTemp = dequeTreeNode.front();
            dequeTreeNode.pop_front();//����
            length--;//���ȼ�һ
            if (pTemp->left)
            {
                dequeTreeNode.push_back(pTemp->left);//��һ��ڵ����
            }
            if (pTemp->right)
            {
                dequeTreeNode.push_back(pTemp->right);//��һ��ڵ����
            }
        }
        maxWidth = maxWidth > dequeTreeNode.size() ? maxWidth : dequeTreeNode.size();//�õ������
    }
    return maxWidth;
}
