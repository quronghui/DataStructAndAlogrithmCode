//
// Created by quronghui on 2019/9/3.
//
/*
 * 实现strcpy: 
 * 实现strncpy

 * */

#include <iostream>
#include <assert.h>

using namespace std;

// 思路一：不考虑内存覆盖的现象；
// 思路二：类似于memcpy函数的实现，将高地址到低地址的复制（转化为低地址到高地址的转化）
char *my_strcpy(char *dst, const char *src)
{
    // 检查两个字符串的合法性
    assert( dst != nullptr && src != nullptr);
    // 保存目的地址的首地址
    char *pdst = dst;

    // 方法一：先比较后复制
//    while(*src != '\0')
//        *dst++ = *src++;
//    *dst = '\0';          // 字符串结尾加上'\0'

    //方法二：先复制后比较
    while((*dst++ = *src++) != '\0');

    return pdst;
}

// 思路二： 实现strncpy
char *my_strncpy(char *dst, const char *src, int num)
{
    // 检查两个字符串的合法性；
    assert( dst != nullptr && src != nullptr);
    char *pdst = dst;
    while( (num--) && ((*dst++ = *src++) != '\0') );

    // 当num的值大于src中字符个数时，将会自动补'\0'；
    // num 是一个无符号的整数，一直减的话会报错; 将其类型改为int才能正确；
    while (num > 0) {
        *dst++ = '\0';
        num--;
    }
    return pdst;
}


// Test code
void Test1()
{
    char dst[10] = {};
    char *src = "hello";
    char *dst_new = my_strcpy(dst, src);
    cout << dst_new << endl;
}

// Test code
void Test2()
{
    char dst[10] = {};
    char *src = "hello";
    char *dst_new;
    dst_new = my_strncpy(dst, src, 5);
    cout << dst_new << endl;
}


int main()
{
//    Test1();
    Test2();
    return 0;
}