/*
 * MyStrcpy.cpp
 *
 *  Created on: 2018年10月30日
 *      Author: Administrator
 */


#include <stdio.h>
#include <string.h>
#include "MyStrcpy.h"


char * MyStrcpy(char * strDest,const char * strSrc)
{

    if( strDest == NULL || strSrc == NULL)
    {
        return NULL;
    }
    char * strDestCopy=strDest;
    //先复制，再判断 ， 实际上已经把最后一个 \0复制进去了，如果自己写 ，需要逐级添加 最后一个 \0;
    while ((*strDest++=*strSrc++)!='\0');

    return strDestCopy;
}
