/*
 * readfile.c
 *
 *  Created on: 2016年8月16日
 *      Author: Administrator
 */




#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int c=0;//临时变量。
	int cnt = 0; //标记目前读到几个字节。

	char * path=get_current_dir_name();
	char * filename="/chars";

	printf("dir:%s\n",path);
	path=strcat(path,filename);

	printf("path :dir:%s\n",path);
	//使用path打不开文件
	char * path1="/home/phub/gd/core/chars";
	printf("path1 :dir:%s\n",path1);
	printf("path1: %d ,path :%d length \n",strlen(path1),strlen(path));
	printf("stcmp:%d \n", strcmp(path,path1));

	const char * path3=path;
//	strcpy(path3,path);
	printf("path3 :dir:%s\n",path3);


//gdb 调试的时候，可以控制程序执行，所以下面三行可以有选择的执行
//	FILE *pf = fopen(path,"r");
//	FILE *pf = fopen(path1,"r");
	FILE *pf = fopen(path3,"r");
	if(pf==NULL) //打开文件。
	{
		printf("Cannot open file, press any key to exit!\n");
		exit(1);
	}


	while(1)
	{
		c = fgetc(pf); //读一个字节。
		if(c == EOF) break; //到文件尾，退出循环。
		printf("%d",c);
//		buf[cnt] = c;//赋值到字符数组中。
		cnt ++;//读到的字符增加一个。
	}
	fclose(pf);//关闭文件。
	return 0;
}
