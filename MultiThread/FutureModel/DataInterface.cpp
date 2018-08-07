/*
 * DataInterface.cpp
 *
 *  Created on: 2017年12月20日
 *      Author: Administrator
 */




#include "DataInterface.h"
#include <unistd.h>

Data::Data()
{

}

Data::~Data()
{
}

std::string  RealData:: getResult() {

    //实际获取比较慢 sleep代替
    int second = 15;
    sleep(second);
    printf("sleep %d  in RealData:: getResult. \n",second);
    std:: string sRet="Real Answer to request: ";
    sRet += this->request;

    return sRet;
}

RealData::RealData()
{
    this->request =" request_null";
}
RealData::RealData(string request)
{
    this->request +=" request_";
    this->request +=request;
}

FutureData::FutureData()
{
    bReady=false;

}
FutureData:: FutureData(string request)
{
    bReady=false;
    this->request += request;
}

std::string  FutureData::getResult()
{
    while( bReady == false )
    {
        printf("not ready now ,wait for a while \n");
        sleep(2);
    }
    return result;
};

bool FutureData:: IsReady(){
    return bReady;
}
