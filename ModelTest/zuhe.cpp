#include<iostream>
#include<string>
#include<vector>
#include "zuhe.h"
using namespace std;


/*
 * 组合模式：
 *      1,
 *      2，
 *      3，
 *
 *
 *
 *
 *
 *
 *
 * */
//对外接口   实现组件和叶子节点的所有功能
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
    //将节点类型，是不是叶子节点和枝节点 通过该变量在 初始化列表中进行初始化
    bool isLeaf;

    virtual ~Component(){    }
};


//叶子节点，叶子节点无法扩展，实现该节点的必要功能就可以了
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
    //在add这里，屏蔽了 叶子节点与枝节点的区别
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
    Composite *p=new Composite("总经理");
    Composite *pM=new Composite("技术部门经理");
    p->add(pM);
    pM->add(new Leaf("开发人员A"));
    pM->add(new Leaf("开发人员B"));
    Composite *pS=new Composite("销售部门总经理");
    Composite * pSS=new Composite("A区域销售经理");
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
    pSS->add(new Leaf("A区域销售人员E"));
    pSS->add(new Leaf("A区域销售人员F"));
    pS->add(new Leaf("总部销售人员C"));
    pS->add(new Leaf("总部销售人员D"));
    p->dispaly(1);

    return 0;
};
