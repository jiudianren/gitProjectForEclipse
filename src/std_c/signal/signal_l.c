
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void fun()
{
    printf("cathch the signal \n");
    signal(SIGABRT, fun);
    exit(0);
}

int main()
{

    signal(SIGABRT, fun);
    FILE *stream;
    if (stream = fopen("aa.txt", "r") == NULL)
    {
        perror(" CANN'T OPEN FILE");
        abort();
    }
    else
    {
        fclose(stream);
    }
}
