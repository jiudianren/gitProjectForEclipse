/*
 * PointerAndRef.cpp
 *
 *  Created on: 2016��12��21��
 *      Author: Administrator
 */

/*http://www.cnblogs.com/li-peng/p/4116349.html �Ա�����*/

//#include
#include <iostream>
#include<stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include<iostream>
#include<string>
#include<string.h>
#include "PointerAndRef.h"
using namespace std;
int aimVal=5;

//�����ǰ�һ��ָ����Ϊ������һ������ʱ����ʵ�ǰ�ָ��ĸ������ݸ��˷�����Ҳ����˵����ָ����ָ���ֵ���ݡ�
//�����ı�ʵ��  p��ָ���ָ��
//Poiter�У��ȴ���һ��ָ�����p��ָ��ʵ��ָ����ָ��ĵ�ַ�����Բ��ı�ʵ��ָ���ָ��
//�ں����ڲ���ָ��P��ָ�򣬷����仯��ָ����aimVal����ʵ�ε�ָ���ָ��û�з������������Ժ�������ǰ��ʵ��ָ��û���κθı䡣
//�������xPointer��������֤���˹���
void Pointer(int * p)
{
	p=&aimVal;
}


//ͬ�� ���������Ҳ���޷��ı�ʵ�ε�ֵ��
//void GetVersion(char* pStr)
//{
//    pStr = malloc(10);
//    strcpy ( pStr, "2.0" );
//}

/*�˺������ص���˭��ֵ���ǲ���p�ĵ�ַ������p��ֵ��  */
int * xPointer (int * p)
{
	p=&aimVal;
	return p;
}
//�����ı�ʵ��ָ���ָ������Ҫʹ��ʵ�ε�ָ�룬��ָ���ָ��
//����һ����ʱ����p��p��һ��ָ���ָ�룬pָ�����ʵ�ε�ַ����ʵ�εĵ�ַ��������ʵ�Σ��Ǹ�ָ�룩��ָ��ĵ�ַ��
//�ں������У�ͨ����p�������õ�p��ָ��ĵ�ַ���ٽ�aimVale�ĵ�ַ����ֵ��p��ָ��ĵ�ַ����ʵ����ָ��ĵ�ַ�����˱���

/*
����          |p�β�                |&chang(ʵ��)=ptemp      |change
��ַ          |adr3     |adr2                  |adr1
ֵ              |adr2(p)  |adr1 (*p)             |value

˵������&change����ʹ��һ����ʱ������תһ�£�
���ܶ�һ����ַ��ȡ��ַ
���磨&��&change������Ϊ��change�ĵ�ַ��adr1����adr1�������һ����ַ�ˣ���û�д������κα����У������޷���adr1��ȡ��ַ��
���Կ���ͨ��  int *ptemp = &change; ������ptemp�ĵ�ַ�£��洢һ�� change�ĵ�ֵַ�������Ϳ��ԣ���ptemp��ֵ������һ����ַ����ȡֵ������value
���� change�ĵ�ַ0x00001 ,�õ�ַ�ϣ��洢��intֵ��2����ô��&change������0x00001,����ٶԵ�ַ0x00001ȡ��ַ�����ǣ�&��&change����ȡɶ�أ�����û��ȡ��
�������int *ptemp = &change����ô����ptemp�ĵ�ַ0x00002,�õ�ַ�ϴ洢������һ����ֵַ0x00001,��ô��ptemp��ָ���ָ�룬����change��ֵ��
 * */

void PPointer(int* * p)
{
	*p=&aimVal;
}

/*
 * lvalue��rvalue
�ڼ������Զ��ʱ����������lvalue��rvalue��ָ��
lvalue���������ڴ��е�λ�á�ͨ�����ܹ��ҵ��ڴ��д�ŵı�����location value����
rvalue�������lvalue��Ӧ���ڴ��еĶ�����register value����

������lvalue�Ĵ��ڱ����д洢�ռ䣬Ȼ����rvalue��û�ж�Ӧ�洢�ռ䣬��ֻ����Ƭ�洢�ռ��Ӧ��ֵ��������������͵Ļ����Ǹ�����һ��1��0�����С�
 */

