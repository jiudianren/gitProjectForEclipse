/*
 * TestStringToTime.cpp
 *
 *  Created on: 2017年8月28日
 *      Author: Administrator
 */



#include <string.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <sstream>
#include <sys/time.h>
#include "TestStringToTime.h"

#define  DT_YEAR_LEN         (4)
#define  DT_MONTH_LEN        (2)
#define  DT_DAY_LEN          (2)
#define  DT_HOUR_LEN         (2)
#define  DT_MINUTE_LEN       (2)
#define  DT_SECOND_LEN       (2)
#define  DT_DATE_LEN         (DT_YEAR_LEN + DT_MONTH_LEN + DT_DAY_LEN)
#define DATE_TIME_SIZE      15   //日期时间格式大小YYYYMMDDHHMISS

const unsigned long SEC_1900_TO_1970 =  2208988800;

#define SIMPLE_SCPY(dest,src) memccpy(dest,src,'\0',sizeof(dest)-1); dest[sizeof(dest)-1]='\0';

using namespace std;


const char * TimeToString(const time_t tTime, char sCurtime[], int iCurtimeLen)
{

    struct tm tm_Cur;

    memset(sCurtime, 0, iCurtimeLen);
    localtime_r(&tTime, &tm_Cur);
    snprintf(sCurtime, iCurtimeLen, "%04d%02d%02d%02d%02d%02d", tm_Cur.tm_year + 1900, tm_Cur.tm_mon + 1, tm_Cur.tm_mday, tm_Cur.tm_hour, tm_Cur.tm_min, tm_Cur.tm_sec);

    return sCurtime;
}

time_t StringToTime(const char sTime[])
{

    cout<<"*************" <<endl;
    if (strlen(sTime) != 14)
    {
        cout<<"your time is a date!."<<endl;
    }

    //使用localtime，以更新::daylight，使其和系统时区保持一致
    time_t tCurrent = 0;
    localtime(&tCurrent);

    char sTempYear[5] = {0}, sTempMon[3] = {0}, sTempMDay[3] = {0}, sTempHour[3] = {0}, sTempMin[3] = {0}, sTempSec[3] = {0};
    strncpy(sTempYear, sTime, DT_YEAR_LEN);
    sTempYear[DT_YEAR_LEN] = 0;
    sTempMon[0] = sTime[4];
    sTempMon[1] = sTime[5];
    sTempMDay[0] = sTime[6];
    sTempMon[2] = 0;
    sTempMDay[1] = sTime[7];
    sTempMDay[2] = 0;
    sTempHour[0] = sTime[8];
    sTempHour[1] = sTime[9];
    sTempHour[2] = 0;

    sTempMin[0] = sTime[10];
    sTempMin[1] = sTime[11];
    sTempMin[2] = 0;

    sTempSec[0] = sTime[12];
    sTempSec[1] = sTime[13];
    sTempSec[2] = 0;

    struct tm s;
    s.tm_year = atoi(sTempYear) - 1900;
    s.tm_mon = atoi(sTempMon) - 1;
    s.tm_mday = atoi(sTempMDay);
    s.tm_hour = atoi(sTempHour);
    s.tm_min = atoi(sTempMin);
    s.tm_sec = atoi(sTempSec);
    s.tm_isdst = (int)0;  //::daylight 是否启动日光节约时间。＝0为不启动。屏蔽夏令时对程序时间的影响。

    long ltemp =0 ;

    cout<<" befre mktime s.tm_isdst = "<< s.tm_isdst <<endl;
    long lReturn =  mktime(&s);
    cout<<" after  mktime s.tm_isdst = "<< s.tm_isdst <<endl;

    std::ostringstream sLineText;
    sLineText<< lReturn ;
    cout<<" result is  = "<< sLineText.str()<< endl;

    ltemp = lReturn;
    char sTimeOut[DATE_TIME_SIZE]={0};
    TimeToString(ltemp,sTimeOut,sizeof(sTimeOut));
    cout<<" transform   "<< sTimeOut <<endl;
    cout<<"*************" <<endl;


    s.tm_isdst = (int) -1 ;
    s.tm_hour = atoi(sTempHour);

    cout<<" befre mktime s.tm_isdst = "<< s.tm_isdst <<endl;
    long lReturn2 =  mktime(&s);
    cout<<" after  mktime s.tm_isdst = "<< s.tm_isdst <<endl;

    std::ostringstream sLineText2;
    sLineText2<< lReturn2 <<endl;
    cout<<" result is  = "<< sLineText2.str() <<endl;

    ltemp = lReturn2;
    char sTimeOut1[DATE_TIME_SIZE]={0};
    TimeToString(ltemp,sTimeOut1,sizeof(sTimeOut1));
    cout<<"transform   "<< sTimeOut1 <<endl;

    cout<<"*************" <<endl;


    s.tm_isdst = 1 ;
    s.tm_hour = atoi(sTempHour);
    cout<<"  for extern test tm_isdst =  "<< s.tm_isdst <<endl;
    cout<<" befre mktime s.tm_isdst = "<< s.tm_isdst <<endl;
    long lReturn3 =  mktime(&s);

    cout<<" after  mktime s.tm_isdst = "<< s.tm_isdst <<endl;


    std::ostringstream sLineText3;
    sLineText3<< lReturn3 <<endl;
    cout<<" result is  = "<< sLineText3.str() <<endl;


    ltemp = lReturn3;
    char sTimeOut3[DATE_TIME_SIZE]={0};
    TimeToString(ltemp,sTimeOut3,sizeof(sTimeOut3));
    cout<<" transform   "<< sTimeOut3 <<endl;

    cout<<"*************" <<endl;

    return lReturn;
}

