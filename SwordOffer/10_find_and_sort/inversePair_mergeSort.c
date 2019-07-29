// 面试题51：数组中的逆序对
// 题目：在数组中的两个数字如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
// 输入一个数组，求出这个数组中的逆序对的总数。
/*
    1. 解题思路一: 
        a. 不改变数组的前提下, 将每一个元素, 和后面所有元素进行比较;
        b. 时间效率: O(n^2)
    2. 解题思路二:
        a. 采用归并排序的方式, 时间复杂度 O(nlog(n)), 空间复杂度是O(n);
        b. 
*/
#include <stdio.h>
#include <stdlib.h>

// 函数声明;
int MergeSort(int *data, int   *copy, int start, int end);

// 用户接口函数
int inversePair( int *data, int length )
{
    if( data == NULL || length <= 0 )
        return 0;
    // 归并排序: 需要一个数组空间保存新的元素;
    // 为了不改变原来的数组, 我们创建一个新的数组空间指向原来的
    
    int *copy = malloc( sizeof(int)  * length );
    for (int i = 0; i < length; i++){
        copy[i] = data[i];
    }
    // 调用归并函数
    int count = MergeSort(data, copy, 0, length-1);
    free(copy);

    return count;
}

// 归并排序的方式:
int MergeSort(int *data, int   *copy, int start, int end)
{
    // 递归的base; 归并排序时, 数组分到最小, 单个元素;
    if( start == end ){
        copy[start] = data[start];
        return 0;
    }
    // 归并排序, 先分半; 递归调用
    int length = (end -start) / 2;
    // int left = MergeSort(data, copy,  start, start + length);    // 这里为啥要倒置
    // int right = MergeSort(data, copy,  start+length+1, end);
    int left = MergeSort(copy, data,  start, start + length);    // 这里为啥要倒置, 不倒置的话, 会出现次数多1
    int right = MergeSort(copy, data,   start+length+1, end);

    // 定义两个下标, 指向两个分半数组的最后一个值
    int i_left = start + length;    
    int j_right = end;                    
    int copy_end = end;             //  新数组的最后一个下标位置

    // 统计逆序对的个数
    int count = 0;
    while( i_left >= start &&  j_right   >=   start+length+1  ){
        // 统计逆序队个数
        if( data[i_left] > data[j_right] ){
            copy[copy_end--] = data[i_left -- ];
            count += j_right - start - length;
        }
        else 
            copy[copy_end--] = data[j_right--];     // 不存在逆序队的个数;
    }

    // 不太清楚, 这里是在干啥呢;
    for(; i_left >=start; i_left--)
        copy[copy_end--] = data[i_left];

    for(; j_right >= start+length+1; j_right--)
        copy[copy_end--] = data[j_right];
        
     return left + right + count;
}

/********************************Test code*********************************/
void Test(char* testName, int* data, int length, int expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    int count = inversePair(data, length);
    if(count  == expected)
        printf("Passed. The count  == expected is %d.\n", count);
    else
        printf("Failed. The count  != expected is %d.\n", count);
}

//  test1
void test1()
{
    int data[] = { 7, 5, 6, 4, 3 };
    int expected = 9;

    Test("Test1", data, sizeof(data) / sizeof(int), expected);
}

//test2
void test2()
{
    int data[] = { 6, 5, 4, 3, 2, 1 };
    int expected = 15;

    Test("Test2", data, sizeof(data) / sizeof(int), expected);
}

//test3
void test3()
{
    int data[] = { 1, 2, 3, 4, 5, 6 };
    int expected = 0;

    Test("Test3", data, sizeof(data) / sizeof(int), expected);
}

// main()
int main()
{
    test1();
    test2();
    test3();
    return 0;
}