//ָ������ã���ָ���ָ�룬��һ��Ч�����޸ĵľ��Ǹ�ָ��
/**
 * ����������ûر���
 * int change =1;
 * RPointer(&change)
 * �������£�
 * error: invalid initialization of non-const reference of type 'int*&' from an rvalue of type 'int*'
 * ��Ϊ&change��һ��rvalue,�������Ϊ��int x=5��,�����5,5��������Ϊһ��������
 * ����&change ��0x0001,��ô����&change���Ǹ�������ʵ����&change������һ����������ֻ��һ��ֵ0x0001����û��һ����ַ��֮��Ӧ��
 * ���� int x=5,���ﲢ����˵�� 5��һ��������5������ֻ��һ�� rvalue,��˼����read value ,ֻ�ɶ���
 * ����Ҫͨ��һ����ʱ����תһ��
 * int * ptemp=&change
 * RPointer(ptemp);
 * �Ϳ�����
 *
 * */
void RPointer(int* & p)
{
	p=&aimVal;
}


//pΪ�����ڵ���ʱ������������ʱ���������ᷢ�����벻��������,��ʱ�����ٺ����˳��󣬾ͻᱻ�ͷŵ�   �и澯
char* Getmemory(void)
{
	char p[]="hello world";
	return p; //returning address of local variable or temporary
}
void Test()
{
	char *str=NULL;
	str=Getmemory();
	printf(str); //unknown results
}


std::string TestStringReference()
{
	std::string strTest = "This is a test.";
	return strTest;
}


void  printsx(const char *pc )
{
	std::cout << "printx "<<pc << std::endl;

}


void TestPAR()
{
	printf("==============s \n");
	string tempaa= TestStringReference();

	//    std::string& strRefer = TestStringReference();
	std::string& strRefer = tempaa;
	std::cout << "strRefer:" << strRefer << std::endl;

	//��ʽһ��
	//TestStringReference�ķ���ֵ�����ڴ˴�����һ����ʱ���������ñ������������٣����Բ���ʹ����ʱ������c_str()
	//    const char *pc = TestStringReference().c_str();
	//
	//        std::cout << pc << std::endl;
	//        printsx(pc);
	//    printf("==============s \n");

	//��ʽer��
	//    const char * pc;
	//    strcpy(pc,TestStringReference().c_str());
	//            std::cout << pc << std::endl;
	//    printsx(pc);
	printf("==============s \n");

	int change=0;

	int * temp=&change;
	printf("before Point :%d \n",*temp);
	Pointer( temp);
	printf("after Point :%d \n",*temp);


	change=3;
	int * xtemp=&change;
	printf("before xPoint :%d \n",*xtemp);
	int *ytemp=xPointer( temp);
	printf("after xPoint :%d \n",*xtemp);
	printf("after yPoint :%d \n",*ytemp);

	change=1;
	int *ptemp = &change;
	printf("before PPoint :%d \n",*ptemp);
	PPointer(&ptemp);

	//    PPointer((&(&change)));
	printf("after PPoint :%d \n",*ptemp);

	change=2;
	int * rtemp=&change;
	printf("before RPoint :%d \n",*rtemp);
	//    RPointer(&change);
	RPointer(rtemp);
	//Ч����PPointer(&rtemp)һ��
	printf("after RPoint :%d \n",*rtemp);


	printf("aaa======== \n");
	Test();
}


/*ָ�����   pStr�� ����һ��ָ�룬�ں������޸ĵ���ָ��ĸ�����
 * �޸�ָ�븱����ָ�򣬲������޸�ԭָ������
 *
 * ����ͨ���޸�ָ���ָ�������
 * ������ͨ���������޸�ʵ�ε�ָ���ָ��
 *
 * */
void GetVersion(char * pStr)
{
	pStr= (char * )malloc(10);
	strcpy( pStr,"V2.0");
}

void TestPAR2()
{
	char v1 []="V1.0";
	char * pStr = v1;
	printf("pStr :%s \n",pStr);

	GetVersion(pStr);
	printf("pStr :%s \n",pStr);

}

struct  TestS
{
	int i;
};


struct TestRef
{

	TestRef( TestS & s):ms(s)
	{

	}

	TestS  & ms;
};

void TestPart1()
{
 TestS ts;
 ts.i=100;
 TestRef tsr(ts);

 printf("tsr.i=%d,\n",tsr.ms.i);
}
int mainPAR ()
{
	TestPAR();
	TestPAR2();
	TestPart1();
	return 0;

}
