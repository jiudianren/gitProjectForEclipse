
#include "iostream"
#include "BinaryTree.h"
#include <stack>
#include <deque>
#include <queue>

using namespace std;


//�ݹ�汾
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


/*�ǵݹ�汾*/
void PreOrder_Nor(TreeNode * root)
{
    if(NULL == root)
        return;

    stack<TreeNode *> s;
    s.push(root); //�Ƚ�root ��ջ
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



void InOrder_Nor(TreeNode *root)      //�ǵݹ��������
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
 * ��������ķǵݹ�ʵ�������ֱ�����ʽ�����ѵ�һ�֡�
 * ��Ϊ�ں�������У�Ҫ��֤���Ӻ��Һ��Ӷ��ѱ����ʲ����������Һ���ǰ���ʲ��ܷ��ʸ���㣬
 * ���Ϊ���̵Ŀ��ƴ��������⡣
 * �����������˼·��

      ��һ��˼·��������һ���P��������ջ��Ȼ������������һֱ����������ֱ��������û�����ӵĽ�㣬
      ��ʱ�ý�������ջ�������Ǵ�ʱ���ܽ����ջ�����ʣ� ������Һ��ӻ�Ϊ�����ʡ�
      ���Խ�����������ͬ�Ĺ������������������ͬ�Ĵ��������������Һ���ʱ���ý���ֳ�����ջ������ʱ���Խ����ջ�����ʡ������� ��֤����ȷ�ķ���˳��
      ���Կ���������������У�ÿ����㶼���γ�����ջ����ֻ���ڵڶ��γ�����ջ��ʱ��
      ���ܷ������������Ҫ������һ��������ʶ�ý���� ���ǵ�һ�γ�����ջ����
 * */
/*
void postOrder_Nor1(TreeNode *root)    //�ǵݹ�������
{
    stack<TreeNode*> s;

    TreeNode *p = root;
    TreeNode *temp;
    while(p!=NULL||!s.empty())
    {
        while(p!=NULL)              //��������һֱ����������ֱ������û���������Ľ��
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
            if(temp->isFirst==true)     //��ʾ�ǵ�һ�γ�����ջ��
             {
                temp->isFirst=false;
                s.push(temp);
                p=temp->btnode->rchild;
            }
            else                        //�ڶ��γ�����ջ��
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
 * �ڶ���˼·��
 *
 * Ҫ��֤����������Ӻ��Һ��ӷ���֮����ܷ��ʣ���˶�����һ���P���Ƚ�����ջ��
 * ���P���������Ӻ��Һ��ӣ������ֱ�ӷ�����������P�� �����ӻ����Һ��ӣ�
 * ���������Ӻ��Һ��Ӷ��ѱ����ʹ��ˣ���ͬ������ֱ�ӷ��ʸý�㡣
 * �������������������P���Һ��Ӻ�����������ջ�������ͱ�֤�� ÿ��ȡջ��Ԫ�ص�ʱ��
 * �������Һ���ǰ�汻���ʣ����Ӻ��Һ��Ӷ��ڸ����ǰ�汻���ʡ�
 *
 * */
void postOrder_Nor(TreeNode *root)     //�ǵݹ�������
{
    stack<TreeNode*> s;
    TreeNode *cur;                      //��ǰ���
    TreeNode *pre=NULL;                 //ǰһ�η��ʵĽ��
    s.push(root);

    while(!s.empty())
    {
        cur=s.top();
        if( (cur->left== nullptr&&cur->right== nullptr)
                || ( pre!= nullptr && (pre==cur->left||pre==cur->right)))
        {
            cout<<cur->value<<" ";  //�����ǰ���û�к��ӽ����ߺ��ӽڵ㶼�ѱ����ʹ�
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




/*�ݹ鷨 ���� ����*/
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
// ������ ���ղ����
void ListNodeByLevel(TreeNode*  root)
{
    for(int i = 0; i < Depth(root); ++i)
    {
        PrintNodeAtLevel(root, i);
        cout << "_____________________________" << endl;
    }
}



/* ��ÿ������� ��֯�������� */
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

void levels_showBT(const TreeNode * root){//��α���,���ö���ʵ��


    if(root == nullptr )
        return;

    std::queue<TreeNode *> que;//����һ�������ָ��Ķ���
    que.push(root);

    while(!que.empty()){
        TreeNode *q = que.front();
        cout<<q->value<<" ";
        que.pop();

        if( q->left != nullptr)//que.front()�õ���ǰ���
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
        return -1;   //�սڵ�ĸ߶�Ϊ-1
    //�ݹ�

    std::cout<< pNode->value  <<std::endl;

    int nHeightOfLeftTree  = MostFar(pNode->left, nMaxDistance) + 1;   //�������ĵĸ߶ȼ�1
    int nHeightOfRightTree = MostFar(pNode->right, nMaxDistance) + 1;   //�������ĸ߶ȼ�1

    int nDistance = nHeightOfLeftTree + nHeightOfRightTree;    //��������������ĸ߶ȼ����������ĸ߶�+2

    nMaxDistance = ( nMaxDistance > nDistance ? nMaxDistance : nDistance);            //�õ���������ֵ

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



/*���������ʱ�򣬻�ȡ����Ҳ���� */
/* �������Ŀ��      ����һ�������ɺ���һ������нڵ��Ѿ��ŵ������У���ʱ�����е�Ԫ�ظ���������һ��Ŀ��*/
/************************************************************************/
int WidthOfBinaryTree(const TreeNode * pNode){

    if (pNode == NULL)
    {
        return 0;
    }

    std::deque<TreeNode*> dequeTreeNode;//˫�˶���

    int maxWidth = 1;//���Ŀ��,���ڵ�ֻ��һ���ڵ�ʱ�򷵻�1
    dequeTreeNode.push_back(pNode);//ͷ������

    while (true)
    {
        int length = dequeTreeNode.size();//��ǰ��ڵ�ĸ���
        if ( length == 0)//��ǰ��û�нڵ㣬����ѭ��
        {
            break;
        }


        while ( length > 0)//�����ǰ�㻹�нڵ�
        {
            TreeNode* pTemp = dequeTreeNode.front();
            dequeTreeNode.pop_front();//����
            length--;//���ȼ�һ
            if (pTemp->left)
            {
                dequeTreeNode.push_back(pTemp->left);//��һ��ڵ����
            }
            if (pTemp->right)
            {
                dequeTreeNode.push_back(pTemp->right);//��һ��ڵ����
            }
        }

        maxWidth = maxWidth > dequeTreeNode.size() ? maxWidth : dequeTreeNode.size();//�õ������
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


/* ���� ������·����Ϊ sum�Ķ�������·��*/
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

