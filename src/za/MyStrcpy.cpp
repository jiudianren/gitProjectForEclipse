/*
 * MyStrcpy.cpp
 *
 *  Created on: 2018��10��30��
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
    //�ȸ��ƣ����ж� �� ʵ�����Ѿ������һ�� \0���ƽ�ȥ�ˣ�����Լ�д ����Ҫ����� ���һ�� \0;
    while ((*strDest++=*strSrc++)!='\0');

    return strDestCopy;
}
