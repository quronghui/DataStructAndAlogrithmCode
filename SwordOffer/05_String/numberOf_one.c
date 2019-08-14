// 面试题43：从1到n整数中1出现的次数
// 题目：输入一个整数n，求从1到n这n个整数的十进制表示中1出现的次数。
// 例如输入12，从1到12这些整数中包含1 的数字有1，10，11和12，1一共出现了5次。
/*
*   1.注意：n这个整数会是一个很大的数：对大数的处理，转化为字符串；
    2.解题思路一：
        a. 从（1 - n），不停的循环得到每一个数中1的个数；然后再将他们加起来
        b. 通过 %10 取余数；/10 取商进行判断
    3.解题思路二：
        a. 将这个大数n，保存到字符串中；
        b. 将这个数分为两大部分：1-（去除第一位之后的数）；（后几位数）--n;
        c. 分析首位字符，以及字符串的长度；
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/***************思路一：不停地取余数****************/
// 函数声明
int numberOf_one_remainder(unsigned int  n);    // 对一个数不停的取余数
// 用户接口函数，从1-n不停地取数
int numberOf_one(unsigned int n)
{
    int times = 0;
    // 通过for循环进行查找
    for(int i=1; i<=n; i++)
        times += numberOf_one_remainder(i);
    return times;
}

// 对每一个数计算其中1的个数；
int numberOf_one_remainder(unsigned int  n)
{
    int times = 0;
    while(n){
        if(n % 10 == 1)
            times++;
        n /= 10;
    }
    return times;
}

/***************思路二：保存这个大数****************/
// 函数声明
int string_ofOne(const char *str);
int powerBase10(unsigned int n);

// 通过字符串形式保存大数；
int string_ofNumber_one(int n)
{
    if(n<0)
        return 0;
    char str[50];
    sprintf(str, "%d", n);  //  write to the character string str.直接将数字n转化为字符串
    
    return string_ofOne(str);
}

// 功能函数：统计1的个数
int string_ofOne(const char *str)
{   
    // 字符数判断的边界条件；
    if( str==NULL || *str<'0' || *str>'9' || *str=='\0')
        return 0;
    // 对大数进行分段
    int first = *str - '0';     // 判断首字符是0-9的哪一个数； 
    unsigned int length = strlen(str);  // 字符串的长度；

    // 如果里面只有一个字符
    if(first == 0 && length == 1)
        return 0;
    if( length ==1 && first > 0 )   // '1' - '9' 中1只出现一次；
        return 1;
    
    // 假设str是一个大数“21354”； 求‘1’-“21354” 中1的个数

    // numFirstDigit 是数字10000-19999中；第一位中1出现的次数
    int numFirtstDigit = 0;
    if(first > 1)
        numFirtstDigit = powerBase10(length - 1);  // 首字符大于1时，1的个数就是 = 10^(字符串的长度)
    else if(first == 1)
        numFirtstDigit = atoi(str + 1) + 1; // 除去最高位后，剩下数目便是1的个数；
    
    // numOtherFigit是1346-21345； 除第一位之外：剩余数位中1的个数
    int numOtherFigit = first * (length-1) * powerBase10(length - 2);

    // numRecursive 是 1 - 1345 中1的个数； 
    int numRecursive = string_ofOne(str + 1);   // 递归调用

    return numFirtstDigit + numOtherFigit + numRecursive;
}

// 根据位数，将其转换为百位、千位....
int powerBase10(unsigned int n)
{
    int result = 1;
    for(unsigned int i=0; i<n; i++)
        result *= 10;
    return result;
}

/******************Test code******************/
void Test(char *name, int n, int expected)
{
    if(name != NULL)
        printf("%s begin:   ", name);
    
    // test 思路一
    printf("Test first resolution way\n");
    int times = numberOf_one(n);
    if(times == expected)
        printf("the times is %d.\n", times);
    else 
        printf("the times is %d and failed.\n", times);
    
    printf("\nTesting second resolution ways.\n");
    if(string_ofNumber_one(n) == expected)
        printf("the number is %d.\n", times);
    else 
        printf("the number is %d and failed.\n", times);
}
// test 函数
void test()
{
    // Test("test1", 5, 1);
    // Test("Test3", 10, 2);
    // Test("Test4", 55, 16);
    Test("Test5", 15, 8);
}

// main
int main()
{
    test();
    return 0;
}