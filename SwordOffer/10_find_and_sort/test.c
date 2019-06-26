#include <stdio.h>
#include <stdlib.h>
void swap( int *one , int *two)
{
    int temp;
    temp = *one;
    *one = *two;
    *two = temp;
}
int main()
{   
    int data[] = {1, 2};
    int length = sizeof(data) / sizeof(int);
    printf(" %d\n", length);
    swap(&data[0], &data[1]);
    printf( "data[0] is %d ; data[1] is %d\n", data[0], data[1]);
    return 0;
}