/*
 * PointerAndRef.cpp
 *
 *  Created on: 2016年12月21日
 *      Author: Administrator
 */

/*http://www.cnblogs.com/li-peng/p/4116349.html 对比这里*/

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

//当我们把一个指针做为参数传一个方法时，其实是把指针的复本传递给了方法，也可以说传递指针是指针的值传递。
//并不改变实参  p的指针的指向，
//Poiter中，先创建一个指针变量p，指向实参指针所指向的地址，所以不改变实参指针的指向。
//在函数内部，指针P的指向，发生变化，指向了aimVal，而实参的指针的指向并没有发生变量，所以函数调用前后，实参指针没有任何改变。
//其可以在xPointer函数中验证，此过程
void Pointer(int * p)
{
	p=&aimVal;
}


//同理 ，这个函数也是无法改变实参的值的
//void GetVersion(char* pStr)
//{
//    pStr = malloc(10);
//    strcpy ( pStr, "2.0" );
//}

/*此函数返回的是谁的值，是参数p的地址，还是p的值？  */
int * xPointer (int * p)
{
	p=&aimVal;
	return p;
}
//如果想改变实参指针的指向，则需要使用实参的指针，即指针的指针
//创建一个临时变量p，p是一个指针的指针，p指向的是实参地址，即实参的地址，而不是实参（是个指针）所指向的地址。
//在函数体中，通过对p解引，得到p所指向的地址，再讲aimVale的地址，赋值给p所指向的地址，则实参所指向的地址发生了变量

/*
变量          |p形参                |&chang(实参)=ptemp      |change
地址          |adr3     |adr2                  |adr1
值              |adr2(p)  |adr1 (*p)             |value

说明，对&change必须使用一个临时变量来转一下，
不能对一个地址再取地址
比如（&（&change））因为对change的地址是adr1，但adr1本身就是一个地址了，并没有存在在任何变量中，所以无法对adr1再取地址。
所以可以通过  int *ptemp = &change; 这样在ptemp的地址下，存储一下 change的地址值，这样就可以，对ptemp的值（就是一个地址）再取值，就是value
比如 change的地址0x00001 ,该地址上，存储的int值是2，那么（&change）就是0x00001,如果再对地址0x00001取地址，就是（&（&change））取啥呢，根本没法取。
如果定义int *ptemp = &change，那么加入ptemp的地址0x00002,该地址上存储的是是一个地址值0x00001,那么对ptemp的指针的指针，就是change的值。
 * */

void PPointer(int* * p)
{
	*p=&aimVal;
}

/*
 * lvalue和rvalue
在计算机的远古时代，变量的lvalue和rvalue是指：
lvalue：变量在内存中的位置。通过它能够找到内存中存放的变量（location value）；
rvalue：存放在lvalue对应的内存中的东西（register value）；

变量的lvalue的存在表明有存储空间，然而其rvalue并没有对应存储空间，它只是那片存储空间对应的值。如果不考虑类型的话，那个就是一个1和0的序列。
 */

//指针的引用，和指针的指针，是一个效果，修改的就是该指针
/**
 * 但如果这样用回报错
 * int change =1;
 * RPointer(&change)
 * 报错如下：
 * error: invalid initialization of non-const reference of type 'int*&' from an rvalue of type 'int*'
 * 因为&change是一个rvalue,可以理解为“int x=5”,这里的5,5并不能作为一个变量，
 * 加入&change 是0x0001,那么假设&change，是个变量，实际上&change并不是一个变量，它只有一个值0x0001，并没有一个地址与之对应，
 * 比如 int x=5,这里并不能说明 5是一个变量，5在这里只是一个 rvalue,意思就是read value ,只可读。
 * 所以要通过一个临时变量转一下
 * int * ptemp=&change
 * RPointer(ptemp);
 * 就可以了
 *
 * */
void RPointer(int* & p)
{
	p=&aimVal;
}


//p为函数内的临时变量，返回临时变量，将会发生意想不到的问题,临时变量再函数退出后，就会被释放掉   有告警
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

	//方式一：
	//TestStringReference的返回值，将在此处创建一个临时变量，而该变量，将会销毁，所以不能使用临时变量的c_str()
	//    const char *pc = TestStringReference().c_str();
	//
	//        std::cout << pc << std::endl;
	//        printsx(pc);
	//    printf("==============s \n");

	//方式er：
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
	//效果和PPointer(&rtemp)一样
	printf("after RPoint :%d \n",*rtemp);


	printf("aaa======== \n");
	Test();
}


/*指针参数   pStr会 拷贝一份指针，在函数内修改的是指针的副本，
 * 修改指针副本的指向，并不会修改原指针内容
 *
 * 可以通过修改指针的指向的内容
 * 并不能通过函数，修改实参的指针的指向
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
