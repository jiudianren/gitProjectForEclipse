

#include <limits.h>

int main()
{



    int x =128;

    if(x > CHAR_MAX)
    {

        printf(" %d not a char  \n",x );
    }

    printf(" max char  %d \n", CHAR_MAX);
    printf("max long %ld \n", LONG_MAX);
    printf("MB_LEN_MAX %d", MB_LEN_MAX);
}