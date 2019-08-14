    // 题目五: 忽略字母大小写的差异, 实现字符串比较?
/*
    1. 要求:
        a. 比较两个字符串的前n个字符;
        b. 比较时忽略字母大小写的差异;
        c. 如果字符串相等则返回0, 否则返回第一个不同字符的差值;
            int abs(int i)  //返回整型参数i的绝对值 
            double fabs(double x)  //返回双精度参数x的绝对值    
            long labs(long n)  //返回长整型参数n的绝对值 
        d. 字母大小写的转换不能使用库函数
            用C语言提供的函数：小写转成大写toupper() ,tolower()
    2. 问题
        a. 大小写转换出了问题: 没有必要进行大小写的字符转换;  -- 被题目给误解了
        b. 我如何保证之比较前n个字符
    3. 解题思路:
        a. 根据两个字符串的差值进行while循环; 
            当*str1 - *str2 == 32 时, 写一个逻辑表达式, 判断两个字符串是不是属于大小写字母;
            如果为真, 继续循环; 否则就直接返回;
        b. 跳出循环时的如何做出判断?
            1) 首先判断n的值:   (当n  > 两个字符串长度的最小值), 返回 -1;
            2) 其次判断字符串的差值:
                创建了一个 bool保证为大小写字母 
            3) 如何判断此时大小写的差值: 这个得转化到同一个区间;
                创建了一个 bool 函数: 检测两个字符的大小写情况; 

*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int mystrcmp (const char *str1,const char *str2)
{
    while (*str1 && *str2 && (*str1 == *str2))
    {
        str1++;
	    str2++;
    }
    return *str1 - *str2;
}

// 判断字符串是否是大小写字母;
bool Capitalization(char str1, char str2){
     return  ( ('A' <= str1 && str1 <= 'Z') ||  ('a' <= str1 && str1 <= 'z') ) &&   ( ('A' <= str2 && str2 <= 'Z') ||  ('a' <= str2 && str2 <= 'z') ) ; 
 }

// 需要大小写转换的判断
bool CapitalizationConvert(char str1, char str2)
{
    return  ( ('A' <= str1 && str1 <= 'Z') &&  ('a' <= str2 && str2 <= 'z') ) ||    ( ('A' <= str2 && str2 <= 'Z') &&  ('a' <= str1 && str1 <= 'z') ) ; 
}

/******************根据字符串进行比较*********************/
int mystrncmp (const char *str1,const char *str2,int n)
 {
     if(n < 1)
        return -1;
    //  while 循环的判断条件 ; 字符相等的条件, 差值为0或者为32  = 'a' - 'A'
             
    while(*str1 && *str2 &&  ( (*str1 == *str2) ||   (abs(*str1  - *str2) == 32 )   )  &&  (n--) ){
        // 判断一下差值为32时是不是大小写;
        if( ! Capitalization(*str1, *str2)){
            return  abs(*str1 - *str2);
        }
        str1++;
	    str2++;
    }
    // 判断n的值的时候, 保证两个字符串为空; (当n  > 两个字符串长度的最小值)
    if(  (str1 == NULL || str2 == NULL) ||  n > 0 )
        return -1;
    // 判断字符串的差值
    int diffValue = abs(*str1 - *str2);
    // 字符相等情况
    if(  n == 0 &&  ( diffValue == 0  ||  ( diffValue == 32 &&  Capitalization(*str1, *str2) ) ) )
        return 0;
    // 如果里个字符串一个是大写一个是小写
    if( Capitalization(*str1, *str2)   &&  CapitalizationConvert(*str1, *str2)){
        // 固定将大写字母转换为小写字母
        if('A' < *str1 && *str1 < 'Z')
            return abs(*str1 + ('a' - 'A') - *str2);
        if(  ('A' <= *str2 && *str2 <= 'Z') )
            return abs( *str1 - *str2 -   ('a' - 'A') );
    }
    else 
        return diffValue;
    return -1;
}

/**************  a. 大小写转换出了问题: 没有必要进行大小写的字符转换;  -- 被题目给误解了****************/
// int mystrncmp (const char *str1,const char *str2,int n)
// {
//     if(n < 1)
//         return -1;
//     // 比较两个字符
//     while (*str1 && *str2 && (n--))
//     {
//         // 如果是一大一小的情况: 我统一转换成小写;
//         if( ( ('A' <= *str1 && *str1 <= 'Z') &&  ('a' <= *str2 && *str2 <= 'z') )  ||   ( ('a' <= *str1 && *str1 <= 'z') &&  ('A' <= *str2 && *str2 <= 'Z') )  ){
//             // 固定将大写字母转换为小写字母
//             char Constr;
//             if('A' < *str1 && *str1 < 'Z') {
//                 if( abs(*str1 - *str2) == 32)

//             }
//             else {
//                 Constr  =   *str2   +   ( 'a' - 'A' ) ;
//                 if(Constr != *str1)
//                     return abs(Constr - *str1); 
//             }  
//         }
//         // 全是大的, 或者全是小写, 那就不改变;
//         if(*str1 != *str2)
//             return abs( *str1 - *str2);
//         // 如果字符相等, 继续比较下一个字符;
//         str1++;
// 	    str2++;
//     }
//     return 0;
// }

void Test(char *name, char *str1, char *str2, int n)
{
    if(name != NULL)
        printf("%s begin:   ", name);
    
}

int main()
{   
    char str1[10];
    char str2[10];
    int n ;
    scanf ("%s",str1);
    scanf ("%s",str2);
    scanf ("%d",&n);
    // printf ("%d\n",mystrcmp(str1,str2));
    printf ("%d\n",mystrncmp(str1,str2,n));
    return 0;
}
