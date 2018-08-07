/*
 * tl.c
 *
 *  Created on: 2016Äê8ÔÂ10ÈÕ
 *      Author: Administrator
 */



#include <stdio.h>
#include <pthread.h>


pthread_mutex_t Device_mutex ;

int count=0;

void thread_func1()
{
	while(1)
	{
		pthread_mutex_lock(&Device_mutex);
		printf("thread1: %d/n",count);
		pthread_mutex_unlock(&Device_mutex);
		count++;
		sleep(1);
	}
}




void thread_func2()
{
	while(1)
	{
		pthread_mutex_lock(&Device_mutex);
		printf("thread2: %d/n",count);
		pthread_mutex_unlock(&Device_mutex);
		count++;
		sleep(1);
	}
}




int main()
{
	pthread_t thread1, thread2;

	
	pthread_mutex_init(&Device_mutex,NULL);
	if(pthread_create(&thread1,NULL,thread_func1,NULL) == -1)
	{
		printf("create IP81 Thread error !n");
		exit(1);
	}
	sleep(1);
	if(pthread_create(&thread2,NULL,thread_func2,NULL) == -1)
	{
		printf("create IP81_2 Thread error!n");
		exit(1);
	}


	
	sleep(1);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	pthread_mutex_destroy(&Device_mutex);
	

	return 0;
}
