

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <map>
#include <string>
#include "struct.h"
struct SA
{
    int a;
    int b;
    void ClearData(void)
    {

    }
};
struct SB
{

    int c;
    SA d;
};
 struct   QosInfo
{
    int  iGBRUL ;
    int  iGBRDL ;
};

enum RefRTSrc
{
    RTSrc_START   = 0,
    RTSrc_ACM     = 1,
    RTSrc_BAL     = 2,
    RTSrc_PACK    = 3,
    RTSrc_BIRDAY  = 4,
    RTSrc_SYSPARA = 5,
    RTSrc_END     =6 ,
};
struct TRTSrc
{
    RefRTSrc eRTSrc;   //RTSrc Type
    bool bNeedRan;    //是否需要随机化
    char sRTSrcTime[DATE_TIME_SIZE];
};
void mainStruct()
{
    QosInfo aQosInfo[7];
    //定义一个数组成员类型的指针，该指针可以指向任意的数组成员的位置
    QosInfo * pQosInfo;
    for(int i=0;i<=6;i++)
    {
        aQosInfo[i].iGBRDL=i;
        aQosInfo[i].iGBRUL=i;
    }
    char sRTSrcTime[DATE_TIME_SIZE];

    strcpy(sRTSrcTime, MAX_DAE_TIME);
    printf("sRTSrcTime = %s \n ",sRTSrcTime);

    for(pQosInfo=aQosInfo;pQosInfo<aQosInfo+4;pQosInfo++)
    {
        printf("Pqos= %d \n",pQosInfo->iGBRDL);
    }

    printf("pqos= %d  \n ",(pQosInfo-4)->iGBRDL);
    printf("pqoss= %d  \n ",pQosInfo->iGBRDL);

    TRTSrc trt[RTSrc_END];
    memset(trt,0,sizeof(TRTSrc)*RTSrc_END);
    printf("trt %d  %d, %c a\n ", trt[2].eRTSrc,trt[0].eRTSrc, trt[1].sRTSrcTime[0]);
    if( trt[1].sRTSrcTime[0] == 0)
    {
        printf("yes \n");
    }

    TRTSrc a1={RTSrc_START,false,MAX_DAE_TIME};
    printf("a1 %s  \n ", a1.sRTSrcTime);
    TRTSrc * trt2 =new TRTSrc[RTSrc_END];
    memset(trt2,0,sizeof(TRTSrc)*RTSrc_END);
    char sDayOfBirthDay[DATE_TIME_SIZE] = { 0 };
    snprintf(sDayOfBirthDay, sizeof(sDayOfBirthDay), "20170101010203");

    if(trt2[0].bNeedRan)
    {
        std::cout<<"yes"<<std::endl;
    }
    else
    {
        std::cout<<"no"<<std::endl;
    }

    for(int i=0;i<RTSrc_END;i++)
    {
        std::cout<<"test for for"<<trt2[i].bNeedRan<<std::endl;
    }

}
