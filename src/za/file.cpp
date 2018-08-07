

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <string>
#include <iostream>


/*对文件的操作*/
void mainfile()
{


    char fileName []="C:\\Users\\Administrator\\Desktop\\test.txt";
    FILE * fp = fopen(fileName, "a");

    if(fp== NULL)
    {
        printf("it is erro \n");
    }else
    {
        printf("it is ok " );
    }

    if (remove(fileName) == 0)
        printf("Removed %s.\n",fileName);
    else
        perror("remove");

    if(access(fileName,F_OK)==0)
    {
        printf("file ok: %s. \n",fileName);
    }
    else
    {
        perror("remove  xx \n");
    }

    if(fp== NULL)
    {
        printf("it is erro \n");
    }else
    {
        printf("it is ok " );
    }


    fclose(fp);
}
