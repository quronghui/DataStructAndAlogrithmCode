// 面试题61：扑克牌的顺子
// 题目：从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
// 2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王可以看成任意数字。
/*
*   1.  解题思路:
        a . 大小王可以看成任何数字, 将大小王初始化为0;
        b. 顺子的判断, 定义一个大小为5的数组;
        c. 第一步: 进行排序;
        d. 第二步: 统计数组中0的个数;
        e. 第三步: 统计数组中相邻数组之间的空缺总数;
        f.  判断: (1)如果空缺数和 = 0 ,则连续;  (2) 非0重复数字出现, 那么就是不连续的;
    2. 选择的数组排序是qsort ;O(nlogn)
        a. 也可以定义一个长度为14的哈希表, 这样在O(n)时间完成排序;
        b. 当n不是很大的时候, O(n) 和 O(nlogN)不会有很大的区别;
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 函数声明
int compare(const void *arg1, const void *arg2);


/*****************判断是否连续********************/
bool IsContinuous( int *number, int length )
{
    // 边界条件
    if(number == NULL || length < 1)
        return false;
    
    // 对数组进行排序
    qsort(number, length, sizeof(int), compare);
    // 统计数组中空缺数, 和0的数目
    int numberZero  =   0;
    int numberGap   =   0;
    
    // 统计0的个数
    for( int i=0; (i < length) && (number[i] == 0) ; i++)
        ++numberZero;
    
    // 统计间隔数, 
    int small = numberZero;
    int big =   small   +   1;          //存在0时, 0总是出现在开头, 要将0的个数和位置过滤;
    while ( big <   length ){
        // 两个数相等, 存在对子; 
        if( number[small]  == number[big])
            return false;
        numberGap   += number[big] - number[small] - 1;
        
        small   =   big;
        ++big;
    }
    return  (numberGap  >   numberZero)?    false   :   true ;
}

// compare函数
int compare(const void *arg1, const void *arg2)
{
    return *(int    *)arg1 - *(int *)arg2;
}

/*********************Test code**********************/
void    Test(char *name, int *number,   int length, bool expected)
{
    if(name != NULL)
        printf("%s begin:   ", name);
    
    if( IsContinuous(number,length) == expected )
        printf("Passed.\n");
    else 
        printf("Failed.\n");
}

// 是连续的
void Test1()
{
    int numbers[] = { 1, 3, 2, 5, 4 };
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), true);
}

// 不是连续的
void Test2()
{
    int numbers[] = { 1, 3, 2, 6, 4 };
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), false);
}

// 存在一个大小王
void Test3()
{
    int numbers[] = { 0, 3, 2, 6, 4 };
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), true);
}

// 有对子
void Test11()
{
    int numbers[] = { 1, 0, 0, 1, 0 };
    Test("Test11", numbers, sizeof(numbers) / sizeof(int), false);
}

// 鲁棒性测试
void Test12()
{
    Test("Test12", NULL, 0, false);
}
// main
int main()
{
    Test1();
    Test2();
    Test3();
    // Test4();
    // Test5();
    // Test6();
    // Test7();
    // Test8();
    // Test9();
    // Test10();
    Test11();
    Test12();

    return 0;
}