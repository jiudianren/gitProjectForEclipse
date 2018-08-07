#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/shm.h>

#include "mailbox.h"


int maillbox_bread(const char *w_path)
{
	FILE *w_fp;	
	int sizen;
	char tmp_buff[SIZE];
	int tmp;
	int tmp_kHead;
	

	if(NULL == (w_fp= fopen(w_path , "r")))
	{
			printf("error: Can not open %s .\n",w_path);
			
			pthread_exit((void *)1);
	}
	
	
	while(1)
	{

		
		tmp_kHead = my_box->kHead;
		if(((my_box->kTail + 1) % BUFF_MAX)  ==  tmp_kHead)  
		{
			continue ;
		}
		

		
		if((sizen = fread(tmp_buff,1,SIZE,w_fp)) == 0 ) 
		{
				while(1)
				{
					if(my_box->kHead == my_box->kTail)
					{	
						my_box->kHead = -1;
						fclose(w_fp);
						pthread_exit((void *)1);
					}
				}
		}
		

		for(tmp= 0;tmp < sizen; tmp++ )
		{
		
			my_box->bBuff[my_box->kTail] = tmp_buff[tmp];

		
			while((my_box->kTail + 1)%BUFF_MAX  ==  my_box->kHead)
			{	
		
			}

			my_box->kTail = (my_box->kTail + 1)%BUFF_MAX;
		}
	}
}



int maillbox_bwrite(const char *r_path)
{
    
	FILE *fp;
	int i,j;
	int sizen;
	int p_sizen ;
	int tmp_iTail;
	
	if(NULL == (fp = fopen(r_path , "w")))
	{
			printf("error: Can not open %s.\n",r_path);
			
			pthread_exit((void *)1);
	}
				
	while(1)
	{
		tmp_iTail = my_box->iTail;

		if((my_box->iHead == tmp_iTail) ) 
		{
			continue ;
		}

		if(my_box->iHead ==-1)
		{
			break;
		}
	
		if(tmp_iTail > my_box->iHead)
		{
			p_sizen = tmp_iTail - my_box->iHead;			

			if((sizen = fwrite(my_box->cBuff+my_box->iHead,p_sizen, 1 ,fp)) < 0) 
			{
				fclose(fp);
				printf("1+%d++%d\n",my_box->iHead,my_box->iTail);
				pthread_exit((void *)2);
			}
		
			my_box->iHead += p_sizen;
		
		}
		

		else
		{
			p_sizen = BUFF_MAX - my_box->iHead ;
			
			if((sizen = fwrite(my_box->cBuff+my_box->iHead,p_sizen, 1 ,fp)) < 0) 
			{
				fclose(fp);

				pthread_exit((void *)2);
			}
			
	

			p_sizen = tmp_iTail;

			if((sizen = fwrite(my_box->cBuff,p_sizen, 1 ,fp)) < 0) 
			{
				fclose(fp);
			
				pthread_exit((void *)2);
			}

			my_box->iHead = tmp_iTail;
		}
		
	}
}


int main(int argc , char *argv[])
{
	int *value_ptr;
    pthread_t wtid,rtid;
	
	key_t key;
	int shmid,cntr;

	

	key = ftok(".",'B');

	if((shmid = shmget(key,BUFF_MAX,IPC_CREAT|0666)) == -1)
	{
		perror("shmget");
		return 1;
	}

	if((my_box = (struct mailbox *)shmat(shmid,0,0)) == -1)
	{
		perror("shmat");
		 return 1;
	}

	if(argc != 3)
	{
			printf("error:please input two files name.\n");
			return -1;
	}
	
	if(pthread_create(&rtid,NULL,(void *)maillbox_bwrite,argv[2]) != 0)
	{
			printf("error: Can not create maillbox_write.\n");
			return -2;
	}
	

	if(pthread_create(&wtid,NULL,(void *)maillbox_bread,argv[1]) != 0)
	{
			printf("error: Can not create maillbox_read.\n");
			return -2;
	}

		
	pthread_join(wtid,(void **)&value_ptr); 
	
	while(my_box->iHead != -1){}
	
	printf(" over \n");
	
	
	return 0;
}



