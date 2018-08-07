
/*
 * 树中的最大值
 *
 *
 *
 *
 *
 * */

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };



class Solution {
public:

	TreeNode maxNode(TreeNode root) {

        if(root == NULL)//首先判断root节点是否为空，空就直接返回
            return NULL;

        TreeNode left = root,right = root;//将root值付给left和right，因为三点的val做比较，防止出现left或right在val比较时出现null异常（卡在这里很久）
        if(root.left != NULL)
            left = maxNode(root.left);//递归获取左子树最大node
        if(root.right != NULL)
            right = maxNode(root.right);//递归获取右子树最大node
        TreeNode temp = left.val > root.val ? left:root; //先做比较左子树和root取得最大值

        return right.val > temp.val ?right:temp;//在做最大值和右子树比较

    }

};



