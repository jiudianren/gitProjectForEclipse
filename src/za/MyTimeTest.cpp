/*
 * MyTimeTest.cpp
 *
 *  Created on: 2018年8月30日
 *      Author: Administrator
 */




/*
 *
 *https://blog.csdn.net/ybhjx/article/details/69374354

 linux下存储时间常见的有两种存储方式，一个是从1970年到现在经过了多少秒，一个是用一个结构来分别存储年月日时分秒的。
time_t 这种类型就是用来存储从1970年到现在经过了多少秒，要想更精确一点，可以用结构struct timeval，它精确到微妙。
struct timeval
{
    long tv_sec; 秒
    long tv_usec; 微秒
};



而tm直接存储年月日的是一个结构：
//struct tm
//{
//    int tm_sec;  /*秒，正常范围0-59， 但允许至61*/
//    int tm_min;  /*分钟，0-59*/
//    int tm_hour; /*小时， 0-23*/
//    int tm_mday; /*日，即一个月中的第几天，1-31*/
//    int tm_mon;  /*月， 从一月算起，0-11*/  1+p->tm_mon;
//    int tm_year;  /*年， 从1900至今已经多少年*/  1900＋ p->tm_year;
//    int tm_wday; /*星期，一周中的第几天， 从星期日算起，0-6*/
//    int tm_yday; /*从今年1月1日到目前的天数，范围0-365*/
//    int tm_isdst; /*日光节约时间的旗标*/
//};

/*需要特别注意的是，年份是从1900年起至今多少年，而不是直接存储如2011年，月份从0开始的，0表示一月，星期也是从0开始的， 0表示星期日，1表示星期一。
 *
 *
 *
 * https://blog.csdn.net/ybhjx/article/details/69374354
 *
 * */





