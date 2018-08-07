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
	int sizen;			 	/*标记从文件中读了多少字节*/	
	char tmp_buff[SIZE];	/*读缓冲*/
	int tmp;			
	int tmp_iHead;			/*存储头指针*/

	if(NULL == (w_fp= fopen(w_path , "r")))
	{
			printf("error: Can not open %s .\n",w_path);
			
			pthread_exit((void *)1);
	}
	
	
	while(1)
	{

		tmp_iHead = my_box->iHead;

		/*判断邮箱是否满了*/
		if(((my_box->iTail + 1) % BUFF_MAX)  ==  tmp_iHead)  
		{
			continue ;
		}

		/*从文件读到缓冲区*/
		if((sizen = fread(tmp_buff,1,SIZE,w_fp)) == 0 ) 
		{
				while(1)
				{
					if(my_box->iHead == my_box->iTail)  	/*读写结束*/
					{	
						my_box->iHead = -1;					/*标记读写已结束*/
					
						fclose(w_fp);
						pthread_exit((void *)1);
					}
				}
		}
		
		/*写到邮箱*/
		for(tmp= 0;tmp < sizen; tmp++ )
		{
		
			my_box->cBuff[my_box->iTail] = tmp_buff[tmp];


			/*防止写满了*/
			while((my_box->iTail + 1)%BUFF_MAX  ==  my_box->iHead)
			{	

		
			}
			/*移动尾指针*/
			my_box->iTail = (my_box->iTail + 1)%BUFF_MAX;
		}
	}
}



int maillbox_write(const char *r_path)
{
    
	FILE *fp;
	int sizen; 
	int p_sizen ; 	
	int tmp_kTail; 	/*存储尾指针*/
	
	if(NULL == (fp = fopen(r_path , "w")))
	{
			printf("error: Can not open %s.\n",r_path);
			
			pthread_exit((void *)1);
	}
	
		
	while(1)
	{	
		tmp_kTail = my_box->kTail;

		/*判断是否为空*/
		if((my_box->kHead == tmp_kTail) ) 
		{
			continue ;
		}

		/*判断读写是否结束*/
		if(my_box->kHead ==-1)
		{
			break;
		}
	
	
		/*写到文件中，判断尾指针位置是否以循环了一次*/		
		if(tmp_kTail > my_box->kHead)
		{
			p_sizen = tmp_kTail - my_box->kHead;		/*判断邮箱中有多少数据*/		
			
			if((sizen = fwrite(my_box->bBuff+my_box->kHead,p_sizen, 1 ,fp)) < 0) 
			{
				fclose(fp);
				
				pthread_exit((void *)2);
			}
		
			my_box->kHead += p_sizen;
	
		}
		

		/*已经循环了一次*/
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

	
	/*创建共享内存*/
	key = ftok(".",'B');

	if((shmid = shmget(key,BUFF_MAX,IPC_CREAT|0666)) == -1)
	{
		perror("shmget");
		return 1;
	}

	/*把共享内存映射到邮箱*/
	if((my_box = (struct mailbox *)shmat(shmid,0,0)) == -1)
	{
		perror("shmat");
		 return 1;
	}

	/*初始化话指针*/
	my_box ->iTail = 0;
	my_box ->kTail = 0;
	my_box ->iHead = 0;
	my_box ->kHead = 0;

	/*参数判断*/
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

	/*等待读进程结束*/	
	pthread_join(wtid,(void **)&value_ptr); 

	/*等待写进程结束*/
	while(my_box->kHead != -1){}
	
	printf(" over \n");
	
	
	return 0;
}



