/*
 * Data.cpp
 *
 *  Created on: 2018Äê5ÔÂ10ÈÕ
 *      Author: Administrator
 */

#include "Data.h"
#include <iostream>
#include <string>

string GetDirtString( DIRCT  dir)
{
    string dirStr;

    switch(dir)
    {
        case DIRCT::UP:
        {
            dirStr+="UP";
            break;
        }

        case DIRCT::DOWN:
        {
            dirStr+="DOWN";
            break;
        }
        case DIRCT::LEFT:
        {
            dirStr+="LEFT";
            break;
        }
        case DIRCT::RIGHT:
        {
            dirStr+="RIGHT";
            break;
        }
    }

    return dirStr;
}

string GetAreaString( AREA  area)
{
    string areaStr;
    switch(area)
    {
        case AREA::LEFTDOWN:
        {
            areaStr+="LEFTDOWN";
            break;
        }

        case AREA::LEFTUP:
        {
            areaStr+="LEFTUP";
            break;
        }
        case AREA::RIGHTDOWN:
        {
            areaStr+="AREA";
            break;
        }
        case AREA::RIGHTUP:
        {
            areaStr+="RIGHTUP";
            break;
        }
    }
    return areaStr;
}
