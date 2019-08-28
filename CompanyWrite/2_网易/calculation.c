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
            if( str1[i] > str2[i] )
                return true;
            else if(str1 < str2)
                return false;
        }
    }
    return true;
}

// d 大数的减法 -- 结果不包括小数点
// 用长度为len1的大整数p1 减去 长度为len2的大整数p2
// 结果存在p1中，返回值代表结果的长度
int SubStract(int *p1, int len1, int *p2, int  len2)
{
    if(len1 < len2)
        return -1;
    // 判断两个字符串的差值
    if(len1 == len2){
        for( int i = len1-1; i>=0; i-- ){
            if(p1[i] > p2[i])  // 若大，则满足条件，可做减法
                break;
            else if( p1[i] < p2[i] ) 
                return -1;
        }
    }
    // 从低位开始做减法
    for( int i = 0; i <= len1-1; i++ ){
        p1[i] -= p2[i];
        if(p1[i] < 0){  // 需要进行借位;
            p1[i] += 10;
            p1[i+1]--;
        }
    }
    for(int i = len1-1; i>=0; i--){
        if(p1[i])                               // 最高位第一个不为0
            return (i+1);                  // 得到位数并返回
    }

    return 0;       // 两个数相等则返回0;
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
     // 将除数扩大，使得除数和被除数位数相等
    for(int i = len1-1; i >= 0; i--){
        if(i >= number)
            strr2[i] = strr2[i - number];
        else 
            strr2[i] = 0;  // 将低位置为0; 
    }
     
     //  重复调用，同时记录减成功的次数，即为商
    len2 = len1;
    int  n; // 记录Subtract函数返回值
    for(int i =0; i <= number; i++){
        while( (n = SubStract(strr1, len1, strr2 + i, len2 - i) ) >= 0 )
            len1 = n;   
    }
    
    // 返回商的值 
    int x = 0;
    for(int i = len1-1; i >= 0; i--)
        sum[x++] = strr1[i] + 48;
    
    return len1;
}

int main()
{
    char    str1[MAX] = {0};    //保存第一个大数
    char    str2[MAX] = {0};    // 保存第二个大数
    char    sum[MAX] = {0};     // 计算结果;
    char    summ[MAX] = {0};

    // a. 输入两个字符串
    scanf("%s %s", str1, str2);     //数组名代表首地址
    // b. 比较两个字符串的大小
    if( !compare(str1, str2) ){
        char num[MAX] ;
        strcpy(num, str1);
        strcpy(str1, str2);
        strcpy(str2, num);
    }
    int len = division(str1, str2, sum);
    if(len > 0){
        while(len > 0){
            len = division(str2, sum, summ);
            strcpy(str2, sum);
            strcpy(sum, summ);
            memset(summ, 0, sizeof(summ));
        }
        printf("最大公约数为: %s \n", str2);
    }
    else if(len == 0)
        printf("最大公约数为: %s \n", str2);
    else 
        printf("1 \n" );

    return 0;
}