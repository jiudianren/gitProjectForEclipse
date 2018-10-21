/*
 * BalancedBinaryTree.cpp
 *
 *  Created on: 2018年5月16日
 *      Author: Administrator
 */



/*
 * http://www.cnblogs.com/polly333/p/4798944.html
 *
 *
 * 判断是不是平衡二叉树
 *
 *https://blog.csdn.net/zjull/article/details/11646591
 *https://blog.csdn.net/zjull/article/details/11646591
 *https://blog.csdn.net/zjull/article/details/11646591
 *https://blog.csdn.net/zjull/article/details/11646591
 *https://blog.csdn.net
 * */

/*

int Depth(TreeNode *root)
{
	if (!root) return 0;
	return 1 + max(Depth(root->left),Depth(root->right));
}

bool isBalanced(TreeNode *root)
{
	if (!root) return true;
	if(!isBalanced(root->left)) return false;
	if(!isBalanced(root->right)) return false;

	int depthLeft = Depth(root->left);
	int depthRight = Depth(root->right);
	if (abs(depthLeft - depthRight) > 1)
		return false;
	return true;
}

*/


/*

bool isBalanced(TreeNode *root, int &height)
{
	if(!root) return true;
	int left=0,right=0;
	if(!isBalanced(root->left,left)) return false;
	if(!isBalanced(root->right,right)) return false;
	if(abs(left-right) > 1) return false;
	height = max(left,right) + 1;
	return true;
}

*/
