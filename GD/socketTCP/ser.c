/*
 * ser.c
 *
 *  Created on: 2016年8月9日
 *      Author: Administrator
 */




#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>

#define MYPORT  8887
#define QUEUE   20
#define BUFFER_SIZE 1024

int main()
{






	///定义sockfd
	int server_sockfd = socket(AF_INET,SOCK_STREAM, 0);

	int on = 1;

	//bind API 函数将允许地址的立即重用
	if (setsockopt(server_sockfd, SOL_SOCKET, SO_REUSEADDR,  &on, sizeof(on)) < 0)
	{
		perror("setsockopet error\n");
		return -1;
	}
	int quit=1;
	///定义sockaddr_in
	struct sockaddr_in server_sockaddr;
	server_sockaddr.sin_family = AF_INET;
	server_sockaddr.sin_port = htons(MYPORT);
	server_sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	///bind，成功返回0，出错返回-1
	if(bind(server_sockfd,(struct sockaddr *)&server_sockaddr,sizeof(server_sockaddr))==-1)
	{
		perror("bind");
		exit(1);
	}

	///listen，成功返回0，出错返回-1
	if(listen(server_sockfd,QUEUE) == -1)
	{
		perror("listen");
		exit(1);
	}

	///客户端套接字
	char buffer[BUFFER_SIZE];
	struct sockaddr_in client_addr;
	socklen_t length = sizeof(client_addr);

	///成功返回非负描述字，出错返回-1
	int conn = accept(server_sockfd, (struct sockaddr*)&client_addr, &length);
	if(conn<0)
	{
		perror("connect");
		exit(1);
	}

	while(quit==1)
	{
		memset(buffer,0,sizeof(buffer));
		int len = recv(conn, buffer, sizeof(buffer),0);
		if(strcmp(buffer,"exit\n")==0)
			break;
		fputs(buffer, stdout);
		send(conn, buffer, len, 0);
		if(strncmp(buffer, "end", 3) == 0)
		{
			quit=0;
		}
	}
	close(conn);
	close(server_sockfd);
	return 0;
}
