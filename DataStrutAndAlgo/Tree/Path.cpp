/*
 * Paht.cpp
 *
 *  Created on: 2018年10月21日
 *      Author: Administrator
 */


/*
https://blog.csdn.net/u011185633/article/details/47207513
https://blog.csdn.net/liuyi1207164339/article/details/50916687

比如求 叶子节点1 ，2 的路径

1 求root -->1 的路径
2 求root -->2的路径
3 对这两条路径进行 进程处理，排除相同节点，
*/


//寻找某一个特定的子节点
bool bLeafIsFound = false;//全局变量
void findPath(BinaryTreeNode*pRoot, vector<int>&path, int nToFind){
    if (pRoot == NULL)
    {
        return;
    }
    path.push_back(pRoot->m_nValue);
    if (!bLeafIsFound&&pRoot->m_nValue == nToFind) //达到了子节点
    {
        printPath(path);//打印路径
        bLeafIsFound = true;
        return;   //已经找到了
    }
    if (!bLeafIsFound&&pRoot->m_pLeft != NULL)//左子树
    {
        findPath(pRoot->m_pLeft, path, nToFind);
    }
    if (!bLeafIsFound&&pRoot->m_pRight != NULL)//右子树
    {
        findPath(pRoot->m_pRight, path, nToFind);
    }
    if (!bLeafIsFound)//找到后就不弹出了
    {
        path.pop_back();//在返回到父节点之前，在路径上删除当前节点
    }
}


//找到两个子节点之间的路径
void  findPathOfTwoNode(BinaryTreeNode*pRoot,vector<int>& path,int nNodeOne,int nNodeTw0){
    vector<int> path1;
    vector<int> path2;
    //得到两个节点的路径
    findPath(pRoot, path1, nNodeOne);
    bLeafIsFound = false;//全局变量复位
    findPath(pRoot, path2, nNodeTw0);
    bLeafIsFound = false;//全局变量复位
    //常量迭代器
    vector<int>::const_iterator iterOne=path1.begin();
    vector<int>::const_iterator iterTwo=path2.begin();
    int count=0;
    while(iterOne != path1.end() && iterTwo != path2.end())
    {
        if (*iterOne==*iterTwo)
            count++;//得到交点
        ++iterOne;
        ++iterTwo;
    }
    //归并两条路径
    for (int i = path1.size() - 1; i >= 0;i--)
    {
        if (i> count-2)
        {
            path.push_back(path1[i]);
        }
    }
    for (int i =0; i < path2.size(); i++)
    {
        if (i > count-1)
        {
            path.push_back(path2[i]);
        }
    }
}
