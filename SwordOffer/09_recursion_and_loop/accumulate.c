// 面试题64：求1+2+…+n
// 题目：求1+2+…+n，要求不能使用乘除法、for、while、if、else、switch、case
// 等关键字及条件判断语句（A?B:C）。
/* 
*   1. 解题思路
        a. 求1-n的和, 无外乎递归和循环两种思路; n(n+1) / 2
        b. 限制while 和 for , 循环就能用了;
        c. 递归也需要用到 if;
    2. 方法一和二:  
        a. C++ 的虚构函数求解
    3. 方法三: 
        a. 在C中, 通过函数指针进行模拟;
*/
#include <stdio.h>

typedef unsigned int    (*fun)(unsigned int );      // 函数指针;

unsigned int Teminator(unsigned int n)
{
    return 0;
}

unsigned int    Sum(unsigned int    n)
{
    static  fun f[2]    =   { Teminator, Sum };     // 函数指针, 定义了两个函数
    return  n + f[!!n](n-1);
}

/**********Test code************/
void Test(char *name, int n, int expected)
{
    if(name != NULL)
        printf("%s begin:   ", name);
    int sum = Sum(n);
    if(sum  ==  expected)
        printf("Passed. The sum == expected is %d.\n", sum);
    else 
        printf("Failed. The sum != expected is %d.\n", sum);
}

// main
int main()
{
    Test("Test1", 5, 15);
    return 0;
}