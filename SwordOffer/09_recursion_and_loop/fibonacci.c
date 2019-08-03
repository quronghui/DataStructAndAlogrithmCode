// 面试题10：斐波那契数列，青蛙跳台阶
// 题目：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。

/*
*   1.题目提示：  = 0               n=0
             f  = 1               n=1
                = f(n-1) +f(n-2)  n>1
    2.递归实现：
        存在很多重复的计算:调用f(100)时，进程就卡死了
*/

#include <stdio.h>

/*****************基于递归的代码***********************/
long long Fibonacci(unsigned int n)      //long long，长度为8个字节；
{
    if(n <= 0)
        return 0;
    if(n == 1)
        return 1;
    
    return Fibonacci(n-1) + Fibonacci(n-2);
}

/*****************基于循环的代码********************/
long long loop_Fibonacci(unsigned int n)
{
    int result[2] = {0, 1};
    if( n < 2)
        return result[n];
    
    long long fibNOne = 1;  // f(n-1)
    long long fibNTwo = 0;  // f(n-2)
    long long fibN = 0;
    for( unsigned int i = 2; i <= n; ++i ){
        fibN = fibNOne + fibNTwo;
        
        fibNTwo = fibNOne;
        fibNOne = fibN;
    }
    return fibN;
}

/****************test code******************/
int main(void)
{
    printf("Recursive_Fibonacci : %lld \n", Fibonacci(10));
    printf("Loop_Fibonacci: %lld \n", loop_Fibonacci(10));

    return 0;
}