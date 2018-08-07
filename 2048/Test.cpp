/*
 * Test.cpp
 *
 *  Created on: 2018Äê5ÔÂ9ÈÕ
 *      Author: Administrator
 */




#include "Test.h"


void TestDealData()
{

    GINFO  info =
    {
            {GINFO_INDEX::Socre, 0},
            {GINFO_INDEX::Max, 0},
            {GINFO_INDEX::Step, 0},
            {GINFO_INDEX::ALIVE, 1}
    };

    int Data [SCALE][SCALE] ={0};

    inital(  Data);
    show( Data,  info );
    DIRCT dir= DIRCT::RIGHT;
    DealData( dir, Data, info );
    show( Data,  info );

    inital(  Data);
    show( Data,  info );
    dir= DIRCT::LEFT;
    DealData( dir, Data, info );
    show( Data,  info );


    inital(  Data);
    show( Data,  info );
    dir= DIRCT::UP;
    DealData( dir, Data, info );
    show( Data,  info );


    inital(  Data);
    show( Data,  info );
    dir= DIRCT::DOWN;
    DealData( dir, Data, info );
    show( Data,  info );

}
void  TestMerge()
{
    vector<int> t1 {0,0,2,2};
    Merge(t1);
    vector<int> t2 {2,0,2,4};
    Merge(t2);

    vector<int> t3 {2,0,4,2};
    Merge(t3);

    vector<int> t4 {2,4,8,2};
    Merge(t4);

    vector<int> t5 {4,0,4,0};
    Merge(t5);

    vector<int> t6 {2,0,2,2,2,2};
    Merge(t6);
}

void TestArea()
{

    DIRCT dir= DIRCT::DOWN;
    DIRCT dir2= DIRCT::DOWN;
    DIRCT dir3= DIRCT::DOWN;

    AREA area;

    cout<<"down down"<<endl;
    dir= DIRCT::DOWN;
    dir2= DIRCT::DOWN;
    area = GetTheArea(dir,true);
    area = GetTheArea(dir2);
    cout<< GetAreaString(area) << endl;

    cout<<"up down"<<endl;
    dir= DIRCT::UP;
    dir2= DIRCT::DOWN;
    area = GetTheArea(dir,true);
    area = GetTheArea(dir2);
    cout<< GetAreaString(area) << endl;

    cout<<"up right"<<endl;
    dir= DIRCT::UP;
    dir2= DIRCT::RIGHT;
    area = GetTheArea(dir,true);
    area = GetTheArea(dir2);
    cout<< "leftdwon is ok" << endl;

    cout<<"up lef"<<endl;
    dir= DIRCT::UP;
    dir2= DIRCT::LEFT;
    area = GetTheArea(dir,true);
    area = GetTheArea(dir2);
    cout<< GetAreaString(area) << endl;


    cout<<"down down down"<<endl;
    dir= DIRCT::DOWN;
    dir2= DIRCT::DOWN;
    dir3= DIRCT::DOWN;
    area = GetTheArea(dir,true);
    area = GetTheArea(dir2);
    cout<< GetAreaString(area) << endl;
    area = GetTheArea(dir3);
    cout<< GetAreaString(area) << endl;


    cout<<"dwon right right"<<endl;
    dir= DIRCT::DOWN;
    dir2= DIRCT::RIGHT;
    dir3= DIRCT::RIGHT;
    area = GetTheArea(dir,true);
    area = GetTheArea(dir2);
    cout<< GetAreaString(area) << endl;
    area = GetTheArea(dir3);
    cout<< GetAreaString(area) << endl;

    cout<<"RIGHT DOWN LEFT"<<endl;
    dir= DIRCT::RIGHT;
    dir2= DIRCT::DOWN;
    dir3= DIRCT::LEFT;
    area = GetTheArea(dir,true);
    area = GetTheArea(dir2);
    cout<< " LEFTUP is ok" << endl;
    area = GetTheArea(dir3);
    cout<< "RIGHTUP is op" << endl;

}

void Test()
{
    TestMerge();
    TestDealData();
    TestArea();
}
