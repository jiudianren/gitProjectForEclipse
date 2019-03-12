/*
 * KthInBST.CPP
 *
 *  Created on: 2019��3��12��
 *      Author: Administrator
 */

//����һ�Ŷ��������������ҵ�k��Ľ��
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
