// 题目二: 实现大数的辗转相除法;
// 参考思路: 没有完全实验 https://blog.csdn.net/dyw_666666/article/details/85707458
/*
*   1. 解题思路
        a. 两个大数的输入, 通过字符串进行接收
        b. 通过compare比较两个字符串, 始终让 str1保存大数, str2保存小数;
        c. 字符串如何实现辗转相除法
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 1000

// b. 判断两个字符串的数谁更大
// len1< len2：返回false
// len1==len2：看谁的数更大，len1的大返回true
// len1> len2：直接返回true
bool    compare(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if(len1 < len2)
        return false;
    // 比较两个字符串大小的时候: 从后向前读,还是从前向后读:?
    // 我觉得应该是比较最高位;(打端和小端)
    if(len1 ==  len2){
        for( int i = len1 -1 ; i>=0; i-- ){
            if( str1[i] > str2 )
                return true;
            else if(str1 < str2)
                return false;
        }
    }
    return true;
}

// c. 大数除法---结果不包括小数点
// str1 被除数, str2 除数, sum 存放商
int division( char *str1, char *str2, char  *sum )
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // 将数字字符转换成整型数，且翻转保存在整型数组中
    int strr1[MAX] , strr2[MAX];
    for(int j = 0, i = len1-1; i>=0 ; i--, j++)
        strr1[j] = str1[i] - 48;
     for(int j = 0, i = len1-1; i>=0 ; i--, j++)
        strr2[j] = str2[i] - 48;
    
    // 计算两者相差位数
    int number = len1 - len2;

}

int main()
{
    int len;
    char    str1[MAX] = {0};    //保存第一个大数
    char    str2[MAX] = {0};    // 保存第二个大数
    char    sum[MAX] = {0};     // 计算结果;
    char    summ[MAX] = {0};

    // a. 输入两个字符串
    scanf("%d %d", str1, str2);     //数组名代表首地址
    // b. 比较两个字符串的大小
    if( !compare(str1, str2) ){
        char num[MAX] ;
        strcpy(num, str1);
        strcpy(str1, str2);
        strcpy(str2, num);
    }

    return 0;
}