
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;


void 			tips();
void 			opearation(int opn);
static void 	_null_pointer_test(void);
static void 	_null_pointer_test2(void);
void 			outBound();
void 			wildPoint( void )  ;
void 			opreatNullPoint();
void 			outBoundOfString();
void 			readfile();

struct obs
{
	int first;
	char str [1] ;
	int second;
};

int main()
{
	int selectN=1;
	while(1)
	{
		cout<<"��������ѡ����������кţ�"<<endl;
		tips();
		cin>>selectN;
		if(selectN !=0)
		{

			opearation(selectN );
		}else
		{
			break;
		}
	}
	return 0;
}

void tips()
{
	printf("0���˳�����\n");
	printf("1:��ָ��\n");
	printf("2:Ұָ��\n");
	printf("3:����Խ��\n");
	printf("4:�ַ������\n");
	printf("5:��ָ��2\n");
	printf("6:����NULLָ��\n");
}


void opearation(int opn)
{

	switch(opn)
	{
	case 1:
		_null_pointer_test();
		break;
	case 2:
		wildPoint();
		break;
	case 3:
		outBound();
		break;
	case 4:
		outBoundOfString();
		break;
	case 5:
		_null_pointer_test2();
		break;
	case 6:
		opreatNullPoint();
		break;
	default:
		printf("�����ѡ��ԡ�");
	}
}
void opreatNullPoint()
{
	char *p=NULL,*p1="hello first!";
	while((*(p++) = *(p1++)) != 0);

}

static void _null_pointer_test(void)
{

	//jdr:����Ϊ�����Բ�����ַΪ0���ڴ����򣬶�����ڴ�����ͨ���ǲ��ɷ��ʵĽ�������Ȼ�ͻ������
	char *ps_str = 0;
	*ps_str = 'o';
	return;
}

static void _null_pointer_test2(void)
{
	char *ps_str = 0;
	strcpy(ps_str, "_null_pointer_test");
	return;
}
void wildPoint( void )
{
	char* str = new char[100];
	delete[] str;
	// Do something
	char temp='c';
	str=&temp;
	strcpy( str, "Dangerous!!" );
	cout<<"����strlΪ��"<<str<<endl;
}
void outBound()
{
	int aa[5]={1,2,3};
	int i = 1;
	for (i=0;i<10;i++)
		aa[i]=i;
	printf("f()/n");
}

void outBoundOfString()
{
	char BoundChars[4] = {'1','2','3','4'};

	char buf[10240];//����һ���㹻����ַ�������ļ����ݡ�
	int tempChar;//��ʱ������
	int cnt = 0; //���Ŀǰ���������ֽڡ�
	FILE *fp=NULL;//�ļ�ָ�롣

	char * path="/home/phub/gd/core/chars";
	printf("dir:%s\n",path);

	fp = fopen(path, "r");
	if(fp==NULL) //���ļ���
	{
		printf("Cannot open file, press any key to exit!");
		exit(1);
	}


	while(1)
	{
		tempChar = fgetc(fp); //��һ���ֽڡ�
		if(tempChar == EOF) break; //���ļ�β���˳�ѭ����

		buf[cnt] = tempChar;//��ֵ���ַ������С�
		cnt ++;//�������ַ�����һ����
	}

	fclose(fp);//�ر��ļ���

//	printf("buf: %s",buf);
//	printf("s = %s, size of s=%d, strlen s = %d\n", BoundChars, sizeof BoundChars, strlen (BoundChars));

	//���ַ������飬ת��Ϊ�ַ���ָ��
	int l=sizeof(buf)/sizeof(char);;
	char * StringPoint=buf;
	*(StringPoint+l)='\0';
//	printf("%s",StringPoint);
	strcpy(BoundChars, StringPoint);
	cout<<BoundChars<<endl;
//	printf("s = %s, size of s=%d, strlen s = %d\n", BoundChars, sizeof BoundChars, strlen (BoundChars));

}


