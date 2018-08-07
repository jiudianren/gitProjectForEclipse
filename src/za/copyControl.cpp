
#include <iostream>
#include "copyControl.h"
using namespace std;


class innerclass
{
public :
    innerclass():a(0)
    {
        cout<<"initiasl in"<<endl;
    };
    innerclass(const  innerclass  & ic){
        cout<<"this is copy intiasll"<<endl;
        a=ic.a;
    }

    innerclass & operator=(const innerclass & c)
    {
        cout<<"this is operator="<<endl;
        a=c.a;
        return *this;
    };
private:
    int a;
};
class outclass
{
public :
    int b;
    innerclass c;
    outclass(innerclass d):b(0),c(d){};
    outclass():b(0),c(){};
};

class Integerr
{
public:
    Integerr():m_val(0)
{
        cout<<"Integerr default Constructor"<<endl;
};

    Integerr(const Integerr& arg)
    {
        this->m_val=arg.m_val;
        cout<<"Integerr Copy Constructor"<<endl;
    };

    Integerr(int i):m_val(i)
    {
        cout<<"Integerr Constructor"<<endl;
    };

    Integerr& operator=(const Integerr& arg)
    {
        cout<<"Assignment operator function"<<endl;
        this->m_val=arg.m_val;
        return *this;
    };

    ~Integerr(){};
    int GetVal(){  return m_val; };
private:
    int m_val;
};

//返回局部对象 有问题
Integerr testFunc(Integerr inter)
{
    inter.GetVal();
    cout<<"before return"<<endl;
    return inter;
}
void  mainInter()
{
    Integerr inter(5);//Constructor
    Integerr resutl;  //default constructor
    resutl =  testFunc(2);//Constructor,then Copy Constructor,then Assignment operator
    cout<<resutl.GetVal()<<endl;
    //    getchar();
}

void mainCpyCtrl() {

    mainInter();

    cout<<"aaaa"<<endl;
    outclass oc= outclass();//默认构造函数，这里是初始化

    cout<<"dddd"<<endl;
    innerclass ib;

    cout<<"eee"<<endl;
    //	innerclass id= innerclass();
    innerclass ic(ib);

    cout<<"fff"<<endl;
    //	innerclass ie=ib;

    cout<<"bbbB"<<endl;
    oc=outclass();  //赋值操作符
    cout<<"CCC"<<endl;


    cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

}
