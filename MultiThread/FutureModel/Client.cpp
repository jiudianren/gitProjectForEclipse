/*
 * Client.cpp
 *
 *  Created on: 2017年12月20日
 *      Author: Administrator
 */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include "Client.h"

using namespace std;

void * DealRealDate(void * args)
{
    std::shared_ptr< FutureData> * pfuture= static_cast<std::shared_ptr<FutureData>* > (args);

    RealData tRealData( (*pfuture)->getRequest());

    string sRet = tRealData.getResult();

    (*pfuture)->setResult( sRet );
    return (void *)0;
}

std::shared_ptr< FutureData>   Client::request(string queryStr) {

    //这里 用一个new 等待外层去释放，这是不符合常规的
    std::shared_ptr< FutureData>  future  =std::make_shared<FutureData>(queryStr);

    /*建一个线程去获取 实际的结果
     * */

    pthread_t  pDealRealDataThread ;

    int ret = pthread_create( &pDealRealDataThread, NULL, DealRealDate , &future );
    if( ret !=0)
    {
        printf("pthread_create erro %d  \n", ret);
        exit(0);
    }

    return future;
}
