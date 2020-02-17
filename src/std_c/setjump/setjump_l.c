#include <stdio.h>
#include <setjmp.h>
jmp_buf buf;

void F3(void)
{

    printf("F3()\n");
    longjmp(buf,111);
}

void F2(void)
{
    printf("F2()\n");
    F3();
}

void F1(void)
{
    F2();
    printf("F1()\n");
}


int main(void)
{
   int jmpret = setjmp(buf);
    
    if(!jmpret)
    {
        printf("jmpret 1: %d \n", jmpret);
        F1();
    }
    else
    {
        printf("jmpret 2: %d\n",jmpret);
        printf("继续执行main\n");
    }
    return 0;
}