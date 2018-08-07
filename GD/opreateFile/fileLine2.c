#include <stdio.h>
#include <stdlib.h>
#define MAX_LENTH 1024
/**********************************************************
功能描述:按行读写文件
涉及知识:行I/O相关函数
1)未格式化行I/O函数:fgets(),gets(),fputs(),puts()
2)格式化行I/O函数:scanf(),fscanf(),printf(),fprintf()



 **********************************************************/
void printLine(char *path , char *dest);
int main()
{
	char *path = "/home/magc/software/test1.txt";
	char *dest = "/home/magc/software/dest.txt";
	printLine(path,dest);
	return 0;
}

void printLine(char *path , char *dest)
{
	char buffer[MAX_LENTH];//以一个字符数组为缓存,按行读取内容,每次按一个字符串来处理
	int num = 1;
	FILE *pf = fopen(path,"r");
	FILE *df = fopen(dest,"w");
	if(pf != NULL&&df !=NULL)
	{
		perror("file not open ");

	}
	while(fgets(buffer,MAX_LENTH,pf)!=NULL)
	{
		printf("No.%d:%s\n",num,buffer);
		fputs(buffer,df);
		num++;
	}


	fclose(pf);

}
