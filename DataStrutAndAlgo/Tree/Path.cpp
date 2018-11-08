/*
 * Paht.cpp
 *
 *  Created on: 2018��10��21��
 *      Author: Administrator
 */


/*
https://blog.csdn.net/u011185633/article/details/47207513
https://blog.csdn.net/liuyi1207164339/article/details/50916687

������ Ҷ�ӽڵ�1 ��2 ��·��

1 ��root -->1 ��·��
2 ��root -->2��·��
3 ��������·������ ���̴����ų���ͬ�ڵ㣬
*/


//Ѱ��ĳһ���ض����ӽڵ�
bool bLeafIsFound = false;//ȫ�ֱ���
void findPath(BinaryTreeNode*pRoot, vector<int>&path, int nToFind){
    if (pRoot == NULL)
    {
        return;
    }
    path.push_back(pRoot->m_nValue);
    if (!bLeafIsFound&&pRoot->m_nValue == nToFind) //�ﵽ���ӽڵ�
    {
        printPath(path);//��ӡ·��
        bLeafIsFound = true;
        return;   //�Ѿ��ҵ���
    }
    if (!bLeafIsFound&&pRoot->m_pLeft != NULL)//������
    {
        findPath(pRoot->m_pLeft, path, nToFind);
    }
    if (!bLeafIsFound&&pRoot->m_pRight != NULL)//������
    {
        findPath(pRoot->m_pRight, path, nToFind);
    }
    if (!bLeafIsFound)//�ҵ���Ͳ�������
    {
        path.pop_back();//�ڷ��ص����ڵ�֮ǰ����·����ɾ����ǰ�ڵ�
    }
}


//�ҵ������ӽڵ�֮���·��
void  findPathOfTwoNode(BinaryTreeNode*pRoot,vector<int>& path,int nNodeOne,int nNodeTw0){
    vector<int> path1;
    vector<int> path2;
    //�õ������ڵ��·��
    findPath(pRoot, path1, nNodeOne);
    bLeafIsFound = false;//ȫ�ֱ�����λ
    findPath(pRoot, path2, nNodeTw0);
    bLeafIsFound = false;//ȫ�ֱ�����λ
    //����������
    vector<int>::const_iterator iterOne=path1.begin();
    vector<int>::const_iterator iterTwo=path2.begin();
    int count=0;
    while(iterOne != path1.end() && iterTwo != path2.end())
    {
        if (*iterOne==*iterTwo)
            count++;//�õ�����
        ++iterOne;
        ++iterTwo;
    }
    //�鲢����·��
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
