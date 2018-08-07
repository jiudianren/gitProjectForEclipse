/*
 * za.cpp
 *
 *  Created on: 2017年3月2日
 *      Author: Administrator
 */


#include "zaa.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <string>
const unsigned long SEC_1900_TO_1970 =  2208988800;
#define VALID_DATE_TIME_SEC(A1) (A1 > SEC_1900_TO_1970)


#include <iostream>
typedef unsigned char UINT8;

int  * aa;

void initArray()
{

	int ar[6]={1,2,3,4,5,6};
	aa=ar+3;
	printf("first");
	printf("%d ,%d",*aa,*aa++);
	aa--;
}

void testAA()
{
    int atemp=100;
    int btemp=0;
    int c =0 ;
    c =atemp%btemp;
    printf("%d c",c);
}
void  mainbb()
{
    //除数不能为0
    //   testAA();

	initArray();
	printf("%d ,%d",*aa, *aa++);
	aa--;
}




using namespace std;

int xyz = 5;

namespace ns
{
int xyz = 3;

int f()
{
	extern int xyz;//外一层的 这里在 namespace 出已经找到了，所以就不用在向外扩了
	return xyz;
}

int ft()
{
	int xyz=4;
	xyz = 44;
	{
		extern int xyz;
		return xyz;
	}

}

}

int x = 5;

int ff()
{
	int x = 3;
	x = 4;
	{
		extern int x;
		return x;
	}
}

int testEnum(EnumIntEnum enumType)
{
    switch(enumType)
    {
        case MYENUM1:
        {
            printf("testEnum11");
            break;
        }
        default:
        {
            printf("testEnum ok");
        }
    }
    return 0;
}




/* 获取PPSID */
unsigned int GetPPSId(char *pPPSList, unsigned int iAuthAppId)
{
    char sAuthAppIdItem[16] = { 0 } ,  *pPPSId = NULL;
    int    iAuthAppIdLen = 0;
    if(pPPSList == NULL || *pPPSList == '\0')
    {
        return 0;
    }
    iAuthAppIdLen = snprintf(sAuthAppIdItem, sizeof(sAuthAppIdItem),
      "|%u-", iAuthAppId);
    if(iAuthAppIdLen < 0)
    {
        return 0;
    }
    pPPSId = strstr(pPPSList, sAuthAppIdItem);
    if(pPPSId == NULL)
    {
        pPPSId = pPPSList;
    }else
    {
        pPPSId += iAuthAppIdLen;
    }
    return (unsigned int) atol (pPPSId) ;
}
void testIntEnum()
{
    char  pPPSList[100]="|300-1|250-2|350-3";

    unsigned int i300= GetPPSId(pPPSList, 300);
    unsigned int i250= GetPPSId(pPPSList, 250);
    unsigned int i350= GetPPSId(pPPSList, 350);
    printf("i300=%d i300%d i300=%d ok", i300,i250,i350 );
    for(int i = 0 ;i< MYENUM_END;i++)
    {
        testEnum( (EnumIntEnum) i);
    }

}
void testExtern()
{
//	INFO
	cout<<"haha  test inner extern "<<endl;
	cout << ns::f() <<","<<ns::ft()<<","<<::xyz<<endl;
	cout << ff() <<endl;
}


using std::cout;
using std::endl;

void SizeofLong()
{
    long aa= 987654321012345678;
    printf("%ld \n",aa);
    cout << "size of long is " << sizeof(long) << endl;
}
