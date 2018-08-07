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
	///����sockfd
	int sock_cli = socket(AF_INET,SOCK_STREAM, 0);
	int quit=1;
	///����sockaddr_in
	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(MYPORT);  ///�������˿�
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");  ///������ip

	///���ӷ��������ɹ�����0�����󷵻�-1
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
			send(sock_cli, sendbuf, strlen(sendbuf),0); ///����
			if(strcmp(sendbuf,"exit\n")==0)
				break;
			recv(sock_cli, recvbuf, sizeof(recvbuf),0); ///����
			printf("socketserver�����ı�����Ϊ��\n");
			fputs(recvbuf, stdout);
			printf("\n");

			if(strncmp(sendbuf, "end", 3) == 0)
			{
				quit=0;
			}

			//jdr�������Ǹ��Ϊʲô��ô��
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
