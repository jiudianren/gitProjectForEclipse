
#include <iostream>
#include "KthNodeInBST.h"

using namespace  std;

void KthNodeInBST::TestCase()
{

	/*      10
	 *   5     11
	 *  3  6  9   12
 	 * */

	TreeNode tRoot(10);
	TreeNode tLOneLeft(5);
	TreeNode tLOneRight(11);

	tRoot.left = &tLOneLeft;
	tRoot.right = &tLOneRight;



	TreeNode tLTwoLLeft(3);
	TreeNode tLTwoLRight(6);
	tLOneLeft.left = &tLTwoLLeft;
	tLOneLeft.right = &tLTwoLRight;

	TreeNode tLTwoRLeft(9);
	TreeNode tLTwoRRight(12);
	tLOneRight.left = &tLTwoRLeft;
	tLOneRight.right = &tLTwoRRight;

	FindKth( &tRoot, 3);
}

void KthNodeInBST::FindKth(const TreeNode * pRoot, int iKth)
{
	if( pRoot == nullptr)
	{
		cout << "Fail" <<std::endl;
		return;
	}

	std::vector<int> vecNodeVal;
	inOrder(pRoot, vecNodeVal);

	for(auto it: vecNodeVal)
	{
		cout<< it << ",";
	}

	std::cout<< std::endl;

	if(vecNodeVal.size() > iKth)
	{
		cout << "Sucess, the " << iKth <<"th is " << vecNodeVal[iKth-1];
		return;
	}
	else
	{
		cout << "Fail" <<std::endl;
		return;
	}

}

void KthNodeInBST::inOrder( const TreeNode *root , std::vector<int> & vecNodeVal)
{
	if( root != nullptr)
	{
		inOrder( root->left , vecNodeVal);
		vecNodeVal.push_back(root->value);
		inOrder( root->right , vecNodeVal);
	}
}
