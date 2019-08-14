// 面试题39：数组中出现次数超过一半的数字
// 题目：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
// 例如输入一个长度为9的数组{1, 2, 3, 2, 2, 2, 5, 4, 2}。
// 由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。
/*
×   1. 解题思路一：
        a. 如果先将这个数组进行排序，得到一个排序数组； 快速排序时间O(NlogN)
        b. 我们就只需要查看中间位置的数字的数量是否超过一半；
        c. 缺点：快速排序需要改变整个数组；
*   2. 解题思路二：O（N）
        考虑数组下标的特性
        a. 如果一个数组存在超过一半的数字, 这个数字所处的位置下标, 一定在中间位置；
        b. 所以：基于partition快速排序的方式实现题目思路；
        c. 通过每次中间枢纽元素：将数组分为三部分；直到选中的数字下标刚好是 n/2；
        d. 判读下标为n/2 的元素是否达到一半的要求 (不需要全部快排就能得到元素)
    3. 解题思路三：o(N)
        a. 考虑超过一半这个特性，并且只遍历一边数组，不改动数组；
        b. 遍历数组的时候保存两个值：一个数组中的元素value，另外一个是次数time；
        c. 当下一个元素和value相等 ， time++;否则time--；
            当time==0，则换一个元素；
        d. 如果存在超过一半的数，最后 time >= 1；
*/
# include "quick_sort.h"
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
// 函数声明
bool cheakMoreThanHalf(int *numbers, int length, int result);

/***************************解题思路二***************************/
/*******************通过数组下标的特性进行判断************************/
int moreHalfHalfNum(int *numbers, int length)
{
    // 数组是否为空
    if(numbers == NULL || length <= 0){
        printf("The numbers[] is null or parameter invailed.\n");
        return 0;
    }
    // 定下中间下标
    int middle = length >> 1;
    // 构建partition划分函数使用条件
    int start = 0;
    int end = length - 1;
    int index = partition(numbers, length, start, end);
    // 判断得到的index 下标和middle
    while (index != middle)
    {   
        // 在中间枢纽元素的左边
        if(index > middle){
            end = index - 1;
            index = partition(numbers, length, start, end);
        }
        else{
            start = index + 1;
            index = partition(numbers, length, start, end);
        }
    }

    // 得到中间位置元素，并判断其数量是否满足
    int result = numbers[middle];
    if( !cheakMoreThanHalf(numbers, length, result) )
        return 0;
    
    return result;    
}

/***************判读下标为n/2 的元素个数**********************/ 
bool cheakMoreThanHalf(int *numbers, int length, int result)
{
    int times = 0;
    for(int i = 0; i < length; ++i){
        if(numbers[i] == result)
            times++;
    }
    // 超过一半
    if(times * 2 <= length)
        return false;
    else 
        return true;
}

/*************************************************************/
/************************解题思路三************************/
/******************通过出现的次数进行判断********************/
int timeHalfNum(int *numbers, int length)
{
    // 数组是否为空
    if(numbers == NULL || length <= 0){
        printf("The numbers[] is null or parameter invailed.\n");
        return 0;
    }
    int value = numbers[0];
    int times= 1;               // 注意：当value存在元素，则times==1
    for( int i=1; i < length; ++i){
        if(times == 0){
            value = numbers[i];
            times = 1;
        }
        else if(numbers[i] == value)
            times++;
        else 
            times--;
    }
    // 判断最后time1的值；
    if(times >= 1)
        return value;
    else
        return 0;
}


/*********************test code*********************/
// 如果测试函数需要两个测试量时，可以用全局变量产生一个；全局变量声明
void Test(char *name, int *numbers, int length, int expectedValue)
{
    if(name != NULL)
        printf("%s begin: \n", name);
    
    // 复制一遍数组元素；数组的复制需要一个元素一个元素的赋复制；数组名是指针标量
    int *copy = malloc(sizeof(int) * length); // 这里可以直接使用numbers吗？
    for(int i=0; i<length; i++){
        copy[i] = numbers[i];
    }

    // 测试思路二；
    printf("Test for solution two: ");
    int result = moreHalfHalfNum(numbers,length);
    if(expectedValue == result)
        printf("The middle value is %d, and test passed.\n", result);
    else 
        printf("The value is %d, but test failed.\n", result);

    // 测试思路三；
    printf("Test for solution three: ");
    int index = timeHalfNum(numbers, length);
    if(expectedValue == index)
        printf("The middle value is %d, and test passed.\n", index);
    else 
        printf("The value is %d, but test failed.\n", index);
}
// 存在超过一半的数；
void test1()
{
    int numbers[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    Test("test1", numbers, sizeof(numbers)/sizeof(int), 2);
}
int main()
{
    test1();
    return 0;
}