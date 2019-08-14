// 面试题56（一）：数组中只出现一次的两个数字
// 题目：一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序
// 找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
/*
    1. 解题思路一 : 只有一个数字出现一次
        a. 使用位运算的 异或 ^;
        b. 我们先假设只有一个数字出现一次, 其他都出现两次;
        c. 交换律：a ^ b ^ c <=> a ^ c ^ b
            任何数与0异或 0 ^ n = n
            相同的数异或为0 n ^ n => 0
        d. 只需要使用0异或一次便能找出那个数字;
        e. 时间复杂度O(N), 只需要遍历一次
    2. 解题思路一 :  出现一次的两个数字
        a. 按照这两个数字将大数组分为两个小数组;
        b. 每个数组包含一个出现一次的数, 其余的是出现两次的数;
        c. 对这两个数组进行全异或, 便能得出解

    3. 方法二: 哈希表
    4. 方法三: 快速排序
*/
#include <stdio.h>
#include <stdbool.h>

// 函数声明
unsigned int    findFirstBitIs1(int num);
bool IsBit1( int num, unsigned int  indexBit );

/********************函数接口*********************/
void findNumsAppearOnce( int *array, int length, int *num1, int *num2 )
{
    // 至少要有两个元素
    if(array == NULL || length < 2)
        return;
    
    // 全异或
    // 用0与数组中所有元素分别异或，因为是不同的两个数字，所以这个值必定不为0；
    int resultExclusiveOR   =   0;
    for( int i=0; i<length; i++ ){
        resultExclusiveOR ^=  array[i];
    }
    // 这个值右移indexBit 后, &1 != 0;
    unsigned int    indexOf1    =   findFirstBitIs1(resultExclusiveOR);
    // 根据indexOf1将数组进行分类
    *num1   =   *num2   =   0;
    for(int j = 0; j<length; j++){
        if( IsBit1( array[j], indexOf1 ) )
            *num1   ^=  array[j];               // 分别在两个子数组中进行异或得到值
        else 
            *num2   ^=  array[j];
    }
}

// 值右移多少位后, 按位与1的值为0
unsigned int    findFirstBitIs1(int num)
{
    int indexBit    =   0;
    while( ((num & 1) == 0) &&  (indexBit < 8  *  sizeof(int)) ){
        num =   num >>1;
        ++indexBit;
    }
    return indexBit;
}

//  将值分为两类, 一类为0和一类为1的两个数组
bool IsBit1( int num, unsigned int  indexBit )
{
    num =   num >>indexBit;
    return  (num    & 1);
}

/****************Test code****************/
void Test(const char* testName, int data[], int length, int expected1, int expected2)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    int result1, result2;
    findNumsAppearOnce(data, length, &result1, &result2);

    if((expected1 == result1 && expected2 == result2) ||
        (expected2 == result1 && expected1 == result2))
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

// 有两个以上的元素
// void Test1()
// {
//     int data[] = { 2, 4, 3, 6, 3, 2, 5, 5 };
//     Test("Test1", data, sizeof(data) / sizeof(int), 4, 6);
// }

// 只包含两个元素
void Test2()
{
    int data[] = { 4, 6 };
    Test("Test2", data, sizeof(data) / sizeof(int), 4, 6);
}

// main
int main()
{
    // Test1();
    Test2();
    return 0;
}