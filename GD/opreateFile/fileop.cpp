/*
 * fileop.c
 *
 *  Created on: 2016��8��11��
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

//bug:����д���ǵ�ʱ�򣬵�һ�У���ԶΪ�գ����Ǹ�����
void writeToLine(FILE * pf,int lineNume, char input []);

int main()
{

	int fd;//filedesrciption
	char tempFileName[BUFSIZ];
	char  fileName[BUFSIZ];
	char buffer[BUFSIZ];
	int bytes_read,bytes_write;
	int   fileExistFlag=0;//0��ʾ֮ǰ������ ��1��ʾ֮ǰ���� exist
	int   truncFlag=0;//0��ʾ������ԭ�ļ� ��1��ʾ����Դ�ļ�
	printf("�������ļ���������Ѿ����ڽ��򿪸��ļ��������������ᴴ�����ļ�����\n");
	scanf ("%s",tempFileName);
	strcpy(fileName, tempFileName);


	fd=open(fileName,O_RDWR|O_CREAT|O_EXCL,10705);
	if(fd==-1)
	{
		fileExistFlag=1;
		printf("�ļ�:%s�Ѿ�����.\n",fileName);
		printf("�����Ҫ���Ǹ��ļ�������y:\n");
		char reWriteFlag[1];
		scanf ("%s",reWriteFlag);
		if(reWriteFlag[0]=='y')
		{
			fd=open(fileName,O_RDWR|O_TRUNC);
			//�Ѿ������˾��ļ���������Ϊ���ļ�
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

	//jdr:��ʾ���ļ�����
	if(fileExistFlag==1)
	{

		printf("�ļ�: %s�������� ��\n",fileName);

		if(pf == NULL)
		{
			perror("�ļ� û�б���\n");
		}
		while(fgets(buffer,MAX_LENTH,pf)!=NULL)
		{
			printf("No.%d:%s",num,buffer);
			num++;
		}
		printf("�ļ���Ҫ���޸ģ�\n");

	}else
	{
		printf("�ļ�:%s���ǿյģ�����Ҫ���޸�\n",fileName);
	}

	string temp;
	if(fseek(pf,0,SEEK_SET)<0)
	{
		printf("fseek ����");
	}
	while(strncmp(input, "end", 3) != 0)
	{
		if(fileExistFlag==1)
		{
			printf("������Ҫ�޸ĵ��кţ��ڣ�1-%d��\n",num);
			scanf("%d",&lineNum);
			printf("������Ҫ�޸ĵ����ݣ�\n");
			getline(cin,temp);
			strcpy(input,temp.c_str());
			printf("input��%s\n",input);
			//			scanf("%s",input);
			writeToLine(pf,lineNum,input);
		}else
		{
			//����д���ǵ�ʱ�򣬵�һ�У���ԶΪ�գ����Ǹ�����
			//jdr�����һ������һ�����У���
			printf(" ������Ҫ�޸ĵ����ݣ�\n");
			getline(cin,temp);
			strcpy(input,temp.c_str());
			printf("input��%s\n",input);

			if(pf == NULL)
			{
				perror("fputs �ļ� û�б���\n");
			}
			if(fputs(input,pf)<0)
			{
				printf("д�����");
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
		perror("�ļ� û�б���\n");
	}

	if(fseek(pf,0,SEEK_SET)<0)
	{
		printf("fseek ����");
	}
	if(lineNum==1)
	{
		fputs(input,pf);
		printf("�޸Ľ���\n");
	}
	else
	{
		if(fseek(pf,0,SEEK_SET)<0)
		{
			printf("fseek ����");
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
		printf("�޸Ľ���\n");
	}
	while(fgets(buffer,MAX_LENTH,pf)!=NULL)
	{
		//		printf("No.%d:%s",num,buffer);
		num++;
	}
	num=1;
}
