/*
 * width.cpp
 *
 *  Created on: 2018年10月21日
 *      Author: Administrator
 */

/*
 * 求树的宽度
 * */

/* 二叉树的宽度      在上一层遍历完成后，下一层的所有节点已经放到队列中，此时队列中的元素个数就是下一层的宽度*/
/************************************************************************/
int WidthOfBinaryTree(BinaryTreeNode*pNode){
	if (pNode == NULL)
	{
		return 0;
	}
	std::deque<BinaryTreeNode*> dequeTreeNode;//双端队列
	int maxWidth = 1;//最大的宽度,用于当只有一个节点时候返回1
	dequeTreeNode.push_back(pNode);//头结点入队
	while (true)
	{

		int length = dequeTreeNode.size();//当前层节点的个数
		if (length == 0)//当前层没有节点，跳出循环
		{
			break;
		}
		while (length > 0)//如果当前层还有节点
		{
			BinaryTreeNode* pTemp = dequeTreeNode.front();
			dequeTreeNode.pop_front();//出队
			length--;//长度减一
			if (pTemp->m_pLeft)
			{
				dequeTreeNode.push_back(pTemp->m_pLeft);//下一层节点入队
			}
			if (pTemp->m_pRight)
			{
				dequeTreeNode.push_back(pTemp->m_pRight);//下一层节点入队
			}
		}
		maxWidth = maxWidth > dequeTreeNode.size() ? maxWidth : dequeTreeNode.size();//得到最大宽度
	}
	return maxWidth;
}
