// 面试题63：股票的最大利润
// 题目：假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖交易该股票可能获得的利润是多少?
// 例如一只股票在某些时间节点的价格为{9, 11, 8, 5,7, 12, 16, 14}。
// 如果我们能在价格为5的时候买入并在价格为16时卖出，则能收获最大的利润11。
/*
*   1. 解题思路: 只是买卖一次
        a. 要获得的最大的利润:  定义函数 diff(i) 为当卖出价为数组中第 i 个数字时, 可能获得的最大利润;
        b. 在 (i - 1)中找到买入价的最低值, 便能得到最大的利润;
        c. 顺序遍历一遍数组, 最小值永远作为买入, 只需获得最大的差值, 便能得到最大的利润;
*/ 
#include <stdio.h>

// 买卖股票的最大利润
int MaxDiff(int *numbers, unsigned int   length)
{   
    // 至少是两个元素, 够一次买入和卖出
    if(numbers == NULL || length < 2)
        return 0;

    // 定义买入的最小值, 利润的最大值
    int min =   numbers[0];
    int maxDiff =   numbers[1]  -   min;

    for(int i = 2; i < length; i++){
        // 买入值最小
        if( numbers[i - 1] < min )
            min =   numbers[i-1];
        // 记录每次的利润值
        int currentDiff = numbers[i]  - min;
        if( currentDiff > maxDiff )
            maxDiff =   currentDiff;
    }
    return  maxDiff;
}

/*****************Test code******************/
void Test(char *name, int *number, int length, int expected)
{
    if(name !=NULL)
        printf("%s begin:   ", name);
    int maxdiff = MaxDiff(number, length);
    if(maxdiff == expected)
        printf("Passed. The maxdiff == expected  value is %d.\n", maxdiff);
    else 
        printf("Failed. The maxdiff != expected value is %d.\n", maxdiff);
}

// 功能测试
void Test1()
{
    int numbers[] = { 4, 1, 3, 2, 5 };
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), 4);
}

// 价格递增
void Test2()
{
    int numbers[] = { 1, 2, 4, 7, 11, 16 };
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), 15);
}

// 价格递减
void Test3()
{
    int numbers[] = { 16, 11, 7, 4, 2, 1 };
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), -1);
}
// 鲁棒性测试
void Test8()
{
	Test("Test8", NULL, 0, 0);
}

// main
int main()
{
    Test1();
    Test2();
    Test3();
    Test8();
    return 0;
}
