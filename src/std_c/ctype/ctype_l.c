
#include <ctype.h>
#include <stdio.h>
void test()
{
     int uknown = 'c';
    printf(" unkonw %d \n",uknown);
    printf(" ss %d \n ", isalnum(uknown)) ;
    printf(" ss %d \n ", isspace(uknown)) ;
}


int main()
{

 test();
}