const char *  GetCurrentTimeStr(char sTime[], size_t iLen)
{
    time_t tCurrent;
    struct tm tm_Cur;
    char sCurtime[40] = {0};

    if (!sTime || iLen < DATE_TIME_SIZE)
        return NULL;

    sCurtime[39] = 0;
    time(&tCurrent); //取得当前时间的time_t值
    localtime_r(&tCurrent, &tm_Cur); //取得当前时间的tm值


    snprintf(sCurtime, sizeof(sCurtime), "%04d%02d%02d%02d%02d%02d", tm_Cur.tm_year + 1900, tm_Cur.tm_mon + 1, tm_Cur.tm_mday, tm_Cur.tm_hour, tm_Cur.tm_min, tm_Cur.tm_sec);

    strncpy(sTime, sCurtime, iLen);
    sTime[iLen-1] = '\0';

    return sTime;
}

time_t StringToTime222(const char sTime[])
{

    //使用localtime，以更新::daylight，使其和系统时区保持一致
    time_t tCurrent = 0;
    localtime(&tCurrent);

    char sTempYear[5] = {0}, sTempMon[3] = {0}, sTempMDay[3] = {0}, sTempHour[3] = {0}, sTempMin[3] = {0}, sTempSec[3] = {0};
    strncpy(sTempYear, sTime, DT_YEAR_LEN);
    sTempYear[DT_YEAR_LEN] = 0;
    sTempMon[0] = sTime[4];
    sTempMon[1] = sTime[5];
    sTempMDay[0] = sTime[6];
    sTempMon[2] = 0;
    sTempMDay[1] = sTime[7];
    sTempMDay[2] = 0;
    sTempHour[0] = sTime[8];
    sTempHour[1] = sTime[9];
    sTempHour[2] = 0;

    sTempMin[0] = sTime[10];
    sTempMin[1] = sTime[11];
    sTempMin[2] = 0;

    sTempSec[0] = sTime[12];
    sTempSec[1] = sTime[13];
    sTempSec[2] = 0;

    struct tm s;
    s.tm_year = atoi(sTempYear) - 1900;
    s.tm_mon = atoi(sTempMon) - 1;
    s.tm_mday = atoi(sTempMDay);
    s.tm_hour = atoi(sTempHour);
    s.tm_min = atoi(sTempMin);
    s.tm_sec = atoi(sTempSec);
#ifdef __BORLANDC__
    s.tm_isdst = (int)-1;
#else
    s.tm_isdst = (int)-1;  //::daylight 是否启动日光节约时间。＝0为不启动。屏蔽夏令时对程序时间的影响。
#endif


    cout<<" 11 befre mktime s.tm_isdst = "<< s.tm_isdst <<endl;
    long lReturn =  mktime(&s);
    cout<<" after  mktime s.tm_isdst = "<< s.tm_isdst <<endl;

    std::ostringstream sLineText;
    sLineText<< lReturn ;
    cout<<" (-1 )result is  = "<< sLineText.str()<< endl;


    s.tm_isdst = (int)0;  //::daylight 是否启动日光节约时间。＝0为不启动。屏蔽夏令时对程序时间的影响。
    s.tm_hour = atoi(sTempHour);



    cout<<"2  befre mktime s.tm_isdst = "<< s.tm_isdst <<endl;
    long lReturn1 =  mktime(&s);
    cout<<" after  mktime s.tm_isdst = "<< s.tm_isdst <<endl;

    std::ostringstream sLineText2;
    sLineText2<< lReturn1 ;
    cout<<"(0) result is  = "<< sLineText2.str()<< endl;


    return  lReturn;

}



int  mainSTS()
{
    char sTime[DATE_TIME_SIZE]={0};
    GetCurrentTimeStr(sTime, sizeof(sTime));

    cout<<"Test time now is   "<< sTime <<endl;
    long lRet = StringToTime( sTime );


    char sTimeOut[DATE_TIME_SIZE]={0};
    TimeToString(lRet,sTimeOut,sizeof(sTimeOut));
    cout<<" Time after transform   "<< sTimeOut <<endl;


    cout<<" 2222222222222222  " <<endl;
    GetCurrentTimeStr(sTime, sizeof(sTime));

    cout<<"Test time now is   "<< sTime <<endl;
    lRet = StringToTime222( sTime );
    lRet = StringToTime222( sTime );
    char  sTimeOut1[DATE_TIME_SIZE]={0};
    TimeToString(lRet,sTimeOut1,sizeof(sTimeOut1));
    cout<<" Time after transform   "<< sTimeOut1 <<endl;


    cout<<"Test time now is   "<< sTime <<endl;
    lRet = StringToTime222( sTime );
    char  sTimeOut2[DATE_TIME_SIZE]={0};
    TimeToString(lRet,sTimeOut2,sizeof(sTimeOut2));
    cout<<" Time after transform   "<< sTimeOut2 <<endl;

    return 0;
}
