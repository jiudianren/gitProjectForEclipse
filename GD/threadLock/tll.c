/*
 * tll.c
 *
 *  Created on: 2016Äê8ÔÂ11ÈÕ
 *      Author: Administrator
 */



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int tmp;
void* thread1(void *arg)
{
	printf("thread id is %d\n",pthread_self());
	pthread_mutex_lock(&mutex);
	tmp = 1;
	printf("Now a is %d\n",tmp);
	pthread_mutex_unlock(&mutex);
	return NULL;

}

void* thread2(void *arg)
{
	printf("thread id is %d\n",pthread_self());
	pthread_mutex_lock(&mutex);
	tmp = 2;
	printf("Now a is %d\n",tmp);
	pthread_mutex_unlock(&mutex);
	return NULL;
}

int main()
{

	pthread_t id1;
	pthread_t id2;

	printf("main thread id is %d\n", pthread_self() );
	tmp = 3;
	printf("In main func tmp = %d\n", tmp);;

	if (!pthread_create(&id1, NULL, thread1, NULL))
	{
		printf( "Create thread success!\n");
	}
	if (!pthread_create(&id2, NULL, thread2, NULL))
	{
		printf( "Create thread success!\n");
	}

	
	sleep(1);
	pthread_join(id1, NULL);
	pthread_join(id2, NULL);
	pthread_mutex_destroy(&mutex);

	
	return 0;
}
