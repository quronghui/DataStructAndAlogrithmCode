// 面试题40：最小的k个数
// 题目：输入n个整数，找出其中最小的k个数。例如输入4、5、1、6、2、7、3、8
// 这8个数字，则最小的4个数字是1、2、3、4。
/*
*   1. 解题思路：
        a. 对于一个数组中，求数的情况：如果数组排序就直接查找；
        b. 如果允许修改数组中的元素：通过数组的性质，利用快排的partition进行处理；
        c. 如果不允许修改数组中的元素：另外创建一个大小为k的空间，进行插入实现
    2. 思路一：通过partition
        a. 最小的k个数：这个数组应该在下标为k的左边
    3. 思路二：
        a. 引入数据结构：树进行数据的存储；
        b. 创建一个空间大小为k的数组，只保存k个数；下一个数比k个数中最大的元素小，就将其放入数组中；
*/
#include "quick_sort.h"
#include <stdio.h>
#include <stdlib.h>

/******************思路一：通过partition*******************/
void getKnumber_ByPartition(int *input, int length, int *output, int k)
{
    // 边界条件
    if(input == NULL || output==NULL || k>length || k<=0 || length<=0){
        printf("Invaild parameter.\n");
        return ;
    }

    // 构建快速排序；
    int start = 0;
    int end = length - 1;
    int index = partition(input, length, start, end);
    while (index != (k-1))    // 注意这里最小的k个数，下标从0-(k-1);
    {
        if(index > k-1){
            end = index - 1;
            index = partition(input, length, start, end);
        }
        if(index < k-1){
            start = index + 1;
            index = partition(input, length, start, end);
        }
    }
    // 得到前k个数，但是未排序
    for(int i=0; i<k; i++)
        output[i] = input[i];
}

/***********************Test code***************************/
void Test(char *name, int *input, int length, int *expected, int k)
{
    if(name != NULL)
        printf("%s begin: \n", name);
    // 打印期望数组
    printf("Expected result.\n");
    if(expected != NULL){
        for(int i=0; i<k; i++)
            printf("%d\t", expected[i]);
        printf("\n");
    }
    else 
         printf("The input is invalid, we don't expect any result.\n");

    // 调用方法二：
    printf("Result for solution.\n");
    int *output = malloc(sizeof(int) * k);
    getKnumber_ByPartition(input, length, output, k);
    if(expected != NULL){
        for(int i=0; i<k; i++)
            printf("%d\t", output[i]);
        printf("\n");
    }
    free(output);
    output = NULL;
}
// void test1
void test1()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected[] = {1, 2, 3, 4};
    Test("test1", data, sizeof(data)/sizeof(int), expected, sizeof(expected)/sizeof(int));
}
// main()
int main()
{
    test1();
    return 0;
}