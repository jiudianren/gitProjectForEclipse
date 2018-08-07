/*
 * open1.c
 *
 *  Created on: 2016年8月11日
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
	//jdr:为什么末尾要加1,如果不加1呢
	int len=strlen(temp);
	write(fd,temp,len);//若fd为0，或这里直接写0，则会输出到屏幕上而不写入文件中
	close(fd);
}
