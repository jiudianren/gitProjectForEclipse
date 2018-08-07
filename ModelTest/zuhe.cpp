#include<iostream>
#include<string>
#include<vector>
#include "zuhe.h"
using namespace std;


/*
 * ���ģʽ��
 *      1,
 *      2��
 *      3��
 *
 *
 *
 *
 *
 *
 *
 * */
//����ӿ�   ʵ�������Ҷ�ӽڵ�����й���
class Component
{
public:
    string m_strName;
    Component(string strName, bool isLeaf)
    {
        this->m_strName=strName;
        this->isLeaf=isLeaf;
    }
    virtual int add(Component *com)=0;
    virtual void dispaly(int nDepth)=0;
    //���ڵ����ͣ��ǲ���Ҷ�ӽڵ��֦�ڵ� ͨ���ñ����� ��ʼ���б��н��г�ʼ��
    bool isLeaf;

    virtual ~Component(){    }
};


//Ҷ�ӽڵ㣬Ҷ�ӽڵ��޷���չ��ʵ�ָýڵ�ı�Ҫ���ܾͿ�����
class Leaf:public Component
{
public:
    Leaf(string strName):Component(strName,true) {/*this->m_strName=strName;*/}
    virtual int  add(Component *com) {cout<<"can't add leaf"<<endl; return 0; }
    virtual void dispaly(int nDepth)
    {
        string strTemp;
        for(int i=0;i<nDepth;i++)
        {
            strTemp+="-";
        }
        strTemp+=this->m_strName;
        cout<<strTemp<<endl;
    }
};


//
class Composite:public Component
{
public:
    Composite(string strName):Component(strName,false)  {}
    //��add��������� Ҷ�ӽڵ���֦�ڵ������
    virtual int add(Component *com) {m_pCom.push_back(com); return 1;}

    virtual void dispaly(int nDepth)
    {
        string strTemp;
        for(int i=0;i<nDepth;i++)
        {
            strTemp+="-";
        }
        strTemp+=this->m_strName;
        cout<<strTemp<<endl;
        vector<Component*>::iterator it=m_pCom.begin();
        while(it!=m_pCom.end())
        {
            (*it)->dispaly(nDepth+2);
            ++it;
        }
    }
private:
    vector<Component*> m_pCom;
};


int mainZuHe()
{
    Composite *p=new Composite("�ܾ���");
    Composite *pM=new Composite("�������ž���");
    p->add(pM);
    pM->add(new Leaf("������ԱA"));
    pM->add(new Leaf("������ԱB"));
    Composite *pS=new Composite("���۲����ܾ���");
    Composite * pSS=new Composite("A�������۾���");
    if(p->isLeaf)
    {
       cout<<"p is  LEAF"<<endl;
    }
    else
    {
        cout<<"p is NOT LEAF"<<endl;
    }
    p->add(pS);
    pS->add(pSS);
    pSS->add(new Leaf("A����������ԱE"));
    pSS->add(new Leaf("A����������ԱF"));
    pS->add(new Leaf("�ܲ�������ԱC"));
    pS->add(new Leaf("�ܲ�������ԱD"));
    p->dispaly(1);

    return 0;
};
