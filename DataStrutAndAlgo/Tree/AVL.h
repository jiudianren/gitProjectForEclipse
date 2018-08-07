/*
 * AVL.h
 *
 *  Created on: 2018年6月3日
 *      Author: Administrator
 */

/*
 *
 *
 *https://www.cnblogs.com/QG-whz/p/5167238.html
 *https://www.cnblogs.com/sun-haiyu/p/7704654.html
 * 平衡二叉树(AVL
 *
 *https://www.cnblogs.com/sun-haiyu/p/7704654.html
 *
 *在bst的基础上，对左右字数的高度做了限制
 *
 * 平衡二叉树，首先是一棵二叉查找树，但是它满足一点重要的特性：
 * 每一个结点的左子树和右子树的高度差最多为1。
 * 这个高度差限制就完全规避了上述的最坏情况，因此查找、插入和删除的时间复杂度都变成了O(lg n)。
 *[维基百科]：在计算机科学中，AVL树是最先发明的自平衡二叉查找树。
在AVL树中任何节点的两个子树的高度最大差别为一，所以它也被称为高度平衡树。查找、插入和删除在平均和最坏情况下都是O(log n)。
增加和删除可能需要通过一次或多次树旋转来重新平衡这个树。AVL树得名于它的发明者G.M. Adelson-Velsky和E.M. Landis。
 *
 平衡二叉树定义(AVL)：它或者是一颗空树，
 或者具有以下性质的二叉树：它的左子树和右子树的深度之差(平衡因子)的绝对值不超过1，且它的左子树和右子树都是一颗平衡二叉树。
平衡因子(bf)：结点的左子树的深度减去右子树的深度，那么显然-1<=bf<=1,这里我们定义:


图解 左右旋
https://blog.csdn.net/collonn/article/details/20128205


何时需要左旋，何时需要右旋


插入的话就是以下四种情况

在根结点的左孩子的左子树上插入，对根结点进行右旋转。调用rotateRight
在根结点的右孩子的右子树上插入，对根结点进行左旋转。调用rotateLeft
在根结点的左孩子的右子树上插入，先对根结点的左孩子进行左旋转，再对根结点进行右旋转。调用rotateLeft(h.left);rotateRight(h);
在根结点的右孩子的左子树上插入，先对根结点的右孩子进行右旋转，再对根结点进行左旋转。调用rotateRight(h.right);rotateLeft(h);
插入之后还要调整每个结点的平衡因子，看起来比较麻烦，代码量不小。删除操作也是比较麻烦。
由于我们的重点在于讲解红黑树，平衡查找树只是抛砖引玉。所以对于平衡二叉树的介绍就到此为止。
#define EH 0,#define LH 1,#define RH -1.依次为等高，左高，右高。
 *
 *
 https://www.cnblogs.com/QG-whz/p/5167238.html

 */




template<typename T> class  AVLTreeNode
{
    AVLTreeNode(T value, AVLTreeNode<T>*l, AVLTreeNode<T>*r)
    :key(value), lchild(l), rchild(r),height(0){}

    T key;
    int height;
    AVLTreeNode<T>* lchild;
    AVLTreeNode<T>* rchild;
};


template<typename T>
class AVLTree
{
public:
    AVLTree();            //构造函数
    ~AVLTree();            //析构函数

    void preOrder();    //前序遍历AVL树
    void InOrder();        //中序遍历AVL树
    void postOrder();    //后序遍历AVL树

    void print();        //打印AVL树
    void destory();        //销毁AVL树

    void insert(T key);    //插入指定值的节点
    void remove(T key);    //移除指定值的节点

    AVLTreeNode<T>* search_recurse(T key);    //利用递归算法进行指定值的查找
    AVLTreeNode<T>* search_iterator(T key);    //利用迭代算法进行指定值的查找
    T minimum();        //返回AVL中的最小值
    T maximum();        //返回AVL中的最大值

    int height()   //返回树的高度
    {
        return height(root);
    };

private:
    AVLTreeNode<T>* root;    //AVL树的根节点

private:
    void preOrder(AVLTreeNode<T>* pnode) const;
    void inOrder(AVLTreeNode<T>* pnode) const;
    void postOrder(AVLTreeNode<T>* pnode) const;

    void print(AVLTreeNode<T>* pnode,T key, int direction) const;
    void destory(AVLTreeNode<T>* & pnode);

