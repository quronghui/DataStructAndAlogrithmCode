// 面试题58（二）：左旋转字符串
// 题目：字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
// 请定义一个函数实现字符串左旋转操作的功能。比如输入字符串"abcdefg"和数
// 字2，该函数将返回左旋转2位得到的结果"cdefgab"。
/*
*   1. 解题思路: 
        a. 假设左旋转 2位;  将字符串看成两部分:     "ab  cdefg";
        b. 左旋转实现 "cdefgab", 类似于翻转字符串;
        c. 先内部字符串进行翻转: ba  gfedc    
        d. 然后进行全翻转 cdefg ba  
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

/******************将字符串分为两部分进行翻转**********************/
char *leftRotateString( char *string, int n )
{
    if(string != NULL)
    {
        int length  =   strlen(string);
        // 判断 n 和length之间的关系
        if( n > 0 && length > 0 && n < length ){
            char *firstStart = string;
            char *firstEnd  =   string + n -1;
            char *secondStart   =   string  +   n;
            char    *secondEnd  =   string  +length -  1;
            // 翻转前面n个字符
            Reserve(firstStart, firstEnd);
            // 翻转后面的字符
            Reserve(secondStart, secondEnd);
            // 全翻转整个字符串
            Reserve(firstStart, secondEnd);
        }
    }
    return string;
}

/*******************Test code********************/
void Test(char *name, char *string, int n, char *expected)
{
    if(name != NULL)
        printf("%s begin:   ", name);
    // 打印原来的字符串
    printf("original string is %s, rotate is %d. \n", string, n);

    char *result = leftRotateString(string, n);
     // 注意这里内部逻辑与或要加()
    if( (string == NULL && expected== NULL )   ||  ( string!=NULL && strcmp(result, expected) == 0) ) 
        printf(" Passed. The rsult is %s.\n ", result);
    else 
        printf("Failed. The result is %s.\n", result);
}
// 功能测试
void Test1()
{
    char input[] = "abcdefg";
    char expected[] = "cdefgab";

    Test("Test1", input, 2, expected);
}

// 边界值测试
void Test2()
{
    char input[] = "abcdefg";
    char expected[] = "bcdefga";

    Test("Test2", input, 1, expected);
}
// 边界值测试
void Test3()
{
    char input[] = "abcdefg";
    char expected[] = "gabcdef";

    Test("Test3", input, 6, expected);
}
// 鲁棒性测试
void Test4()
{
    Test("Test4", NULL, 6, NULL);
}

// 鲁棒性测试
void Test5()
{
    char input[] = "abcdefg";
    char expected[] = "abcdefg";

    Test("Test5", input, 0, expected);
}

// 鲁棒性测试
void Test6()
{
    char input[] = "abcdefg";
    char expected[] = "abcdefg";

    Test("Test6", input, 7, expected);
}

// main
int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}