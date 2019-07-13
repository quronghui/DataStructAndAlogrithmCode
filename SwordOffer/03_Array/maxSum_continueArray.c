// 面试题42：连续子数组的最大和
// 题目：输入一个整型数组，数组里有正数也有负数。数组中一个或连续的多个整数组成一个子数组。
// 求所有子数组的和的最大值。要求时间复杂度为O(n)。
/*
*   1.解题思路一：枚举法，最快需要O(n^2);
    2.解题思路二：分析数组规律
        a. 连续子数组的最大和： 当前面的和小于0时，删除啊前面的序列，从当前位置开始；

    题目扩展：
        b. 输出这个最大子序列这个数组：定义两个下标，指向开始和结束位置；
        （思路：想通过队列实现数据结构）
        c. 对于最大和为负数时如何输出最大子序列：start = end;
    3. 解题思路二：代码缺陷
        a. 这个代码实现的是最大的子序列之和，没有判断这个子序列是不是最短的;
*/
#include <stdio.h>
#include <stdbool.h>

bool g_InvailedInput = false;   // 定义全局变量，设置错误输入检测位；

/*******************思路二：根据数组的规律**********************/
int findMaxSum_InArray(int *numbers, int length)
{
    // 边界参数
    if((numbers == NULL) || (length <= 0)){
        g_InvailedInput = true;
        printf("Invailed parameter input.\n");
        return 0;
    }
    // 不能忘记设置标志位；
    g_InvailedInput = false;
    // 求和判断序列
    int nCurSum = 0;
    int nGreatestSum = 0x80000000;
    
    int start = 0;      // 最大子序列起始位置；
    int end = 0;

    for(int i=0; i<length; i++){
        // 序列和小于0
        if(nCurSum <= 0){
            nCurSum = numbers[i];
            start = i;
        }
        else
            nCurSum += numbers[i];

        // 更新最大和
        if(nCurSum > nGreatestSum){
            nGreatestSum = nCurSum;
            end = i;
        }   
    }

    // 输出最大子序列
    printf("The max order is: \n");

    if( start > end)    // 注意：序列全为负数，此时就以序列和最大的负数为准
        start = end;
    // 输出最大序列和
    for(int j=start; j <= end; j++ )
        printf("%d\t", numbers[j]);
    
    return nGreatestSum;
}

/****************Test ********************/
void Test(char *name, int *numbers, int length, int expected, bool expectedFlag)
{
    if(name != NULL)
        printf("%s begin \n:", name);
    // 调用功能函数
    int index = findMaxSum_InArray(numbers, length);
    if(index == expected && expectedFlag == g_InvailedInput)
        printf("Passed.\n");
    else 
        printf("Failed.\n");
}

// test1()
void test1()
{
    int data[] = {1, -2, 3, 10, -4, 7, 2, -5};
    Test("test1", data, sizeof(data) / sizeof(int), 18, false);
}

// 全为复数；
void test2()
{
    int data[] = {-2, -8, -1, -5, -8, -9};
    Test("Test2", data, sizeof(data) / sizeof(int), -1, false);
}

// 全是正数 
void test3()
{
    int data[] = {2, 8, 1, 5, 9};
    Test("test3", data, sizeof(data) / sizeof(int), 25, false);
}

// main函数
int main()
{
    test1();
    test2();
    test3();
    return 0;
}