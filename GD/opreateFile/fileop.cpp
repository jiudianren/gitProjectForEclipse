/*
 * fileop.c
 *
 *  Created on: 2016年8月11日
 *      Author: Administrator
 */




#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include <stdio.h>
#include <string>
#include "stdio.h"
#include <iostream>

#include <errno.h>  /* for strerror */
using namespace std;
#define MAX_LENTH 1024

//bug:重新写入是的时候，第一行，永远为空，这是个问题
void writeToLine(FILE * pf,int lineNume, char input []);

int main()
{

	int fd;//filedesrciption
	char tempFileName[BUFSIZ];
	char  fileName[BUFSIZ];
	char buffer[BUFSIZ];
	int bytes_read,bytes_write;
	int   fileExistFlag=0;//0表示之前不存在 ，1表示之前存在 exist
	int   truncFlag=0;//0表示不覆盖原文件 ，1表示覆盖源文件
	printf("请输入文件名（如果已经存在将打开该文件，如果不存在则会创建该文件）：\n");
	scanf ("%s",tempFileName);
	strcpy(fileName, tempFileName);


	fd=open(fileName,O_RDWR|O_CREAT|O_EXCL,10705);
	if(fd==-1)
	{
		fileExistFlag=1;
		printf("文件:%s已经存在.\n",fileName);
		printf("如果需要覆盖该文件请输入y:\n");
		char reWriteFlag[1];
		scanf ("%s",reWriteFlag);
		if(reWriteFlag[0]=='y')
		{
			fd=open(fileName,O_RDWR|O_TRUNC);
			//已经覆盖了旧文件，将其视为新文件
			fileExistFlag=0;
		}
		else
		{
			fd=open(fileName,O_RDWR);
		}
	}

	close(fd);

	char * path=fileName;
	FILE *pf = fopen(path,"r+");

	int lineNum=0;
	char input[BUFSIZ];
	int num = 1;

	//jdr:显示该文件内容
	if(fileExistFlag==1)
	{

		printf("文件: %s内容如下 ：\n",fileName);

		if(pf == NULL)
		{
			perror("文件 没有被打开\n");
		}
		while(fgets(buffer,MAX_LENTH,pf)!=NULL)
		{
			printf("No.%d:%s",num,buffer);
			num++;
		}
		printf("文件将要被修改：\n");

	}else
	{
		printf("文件:%s还是空的，它将要被修改\n",fileName);
	}

	string temp;
	if(fseek(pf,0,SEEK_SET)<0)
	{
		printf("fseek 出错");
	}
	while(strncmp(input, "end", 3) != 0)
	{
		if(fileExistFlag==1)
		{
			printf("请输入要修改的行号：在（1-%d）\n",num);
			scanf("%d",&lineNum);
			printf("请输入要修改的内容：\n");
			getline(cin,temp);
			strcpy(input,temp.c_str());
			printf("input：%s\n",input);
			//			scanf("%s",input);
			writeToLine(pf,lineNum,input);
		}else
		{
			//重新写入是的时候，第一行，永远为空，这是个问题
			//jdr：如何一次输入一个整行？？
			printf(" 请输入要修改的内容：\n");
			getline(cin,temp);
			strcpy(input,temp.c_str());
			printf("input：%s\n",input);

			if(pf == NULL)
			{
				perror("fputs 文件 没有被打开\n");
			}
			if(fputs(input,pf)<0)
			{
				printf("写入错误");
			}
			fputc('\n',pf);
		}
	}
	fclose(pf);
}



void writeToLine(FILE * pf,int lineNum, char input [])
{
	char buffer[BUFSIZ];
	int num = 1;
	if(pf == NULL)
	{
		perror("文件 没有被打开\n");
	}

	if(fseek(pf,0,SEEK_SET)<0)
	{
		printf("fseek 出错");
	}
	if(lineNum==1)
	{
		fputs(input,pf);
		printf("修改结束\n");
	}
	else
	{
		if(fseek(pf,0,SEEK_SET)<0)
		{
			printf("fseek 出错");
		}
		while(fgets(buffer,MAX_LENTH,pf)!=NULL)
		{
			//			printf("No.%d:%s",num,buffer);
			num++;
			if(num==lineNum)
			{
				break;
			}
		}
		fputs(input,pf);
		fputc('\n',pf);
		printf("修改结束\n");
	}
	while(fgets(buffer,MAX_LENTH,pf)!=NULL)
	{
		//		printf("No.%d:%s",num,buffer);
		num++;
	}
	num=1;
}
