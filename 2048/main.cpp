/*
 * main.cpp
 *
 *  Created on: 2018��5��9��
 *      Author: Administrator
 */

#include "Data.h"
#include "Deal.h"
#include "Show.h"
#include "Test.h"

#include <map>

GINFO  gInfo =
{
        {GINFO_INDEX::Socre, 0},
        {GINFO_INDEX::Max, 0},
        {GINFO_INDEX::Step, 0},
        {GINFO_INDEX::ALIVE, 1}
};

int GData [SCALE][SCALE] ={0};

int main()
{
    showHelp();
    inital(  GData);
    show( GData,  gInfo );
    Test();

    DealInput( GData, gInfo);

}
