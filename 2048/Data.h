/*
 * Data.h
 *
 *  Created on: 2018年5月9日
 *      Author: Administrator
 */

#ifndef DATA_H_
#define DATA_H_

#include <map>
#define DEBUG 1

using namespace std;
enum GINFO_INDEX
{
    Socre =0,
    Max  =1,
    Step =2,
    ALIVE =3
};

enum DIRCT
{
    UP =0,
    DOWN  =1,
    LEFT =2,
    RIGHT =3
};

enum AREA
{
    LEFTUP =0, //左上
    LEFTDOWN ,
    RIGHTUP,
    RIGHTDOWN
};


string GetDirtString( DIRCT  dir);
string GetAreaString( AREA  area);

#define GINFO std::map<int,int>

#define SCALE  5

#endif /* 2048_DATA_H_ */
