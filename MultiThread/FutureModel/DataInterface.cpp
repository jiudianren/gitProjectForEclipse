/*
 * DataInterface.cpp
 *
 *  Created on: 2017��12��20��
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

    //ʵ�ʻ�ȡ�Ƚ��� sleep����
    int second = 15;
    sleep(second);
    printf("sleep %d  in RealData::getResult. \n",second);
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

void FutureData::setResult(string  result)
{
    printf("SetResult For FutureData Now .\n");
    this->result =result;
    bReady = true;
}

bool FutureData:: IsReady(){
    return bReady;
}
