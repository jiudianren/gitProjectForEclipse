//============================================================================
// Name        : duck.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <string>
#include <iostream>
#include "duck.h"
using namespace std;


int mainduck()
{
    NoFly nofly;
    FlyBehavior &rf=nofly;
    FlyBehavior ftemp;

    cout<<"test one"<<endl;
    ToyDuck toyDuck(ftemp);
    toyDuck.performFly();

    cout<<"set nofly"<<endl;
    NoFly & rnf=nofly;
    toyDuck.setFly(rnf);
    toyDuck.performFly();

    //    cout<<"set f &"<<endl;
    //    toyDuck.setFly(&f);
    //    toyDuck.performFly();

    cout<<"test two"<<endl;
    ToyDuck toyDuck1(nofly); //这个也Ok 引用形参，可以传个左值。
    toyDuck1.performFly();

    cout<<"test threee"<<endl;
    ToyDuck toyDuck2(rf); //这个也Ok
    toyDuck2.performFly();

    cout<<"the usage of virtual"<<endl;
    rf.fly();

    return 0;
}


void testRefe()
{
    cout<<"yyyy"<<endl;
    string s1 = "aaa";
    string s2 = "bbb";
    string s3 = "bbb";
    string& res1 = s1;
    string& res2 = s2;
    string& res3 = s3;
    res2 = s1;  //实际上改变的 是s2的值
    cout<<res2<<endl;
    res3 = res1;
    cout<<res3<<endl;
    cout<<s1<<"，"<<s2<<","<<s3<<endl;

}
