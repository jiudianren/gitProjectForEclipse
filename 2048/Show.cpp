/*
 * Show.cpp
 *
 *  Created on: 2018年5月9日
 *      Author: Administrator
 */


#include <iomanip>

#include "Show.h"
#include <iostream>
using namespace std;

void showHead( GINFO  & info)
{
    cout<<"---------ATTION--------"<<endl;
    cout<<"-----------------------"<<endl;
    cout<<endl;

    cout<<"Score :"<< info.find(GINFO_INDEX::Socre)->second;
    cout<<" Max :"<< info.find(GINFO_INDEX::Max)->second;
    cout<<" Step :"<< info.find(GINFO_INDEX::Step)->second;
    cout<<" ALIVE :"<< info.find(GINFO_INDEX::ALIVE)->second;
    cout<<endl;
}

void showHelp()
{
    cout<<"---------HELP--------"<<endl;
    cout << "J: left" <<" L:right " <<"i: up" <<"  k:down " <<endl;

}


//使用cout的颜色控制，让同样的数据显示一个颜色
void show( int data [SCALE][SCALE] , GINFO  & info)
{
    showHead( info);
    cout <<"DATA INFO: "<<endl;
    for(int i =0; i <SCALE ; i++ )
    {
        for(int j=0 ; j<SCALE ;j++)
        {
            cout<<setw( CELL_LEN )<< data[i][j] ;
            cout<<"|";
        }
        cout<<endl;
    }

    cout<<endl;
    cout<<"-----------------------"<<endl;
    cout<<"---------ATTION--------"<<endl;
}

