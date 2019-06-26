#include<stdio.h>
#include<stdbool.h>

int main()
{
    bool m = true;
    bool n = false;
    printf("m==%d,  n==%d  \n", m, n);
    
    printf("sizeof(_Bool) == %ld  \n", sizeof(_Bool));

    bool number[] = {true};
    printf("%d \n", number[0]);
 
    // system("pause");
    // return EXIT_SUCCESS;
}