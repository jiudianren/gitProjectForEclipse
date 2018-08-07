
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
		cout<<"请输入你选择操作的序列号："<<endl;
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
	printf("0，退出操作\n");
	printf("1:空指针\n");
	printf("2:野指针\n");
	printf("3:数组越界\n");
	printf("4:字符串溢出\n");
	printf("5:空指针2\n");
	printf("6:操作NULL指针\n");
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
		printf("输入的选项不对。");
	}
}
void opreatNullPoint()
{
	char *p=NULL,*p1="hello first!";
	while((*(p++) = *(p1++)) != 0);

}

static void _null_pointer_test(void)
{

	//jdr:，因为它尝试操作地址为0的内存区域，而这个内存区域通常是不可访问的禁区，当然就会出错了
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
	cout<<"现在strl为："<<str<<endl;
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

	char buf[10240];//定义一个足够大的字符数组存文件数据。
	int tempChar;//临时变量。
	int cnt = 0; //标记目前读到几个字节。
	FILE *fp=NULL;//文件指针。

	char * path="/home/phub/gd/core/chars";
	printf("dir:%s\n",path);

	fp = fopen(path, "r");
	if(fp==NULL) //打开文件。
	{
		printf("Cannot open file, press any key to exit!");
		exit(1);
	}


	while(1)
	{
		tempChar = fgetc(fp); //读一个字节。
		if(tempChar == EOF) break; //到文件尾，退出循环。

		buf[cnt] = tempChar;//赋值到字符数组中。
		cnt ++;//读到的字符增加一个。
	}

	fclose(fp);//关闭文件。

//	printf("buf: %s",buf);
//	printf("s = %s, size of s=%d, strlen s = %d\n", BoundChars, sizeof BoundChars, strlen (BoundChars));

	//将字符串数组，转化为字符串指针
	int l=sizeof(buf)/sizeof(char);;
	char * StringPoint=buf;
	*(StringPoint+l)='\0';
//	printf("%s",StringPoint);
	strcpy(BoundChars, StringPoint);
	cout<<BoundChars<<endl;
//	printf("s = %s, size of s=%d, strlen s = %d\n", BoundChars, sizeof BoundChars, strlen (BoundChars));

}


