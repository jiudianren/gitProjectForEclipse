/*
 * Client.cpp
 *
 *  Created on: 2017��12��20��
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
    FutureData  * future=  ( FutureData  *) args;

    RealData tRealData( future->getRequest());
    string sRet = tRealData.getResult();
    future->setResult( sRet );
    return (void *)0;
}

Data *  Client::request(string queryStr) {

    //���� ��һ��new �ȴ����ȥ�ͷţ����ǲ����ϳ����
    FutureData  * future  = new FutureData (queryStr);

    /*��һ���߳�ȥ��ȡ ʵ�ʵĽ��
     *
     * */

    pthread_t  pDealRealDataThread ;

    int ret = pthread_create( &pDealRealDataThread, NULL, DealRealDate , future );
    if( ret !=0)
    {
        printf("pthread_create erro %d  \n", ret);
        exit(0);
    }

    return future;
}
