
#include "iostream"
#include "BinaryTree.h"
#include <stack>
#include <deque>
#include <queue>

using namespace std;


//递归版本
void proOrder( TreeNode *root)
{
    if(root != nullptr)
    {
        cout<< root->value<<" ";
        proOrder( root->left );
        proOrder( root->right);
    }
}


void inOrder( TreeNode *root)
{
    if(root != nullptr)
    {
        proOrder( root->left );
        cout<< root->value<<" ";
        proOrder( root->right);
    }
}

void postOrder( TreeNode *root)
{
    if(root != nullptr)
    {
        proOrder( root->left );
        proOrder( root->right);
        cout<< root->value<<" ";
    }
}


/*非递归版本*/
void PreOrder_Nor(TreeNode * root)
{
    if(NULL == root)
        return;

    stack<TreeNode *> s;
    s.push(root); //先将root 入栈
    TreeNode * pTemp = NULL;

    while(!s.empty())
    {
        pTemp = s.top();
        cout<< pTemp->value << " ";
        s.pop();

        if( nullptr != pTemp->right)
            s.push(pTemp->right);

        if( nullptr  != pTemp->left)
            s.push(pTemp->left);
    }
    cout<<endl;
}



void InOrder_Nor(TreeNode *root)      //非递归中序遍历
{
    stack<TreeNode*> s;
    TreeNode * p=root;

    while(  p!=NULL || !s.empty())
    {
        while( p!=NULL)
        {
            s.push(p);
            p=p->left;
        }
        if(!s.empty())
        {
            p =s.top();
            cout<<p->value<<" ";
            s.pop();
            p=p->right;
        }
    }
}

/*https://www.cnblogs.com/SHERO-Vae/p/5800363.html*/

/*
 * 后序遍历的非递归实现是三种遍历方式中最难的一种。
 * 因为在后序遍历中，要保证左孩子和右孩子都已被访问并且左孩子在右孩子前访问才能访问根结点，
 * 这就为流程的控制带来了难题。
 * 下面介绍两种思路。

      第一种思路：对于任一结点P，将其入栈，然后沿其左子树一直往下搜索，直到搜索到没有左孩子的结点，
      此时该结点出现在栈顶，但是此时不能将其出栈并访问， 因此其右孩子还为被访问。
      所以接下来按照相同的规则对其右子树进行相同的处理，当访问完其右孩子时，该结点又出现在栈顶，此时可以将其出栈并访问。这样就 保证了正确的访问顺序。
      可以看出，在这个过程中，每个结点都两次出现在栈顶，只有在第二次出现在栈顶时，
      才能访问它。因此需要多设置一个变量标识该结点是 否是第一次出现在栈顶。
 * */
/*
void postOrder_Nor1(TreeNode *root)    //非递归后序遍历
{
    stack<TreeNode*> s;

    TreeNode *p = root;
    TreeNode *temp;
    while(p!=NULL||!s.empty())
    {
        while(p!=NULL)              //沿左子树一直往下搜索，直至出现没有左子树的结点
        {
            TreeNode *btn=(BTNode *)malloc(sizeof(BTNode));
            btn->btnode=p;
            btn->isFirst=true;
            s.push(btn);
            p=p->lchild;
        }
        if(!s.empty())
        {
            temp=s.top();
            s.pop();
            if(temp->isFirst==true)     //表示是第一次出现在栈顶
             {
                temp->isFirst=false;
                s.push(temp);
                p=temp->btnode->rchild;
            }
            else                        //第二次出现在栈顶
             {
                cout<<temp->btnode->data<<" ";
                p=NULL;
            }
        }
    }
}

 */


/*
 *
 * 第二种思路：
 *
 * 要保证根结点在左孩子和右孩子访问之后才能访问，因此对于任一结点P，先将其入栈。
 * 如果P不存在左孩子和右孩子，则可以直接访问它；或者P存 在左孩子或者右孩子，
 * 但是其左孩子和右孩子都已被访问过了，则同样可以直接访问该结点。
 * 若非上述两种情况，则将P的右孩子和左孩子依次入栈，这样就保证了 每次取栈顶元素的时候，
 * 左孩子在右孩子前面被访问，左孩子和右孩子都在根结点前面被访问。
 *
 * */
void postOrder_Nor(TreeNode *root)     //非递归后序遍历
{
    stack<TreeNode*> s;
    TreeNode *cur;                      //当前结点
    TreeNode *pre=NULL;                 //前一次访问的结点
    s.push(root);

    while(!s.empty())
    {
        cur=s.top();
        if( (cur->left== nullptr&&cur->right== nullptr)
                || ( pre!= nullptr && (pre==cur->left||pre==cur->right)))
        {
            cout<<cur->value<<" ";  //如果当前结点没有孩子结点或者孩子节点都已被访问过
            s.pop();
            pre=cur;
        }
        else
        {
            if(cur->right!= nullptr )
                s.push(cur->right);

            if(cur->left!= nullptr)
                s.push(cur->left);
        }
    }
}




