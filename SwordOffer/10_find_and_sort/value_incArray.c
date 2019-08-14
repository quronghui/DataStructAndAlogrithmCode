// 面试题53（三）：数组中数值和下标相等的元素
// 题目：假设一个单调递增的数组里的每个元素都是整数并且是唯一的。
// 请编程实现一个函数找出数组中任意一个数值等于其下标的元素
// 例如，在数组{-3, -1,1, 3, 5}中，数字3和它的下标相等。
/*
    注意: 不用找出第一个下标元素相等的位置
    1. 思路一: 
        a. 从头开始遍历一遍, 找到第一个下标和值相等的元素;
    2. 思路二:
        a. 单调递增的数组: 使用二分查找法;
        b. 假设位置是m;
*/
#include <stdio.h>

/**************在递增数组中找出第一个下标和元素相等的位置******************/
int getValueIncreasingArray(const int *array, int length)
{
    if(array== NULL || length <= 0)
        return -1;
    // 找出第一个元素
    int left = 0;
    int right = length - 1;
    while( left <= right ){
        int middle = (left + right) >> 1;
        if( array [ middle] == middle ) 
            return middle;
        if( array[middle] > middle )
            right = middle - 1;
        else 
            left = middle + 1;
    }
    return -1;
}

/*********************Test code********************/
void Test(char *name, const int *array, int length, int expected)
{
    if(name != NULL)
        printf("%s begin:   ", name);
    int result = getValueIncreasingArray(array, length);
    if(result == expected)  
        printf("Passed. The result == expected is %d.\n", result);
    else 
        printf("Failed. The result != expected is %d.\n", result);
}
// 相等元素出现在中间
void Test1()
{
    int numbers[] = { -3, -1, 1, 3, 5 };
    int expected = 3;
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), expected);
}
// 相等元素出现在头部
void Test2()
{
    int numbers[] = { 0, 1, 3, 5, 6 };
    int expected = 0;
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), expected);
}
// 特殊的测试
void Test7()
{
    Test("Test7", NULL, 0, -1);
}

// main
int main()
{
    Test1();
    Test2();
    Test7();
    return 0;
}