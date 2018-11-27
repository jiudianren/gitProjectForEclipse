#include  <string.h>
#include <assert.h>
#include <iostream>


char * strcpy1(char *dst, const char *src) //[1]
{
    assert(dst != NULL && src != NULL);  //[2]
    char *ret = dst;                     //[3]
    //�ȸ��� ���жϣ�������һ�� \0�����ˣ�Ȼ�����ж�

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
    char * src = (const char *) srcc;
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





#define INT_MAX ((int)0x7fffffff)
#define INT_MIN ((int)0x80000000)

enum Status{Valid = 0, Invalid, OutOfRange};
int g_status = Invalid;

int strToInt(const char* str){
    long long result=0; //8���ֽڳ���
    int flag=1;//Ĭ������

    //�ж�ָ���Ƿ�Ϊ��
    if (str== nullptr || *str=='\0')
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
    return static_cast<int>(flag*result);
}





//18. strcat������ʵ��

char *strcat(char *strDes, const char *strSrc){

    assert((strDes != NULL) && (strSrc != NULL));

    char *address = strDes;

    while (*strDes != '\0')
        ++ strDes;

    while ((*strDes ++ = *strSrc ++) != '\0')
    {}

    return address;
}

//19��strncatʵ��

char *strncat(char *strDes, const char *strSrc, int count){

    assert((strDes != NULL) && (strSrc != NULL));

    char *address = strDes;

    while (*strDes != '\0')
        ++ strDes;

    while (count - && *strSrc != '\0' )
        *strDes ++ = *strSrc ++;

    *strDes = '\0';
    return address;
}

//20. strcmp����ʵ��

int strcmp(const char *str1,const char *str2){

    /*������while(*str1++==*str2++)���Ƚϣ��������ʱ�Ի�ִ��һ��++��

    return���صıȽ�ֵʵ��������һ���ַ���Ӧ��++�ŵ�ѭ�����н��С�*/

    while(*str1 == *str2){

        if(*str1 == '\0')

            return0;



        ++str1;

        ++str2;

    }

    return *str1 - *str2;

}

21. strncmpʵ��

int strncmp(const char *s, const char *t, int count){

    assert((s != NULL) && (t != NULL));

    while (*s && *t && *s == *t && count �C) {

        ++ s;

        ++ t;

    }

    return (*s �C *t);

}

//22.strlen����ʵ��

int strlen(const char *str){

    assert(str != NULL);
    int len = 0;

    while (*str ++ != '\0')
        ++ len;

    return len;

}

//23. strpbrk����ʵ��

char * strpbrk(const char * cs,const char * ct){

    const char *sc1,*sc2;

    for( sc1 = cs; *sc1 != '\0'; ++sc1){

        for( sc2 = ct; *sc2 != '\0'; ++sc2){

            if (*sc1 == *sc2){

                return (char *) sc1;

            }

        }

    }

    return NULL;

}

//24. strstr����ʵ�� strstr(str1,str2) ���������ж��ַ���str2�Ƿ���str1���Ӵ�
//����ǣ���ú�������str2��str1���״γ��ֵĵ�ַ�����򣬷���NULL��

char *strstr(const char * in1,const char *s2){

    char * s1= in1; //һ��Ҫ�����������Ȼ���ܻ�ı�ָ��λ��
    int len2=0 ;
    //���ڳ����жദ���õ�strlen,����strlen�ڲ���ΪNULL����»����
    if( s2 == nullptr)
    {
        return nullptr;
    }

    if(!(len2=strlen(s2)))//���������s2����ָ��գ�����strlen�޷�������ȣ�����������
        return(char*)s1;

    for( ; *s1 ;++s1)
    {

        if(*s1==*s2 && strncmp(s1,s2,len2)==0)
            return(char*)s1;
    }

    return NULL;
}

int mainImplement()
{

    /*
     *
     * memcpyֻ�Ǽ򵥵Ľ������ڴ�������û�й�ϵ���໥�����ڴ���������ڴ�Ŀ�����
     * ��memmove�����˵������ڴ��������ص�ʱ�����ò�ͬ����Ŀ���ģʽ���д���
     * */



}
