
/*
 * ͨ���궨�� ������һ����������չ ��
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
