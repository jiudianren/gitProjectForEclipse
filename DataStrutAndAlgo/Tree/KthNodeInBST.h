#ifndef SRC_ALG_KTHNODEINBST_H_
#define SRC_ALG_KTHNODEINBST_H_


#include "TreeNode.h"
#include <vector>

class KthNodeInBST
{
public:
	static void TestCase();
	static void FindKth(const TreeNode * pRoot = nullptr ,int iKth = 0 );
	static void inOrder( const TreeNode *root , std::vector<int> &vecNodeVal);

};




#endif 
