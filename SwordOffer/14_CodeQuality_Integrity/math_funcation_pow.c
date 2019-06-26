// 面试题16：数值的整数次方
// 题目：实现函数double Power(double base, int exponent)，求base的exponent次方。
// 不得使用库函数，同时不需要考虑大数问题。

/*
*   1.题目提示：
        a. 实现base的exponent次方，不能使用math funcation;
        b. 学会理解库函数的实现过程
    2.解题思路
        a.实现功能的代码： 通过for循环，实现 exponent 个 base 相乘；
            进一步优化：exponent / 2， 减少循环次数；（底数相同，指数相加）
        b.边界情况
            当exponent为负数时，取绝对值
        c.异常情况：需要异常处理
            通过举例的方式，找出特殊的情况
            base = 0.0; exponent < 0; 需要异常处理
*/

#include <stdio.h>
#include <stdbool.h>

bool g_InvalidInput = false;    // 定义全局变量，对异常进行处理

double PowerWithUnsignedExponent(double base, unsigned int exponent);
bool equal(double num1, double num2);

/********************异常处理和边界条件，调用功能函数***********************/
double Pow(double base, double exponent)
{
    g_InvalidInput = false;     // 全局变量检查

    if( equal(base, 0.0) && exponent < 0 ){   // 异常情况的处理
        g_InvalidInput = true;
        return 0.0;
    }

    unsigned int absExponent = (unsigned int) exponent; // 类型强制转换为，无符号整形
    if(exponent < 0)
        absExponent = (unsigned int)(-exponent);        // exponent 为绝对值
    
    double result = PowerWithUnsignedExponent(base, absExponent);  // 功能函数
    if( exponent < 0)
        result = 1.0/result;    // 取倒数
    
    return result;
}
/*****************double 类型值的判断********************/
//C规定，float 类型必须至少能表示6位有效数字
bool equal(double num1, double num2)
{
    if((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
        return true;
    else 
        return false;
}

/***************功能函数的实现*****************/
// 通过exponent 进行优化
double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
    if(exponent == 0)
        return 1;
    if(exponent == 1)
        return base;

    double result = PowerWithUnsignedExponent(base, exponent >> 1); //递归调用
    result *= result;

    if( (exponent & 0x1) == 1)  // 按位运算，判断是够为奇数为奇数时
        result *= base;

    // double result = 1.0;
    // for(int i=1; i<=exponent; i++){
    //     result *= base;
    // }
    return result;
}

/*********************test code*********************/
void test(double base, double exponent, double expectedResult, bool expectedFlag)
{
    double result = Pow(base, exponent);
    if(equal(result, expectedResult) && expectedFlag == g_InvalidInput)
        printf("Reculate result is %f passed.\n", result);
    else 
        printf("Reculate result is failed.\n");
}

int main()
{
    test(2, 3, 8, false);

    // 底数为0、指数为负数
    test(0, -4, 0, true);

    // 指数为负数
    test(2, -3, 0.125, false);

    return 0;
}