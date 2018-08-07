#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "mailbox.h"




int maillbox_read(const char *w_path)
{
	FILE *w_fp;			
	int sizen;			 	/*��Ǵ��ļ��ж��˶����ֽ�*/	
	char tmp_buff[SIZE];	/*������*/
	int tmp;			
	int tmp_iHead;			/*�洢ͷָ��*/

	if(NULL == (w_fp= fopen(w_path , "r")))
	{
			printf("error: Can not open %s .\n",w_path);
			
			pthread_exit((void *)1);
	}
	
	
	while(1)
	{

		tmp_iHead = my_box->iHead;

		/*�ж������Ƿ�����*/
		if(((my_box->iTail + 1) % BUFF_MAX)  ==  tmp_iHead)  
		{
			continue ;
		}

		/*���ļ�����������*/
		if((sizen = fread(tmp_buff,1,SIZE,w_fp)) == 0 ) 
		{
				while(1)
				{
					if(my_box->iHead == my_box->iTail)  	/*��д����*/
					{	
						my_box->iHead = -1;					/*��Ƕ�д�ѽ���*/
					
						fclose(w_fp);
						pthread_exit((void *)1);
					}
				}
		}
		
		/*д������*/
		for(tmp= 0;tmp < sizen; tmp++ )
		{
		
			my_box->cBuff[my_box->iTail] = tmp_buff[tmp];


			/*��ֹд����*/
			while((my_box->iTail + 1)%BUFF_MAX  ==  my_box->iHead)
			{	

		
			}
			/*�ƶ�βָ��*/
			my_box->iTail = (my_box->iTail + 1)%BUFF_MAX;
		}
	}
}



int maillbox_write(const char *r_path)
{
    
	FILE *fp;
	int sizen; 
	int p_sizen ; 	
	int tmp_kTail; 	/*�洢βָ��*/
	
	if(NULL == (fp = fopen(r_path , "w")))
	{
			printf("error: Can not open %s.\n",r_path);
			
			pthread_exit((void *)1);
	}
	
		
	while(1)
	{	
		tmp_kTail = my_box->kTail;

		/*�ж��Ƿ�Ϊ��*/
		if((my_box->kHead == tmp_kTail) ) 
		{
			continue ;
		}

		/*�ж϶�д�Ƿ����*/
		if(my_box->kHead ==-1)
		{
			break;
		}
	
	
		/*д���ļ��У��ж�βָ��λ���Ƿ���ѭ����һ��*/		
		if(tmp_kTail > my_box->kHead)
		{
			p_sizen = tmp_kTail - my_box->kHead;		/*�ж��������ж�������*/		
			
			if((sizen = fwrite(my_box->bBuff+my_box->kHead,p_sizen, 1 ,fp)) < 0) 
			{
				fclose(fp);
				
				pthread_exit((void *)2);
			}
		
			my_box->kHead += p_sizen;
	
		}
		

		/*�Ѿ�ѭ����һ��*/
		else
		{
			p_sizen = BUFF_MAX - my_box->kHead ;
		
			if((sizen = fwrite(my_box->bBuff+my_box->kHead,p_sizen, 1 ,fp)) < 0) 
			{
				fclose(fp);
				
				pthread_exit((void *)2);
			}
			
			p_sizen = tmp_kTail;

			if((sizen = fwrite(my_box->bBuff,p_sizen, 1 ,fp)) < 0) 
			{
				fclose(fp);
				
				pthread_exit((void *)2);
			}

			my_box->kHead = tmp_kTail;
		
		}
		
	}
}


int main(int argc , char *argv[])
{
	int *value_ptr;
    pthread_t wtid,rtid;
	
	key_t key;
	int shmid,cntr;

	
	/*���������ڴ�*/
	key = ftok(".",'B');

	if((shmid = shmget(key,BUFF_MAX,IPC_CREAT|0666)) == -1)
	{
		perror("shmget");
		return 1;
	}

	/*�ѹ����ڴ�ӳ�䵽����*/
	if((my_box = (struct mailbox *)shmat(shmid,0,0)) == -1)
	{
		perror("shmat");
		 return 1;
	}

	/*��ʼ����ָ��*/
	my_box ->iTail = 0;
	my_box ->kTail = 0;
	my_box ->iHead = 0;
	my_box ->kHead = 0;

	/*�����ж�*/
	if(argc != 3)
	{
			printf("error:please input two files name.\n");
			return 2;
	}
	
	if(pthread_create(&rtid,NULL,(void *)maillbox_write,argv[2]) != 0)
	{
			printf("error: Can not create maillbox_write.\n");
			return 3;
	}
	

	if(pthread_create(&wtid,NULL,(void *)maillbox_read,argv[1]) != 0)
	{
			printf("error: Can not create maillbox_read.\n");
			return 3;
	}

	/*�ȴ������̽���*/	
	pthread_join(wtid,(void **)&value_ptr); 

	/*�ȴ�д���̽���*/
	while(my_box->kHead != -1){}
	
	printf(" over \n");
	
	
	return 0;
}



