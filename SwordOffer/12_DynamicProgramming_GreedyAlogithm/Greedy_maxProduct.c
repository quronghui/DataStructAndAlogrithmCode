//  题目： 剪绳子：通过贪婪算法实现；
/*
*   1. 解题思路：当length >= 5时
        a. 2(length - 2) > length;
        b. 3(length -3 ) > length;
        c. 3(length -3 ) >= 2(length - 2);
        因此：我们要尽可能的得到长度为3的段，剩下的为长度2的段；
    2. 其余的情况分析 length == 4
        本来是不用剪的，但是题目要求减一刀
        2*2 > 1*3;  和上面的规律不符合，因此提出来
    3. 贪婪算法：
        保证每一步都是最优解，需要数学公式进行证明；
*/
#include <stdio.h>
#include <math.h>

int greedy_maxProduct(int length)
{
    // 绳子长度 length < 4的情况
    if(length < 2)
        return 0;
    if(length == 2)
        return 1;
    if(length == 3)
        return 2;
    
    //尽可能多地减去长度为3的绳子段
    int timesOf3 = length / 3;

    // 当绳子最后剩下的长度为4的时候，不能再剪去长度为3的绳子段。
    // 此时更好的方法是把绳子剪成长度为2的两段，因为2*2 > 3*1。
    if(length - timesOf3 * 3 == 1)
        timesOf3 -= 1;
    int timesOf2 = (length - timesOf3 * 3) / 2; 

    return (int) ( pow(3, timesOf3)) *  (int) (pow(2, timesOf2)) ;
}

/****************test code*********************/
void test(int length, int expected)
{
    int result = greedy_maxProduct(length);
    if(result == expected)
        printf("Max product is: %d passed.\n", result);
    else 
        printf("Invaild parameter, failed.\n");
}

int main()
{
    int length = 8;
    int expected = 18;
    test(length, expected);

    return 0;
}