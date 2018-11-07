

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
 * ��1��const����
Դ�ַ���������const���Σ���ֹ�޸�Դ�ַ�����

��2����ָ����
(A)�����ָ�����Ч�ԣ�˵�������߲�ע�ش���Ľ�׳�ԡ�
(B)���ָ�����Ч��ʱʹ��assert(!dst && !src);
char *ת��Ϊbool����������ʽת�������ֹ�����Ȼ����������ǵ��³�����������ά���ɱ����ߡ�
(C)���ָ�����Ч��ʱʹ��assert(dst != 0 && src != 0);
ֱ��ʹ�ó������籾���е�0������ٳ���Ŀ�ά���ԡ���ʹ��NULL����0���������ƴд���󣬱������ͻ��������

��3������Ŀ��ָ��
���Ǳ���dst��ԭֵ

��4��'\0'
ѭ��д��while (*src!='\0') *dst++=*src++;
ѭ���������dst�ַ�����ĩβû����ȷ�ؼ���'\0'��

2. ����char *��ԭ��
����dst��ԭʼֵʹ�����ܹ�֧����ʽ���ʽ��
���ʽ����ʽ�磺
int l=strlen(strcpy(strA,strB));
���磺
char * strA=strcpy(new char[10],strB);


����strSrc��ԭʼֵ�Ǵ���ġ�
��һ��Դ�ַ����϶�����֪�ģ�������û�����塣
���������֧������ڶ����ı��ʽ��
��������const char *��Ϊchar *���أ����Ͳ��������뱨��
 *
 * */


void * my_memcpy(void  *dstt, const void * srcc, int cnt)
{
	assert(dstt != NULL && srcc != NULL);


	void  * ret = dstt;
	char * dst = (char *) dstt;
	char * src = (char *) srcc;
	if (dst >= src && dst <= src+cnt-1) //�ڴ��ص����Ӹߵ�ַ��ʼ����
	{
		dst = dst+cnt-1;
		src = src+cnt-1;
		while (cnt--)
			*dst-- = *src--;
	}
	else    //����������ӵ͵�ַ��ʼ����
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
 * 4. strcpy��memcpy������
1�����Ƶ����ݲ�ͬ��strcpyֻ�ܸ����ַ�������memcpy���Ը����������ݣ������ַ����顢���͡��ṹ�塢��ȡ�
2�����Ƶķ�����ͬ��strcpy����Ҫָ�����ȣ��������������ַ��Ĵ�������"\0"�Ž�����
�������������memcpy���Ǹ������3�������������Ƶĳ��ȡ�
3����;��ͬ��ͨ���ڸ����ַ���ʱ��strcpy������Ҫ����������������ʱ��һ����memcpy
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
1. �����ַ���ǰ�Ŀհ��ַ�
2. �ַ�������ʾ��ֵ��������
3. �������������������ֻ����ַ�'\0'����
4. ����������ֱ���intֵ���ܱ�ʾ�����(0x7fffffff)����Сֵ(0x8000000)���бȽ�
5. �����쳣���������

���ڿ��ܳ��ֵĸ��������Լ���������������Ҫ�Խ�������жϣ��������һ�����ִ�����ʽ������ֵ��ȫ�ֱ������쳣��

����ֵ����ϵͳAPIһ�£� ���ǲ��ܷ����ʹ�÷��ؽ�������һ��ж����ԡ�

ȫ�ֱ�������ȫ�ֱ�����ʾ����״̬���ܷ���ʹ�ý���� ���ǳ���Ա���ܻ����Ǽ��ȫ�ֱ�����

�쳣������Ϊ��ͬ�ĳ���ԭ���岻ͬ���쳣���ͣ��߼��������ˣ� ��Щ���Բ�֧�֣�ͬʱ��������һ���̶��ϵĸ���Ӱ�졣

atoi()����ʵ�ֵĴ��룺strToInt()
 * */




#include <iostream>
#define INT_MAX ((int)0x7fffffff)
#define INT_MIN ((int)0x80000000)

enum Status{Valid = 0, Invalid, OutOfRange};
int g_status = Invalid;

int strToInt(const char* str){


	long long result=0; //8���ֽڳ���
	int flag=1;//Ĭ������
	//�ж�ָ���Ƿ�Ϊ��
	if (str==NULL || *str=='\0')
		return 0;

	g_status = Invalid;
	//����ǰ��Ŀհ��ַ�
	while(isspace(*str)){
		++str;
	}
	/*
	 *�ж�������
	 */
	if(*str=='-'){
		flag=-1;
		str++;
	}else if(*str=='+')
		str++;


	//�������ַ����ת������������У�����,�������0
	while(*str<='9' && *str>='0'){

		result=result*10+*str-'0';
		if(flag==1){
			//У���Ƿ������
			if(result>INT_MAX)
			{
				g_status = OutOfRange;
				return 0;
			}
		}else{ //У�鸺���
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
	 * memcpyֻ�Ǽ򵥵Ľ������ڴ�������û�й�ϵ���໥�����ڴ���������ڴ�Ŀ�����
	 * ��memmove�����˵������ڴ��������ص�ʱ�����ò�ͬ����Ŀ���ģʽ���д���
	 * */



}
