// 面试题45：把数组排成最小的数
// 题目：输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
// 例如输入数组{3, 32, 321}，则打印出这3个数字能排成的最小数字321323.
/*
*   1.解题思路
        a. 将这个拼接起来的大数,保存在字符串中;
        b. 根据字符串一位位的进行比较大小;
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 定义两个字符串数组:用于存储拼接在一起的字符串;
const int g_MaxNumberlength = 10;
char strCombine1[2*g_MaxNumberlength +1];
char strCombine2[2*g_MaxNumberlength +1];

/**************打印最小的数字**************/
void printMinNumber(int *numbers, int length)
{
    // 基础边界
    if(numbers == NULL || length < 0)
        return ;
    // 定义一个双指针, 根据数组长度定义基本大小
    // 相当于在定义二维数组;
    char **strNumbers = malloc(sizeof(int) * length);
    for(int i=0; i<length; i++){
        strNumbers[i] = malloc(sizeof(char) * g_MaxNumberlength + 1);
        sprintf(strNumbers, "%d" , numbers[i]);     // 将数组先转化为字符串
    }
    // qsort sort an array
    qsort(strNumbers, length, sizeof(char *), compare); // compare 比较函数
}

// compare 比较函数
int compare(const void *strNumber1, const void *strNumber2)
{
    
}