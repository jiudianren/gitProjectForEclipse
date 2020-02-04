#include <errno.h>
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    fprintf(stderr, "Value of errno: %d\n", errno);

    fp = fopen("file.txt", "r");
    if( fp == NULL ) 
    {
      fprintf(stderr, "Value of errno: %d\n", errno);
      fprintf(stderr, "Error opening file: %s\n", strerror(errno));
    }
    else 
    {
      fclose(fp);
    }
}