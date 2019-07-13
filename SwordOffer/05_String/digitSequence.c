// 面试题44：数字序列中某一位的数字
// 题目：数字以0123456789101112131415…的格式序列化到一个字符序列中。
// 在这个序列中，第5位（从0开始计数）是5，第13位是1，第19位是4，等等。
/*
    1. 从0开始计数，而不是从1开始计数；%取余数的时候，就会从0开始
*   2.解题思路：对大数的位数进行区分；
        a. digit = 1数字从'0'-'9': 这个就是前10位；
        b. digit = 2数字从'10'-'99': 两位数，总共有180位；
        c. digit = 3数字从'100'- '999': 三位数，总共有2700位 ...
    3.举例子: 第1001位是那一个数字
        a. 递增得到digit位数字中,总的数字个数numbers * digit;
        b. 判断查找的位数 index 和总数字之间的关系;
        c. 当index 在digit这个位数内, 查找出具体的数字;
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// 函数声明
int countOfIntegers(int digit);
int determine_digitAtIndex(int index, int digit);
int beginNumber(int digit);

/****************查看digit位数, 对应的数字总的位数*******************/
int digitAtIndex(int index)
{
    // 边界条件；查找的位数至少是大于0的
    if(index < 0)
        return -1;
    
    int digit = 1;  // 从一位数开始...数字从'0'-'9'
    while(true){
        // 得到digit位数：总共含有多少位数字；
        int numbers = countOfIntegers(digit);
        // 当digit位数 > index时，在里面进行查找得到；
        if(index < numbers * digit)
            return determine_digitAtIndex(index, digit);
        index -= digit * numbers;
        digit ++;
    }
}

// 1. 得到digit位数字的总个数；
int countOfIntegers(int digit)
{
    if(digit == 1)
        return 10;
    int count = (int)pow( 10, digit-1);
    return 9 * count;
}

// 2. 得出要找的数字位于m位的数中，找出具体是哪一个数字
// 此时的index已经减去了前面几位digit中含有的数字个数
int determine_digitAtIndex(int index, int digit)
{
    int number = beginNumber(digit) + index/digit;  // 从100开始的三位数; index此时含有多少个三位数
    int indexFromRight = digit - index % digit;     // 查看此时剩余的余数,
    
    // 注意:我们取356中的某一位的时候,是通过取余数的,而且从右到左的;
    for(int i=1; i<indexFromRight; i++)
        number /= 10;
    return number % 10;
}

// 3.需要知道m位数的第一个数字; digit=2 --> beginNumber = 10
int beginNumber(int digit)
{
    if(digit == 1)
        return 0;
    return (int)pow(10, digit-1);
}

/********************Test code********************/ 
void Test(char *name, int inputIndex, int expectedOutput)
{
    if(name != NULL)
        printf("%s begin:   ", name );
    
    int value = digitAtIndex(inputIndex);
    if(value == expectedOutput)
        printf("The value=expectedOutput is %d, passed.\n", value);
    else 
        printf("The value != expectedOutput is %d, failed.\n", value);    
}

// main
int main()
{
    Test("test1", 5, 5);
    return 0;
}