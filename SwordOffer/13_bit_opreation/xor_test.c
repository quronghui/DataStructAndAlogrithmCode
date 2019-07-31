// 异或运算的简单测试

/* 
    1. 数组作为形参传递后, 不能通过sizeof(array) / sizeof(int) 计算长度?
        a. 函数数组名作为参数传递后, 从数组的首地址退化为了一般的指针
        b. 使用动态分配的数组; 这样就可行
*/

#include <stdio.h>
# include <stdlib.h>
// 异或的几种情况测试
void XORArray( int array[])
{  
    int length = sizeof(array) / sizeof(int);   

    //任何数与0异或 0 ^ n = n
    int number = 0;   
    for (int i = 0; i < length; i++) {
        number ^= array[i];
    }
    printf("The  0 ^ n = n is %d.\n", number);

    // 相同的数异或为0 n ^ n => 0 
}

// 异或的测试
void Test1()
{
   // a. 数组作为形参传递
    // int array[] = {4, 5};

    // b. 动态分配数组
    int *array =  malloc(sizeof(int) * 2);
    array[0] = 3;
    array[1] = 5;

    XORArray(array);
}

// 按位与 0&0=0;   0&1=0;    1&0=0;     1&1=1;
void Test2()
{
    int value = 5;
    int number = value & 2;
    printf("The value & 1 is %d.\n ", number);
}

// main
int main()
{
    Test1();
    Test2();
    return 0;
}