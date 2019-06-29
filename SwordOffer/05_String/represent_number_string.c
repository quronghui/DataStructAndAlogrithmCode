// 面试题20：表示数值的字符串
// 题目：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
// 例如，字符串“+100”、“5e2”、“-123”、“3.1416”及“-1E-16”都表示数值，
// 但“12e”、“1a3.14”、“1.2.3”、“+-5”及“12e+5.4”都不是

/*
*   1. 通过举例子得到规律
        a.表示数值的字符串遵循模式 A[.[B]][e|E C] 或者是 .B[e|E C]
        b. A 和 C 可能是以'+'/'-' 开头的 0-9 的多位字符串；C 表示的是指数部分，指数不能是小数； signed int
        c. B 是 0-9 的多位字符串    unsigned int
        d. 用字符串表示大数；
    2.解题思路：
        从左到右扫描 A，B, C；
        各自有判断的条件：
    3.字符串的判断类型：使用的是bool类型
*/
#include <stdio.h>
#include <stdbool.h>

bool scanInteger(const char **str);
bool scanUnsignedInteger(const char **str);

/****************对数值中的三种情况进行分类*******************/
bool isNumber(const char *str)
{
    if(str == NULL){            // 边界条件
        puts("String is null.");
        return false;
    }
    /* 扫描整数部分，相当于A */
    bool numeric = scanInteger(&str);

    /* 遇到小数点’.‘，扫面B的整数部分 */
    if(*str == '.'){
        ++str;
        // 下面一行代码用||的原因：
        // 1. 小数可以没有整数部分，例如.123等于0.123；
        // 2. 小数点后面可以没有数字，例如233.等于233.0；
        // 3. 当然小数点前面和后面可以有数字，例如233.666

        // 这个顺序的scanUnsignedInteger(&str)在前，不然字符串就不会检测后面部分了
        numeric = scanUnsignedInteger(&str) || numeric ;   
    }
    /* 遇到了指数的部分 'e/E'，相当于C */
    if( *str=='e' || *str=='E'){
        ++str;
        // 下面一行代码用&&的原因：
        // 1. 当e或E前面没有数字时，整个字符串不能表示数字，例如.e1、e1；
        // 2. 当e或E后面没有整数时，整个字符串不能表示数字，例如12e、12e+5.4
        numeric = numeric && scanInteger(&str);
    }
    return numeric && *str == '\0';     // 检查到最后一个字符
}

/************scanUnsignedInteger 扫描无符号的整数部分0-9； 相当于B部分******************/
bool scanUnsignedInteger(const char **str)
{
    const char *before = *str;
    while(**str != '\0' && **str >='0' && **str <='9')
        ++(*str);   // 移动到下一位，下一位的地址；
    // 比较的是 地址的大小；当地址大的时候，才是有数据的；
    return *str > before;
}
/*********************scanInteger 扫描有符号整数部分。相当于A*************************/
bool scanInteger(const char **str)
{
    if(**str=='+' || **str=='-')
        ++(*str);
    return scanUnsignedInteger(str);
}

/****************void test******************/
void Test(const char* testName, const char* str, bool expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    if(isNumber(str) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
    Test("Test1", "100", true);
    Test("Test2", "123.45e+6", true);
    Test("Test3", "+500", true);
    Test("Test4", "5e2", true);
    Test("Test5", "3.1416", true);
    Test("Test6", "600.", true);
    Test("Test7", "-.123", true);
    Test("Test8", "-1E-16", true);
    Test("Test9", "1.79769313486232E+308", true);

    printf("\n\n");

    Test("Test10", "12e", false);
    Test("Test11", "1a3.14", false);
    Test("Test12", "1+23", false);
    Test("Test13", "1.2.3", false);
    Test("Test14", "+-5", false);
    Test("Test15", "12e+5.4", false);
    Test("Test16", ".", false);
    Test("Test17", ".e1", false);
    Test("Test18", "e1", false);
    Test("Test19", "+.", false);
    Test("Test20", "", false);
    Test("Test21", NULL, false);

    return 0;
}
