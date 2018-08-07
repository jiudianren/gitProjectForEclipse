/*
 * debutExample.cpp
 *
 *  Created on: 2017Äê5ÔÂ14ÈÕ
 *      Author: Lian
 */

#include "debug.h"

#include <iostream>
#include <assert.h>
using namespace std;

void testDE()
{
	__FUNC_LOGn();


	__FUNC_LOGn();

	int a =1;
	auto b =a;

	__FUNC_LOGn();
	__ASSERT_LOG( (a==1) ," a value is %d",a);

	__FUNC_LOGn();
	__FUNC_LOGn();

	__BEFORE_LOG(2,"test befor log  %d ",a);

	__ASSERT_LOG( true ," test true  %d",a);
	__ASSERT_LOG( false ," test false  %d",a);

	__PRINT_POS_P_expn("changefrom ","change to");
	cout<<"b:"<<b<<endl;
	__FUNC_LOGn();
}


#define NDEBUG 0

void print_number(int* myInt) {
	assert (myInt!=NULL);
	printf ("%d\n",*myInt);
}

/*http://www.cplusplus.com/reference/cassert/assert/
  */
void mainDebugTest()
{

	cout<<"============mainDebugTest"<<endl;
	testDE();
	int a=10;
	int * b = NULL;
	int * c = NULL;

	b=&a;

	print_number (b);
	print_number (c);
	cout<<"============mainDebugTest"<<endl;

}
