/*
 *
 *  Created on: 2017��12��19��
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
 * Future ģ��
 *http://blog.csdn.net/lmdcszh/article/details/39696357
 *�û�����󣬲���Ҫ����õ������ �����ڣ���ǰִ��һϵ�ж�����������ȡ���

 *
 * */
int main(void)
{
    printf("Futural Model start ==========.\n");

    Client client;

    Data * data=  client.request( "request1");
    //do something other thing or sleep to wait the result;
    int second = 10;
    sleep(second);
    printf("sleep %d  in main() \n",second);

    sleep(second);
    printf("sleep %d  in main() \n",second);

    sleep(second);
    printf("sleep %d  in main() \n",second);

    string ret = data->getResult();
    printf("Real date return :[%s].\n", ret.c_str());
    delete(data);




    Data * data2=  client.request( "request1");
     second = 5;
    sleep(second);
    printf("sleep %d  in main() \n",second);
     ret = data2->getResult();
    printf("Real date return :[%s].\n", ret.c_str());
    delete(data2);


    printf("Futural Model end ==========.\n");
    return 0;
}