/*递归法 按层 遍历*/
int Depth(const TreeNode *root)
{
    if (!root) return 0;
    int left =  Depth(root->left);
    int right = Depth(root->right);
    return 1 + ( left >right ? left: right);
}

int PrintNodeAtLevel(TreeNode*  root, int level)
{
    if(!root || level < 0)
        return 0;

    else if(level == 0)
    {
        cout << root->value<< endl;
        return 1;
    }
    else
        return PrintNodeAtLevel( root->left, level - 1) + PrintNodeAtLevel( root->right, level - 1);
}

/*https://www.cnblogs.com/kaituorensheng/p/3558645.html
 * */
// 二叉树 按照层遍历
void ListNodeByLevel(TreeNode*  root)
{
    for(int i = 0; i < Depth(root); ++i)
    {
        PrintNodeAtLevel(root, i);
        cout << "_____________________________" << endl;
    }
}



/* 将每层的数据 组织到容器中 */
void getSolution(vector<vector<int>>& ret, const TreeNode*  root, int level)
{
    if(root == NULL)
        return;

    ret[level].push_back(root->value);
    getSolution(ret,root->left,level+1);
    getSolution(ret,root->right,level+1);
}


vector<vector<int>> levelOrder(const TreeNode *root) {

    int depth = Depth(root);

    vector<vector<int>> ret(depth);

    if(depth == 0) //invalid check
        return ret;

    getSolution(ret,root,0);
    return ret;
}

void levels_showBT(const TreeNode * root){//层次遍历,利用队列实现


    if(root == nullptr )
        return;

    std::queue<TreeNode *> que;//构造一个树结点指针的队列
    que.push(root);

    while(!que.empty()){
        TreeNode *q = que.front();
        cout<<q->value<<" ";
        que.pop();

        if( q->left != nullptr)//que.front()拿到最前结点
        {
            que.push( q->left );
        }


        if( q->right != nullptr){
            que.push( q->right );
        }
    }
    cout<<endl;
}



//https://blog.csdn.net/liuyi1207164339/article/details/50898902
int MostFar(const TreeNode*pNode, int&nMaxDistance){

    if (pNode == NULL)
        return -1;   //空节点的高度为-1
    //递归

    std::cout<< pNode->value  <<std::endl;

    int nHeightOfLeftTree  = MostFar(pNode->left, nMaxDistance) + 1;   //左子树的的高度加1
    int nHeightOfRightTree = MostFar(pNode->right, nMaxDistance) + 1;   //右子树的高度加1

    int nDistance = nHeightOfLeftTree + nHeightOfRightTree;    //距离等于左子树的高度加上右子树的高度+2

    nMaxDistance = ( nMaxDistance > nDistance ? nMaxDistance : nDistance);            //得到距离的最大值

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
    MostFar( & node1, nMaxDistance);

    std::cout<< "Final result " << nMaxDistance <<std::endl;
}



/*按层遍历的时候，获取其宽度也可以 */
/* 二叉树的宽度      在上一层遍历完成后，下一层的所有节点已经放到队列中，此时队列中的元素个数就是下一层的宽度*/
/************************************************************************/
int WidthOfBinaryTree(const TreeNode * pNode){

    if (pNode == NULL)
    {
        return 0;
    }

    std::deque<TreeNode*> dequeTreeNode;//双端队列

    int maxWidth = 1;//最大的宽度,用于当只有一个节点时候返回1
    dequeTreeNode.push_back(pNode);//头结点入队

    while (true)
    {
        int length = dequeTreeNode.size();//当前层节点的个数
        if ( length == 0)//当前层没有节点，跳出循环
        {
            break;
        }


        while ( length > 0)//如果当前层还有节点
        {
            TreeNode* pTemp = dequeTreeNode.front();
            dequeTreeNode.pop_front();//出队
            length--;//长度减一
            if (pTemp->left)
            {
                dequeTreeNode.push_back(pTemp->left);//下一层节点入队
            }
            if (pTemp->right)
            {
                dequeTreeNode.push_back(pTemp->right);//下一层节点入队
            }
        }

        maxWidth = maxWidth > dequeTreeNode.size() ? maxWidth : dequeTreeNode.size();//得到最大宽度
    }
    return maxWidth;
}



void  FindPath(TreeNode * root , std::vector<int>  path , int curSum, int sum )
{

    curSum += root->value;
    path.push_back(root->value);

    bool isLeaf =( (root->left== nullptr) && ( root->right == nullptr) );
    if(isLeaf && curSum == sum )
    {

        for( auto it :path)
        {
            cout<< *it;
        }
    }

    if( root->left != nullptr)
    {
        FindPath(  root->left  , path ,curSum , sum );
    }
    if(root->right != nullptr)
    {
        FindPath( root->right , path ,curSum , sum );
    }

    curSum -= root->value;
    path.pop_back();
}


/* 遍历 ，所有路径和为 sum的二叉树的路径*/
void  FindPath(TreeNode * root , int sum)
{
    if( root == nullptr )
    {
        return ;
    }
    vector<int> path;
    int curSum =0 ;
    FindPath( root , path ,curSum , sum );
}

