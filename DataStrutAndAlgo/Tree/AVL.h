/*
 * AVL.h
 *
 *  Created on: 2018��6��3��
 *      Author: Administrator
 */

/*
 *
 *
 *https://www.cnblogs.com/QG-whz/p/5167238.html
 *https://www.cnblogs.com/sun-haiyu/p/7704654.html
 * ƽ�������(AVL
 *
 *https://www.cnblogs.com/sun-haiyu/p/7704654.html
 *
 *��bst�Ļ����ϣ������������ĸ߶���������
 *
 * ƽ���������������һ�ö��������������������һ����Ҫ�����ԣ�
 * ÿһ���������������������ĸ߶Ȳ����Ϊ1��
 * ����߶Ȳ����ƾ���ȫ�������������������˲��ҡ������ɾ����ʱ�临�Ӷȶ������O(lg n)��
 *[ά���ٿ�]���ڼ������ѧ�У�AVL�������ȷ�������ƽ������������
��AVL�����κνڵ�����������ĸ߶������Ϊһ��������Ҳ����Ϊ�߶�ƽ���������ҡ������ɾ����ƽ���������¶���O(log n)��
���Ӻ�ɾ��������Ҫͨ��һ�λ�������ת������ƽ���������AVL�����������ķ�����G.M. Adelson-Velsky��E.M. Landis��
 *
 ƽ�����������(AVL)����������һ�ſ�����
 ���߾����������ʵĶ������������������������������֮��(ƽ������)�ľ���ֵ������1��������������������������һ��ƽ���������
ƽ������(bf)����������������ȼ�ȥ����������ȣ���ô��Ȼ-1<=bf<=1,�������Ƕ���:


ͼ�� ������
https://blog.csdn.net/collonn/article/details/20128205


��ʱ��Ҫ��������ʱ��Ҫ����


����Ļ����������������

�ڸ��������ӵ��������ϲ��룬�Ը�����������ת������rotateRight
�ڸ������Һ��ӵ��������ϲ��룬�Ը�����������ת������rotateLeft
�ڸ��������ӵ��������ϲ��룬�ȶԸ��������ӽ�������ת���ٶԸ�����������ת������rotateLeft(h.left);rotateRight(h);
�ڸ������Һ��ӵ��������ϲ��룬�ȶԸ������Һ��ӽ�������ת���ٶԸ�����������ת������rotateRight(h.right);rotateLeft(h);
����֮��Ҫ����ÿ������ƽ�����ӣ��������Ƚ��鷳����������С��ɾ������Ҳ�ǱȽ��鷳��
�������ǵ��ص����ڽ���������ƽ�������ֻ����ש�������Զ���ƽ��������Ľ��ܾ͵���Ϊֹ��
#define EH 0,#define LH 1,#define RH -1.����Ϊ�ȸߣ���ߣ��Ҹߡ�
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
    AVLTree();            //���캯��
    ~AVLTree();            //��������

    void preOrder();    //ǰ�����AVL��
    void InOrder();        //�������AVL��
    void postOrder();    //�������AVL��

    void print();        //��ӡAVL��
    void destory();        //����AVL��

    void insert(T key);    //����ָ��ֵ�Ľڵ�
    void remove(T key);    //�Ƴ�ָ��ֵ�Ľڵ�

    AVLTreeNode<T>* search_recurse(T key);    //���õݹ��㷨����ָ��ֵ�Ĳ���
    AVLTreeNode<T>* search_iterator(T key);    //���õ����㷨����ָ��ֵ�Ĳ���
    T minimum();        //����AVL�е���Сֵ
    T maximum();        //����AVL�е����ֵ

    int height()   //�������ĸ߶�
    {
        return height(root);
    };

private:
    AVLTreeNode<T>* root;    //AVL���ĸ��ڵ�

private:
    void preOrder(AVLTreeNode<T>* pnode) const;
    void inOrder(AVLTreeNode<T>* pnode) const;
    void postOrder(AVLTreeNode<T>* pnode) const;

    void print(AVLTreeNode<T>* pnode,T key, int direction) const;
    void destory(AVLTreeNode<T>* & pnode);

    AVLTreeNode<T>* insert(AVLTreeNode<T>* &pnode, T key)
                    {

        if (pnode == nullptr)    //Ѱ�ҵ������λ��
        {
            pnode = new AVLTreeNode<T>(key, nullptr, nullptr);
        }
        else if (key > pnode->key)    //����ֵ�ȵ�ǰ���ֵ�󣬲��뵽��ǰ������������
        {
            pnode->rchild = insert(pnode->rchild, key);
            if (height(pnode->rchild) - height(pnode->lchild) == 2) //��������ʧ��
            {
                if (key > pnode->rchild->key) //���һ���������������ҽڵ㣬��������
                    pnode=leftRotation(pnode);
                else if (key < pnode->rchild->key)  //���������������������ڵ�,��������������ת
                    pnode=rightLeftRotation(pnode);
            }
        }
        else if (key < pnode->key) //����ֵ�ȵ�ǰ�ڵ�ֵС�����뵽��ǰ������������
        {
            pnode->lchild = insert(pnode->lchild, key);
            if (height(pnode->lchild) - height(pnode->rchild) == 2) //������뵼��ʧ��
            {
                if (key < pnode->lchild->key)        //����������뵽�����������ӽڵ��ϣ���������
                    pnode = rightRotation(pnode);
                else if (key>pnode->lchild->key)
                    pnode = leftRightRotation(pnode);//����ģ����뵽���������Һ��ӽڵ��ϣ��������������ת
            }
        }
        pnode->height = max(height(pnode->lchild), height(pnode->rchild)) + 1;
        return pnode;
                    };
    AVLTreeNode<T>* remove(AVLTreeNode<T>* & pnode, AVLTreeNode<T>* pdel);
    AVLTreeNode<T>* remove(AVLTreeNode<T>* & pnode, T key){


        if (pnode != nullptr)
        {
            if (key == pnode->key)            //�ҵ�ɾ���Ľڵ�
            {
                //��AVLҲ�Ƕ�����������ɾ���ڵ�Ҫά�������������������
                if (pnode->lchild != nullptr&&pnode->rchild != nullptr)        //�����Ҷ���Ϊ��
                {
                    // ����������������,����������ѡ��ڵ�����滻
                    if (height(pnode->lchild) > height(pnode->rchild))
                    {
                        //ʹ�����������ڵ������汻ɾ�ڵ㣬��ɾ�������ڵ�
                        AVLTreeNode<T>* ppre = maximum(pnode->lchild);        //���������ڵ�
                        pnode->key = ppre->key;                                //�����ڵ��ֵ���ǵ�ǰ���
                        pnode->lchild = remove(pnode->lchild, ppre->key);    //�ݹ��ɾ�����ڵ�
                    }
                    else  //����������ѡ��ڵ�����滻
                    {
                        //ʹ����С�ڵ������汻ɾ�ڵ㣬��ɾ������С�ڵ�
                        AVLTreeNode<T>* psuc = minimum(pnode->rchild);        //����������С�ڵ�
                        pnode->key = psuc->key;                                //����С�ڵ�ֵ���ǵ�ǰ���
                        pnode->rchild = remove(pnode->rchild, psuc->key);    //�ݹ��ɾ����С�ڵ�
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
            else if (key > pnode->key)//Ҫɾ���Ľڵ�ȵ�ǰ�ڵ����������������ɾ��
            {
                pnode->rchild =  remove(pnode->rchild, key);
                //ɾ���������ڵ㵼�²�ƽ��:�൱��������������
                if (height(pnode->lchild) - height(pnode->rchild) == 2)
                {
                    //�൱�����������ϲ����ҽڵ���ɵ�ʧ�⣨����ģ�
                    if (height(pnode->lchild->rchild)>height(pnode->lchild->lchild))
                        pnode = leftRightRotation(pnode);
                    else//�൱�����������ϲ�����ڵ���ɵ�ʧ�⣨�������
                        pnode = rightRotation(pnode);
                }
            }
            else if (key < pnode->key)//Ҫɾ���Ľڵ�ȵ�ǰ�ڵ�С����������������ɾ��
            {
                pnode->lchild= remove(pnode->lchild, key);
                //ɾ���������ڵ㵼�²�ƽ�⣺�൱������������һ
                if (height(pnode->rchild) - height(pnode->lchild) == 2)
                {
                    //�൱�����������ϲ�����ڵ���ɵ�ʧ�⣨�������
                    if (height(pnode->rchild->lchild)>height(pnode->rchild->rchild))
                        pnode = rightLeftRotation(pnode);
                    else//�൱�����������ϲ����ҽڵ���ɵ�ʧ�⣨���һ��
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

    AVLTreeNode<T>* leftRotation(AVLTreeNode<T>* proot) 	{      //����:��������
        /*����ת����*/
        /*pnodeΪ��Сʧ�������ĸ��ڵ�*/
        /*������ת��ĸ��ڵ�*/
        AVLTreeNode<T>* prchild = proot->rchild;
        proot->rchild = prchild->lchild;
        prchild->lchild = proot;

        proot->height = max(height(proot->lchild),height(proot->rchild))+1;     //���½ڵ�ĸ߶�ֵ
        prchild->height = max(height(prchild->lchild), height(prchild->rchild)) + 1; //���½ڵ�ĸ߶�ֵ

        return prchild;
    };
    AVLTreeNode<T>* rightRotation(AVLTreeNode<T>* proot){       //����:��������

        AVLTreeNode<T>* plchild = proot->lchild;
        proot->lchild = plchild->rchild;
        plchild->rchild = proot;

        proot->height = max(height(proot->lchild), height(proot->rchild)) + 1;     //���½ڵ�ĸ߶�ֵ
        plchild->height = max(height(plchild->lchild), height(plchild->rchild)) + 1; //���½ڵ�ĸ߶�ֵ

        return plchild;
    };
    AVLTreeNode<T>* leftRightRotation(AVLTreeNode<T>* proot);    //˫��:����������������
    AVLTreeNode<T>* rightLeftRotation(AVLTreeNode<T>* proot)
																			                {

        proot->rchild = rightRotation(proot->rchild);
        return leftRotation(proot);
																			                };    //˫��:����������������


    int height(AVLTreeNode<T>* pnode)
    {
        if (pnode != nullptr)
        {
            return pnode->height;
        }
        return 0;                                                                //����ǿ������߶�Ϊ0
    };


};
