// 面试题53（二）：0到n-1中缺失的数字
// 题目：一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0到n-1之内。
// 在范围0到n-1的n个数字中有且只有一个数字不在该数组 中，请找出这个数字。
/*
        1.思路一: 
            a. 数组中的元素是递增且是唯一的, 先求出n个数的和 : sum1 = n(n-1) / 2;
            b.  从头遍历一遍数组并求和, sum2;
            c. number = sum1 - sum2;        时间复杂度是O(N)
        2. 思路二: 
            a. 使用二分查找的方法:
            b. 不在数组中的元素记为m, 那么此时m位置上的元素应该是(m+1);
            c. 只需要找出第一个下标和元素不相等的位置就行;
            d. 注意: 只要出现位置和元素不相等, 那么这个数就只能在左边区域, 或者就是它本身;
*/
#include <stdio.h>

/******************二分法查找缺失的元素********************/
int getMissing( const int *array, int length )
{
    if(array == NULL || length <= 0)
        return -1;
    
    // 找下标不相等的位置
    int left = 0;
    int right = length-1;
    while( left <=  right ){
        int number = (right + left)>>1;
        // 下标和值不相等, 只可能出现在m的右边
        if( array[number] != number ){
            if( number==0 || ( array[number-1] == number-1  ))
                return number;
            right = number - 1;     // 只可能出现在右边;
        }
        else 
            left = number + 1;
    }
    // 注意: 最后这种情况,  前面所有的数组都不缺, 就只差最后的第n个元素
    if( left == length )
        return length;
    
    return -1;      // 无效输入, 或者有数字不在0-n-1;
}

/********************Test Code**********************/
void    Test(char *name,  const int *array, int length, int expected )
{
    if(name != NULL)
        printf("%s begin:   ", name);

    int result = getMissing(array, length);
    if( result == expected)
        printf("Passed. The  result == expected is %d.\n ", result);
    else 
        printf("Failed. The  result != expected is %d.\n ", result);
}
// 缺失的是第一个数字0
void Test1()
{
    int numbers[] = { 1, 2, 3, 4, 5 };
    int expected = 0;
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 缺失的是最后一个数字
void Test2()
{
    int numbers[] = { 0, 1, 2};
    int expected = 3;
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), expected);
}

// main
int main()
{
    // Test1();
    Test2();
    // Test3();
    return 0;
}