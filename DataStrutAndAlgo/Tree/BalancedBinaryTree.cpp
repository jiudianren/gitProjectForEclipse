
/*
 * http://www.cnblogs.com/polly333/p/4798944.html
  判断是不是平衡二叉树

 *https://blog.csdn.net/zjull/article/details/11646591

 * */

#include "SimpleTreeNode.h"
#include "BinaryTree.h"

bool isBalanced(TreeNode *root)
{
	if (!root) return true;
	if(!isBalanced(root->left)) return false;
	if(!isBalanced(root->right)) return false;

	int depthLeft  = Depth(root->left);
	int depthRight = Depth(root->right);
	int diff = depthLeft - depthRight;
	if ( diff > 1 || diff < -1)
		return false;
	return true;
}
