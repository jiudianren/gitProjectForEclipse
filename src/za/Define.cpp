
/*
 * ͨ���궨�� ������һ����������չ ��
 * */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <typeinfo>
#include "Define.h"

#define MYMAX(X,Y) ((X)>(Y)?(X):(Y))

/*
 *  дһ���궨�� ����ȡ���������еĽϴ�ֵ

 ע������ ���� �� X ��Y Ҫ������
 ��� ���������ʽ Ҫ�� ���� (       .......  )

 * */



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
