/*
 * test.c
 *
 *  Created on: 2016��8��16��
 *      Author: Administrator
 */




#include "stdio.h"
main()
{
	char a[5],c;
	int i=0;
	while((c=getchar())!='\n')
		a[i++]=c;
	printf("%s",a);
}
