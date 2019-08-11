// 题目: 判断两个double类型的值是否相等;
/*
*   1. 解题思路: 
        a. 一般类型的数值判断:  "=="
        b. double类型的两个值判断: 根据double类型的值是8位进行判断;
*/
#include <stdbool.h>

/*********************Equal double相等函数的判断********************/
bool Equal(double num1, double num2)
{
    if((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
        return true;
    else 
        return false;
}