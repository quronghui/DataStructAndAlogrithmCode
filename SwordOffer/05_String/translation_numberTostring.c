// 面试题46：把数字翻译成字符串
// 题目：给定一个数字，我们按照如下规则把它翻译为字符串：0翻译成"a"，1翻译成"b"，……，11翻译成"l"，……，25翻译成"z"。
// 一个数字可能有多个翻译。例如12258有5种不同的翻译，它们分别是"bccfi"、"bwfi"、"bczi"、"mcfi"和"mzi"。
// 请编程实现一个函数用来计算一个数字有多少种不同的翻译方法。
/*
*   1. 解题思路: 
        a.我们的分析思路, 先是每一位单独翻译, 然后是以两位在一起翻译; 三位是不可能出现的.
            两位数组合后, 区间小于25, 且大于10
        b.如果通过递归的方式实现,存在重复;
        c.所以采用自上而下分析, 自下而上解题, 从最后一位开始翻译
    2. 数字先用字符串数组进行保存
    3. 问题:
        当数字超过两个的时候, 代码不正确;
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 函数声明
int GetTranslationNumber(const char *stringNumber);

/************调用翻译接口**********/
int GetTranslation(int number)
{
    if(number < 0)
        return 0;
    // 数字先用字符串数组进行保存
    int length = sizeof(number) / sizeof(int);
    char *strNumber = malloc(sizeof(char) * length + 1);    // 末尾存在\0
    sprintf(strNumber, "%d", number);
    // 调用数字转换的功能函数
    int count = GetTranslationNumber(strNumber);
    free(strNumber);
    return count;
}

/********计算数字转化为字符串的数目*************/
int GetTranslationNumber(const char *stringNumber)
{
    int length = strlen(stringNumber);
    int count = 0;
    // counts 其实就是当做count计数的一个数组,每次count都会清零, 但是通过counts就能将值赋值给count;
    int *counts = malloc(sizeof(int) * length);

    for(int i=length-1; i>=0; i--){
        count = 0;
        // 两位数字组合的情况, 后一个数字 i 要和i+1数字进行比较;
        if( i < length-1)
            count = counts[i+1];
        else 
            count = 1;
        
        if(i< length-1){
            int digt1 = stringNumber[i] - '0';
            int digt2 = stringNumber[i+1] -'0';
            int converted = digt1 * 10 + digt2; // 查看两位数
            if(converted >= 10 && converted <=25){
                if(i < length-2)
                    count += counts[i+2];       // 注意: 这里要使用加号;
                else 
                    count += 1;
            }
        }
        counts[i] = count;
    }    
    count = counts[0];
    free(counts);

    return count;
}

/****************Test code*****************/
void Test(char *name, int number, int expected)
{
    if(name != NULL)
        printf("%s begin: ", name);

    int count = GetTranslation(number);
    if(count == expected)
        printf("the count == expected is %d passed.\n", count);
    else 
        printf("the count != expected is %d failed.\n", count);
}

// test1()
void test1()
{
    int number = 123;
    int expected = 3;
    Test("Test1", number, expected);
}

// main
int main()
{
    test1();
    return 0;
}