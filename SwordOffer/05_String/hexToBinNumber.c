// 面试题67(三):  写出一个程序，接受一个十六进制的数值字符串，输出该数值的十进制字符串。(满足多组输入)
/*
*  1. 解题思路:
        a. 清楚十六进制数是由什么组成: 字母加数字
        b. 十六进制数从低位到高位（即从右往左）计算
        c. 一个大数转化为字符串的形式保存, sprintf;
        d. 要实现多组的读入: gets()  每次读一行字符串, 直到读到一个空行EOF;
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/***************十六进制转化为十进制****************/
void    convert16to10(char *str, int len)
{
    long    sum =   0;
    int i   =   0;
    for(int i=len-1; i>=0;  i--){                                                       // 由低位到高位计算
        if( str[i] <= '9'  && str[i] >= '0' )
            sum =   sum +   (str[i] - 48) * pow(16, len-i-1);       // 16进制数生成10进制数, 乘以16
        else if( str[i] <= 'F' &&  str[i] >='A' )
            sum =   sum +( str[i]   -   55 ) * pow(16, len-i-1);  
    }
    char    num[100];
    // 将一个大数转化为一个字符串, 这个函数不起作用?
    // 使用sprintf()函数
    sprintf(num, "%ld", sum);
    printf("%s\n", num);
}

/*****************Test code****************/
int main()
{
    char str[100];

    while(gets(str))        // 读一行字符串
    {
        int len = strlen(str);
        convert16to10(str, len);
    }
    return 0;
}