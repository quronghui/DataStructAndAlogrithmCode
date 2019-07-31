// 面试题57（一）：和为s的两个数字
// 题目：输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们
// 的和正好是s。如果有多对数字的和等于s，输出任意一对即可。
/*
*   1. 解题思路:
        a. 数组是递增排序的, 要找出两个数之和;
        b. 两个指针指向开头和结尾, 循环条件 ahead > behind;
        c. 比较 SUM = s  之间的关系, 移动指针;
*/
#include <stdio.h>
#include <stdbool.h>

/*********************funcation*************************/
int findNumberWithSum(int data[], int length, int sum, int *num1, int *num2)
{
    bool found  =   false;
    if( length < 1|| num1 == NULL || num2 == NULL )
        return found;
    
    // 定义两个指针指向数组的开头和结尾
    int ahead   =   length  -   1;      // 向前移动
    int behind  =   0;
    while (ahead > behind)
    {
        long long   curSum  =   data[ahead] + data[behind];
        if( curSum == sum ){
            *num1 = data[behind];           // 通过两个指针保存数值
            *num2   =   data[ahead];
            found = true;
            break;
        }
        else if( curSum > sum )
            ahead--;
        else 
            behind ++;
    }
    return found;
}

/******************Test code*********************/
void Test(const char* testName, int data[], int length, int sum, bool expectedReturn)
{
    if(testName != NULL)
        printf("%s begins: ", testName);
    
    int num1, num2;     // 得到那两个值;
    int result = findNumberWithSum(data, length, sum, &num1, &num2);
    if(result == expectedReturn)
    {
        printf("The value is %d and %d.\n", num1, num2);
    }
    else
        printf("FAILED. \n");
}

// 存在和为s的两个数字，这两个数字位于数组的中间
void Test1()
{
    int data[] = {1, 2, 4, 7, 11, 15};
    Test("Test1", data, sizeof(data) / sizeof(int), 15, true);
}

// main
int main()
{
    Test1();
    return 0;
}