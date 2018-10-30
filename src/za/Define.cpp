
/*
 * 通过宏定义 来代替一个函数的扩展 ，
 * */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <typeinfo>
#include "Define.h"

#define MYMAX(X,Y) ((X)>(Y)?(X):(Y))

/*
 *  写一个宏定义 ，获取两个变量中的较大值

 注意括号 首先 对 X 和Y 要扩括号
 其次 对整个表达式 要扩 括号 (       .......  )

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
