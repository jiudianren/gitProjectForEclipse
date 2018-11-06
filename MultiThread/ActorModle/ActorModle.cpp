
#include <stdio.h>

#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

#include "DataInterface.h"
#include "Client.h"


/*
actor模型属于一种基于消息传递机制并行任务处理思想，它以消息的形式来进行线程间数据传输，
避免了全局变量的使用，进而避免了数据同步错误的隐患。actor在接受到消息之后可以自己进行处理，
也可以继续传递（分发）给其它actor进行处理。
在使用actor模型的时候需要使用第三方Akka提供的框架点击查看。
这里使用scala进行演示，如果需要看java使用方法则可以查阅官方文档：actor for java 使用
 * */
int main(void)
{
    printf("MasterWork Model start ==========.\n");



    printf("MasterWork Model end ==========.\n");
    return 0;
}