    AVLTreeNode<T>* insert(AVLTreeNode<T>* &pnode, T key)
                    {

        if (pnode == nullptr)    //寻找到插入的位置
        {
            pnode = new AVLTreeNode<T>(key, nullptr, nullptr);
        }
        else if (key > pnode->key)    //插入值比当前结点值大，插入到当前结点的右子树上
        {
            pnode->rchild = insert(pnode->rchild, key);
            if (height(pnode->rchild) - height(pnode->lchild) == 2) //插入后出现失衡
            {
                if (key > pnode->rchild->key) //情况一：插入右子树的右节点，进行左旋
                    pnode=leftRotation(pnode);
                else if (key < pnode->rchild->key)  //情况三：插入右子树的左节点,进行先右再左旋转
                    pnode=rightLeftRotation(pnode);
            }
        }
        else if (key < pnode->key) //插入值比当前节点值小，插入到当前结点的左子树上
        {
            pnode->lchild = insert(pnode->lchild, key);
            if (height(pnode->lchild) - height(pnode->rchild) == 2) //如果插入导致失衡
            {
                if (key < pnode->lchild->key)        //情况二：插入到左子树的左孩子节点上，进行右旋
                    pnode = rightRotation(pnode);
                else if (key>pnode->lchild->key)
                    pnode = leftRightRotation(pnode);//情况四：插入到左子树的右孩子节点上，进行先左后右旋转
            }
        }
        pnode->height = max(height(pnode->lchild), height(pnode->rchild)) + 1;
        return pnode;
                    };
    AVLTreeNode<T>* remove(AVLTreeNode<T>* & pnode, AVLTreeNode<T>* pdel);
    AVLTreeNode<T>* remove(AVLTreeNode<T>* & pnode, T key){


        if (pnode != nullptr)
        {
            if (key == pnode->key)            //找到删除的节点
            {
                //因AVL也是二叉排序树，删除节点要维护其二叉排序树的条件
                if (pnode->lchild != nullptr&&pnode->rchild != nullptr)        //若左右都不为空
                {
                    // 左子树比右子树高,在左子树上选择节点进行替换
                    if (height(pnode->lchild) > height(pnode->rchild))
                    {
                        //使用左子树最大节点来代替被删节点，而删除该最大节点
                        AVLTreeNode<T>* ppre = maximum(pnode->lchild);        //左子树最大节点
                        pnode->key = ppre->key;                                //将最大节点的值覆盖当前结点
                        pnode->lchild = remove(pnode->lchild, ppre->key);    //递归地删除最大节点
                    }
                    else  //在右子树上选择节点进行替换
                    {
                        //使用最小节点来代替被删节点，而删除该最小节点
                        AVLTreeNode<T>* psuc = minimum(pnode->rchild);        //右子树的最小节点
                        pnode->key = psuc->key;                                //将最小节点值覆盖当前结点
                        pnode->rchild = remove(pnode->rchild, psuc->key);    //递归地删除最小节点
                    }

                }
                else
                {
                    AVLTreeNode<T> * ptemp = pnode;
                    if (pnode->lchild != nullptr)
                        pnode = pnode->lchild;
                    else if (pnode->rchild != nullptr)
                        pnode = pnode->rchild;
                    delete ptemp;
                    return nullptr;
                }

            }
            else if (key > pnode->key)//要删除的节点比当前节点大，则在右子树进行删除
            {
                pnode->rchild =  remove(pnode->rchild, key);
                //删除右子树节点导致不平衡:相当于情况二或情况四
                if (height(pnode->lchild) - height(pnode->rchild) == 2)
                {
                    //相当于在左子树上插入右节点造成的失衡（情况四）
                    if (height(pnode->lchild->rchild)>height(pnode->lchild->lchild))
                        pnode = leftRightRotation(pnode);
                    else//相当于在左子树上插入左节点造成的失衡（情况二）
                        pnode = rightRotation(pnode);
                }
            }
            else if (key < pnode->key)//要删除的节点比当前节点小，则在左子树进行删除
            {
                pnode->lchild= remove(pnode->lchild, key);
                //删除左子树节点导致不平衡：相当于情况三或情况一
                if (height(pnode->rchild) - height(pnode->lchild) == 2)
                {
                    //相当于在右子树上插入左节点造成的失衡（情况三）
                    if (height(pnode->rchild->lchild)>height(pnode->rchild->rchild))
                        pnode = rightLeftRotation(pnode);
                    else//相当于在右子树上插入右节点造成的失衡（情况一）
                        pnode = leftRotation(pnode);
                }
            }
            return pnode;
        }
        return nullptr;
    };

    AVLTreeNode<T>* minimum(AVLTreeNode<T>*pnode)const;
    AVLTreeNode<T>* maximum(AVLTreeNode<T>*pnode)const;

    AVLTreeNode<T>* search_recurse(AVLTreeNode<T>* pnode, T key) const;
    AVLTreeNode<T>* search_iterator(AVLTreeNode<T>* pnode, T key) const;

    AVLTreeNode<T>* leftRotation(AVLTreeNode<T>* proot) 	{      //单旋:左旋操作
        /*左旋转操作*/
        /*pnode为最小失衡子树的根节点*/
        /*返回旋转后的根节点*/
        AVLTreeNode<T>* prchild = proot->rchild;
        proot->rchild = prchild->lchild;
        prchild->lchild = proot;

        proot->height = max(height(proot->lchild),height(proot->rchild))+1;     //更新节点的高度值
        prchild->height = max(height(prchild->lchild), height(prchild->rchild)) + 1; //更新节点的高度值

        return prchild;
    };
    AVLTreeNode<T>* rightRotation(AVLTreeNode<T>* proot){       //单旋:右旋操作

        AVLTreeNode<T>* plchild = proot->lchild;
        proot->lchild = plchild->rchild;
        plchild->rchild = proot;

        proot->height = max(height(proot->lchild), height(proot->rchild)) + 1;     //更新节点的高度值
        plchild->height = max(height(plchild->lchild), height(plchild->rchild)) + 1; //更新节点的高度值

        return plchild;
    };
    AVLTreeNode<T>* leftRightRotation(AVLTreeNode<T>* proot);    //双旋:先左旋后右旋操作
    AVLTreeNode<T>* rightLeftRotation(AVLTreeNode<T>* proot)
																			                {

        proot->rchild = rightRotation(proot->rchild);
        return leftRotation(proot);
																			                };    //双旋:先右旋后左旋操作


    int height(AVLTreeNode<T>* pnode)
    {
        if (pnode != nullptr)
        {
            return pnode->height;
        }
        return 0;                                                                //如果是空树，高度为0
    };


};
