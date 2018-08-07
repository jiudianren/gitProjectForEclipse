/*
 * test.c
 *
 *  Created on: 2016Äê8ÔÂ16ÈÕ
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
