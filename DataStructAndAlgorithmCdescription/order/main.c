#include <stdio.h>
#include <stdlib.h>

int main(void)
{   
    int i;
    for (i = 0; i < 5; i++)
    {
        int j =3;
        if( i < j )
            printf(" i < j\n");
        else
        {
            break;
            printf(" break only just to if-else\n");
        }
        printf("i = %d\n",i);
    }
    printf("i = %d\n", i);
    printf("cycle five\n");
    return 0;
}