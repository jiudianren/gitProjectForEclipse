/*
 *
 *  Created on: 2017年12月19日
 *      Author: lian.pengfei
 */



#include <stdio.h>

#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

#include "DataInterface.h"
#include "Client.h"


/*
 * Future 模型
 *http://blog.csdn.net/lmdcszh/article/details/39696357
 *用户请求后，不需要立马得到结果。 而是在，当前执行一系列动作后，再来获取结果

 *
 * */
int main(void)
{
    printf("Futural Model start ==========.\n");

    Client client;

    auto data=  client.request( "request1");
    //do something other thing or sleep to wait the result;
    int second = 10;
    int times = 3;
    while(times > 0)
    {
        sleep(second);
        printf("sleep %d  in main() \n",second);
        times--;
    }

    string ret = data->getResult();
    printf("Real date return :[%s].\n", ret.c_str());

    auto data2=  client.request( "request2");
    second = 5;
    sleep(second);
    printf("sleep %d  in main() \n",second);
    ret = data2->getResult();
    printf("Real date return :[%s].\n", ret.c_str());

    printf("Futural Model end ==========.\n");
    return 0;
}
