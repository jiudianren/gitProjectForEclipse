
/*
 * 通过宏定义 来代替一个函数的扩展 ，
 * */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <typeinfo>
#include "Define.h"

void mainDefine()
{
    printf("................********* \n");
    int a=0;
#if  1
    printf("xxxxxxx \n");
#else
    printf("yyyyy \n");
#endif

    printf("not void :%d \n", a );
}
