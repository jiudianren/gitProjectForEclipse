/*
 * virtualFuction.cpp
 *
 *  Created on: 2017Äê5ÔÂ24ÈÕ
 *      Author: Lian
 */


#include "virtualFuction.h"


void mainVir()
{

    ViASon  cA;
    cA.funOut();


    ViA * cB;
    cB= &cA;
    cB->funOut();
}
