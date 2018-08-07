/*
 * DateTest.cpp
 *
 *  Created on: 2017Äê11ÔÂ20ÈÕ
 *      Author: Administrator
 */



#include  "TestStringToTime.h"
#include "DateTest.h"
using namespace std;



std::string ToCSVDate( char * sDate )
{
    std::string sRet("");

    char szCurTime[32] = {0};
    struct tm *pTMCur = NULL, tmTime;
    if(  sDate == NULL || strlen( sDate ) !=  14 )
    {
        return  sRet;
    }
    time_t tCurTime =  StringToTime(sDate);

    pTMCur = localtime_r(&tCurTime, &tmTime);
    if (NULL==pTMCur || strftime(szCurTime,sizeof(szCurTime),"%Y.%m.%d %H:%M:%S",pTMCur)==0)
    {
        szCurTime[0] = '\0';
    }

    sRet += std::string(szCurTime);
    return sRet;
}


void mainDateTest()
{
    unsigned char    ino = -1;
     printf("AcceptConnect: ino=%u, Exceeds", ino);

    char aa[15]="20171221093500";
    cout<<"mainDateTest==================start "<<std::endl;
    cout<<"mainDateTest: "<<ToCSVDate(aa)<<std::endl;
    cout<<"mainDateTest==================end "<<std::endl;
}



