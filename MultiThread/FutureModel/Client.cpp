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
    std::shared_ptr< FutureData> * pfuture= static_cast<std::shared_ptr<FutureData>* > (args);

    RealData tRealData( (*pfuture)->getRequest());

    string sRet = tRealData.getResult();

    (*pfuture)->setResult( sRet );
    return (void *)0;
}

std::shared_ptr< FutureData>   Client::request(string queryStr) {

    //���� ��һ��new �ȴ����ȥ�ͷţ����ǲ����ϳ����
    std::shared_ptr< FutureData>  future  =std::make_shared<FutureData>(queryStr);

    /*��һ���߳�ȥ��ȡ ʵ�ʵĽ��
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
