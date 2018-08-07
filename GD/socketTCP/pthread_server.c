/*
 * pthread_server.c
 *
 *  Created on: 2016��8��9��
 *      Author: Administrator
 */


/***************************************************
 * �ļ�����pthread_server.c
 * �ļ��������������߳������տͻ��˵�����
 ***************************************************/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#define ListenNum 20
#define BUFFER_SIZE 1024
#define MYPORT  9733
void *rec_data(void *fd);
int main(int argc,char *argv[])
{
	int server_sockfd;
	int *client_sockfd;
	int server_len, client_len;
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;
	struct sockaddr_in tempaddr;
	int i,byte;
	char char_recv,char_send;
	//	socklen_t templen;
	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);//�����׽���

	int on = 1;


	//bind API �����������ַ����������
	if (setsockopt(server_sockfd, SOL_SOCKET, SO_REUSEADDR,  &on, sizeof(on)) < 0)
	{
		perror("setsockopet error\n");
		return -1;
	}

	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr =  htonl(INADDR_ANY);
	server_address.sin_port = htons(MYPORT);
	server_len = sizeof(server_address);

	if(bind(server_sockfd, (struct sockaddr *)&server_address, server_len)==-1)
	{
		perror("bind");
		exit(1);
	}

	//	bind(server_sockfd, (struct sockaddr *)&server_address, server_len);//���׽���
	//	templen = sizeof(struct sockaddr);


	if(listen(server_sockfd,ListenNum)<0)
	{
		//		cout<<"listen error"<<endl;
		printf("listen error");
		exit(0);
	}



	//jdr:�����û�����ӵ�ʱ���˳�socket�Ľ������̣߳�
	printf("server waiting for connect. \n");
	while(1){
		pthread_t thread;//������ͬ�����߳�������ͬ�Ŀͻ���
		client_sockfd = (int *)malloc(sizeof(int));
		client_len = sizeof(client_address);
		*client_sockfd = accept(server_sockfd,(struct sockaddr *)&client_address, (socklen_t *)&client_len);
		if(-1==*client_sockfd){
			perror("accept");
			continue;
		}
		if(pthread_create(&thread, NULL, rec_data, client_sockfd)!=0)//�������߳�
		{
			perror("pthread_create");
			break;
		}
	}
//	shutdown(*client_sockfd,2);
//	shutdown(server_sockfd,2);
	close(server_sockfd);
}
/*****************************************
 * �������ƣ�rec_data
 * �������������ܿͻ��˵�����
 * �����б�fd���������׽���
 * ���ؽ����void
 *****************************************/
void *rec_data(void *fd)
{
	int client_sockfd;
	int i,byte;
	char char_recv[BUFFER_SIZE];//�������
	client_sockfd=*((int*)fd);
	while(1)
	{
		memset(char_recv,0,sizeof(char_recv));
		if((byte=recv(client_sockfd,char_recv,sizeof(char_recv),0))==-1)
		{
			printf("byte: %d  \n",byte);//��ӡ�յ�������
			perror("recv");
			exit(EXIT_FAILURE);
		}

		printf("conect: %d ,receive data: %s , size is :%d\n",&fd,char_recv,sizeof(char_recv));//��ӡ�յ�������

		send(client_sockfd, char_recv, sizeof(char_recv), 0);
		if(strcmp(char_recv, "end")==0)//���ܵ�exitʱ������ѭ��
		{
//			printf(" it is end going to break");
			break;
		}
	}
	printf("conect: %d 	is going to closed \n",&fd);//��ӡ�յ�������
	free(fd);
	close(client_sockfd);
	pthread_exit(NULL);
}

