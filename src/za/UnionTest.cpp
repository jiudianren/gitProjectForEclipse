/*
 * UnionTest.cpp
 *
 *  Created on: 2017Äê12ÔÂ3ÈÕ
 *      Author: lian.pengfei
 */


#include <stdio.h>
#include "UnionTest.h"

typedef union
{
    unsigned int Ax;
    struct AX
    {
        unsigned int AL:16;
        unsigned int AH:16;
    }sAX;
}example;

int mainTestUnion(void)
{
    example a;
    a.Ax = 0xAFAFBEBE;

    int i = a.sAX.AH;
    printf("AX = 0x%X, AH = 0x%X, AL = 0x%X\n", a.Ax, a.sAX.AH, a.sAX.AL);

    return 0;
}
