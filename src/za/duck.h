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
using namespace std;

#ifndef DUCK_H_
#define DUCK_H_


/* 将行为  抽象出来 ，最后变成 成员变量， 表示has-a */
class FlyBehavior
{
public:
    int mi;
    FlyBehavior():mi(0){};
    virtual ~ FlyBehavior(){};

    virtual void  fly()
    {
        cout<<"going to  fly"<<endl;
    };

};

class NoFly:public FlyBehavior
{
public:
    int mi;
    NoFly():mi(1){ };
    virtual ~ NoFly(){};
    void fly()
    {
        cout<<"i cannot fly"<<endl;
    };

};


// FlyBehavior为什么是个引用？？ 这里有问题
class Duck
{
public :
    Duck(FlyBehavior & fy):mfly(fy){};
    void performFly()
    {
        mfly.fly();
    };
protected:
    FlyBehavior &mfly;
};


class ToyDuck:public Duck
{
public:

    ToyDuck(FlyBehavior & fly):Duck( fly){};
    void testVirtual( FlyBehavior & fly)
    {
        fly.fly();
    }
    void setFly(NoFly  &fly)
    {
        mfly=fly;//
        cout<<mfly.mi<<endl;
    }
};

int mainduck();
void testRefe();


#endif /* ZA_H_ */

