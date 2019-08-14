// 面试题58（一）：翻转单词顺序
// 题目：输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
// 为简单起见，标点符号和普通字母一样处理。
// 例如输入字符串"I am a student. "，则输出"student. a am I"。
/*
*   1. 解题思路
        a. 通过两次翻转字符串实现;
        b. 第一次翻转: 全部的字符串进行翻转, 判断条件 pBegin < pEnd;
        c. 第二次翻转: 每个单词内部进行翻转, 判断条件 string != '  ';
*/
#include <stdio.h>
#include <string.h>

/***************字符串的全部翻转*****************/
void Reserve( char *pBegin, char *pEnd )
{
    if(pBegin == NULL || pEnd == NULL)
        return ;
    
    while( pBegin < pEnd ){
        char temp = *pBegin;
        *pBegin = *pEnd;
        *pEnd   =   temp;

        pBegin++, pEnd--;
    }
}

/*****************单词组内部的翻转******************/
char    *ReserveSentence( char *pData )
{
    if(pData == NULL)
        return NULL;
    // 初始化 起止位置 
    int length = strlen(pData);
    char *pBegin    =   pData;
    char *pEnd      =   pData + length -1;
    // while (*pEnd    !=  '\0')
    //     pEnd++;
    // pEnd--;     // 去除'\0\位置

    // 第一次翻转, 翻转全部字符;  符号了最近的单词一起
    Reserve(pBegin, pEnd);
    printf("First Reserve is %s\n", pData);
    
    // 第二次翻转
    pBegin = pEnd = pData;      // 这里从新赋值了;
    while (*pBegin != '\0'){
        // (1)遇到空格, 翻转下一个单词;
        if(*pBegin == ' '){
            pBegin++;
            pEnd++;
        }
        // (2) 到达一个单词的结尾
        else if(*pEnd == ' ' || *pEnd == '\0'){
            Reserve(pBegin, --pEnd);

            pBegin = ++pEnd;
        }
        else 
            pEnd++;     // 计算单词的长度
    }
    return pData;
}

/**************Test code****************/
void Test (char *name , char *pData, char *expectedResult)
{
    if(name != NULL)
        printf("%s begin:   ", name);
    // 输出原数组
    printf("\n%s\n", pData);
    // 翻转数组
    ReserveSentence(pData);
    
    if((pData == NULL && expectedResult == NULL)
        || (pData != NULL && strcmp(pData, expectedResult) == 0))
        printf("Passed.  The string is %s. \n", pData);
    else
        printf("Failed. \n");
}
// 功能测试，句子中有多个单词
void Test1()
{
    char input[] = "I am a student.";
    char expected[] = "student. a am I";

    Test("Test1", input, expected);
}

// main()
int main()
{
    Test1();
    return 0;
}