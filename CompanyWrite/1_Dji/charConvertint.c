// 题目二: 当一个char类型的变量, 赋值超过其范围的最大值, 此时应该怎么处理呢?
/*
    1. 有符号类型char的取值范围:  [-128, 127]   ;   超过127就会溢出, 变成最小值-128; 进行循环
    2. 无符号的char类型取值 [0, 255]; 超过255这个值会溢出, 变成最小值0; 进行循环
    

*/

#include <stdio.h>

int main(void)
{
    // unsigned char a = 255 ;
    char a = 128 ;
    int b;
    b = a;
    printf("a value is %d\n", a);
    printf("The (b+1) is %d\n", b+1);
}
