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

#define MYPORT  9733
#define BUFFER_SIZE 1024

int main()
{
	///定义sockfd
	int sock_cli = socket(AF_INET,SOCK_STREAM, 0);
	int quit=1;
	///定义sockaddr_in
	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(MYPORT);  ///服务器端口
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");  ///服务器ip

	///连接服务器，成功返回0，错误返回-1
	if (connect(sock_cli, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
	{
		perror("connect");
		exit(1);
	}

	char sendbuf[BUFFER_SIZE];
	char recvbuf[BUFFER_SIZE];

	while(quit==1)
	{
		if(scanf("%s",sendbuf)>=0)
//		if(fgets(sendbuf, sizeof(sendbuf), stdin) != NULL)
		{
			printf("sendbut: %s ,size :%d\n",sendbuf, sizeof(sendbuf));
			send(sock_cli, sendbuf, strlen(sendbuf),0); ///发送
			if(strcmp(sendbuf,"exit\n")==0)
				break;
			recv(sock_cli, recvbuf, sizeof(recvbuf),0); ///接收
			printf("socketserver将其文本返回为：\n");
			fputs(recvbuf, stdout);
			printf("\n");

			if(strncmp(sendbuf, "end", 3) == 0)
			{
				quit=0;
			}

			//jdr：这里是干嘛？为什么这么做
			memset(sendbuf, 0, sizeof(sendbuf));
			memset(recvbuf, 0, sizeof(recvbuf));

		}else
		{
			printf("pleast input something (end to end) :\n");
		}
	}

	close(sock_cli);
	return 0;
}
