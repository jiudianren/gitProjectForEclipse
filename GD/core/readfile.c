/*
 * readfile.c
 *
 *  Created on: 2016��8��16��
 *      Author: Administrator
 */




#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int c=0;//��ʱ������
	int cnt = 0; //���Ŀǰ���������ֽڡ�

	char * path=get_current_dir_name();
	char * filename="/chars";

	printf("dir:%s\n",path);
	path=strcat(path,filename);

	printf("path :dir:%s\n",path);
	//ʹ��path�򲻿��ļ�
	char * path1="/home/phub/gd/core/chars";
	printf("path1 :dir:%s\n",path1);
	printf("path1: %d ,path :%d length \n",strlen(path1),strlen(path));
	printf("stcmp:%d \n", strcmp(path,path1));

	const char * path3=path;
//	strcpy(path3,path);
	printf("path3 :dir:%s\n",path3);


//gdb ���Ե�ʱ�򣬿��Կ��Ƴ���ִ�У������������п�����ѡ���ִ��
//	FILE *pf = fopen(path,"r");
//	FILE *pf = fopen(path1,"r");
	FILE *pf = fopen(path3,"r");
	if(pf==NULL) //���ļ���
	{
		printf("Cannot open file, press any key to exit!\n");
		exit(1);
	}


	while(1)
	{
		c = fgetc(pf); //��һ���ֽڡ�
		if(c == EOF) break; //���ļ�β���˳�ѭ����
		printf("%d",c);
//		buf[cnt] = c;//��ֵ���ַ������С�
		cnt ++;//�������ַ�����һ����
	}
	fclose(pf);//�ر��ļ���
	return 0;
}
