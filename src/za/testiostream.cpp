/*
 * testiostream.cpp
 *
 *  Created on: 2017年4月12日
 *      Author: Administrator
 */




#include "testiostream.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
void mainTestIo()
{

    std::ofstream ff;

    ff.close();
    if(ff.is_open())
    {
        cout<<" is open"<<endl;
    }
    else
    {
        cout<<" not"<<endl;
    }

    if(ff.good())
    {
        cout<<"ok"<<endl;

    }
    else
    {
        cout<<"ok not "<<endl;
        ff.clear();
    }

    if(ff.good())
    {
        cout<<"ok"<<endl;
        ff.clear();
    }
    else
    {
        cout<<"ok not "<<endl;
        ff.clear();
    }
    //这两个有区别吗
    std::cout<<"std::ios::app "<<std::ios::app<< std::ios_base::app<<std::endl;

    //fstream close以后，最好clear一下，参考c++ primer
}
