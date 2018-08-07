/*
 * shmread.c
 *
 *  Created on: 2016��8��9��
 *      Author: Administrator
 */




#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/shm.h>
#include "shmdata.h"

int main()
{
	int running = 1;//�����Ƿ�������еı�־
	int waring=1;//jdr:1��Ҫ��ʾ��0����Ҫ��ʾ
	void *shm = NULL;//����Ĺ����ڴ��ԭʼ�׵�ַ
	struct shared_use_st *shared;//ָ��shm
	int shmid;//�����ڴ��ʶ��
	//���������ڴ�
	shmid = shmget((key_t)1234, sizeof(struct shared_use_st), 0666|IPC_CREAT);
	if(shmid == -1)
	{
		fprintf(stderr, "shmget failed\n");
		exit(EXIT_FAILURE);
	}
	//�������ڴ����ӵ���ǰ���̵ĵ�ַ�ռ�
	shm = shmat(shmid, 0, 0);
	if(shm == (void*)-1)
	{
		fprintf(stderr, "shmat failed\n");
		exit(EXIT_FAILURE);
	}
	printf("\nMemory attached at %X\n", (int)shm);
	//���ù����ڴ�
	shared = (struct shared_use_st*)shm;
	//jdr:ΪʲôҪ��������Ϊ��д�أ���
//	shared->written = 0;
	shared->written = 1;
	while(running)//��ȡ�����ڴ��е�����
	{
		//û�н��������ڴ涨���������ݿɶ�ȡ
		if(shared->written != 0)
		{
			printf("You wrote: %s", shared->text);
			sleep(rand() % 3);
			//��ȡ�����ݣ�����writtenʹ�����ڴ�ο�д
			shared->written = 0;
			waring=1;
			//������end���˳�ѭ��������
			if(strncmp(shared->text, "end", 3) == 0)
				running = 0;
		}
		else//������������д���ݣ����ܶ�ȡ����
		{
			if(waring==1)
			{
				printf("it maybe is writting.\n");
				waring=0;
			}
			sleep(1);
		}

	}
	//�ѹ����ڴ�ӵ�ǰ�����з���
	if(shmdt(shm) == -1)
	{
		fprintf(stderr, "shmdt failed\n");
		exit(EXIT_FAILURE);
	}
	//ɾ�������ڴ�
	if(shmctl(shmid, IPC_RMID, 0) == -1)
	{
		fprintf(stderr, "shmctl(IPC_RMID) failed\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
