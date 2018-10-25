/*
 * MostFar.cpp
 *
 *  Created on: 2018��10��25��
 *      Author: Administrator
 */



/*
 *
 * https://blog.csdn.net/liuyi1207164339/article/details/50898902
 *
 *
 *������ϵ�С����������������루�������Զ������Ҷ�ӽڵ㣬���֮�����ٶ������⣩
 * */



#include <stdio.h>
#include <iostream>
#include "MostFar.h"

int DepthOfBinaryTree(TreeNode*pNode){
    if (pNode==NULL)
    {
        return 0;
    }
    else{  //�ݹ�
        return DepthOfBinaryTree(pNode->left) > DepthOfBinaryTree(pNode->right) ?
               DepthOfBinaryTree(pNode->left) + 1 : DepthOfBinaryTree(pNode->right) + 1;
    }
}


int HeightOfBinaryTree(TreeNode*pNode, int&nMaxDistance){
    if (pNode == NULL)
        return -1;   //�սڵ�ĸ߶�Ϊ-1
    //�ݹ�

    std::cout<< pNode->value  <<std::endl;

    int nHeightOfLeftTree = HeightOfBinaryTree(pNode->left, nMaxDistance) + 1;   //�������ĵĸ߶ȼ�1
    int nHeightOfRightTree = HeightOfBinaryTree(pNode->right, nMaxDistance) + 1;   //�������ĸ߶ȼ�1
    int nDistance = nHeightOfLeftTree + nHeightOfRightTree;    //��������������ĸ߶ȼ����������ĸ߶�+2
    nMaxDistance = nMaxDistance > nDistance ? nMaxDistance : nDistance;            //�õ���������ֵ

    int result =  nHeightOfLeftTree > nHeightOfRightTree ? nHeightOfLeftTree : nHeightOfRightTree;
    std::cout<< "result " << result <<std::endl;
    return result;
}


/*
        1
     2     3
    4  *   5  6
   *  7  *  * * 8

*/

void  TestMax()
{

    std::cout<<"TestMax start " <<std::endl;
    TreeNode node7(7);
    TreeNode node4(4);
    node4.right = &node7;

    TreeNode node2(2);
    node2.left = & node4;

    TreeNode node8(8);
    TreeNode node6(6);
    node6.right = & node8;


    TreeNode node5(5);
    TreeNode node3(3);
    node3.right = & node6;
    node3.left = & node5;

    TreeNode node1(1);
    node1.right = & node3;
    node1.left = & node2;

    int nMaxDistance =0 ;
     HeightOfBinaryTree( & node1, nMaxDistance);

     std::cout<< "Final result " << nMaxDistance <<std::endl;
}
