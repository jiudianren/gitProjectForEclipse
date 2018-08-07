#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t Device_mutex = PTHREAD_MUTEX_INITIALIZER;

int count=0;
void * thread_func1()
{
	printf("thread id is %d\n",pthread_self());
	while(1)
	{
//		printf("thread  1 ,sleep 20 ,quite c>=10,\n");
		pthread_mutex_lock(&Device_mutex);
		printf("thread  1 ,sleep 20 ,quite c>=10,  c=%d \n",count);
		count++;
		if(count>=10)
		{
			pthread_mutex_unlock(&Device_mutex);
			break;
		}
		else
		{
			pthread_mutex_unlock(&Device_mutex);
		}
		sleep(20);
	}

	printf("     thread  1  quite\n");
	return NULL;
}
void * thread_func2()
{
	printf("thread id is %d \n ",pthread_self());
	while(1)
	{
//		printf("thread  2 ,sleep 5 ,quite c>=30,\n");
		pthread_mutex_lock(&Device_mutex);
		printf("thread  2 ,sleep 5 ,quite c>=30, c= %d \n",count);
		count++;
		if(count>=30)
		{
			pthread_mutex_unlock(&Device_mutex);
			break;
		}
		else
		{
			pthread_mutex_unlock(&Device_mutex);
		}
		sleep(5);
	}
	printf("     thread  2  quite\n");
	return NULL;
}
int main()
{
	pthread_t thread1, thread2;
//	pthread_mutex_init(&Device_mutex,NULL);
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
