/*
 * open1.c
 *
 *  Created on: 2016��8��11��
 *      Author: Administrator
 */


//fileopen.c

#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{

	char temp[]="hello,this is open1 !";
	int fd;
	char pathname[255];
	if((fd=open("fo.txt",O_WRONLY|O_CREAT,0640))==-1)
	{
		printf("creat file wrong!");
	}
//	int len=strlen(temp)+1;
	//jdr:ΪʲôĩβҪ��1,�������1��
	int len=strlen(temp);
	write(fd,temp,len);//��fdΪ0��������ֱ��д0������������Ļ�϶���д���ļ���
	close(fd);
}
