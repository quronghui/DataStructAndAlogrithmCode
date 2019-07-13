// 面试题38：字符串的排列
// 题目：输入一个字符串，打印出该字符串中字符的所有排列。例如输入字符串abc，
// 则打印出由字符a、b、c所能排列出来的所有字符串abc、acb、bac、bca、cab和cba。
/*
*   1.解题思路：
        a. 将字符串分为两部分：第一个字符，后面的所有字符；
        b. 通过第一个字符和后面的字符一一交换；然后固定第一个字符；（全排列的首字母）
        c. 然后将后面的字符：再次分为两部分，递归过程a,b;
        d. 直到后面的字符为 '\0' 打印
    2.这里说的是全排列；不是组合
    3.问题：
        pstring and pbegin; 指向的是同一个地址；只要pbeign被改变了，pstring指向的值也会改变
*/
#include <stdio.h>
#include <string.h>

void permutaionFuncation(char *pString, char *pBgin);

/***********用户接口函数***********/
void permutation( char *pString)
{
    // 边界条件
    if(pString == NULL){
        printf("The string is null.\n");
        return ;
    }
    // 调用功能函数
    permutaionFuncation(pString, pString);
}

/******************功能函数******************/
void permutaionFuncation(char *pString, char *pBgin)
{
    // 输出条件，当pBegin 后移到'\0'位置的时候
    if( *pBgin == '\0')
        printf("%s\n", pString);
    else{
        
        for( char *pCh=pBgin; *pCh != '\0'; pCh++ ){
            // 做交换首字母的工作
            char temp = *pCh;
            *pCh = *pBgin;
            // char pp = *pBgin;
            *pBgin = temp; 

            // 递归交换第一个字符后的所有字符.没有弄清楚pString为什么会变成ba
            // pstring and pbegin; 指向的是同一个地址；只要pbeign被改变了，pstring指向的值也会改变
            permutaionFuncation(pString, pBgin+1);

            // 固定首字母后; pch 和pbegin 没有变；
            temp = *pCh;        
            // char pbeg = *pBgin; 
            *pCh = *pBgin;
            *pBgin = temp;
        }
    }
}

/******************test code**********************/
void Test(char *pString)
{
    if(pString == NULL)
        printf("Test for nullptr begins:\n");
    else
        printf("Test for %s begins:\n", pString);

    permutation(pString);

    printf("\n");
}


// main
int main()
{
    Test(NULL);

    char string1[] = "";    // 含有一个\0
    Test(string1);

    char string2[] = "a";
    Test(string2);

    char string3[] = "ab";
    Test(string3);

    char string4[] = "abc";
    Test(string4);

    return 0;

}