/*
 * virtualFuction.cpp
 *
 *  Created on: 2017��5��24��
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
