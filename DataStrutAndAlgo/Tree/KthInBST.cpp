/*
 * KthInBST.CPP
 *
 *  Created on: 2019年3月12日
 *      Author: Administrator
 */

//给定一颗二叉搜索树，查找第k大的结点
//todo in cpp

 int KthSmallest(TreeNode root, int k)
        {
            Stack<TreeNode> s = new Stack<TreeNode>();
            TreeNode p = root;
            while (s.Count > 0 || p != null)
            {
                if (p != null)
                {
                    s.Push(p);
                    p = p.Left;
                }
                else
                {
                    p = s.Pop();
                    --k;
                    if (k == 0)
                    {
                        return p.value;
                    }
                    p = p.Right;
                }
            }
            return -1;
        }
