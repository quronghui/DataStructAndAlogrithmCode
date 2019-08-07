// 面试题65：不用加减乘除做加法
// 题目：写一个函数，求两个整数之和，要求在函数体内不得使用＋、－、×、÷
// 四则运算符号。
/* 
*   1.解题思路:
        a. 不能使用四则运算, 那么在整数加法上, 可以使用机器的位运算;
        b. 第一步: 相加但不进位;
            第二步: 记下进位值;
            第三步: 将进位值和第一步的值相加;
    2. 注意点:
        不使用新的变量, 进行两个变量的交换: 可以通过异火进行实现;
*/
#include    <stdio.h>

int AddNumber(int num1, int num2)
{
    int sum , carry ;
    do{
        sum =   num1 ^ num2;       //    相加但是不进位就是异或;
        carry   =   (num1   &   num2)   <<  1 ;     // 记下进位的值, 从右往左进行按位&, 进位的话就左移一位;
        num1    =   sum;    
        num2    =   carry;
    }while(num2 !=  0);

    return  num1;
}

/***************test code********************/
void Test(int num1, int num2, int expected)
{
    int result = AddNumber(num1, num2);
    if(result == expected)
        printf("%d + %d is %d. Passed.\n", num1, num2, result);
    else 
        printf("%d + %d is %d. Failed.\n", num1, num2, result);
}

int main()
{
    // Test(1, 2, 3);
    Test(5, 17, 22);

    return 0;
}