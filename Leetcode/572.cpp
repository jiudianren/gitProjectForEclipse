
/*
 * 另一个树的子树
 *
 * */


/**
 *
 * 572
 * Definition for a binary tree node.

 */


/*
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 *
 *
 *       根据前序遍历的特点, 知前序序列(PreSequence)的首个元素(PreSequence[0])为二叉树的根(root),
 *        然后在中序序列(InSequence)中查找此根(root),  根据中序遍历特点, 知在查找到的根(root) 前边的序列为根的左子树的中序遍历序列,
 *       后边的序列为根的右子树的中序遍历序列。 设在中序遍历序列(InSequence)根前边有left个元素.
 *        则在前序序列(PreSequence)中, 紧跟着根(root)的left个元素序列(即PreSequence[1...left]) 为根的左子树的前序遍历序列,
 *        在后边的为根的右子树的前序遍历序列.而构造左子树问题其实跟构造整个二叉树问题一样，只是此时前序序列为PreSequence[1...left]),
 *         中序序列为InSequence[0...left-1], 分别为原序列的子串,
 *        构造右子树同样, 显然可以用递归方法解决。
 * */


/**
 * Definition for a binary tree node.
 */
#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

		TreeNode * t = NULL;

		if( preorder.size()==0)
		{
			return t ;
		}
		int rootNode= preorder[0];

		vector<int>::iterator index =std::find(inorder.begin(), inorder.end(), rootNode);

		vector<int > linorder;
		for( vector<int>::iterator  be= inorder.begin(); be != index && index != inorder.end(); be++)
		{
			cout<< "aa"<<*be<<"," <<endl;
			linorder.push_back( *be);
		}

		vector<int > rinorder;

		for( index++ ; index != inorder.end(); index++)
		{
			cout<< "bb"<<*index<<"," <<endl;
			rinorder.push_back( *index);
		}


		int llength= linorder.size();
		vector<int> lpreorder;
		for( int i=0 ; i < llength; i++)
		{
			lpreorder.push_back( preorder[i+1]);
		}
		int rlength =rinorder.size();

		vector<int> rpreorder;
		for( int i=0 ; i < rlength; i++)
		{
			rpreorder.push_back( preorder[ llength+1+i]);
		}

		t=(TreeNode *)malloc(sizeof(TreeNode));
		if(t!= NULL)
		{
			t->val= rootNode;
			t->left =buildTree(lpreorder,linorder);//递归创建左孩子
			t->right =buildTree( rpreorder ,rinorder);//递归创建右孩子
		}

        return t;
    }

    void pre(TreeNode * t)
    {
    	if( t!= NULL)
    	{
    		cout<< t->val<<",";
    		pre( t->left);
    		pre( t->right);
    	}
    }
};


int main()
{

	vector<int> pre;
	vector<int > inor;

	pre.push_back(3);
	pre.push_back(9);
	pre.push_back(20);
	pre.push_back(15);
	pre.push_back(7);

	inor.push_back(9);
	inor.push_back(3);
	inor.push_back(15);
	inor.push_back(20);
	inor.push_back(7);

	TreeNode * node = Solution().buildTree(pre, inor);
	 Solution().pre(node);

}
