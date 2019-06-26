//  面试题15：二进制中1的个数
// 题目：请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。例如
// 把9表示成二进制是1001，有2位是1。因此如果输入9，该函数输出2。

/*
1. 方法1：将整数n循环右移
   - 每进行一次运算：n & 1，整数n右移一位：n>>1 
   - 缺点：当n为负数时后，循环右移导致n的二进制数全为1；判断会进入死循环
2. 方法2：整数n不移动，1循环左移
   - 每进行一次 : n & 1，与位 1 左移一位：1 << 1;  --> 10
   - 缺点：32位的整数，需要循环32次
3. 方法3：
   - 整数 n > 0; 那么其二进制数中至少有一个1；
   - 整数 n 的二进制有多少个1，就能进行多少次运算
*/
#include <stdio.h>

/************方法1：将整数n循环右移*********************/
int n_RightShift(int n)
{
    int count = 0;
    while(n){           // n 只要不为0就行
        if( n & 1 )
            count++;
        n = n >> 1;     //// 不能只写 n >> 1
    }
    return count;
}
/************** 方法2：整数n不移动，1循环左移**************/
int flag_LeftShift(int n)
{
    int count = 0;
    unsigned int flag = 1;
    while( flag){
        if( n & flag )      // 这里的循环条件是 n & flag, 不是 n&1
            count++;
        
        flag = flag << 1;
    }
    return count;
}
/************************方法3：***************************/
int bit_and(int n)
{
    int count = 0;
    while(n){
        ++count;    // 只要 n 大于0，二进制数至少有一个
        n = (n - 1) & n; 
    }
    return count;
}


/***************void code*******************/
void test1( int n, int expected )
{
    int actual1 = n_RightShift(n);
    printf("Actual one number is %d, ", actual1);
    if( actual1 == expected)
        printf(" test1 passed.\n");
    else 
        printf(" test1 failed.\n");

}

void test2( int n, int expected )
{
    int actual2 = flag_LeftShift(n);
    printf("Actual2 one number is %d, ", actual2);
    if( actual2 == expected)
        printf(" test2 passed.\n");
    else 
        printf(" test2 failed.\n");
}

void test3( int n, int expected )
{
    int actual3 = bit_and(n);
    printf("Actual3 one number is %d, ", actual3);
    if( actual3 == expected)
        printf(" test3 passed.\n");
    else 
        printf(" test3 failed.\n");
}

/*************main***********/
int main(void)
{
    int n = 0x7FFFFFFF;
    int expected = 31;
    test1(n, expected);
    test2(n, expected);
    test3(n, expected);

    // // 输入0x7FFFFFFF，期待的输出是31
    // Test(0x7FFFFFFF, 31);

    // // 输入0xFFFFFFFF（负数），期待的输出是32
    // Test(0xFFFFFFFF, 32);

    // // 输入0x80000000（负数），期待的输出是1
    // Test(0x80000000, 1);

    return 0;
}