#include <stdio.h>
#include <stdlib.h>
#define MAX_LENTH 1024
/**********************************************************
��������:���ж�д�ļ�
�漰֪ʶ:��I/O��غ���
1)δ��ʽ����I/O����:fgets(),gets(),fputs(),puts()
2)��ʽ����I/O����:scanf(),fscanf(),printf(),fprintf()



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
	char buffer[MAX_LENTH];//��һ���ַ�����Ϊ����,���ж�ȡ����,ÿ�ΰ�һ���ַ���������
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
