/*
 * testiostream.cpp
 *
 *  Created on: 2017��4��12��
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
    //��������������
    std::cout<<"std::ios::app "<<std::ios::app<< std::ios_base::app<<std::endl;

    //fstream close�Ժ����clearһ�£��ο�c++ primer
}
