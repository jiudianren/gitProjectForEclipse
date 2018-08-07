/*
 * pthread_server.c
 *
 *  Created on: 2016年8月9日
 *      Author: Administrator
 */


/***************************************************
 * 文件名：pthread_server.c
 * 文件描述：创建子线程来接收客户端的数据
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
	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);//创建套接字

	int on = 1;


	//bind API 函数将允许地址的立即重用
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

	//	bind(server_sockfd, (struct sockaddr *)&server_address, server_len);//绑定套接字
	//	templen = sizeof(struct sockaddr);


	if(listen(server_sockfd,ListenNum)<0)
	{
		//		cout<<"listen error"<<endl;
		printf("listen error");
		exit(0);
	}



	//jdr:如何在没有连接的时候，退出socket的接收主线程？
	printf("server waiting for connect. \n");
	while(1){
		pthread_t thread;//创建不同的子线程以区别不同的客户端
		client_sockfd = (int *)malloc(sizeof(int));
		client_len = sizeof(client_address);
		*client_sockfd = accept(server_sockfd,(struct sockaddr *)&client_address, (socklen_t *)&client_len);
		if(-1==*client_sockfd){
			perror("accept");
			continue;
		}
		if(pthread_create(&thread, NULL, rec_data, client_sockfd)!=0)//创建子线程
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
 * 函数名称：rec_data
 * 功能描述：接受客户端的数据
 * 参数列表：fd——连接套接字
 * 返回结果：void
 *****************************************/
void *rec_data(void *fd)
{
	int client_sockfd;
	int i,byte;
	char char_recv[BUFFER_SIZE];//存放数据
	client_sockfd=*((int*)fd);
	while(1)
	{
		memset(char_recv,0,sizeof(char_recv));
		if((byte=recv(client_sockfd,char_recv,sizeof(char_recv),0))==-1)
		{
			printf("byte: %d  \n",byte);//打印收到的数据
			perror("recv");
			exit(EXIT_FAILURE);
		}

		printf("conect: %d ,receive data: %s , size is :%d\n",&fd,char_recv,sizeof(char_recv));//打印收到的数据

		send(client_sockfd, char_recv, sizeof(char_recv), 0);
		if(strcmp(char_recv, "end")==0)//接受到exit时，跳出循环
		{
//			printf(" it is end going to break");
			break;
		}
	}
	printf("conect: %d 	is going to closed \n",&fd);//打印收到的数据
	free(fd);
	close(client_sockfd);
	pthread_exit(NULL);
}

