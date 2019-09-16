// 题目：实现字符串的重排列
// (一)按照数字，小写字母，大写字母，其他字母进行输出?
// (二)统计各类字母的次数？
/*
 * 误区： 数组的赋值和复制方式：使用for循环，而不是直接赋值数组名；
 *
 * */

#include <stdio.h>

void str(char *s)
{
// TODO 请勿使用库函数
    if(*s == '\0')
        return ;
    char *string = s;
    char str1[100];
    char str2[100];
    char str3[100];
    char str4[100];
    int i=0,j=0,k=0,l=0;
    while (*string != '\0'){
        if(*string >= '0' && *string <= '9')
            str1[i++] = *string;
        else if(*string >= 'a' && *string <= 'z')
            str2[j++] = *string;
        else if(*string >= 'A' && *string <= 'Z')
            str3[k++] = *string;
        else
            str4[l++] = *string;
        string++;
    }
    printf("time %d %d %d %d\n",i,j,k,l);
    for(int jj = 0; jj < j ; jj++)
        str1[i++] = str2[jj];
    for(int jj = 0; jj < k ; jj++)
        str1[i++] = str3[jj];
    for(int jj = 0; jj < l ; jj++)
        str1[i++] = str4[jj];
    str1[i] = '\0';

    // (1) 当时的误区：数组是不能这样赋值的: s = str1; 应该是通过for循环进行赋值
    for (int m = 0; m < i; ++m) {
        s[m] = str1[m];
    }
    printf("%s\n",s);
}

int main() {
    char s[100] ;
    scanf("%s", s);
    str(s);

    printf("%s\n", s);

    return 0;
}