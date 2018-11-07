

/*
 * https://blog.csdn.net/callinglove/article/details/8597189
 *
 * */

#include  <string.h>
#include <assert.h>

char * strcpy1(char *dst, const char *src) //[1]
{
	assert(dst != NULL && src != NULL);  //[2]
	char *ret = dst;                     //[3]
	while ((*dst++ = *src++) != '\0');   //[4]
	return ret;
}




/*
 *
 * 【1】const修饰
源字符串参数用const修饰，防止修改源字符串。

【2】空指针检查
(A)不检查指针的有效性，说明答题者不注重代码的健壮性。
(B)检查指针的有效性时使用assert(!dst && !src);
char *转换为bool即是类型隐式转换，这种功能虽然灵活，但更多的是导致出错概率增大和维护成本升高。
(C)检查指针的有效性时使用assert(dst != 0 && src != 0);
直接使用常量（如本例中的0）会减少程序的可维护性。而使用NULL代替0，如果出现拼写错误，编译器就会检查出来。

【3】返回目的指针
忘记保存dst的原值

【4】'\0'
循环写成while (*src!='\0') *dst++=*src++;
循环体结束后，dst字符串的末尾没有正确地加上'\0'。

2. 返回char *的原因
返回dst的原始值使函数能够支持链式表达式。
表达式的形式如：
int l=strlen(strcpy(strA,strB));
又如：
char * strA=strcpy(new char[10],strB);


返回strSrc的原始值是错误的。
其一，源字符串肯定是已知的，返回它没有意义。
其二，不能支持形如第二例的表达式。
其三，把const char *作为char *返回，类型不符，编译报错。
 *
 * */


void * my_memcpy(void  *dstt, const void * srcc, int cnt)
{
	assert(dstt != NULL && srcc != NULL);


	void  * ret = dstt;
	char * dst = (char *) dstt;
	char * src = (char *) srcc;
	if (dst >= src && dst <= src+cnt-1) //内存重叠，从高地址开始复制
	{
		dst = dst+cnt-1;
		src = src+cnt-1;
		while (cnt--)
			*dst-- = *src--;
	}
	else    //正常情况，从低地址开始复制
	{
		while (cnt--)
			*dst++ = *src++;
	}
	return ret;
}


char * strcpy2(char *dst,const char *src)
{
	assert(dst != NULL && src != NULL);
	char *ret = dst;
	my_memcpy(dst, src, strlen(src)+1);
	return ret;
}

/*
 *
 *
 * 4. strcpy和memcpy的区别。
1、复制的内容不同。strcpy只能复制字符串，而memcpy可以复制任意内容，例如字符数组、整型、结构体、类等。
2、复制的方法不同。strcpy不需要指定长度，它遇到被复制字符的串结束符"\0"才结束，
所以容易溢出。memcpy则是根据其第3个参数决定复制的长度。
3、用途不同。通常在复制字符串时用strcpy，而需要复制其他类型数据时则一般用memcpy
 *
 * */



void* my_memmove(void* dst,const void* src,size_t count)
{
	assert(NULL !=src && NULL !=dst);
	char* tmpdst = (char*)dst;
	char* tmpsrc = (char*)src;

	if (tmpdst <= tmpsrc || tmpdst >= tmpsrc + count)
	{
		while(count--)
		{
			*tmpdst++ = *tmpsrc++;
		}
	}
	else
	{
		tmpdst = tmpdst + count - 1;
		tmpsrc = tmpsrc + count - 1;
		while(count--)
		{
			*tmpdst-- = *tmpsrc--;
		}
	}

	return dst;
}



/*
 * atoi
1. 忽略字符串前的空白字符
2. 字符串所表示数值的正负号
3. 结束条件，遇到非数字或者字符'\0'结束
4. 考虑溢出，分别与int值所能表示的最大(0x7fffffff)和最小值(0x8000000)进行比较
5. 考虑异常输入情况下

由于可能出现的负面输入以及溢出情况，我们需要对结果进行判断，这里介绍一下三种错误处理方式：返回值、全局变量、异常。

返回值：和系统API一致； 但是不能方便的使用返回结果，并且会有二义性。

全局变量：用全局变量表示错误状态，能方便使用结果； 但是程序员可能会忘记检查全局变量。

异常：可以为不同的出错原因定义不同该异常类型，逻辑清晰明了； 有些语言不支持，同时对性能有一定程度上的负面影响。

atoi()函数实现的代码：strToInt()
 * */




#include <iostream>
#define INT_MAX ((int)0x7fffffff)
#define INT_MIN ((int)0x80000000)

enum Status{Valid = 0, Invalid, OutOfRange};
int g_status = Invalid;

int strToInt(const char* str){


	long long result=0; //8个字节长度
	int flag=1;//默认正数
	//判断指针是否为空
	if (str==NULL || *str=='\0')
		return 0;

	g_status = Invalid;
	//跳过前面的空白字符
	while(isspace(*str)){
		++str;
	}
	/*
	 *判断正负号
	 */
	if(*str=='-'){
		flag=-1;
		str++;
	}else if(*str=='+')
		str++;


	//把数字字符逐个转换成整数，并校验溢出,溢出返回0
	while(*str<='9' && *str>='0'){

		result=result*10+*str-'0';
		if(flag==1){
			//校验是否正溢出
			if(result>INT_MAX)
			{
				g_status = OutOfRange;
				return 0;
			}
		}else{ //校验负溢出
			if(-result<INT_MIN)
			{
				g_status = OutOfRange;
				return 0;
			}
		}
		str++;
	}


	return (int)flag*result;
}


int main()
{

	/*
	 *
	 * memcpy只是简单的将两块内存区域当作没有关系的相互独立内存区域进行内存的拷贝，
	 * 而memmove则考虑了当两块内存区域有重叠时所采用不同方向的拷贝模式进行处理。
	 * */



}
