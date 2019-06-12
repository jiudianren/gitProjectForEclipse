/*
 * 104.cpp
 *
 *  Created on: 2018Äê8ÔÂ2ÈÕ
 *      Author: Administrator
 */




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
    int maxDepth(TreeNode* root) {

     int iMax=0;
        int iCurDepth =0;

        if(root == NULL)
        {
            return  iMax;
        }

        GetDepth(root ,iCurDepth ,iMax);

            return iMax;
    }

    void GetDepth(TreeNode * node ,int & curDep, int & Max)
    {
        if( node == NULL)
        {
            if( curDep > Max)
            {
                Max = curDep;
            }
            return ;
        }
        curDep +=1;

     GetDepth(node->left, curDep, Max);

        GetDepth(node->right, curDep, Max);
        curDep --;

    }
    
    
};
