// 面试题21：调整数组顺序使奇数位于偶数前面
// 题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有
// 奇数位于数组的前半部分，所有偶数位于数组的后半部分。

/*
*   1. 解题思路一：O(n^2)时间复杂度的移动；
    2. 解题思路二：
        数组的指针：指向的是下标位置，不像链表；
        a. 通过两个指针在，*head = &array[0]; *tail = &array[n-1];
        b. 通过比较他们的奇偶性，移动指针；
        c. 循环截止条件： (head+1) == tail || (tail-1) = head
    3. 解题思路三：
        a. 题目扩展的思路：本题的判断条件是奇偶性
        b. 如果判断正负数；或者是能否被三整除；
        c. 需要将功能函数封装，留下调用接口函数

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 解题思路二：单一的功能函数
void ReorderArrray_OddEven_1(int *Arrary, unsigned int length)
{
    // 基础条件
    if(Arrary == NULL || length == 0){
        puts("Array is null or length is invaild parameter.");
        return ;
    }
    int *head = Arrary;             // 数组的函数名，表示起始地址
    int *tail = Arrary + length -1;

    while( head < tail ){
        // 向后移动head,使得它指向偶数；
        while( head<tail && (*head & 0x1) != 0 )
            head++;
        // 向前移动tail, 使得它指向奇数
        while( head<tail && (*tail & 0x1) == 0)
            tail--;
        // 此时head 指向第一个偶数，tail 指向第一个奇数；交换
        if(head < tail){
            int temp = *head;
            *head = *tail;
            *tail = temp;
        }
    }
}

// 解题思路三：将功能函数 和判断函数抽象出来

bool isEven(int n);     // 判断函数

void Reorder(int *Arrary, unsigned int length, bool (*func)(int))
{
    // 基础条件
    if(Arrary == NULL || length == 0){
        puts("Array is null or length is invaild parameter.");
        return ;
    }
    int *head = Arrary;             // 数组的函数名，表示起始地址
    int *tail = Arrary + length -1;

    while( head < tail ){
        // 向后移动head,使得它指向
        while( head<tail && !func(*head) )
            head++;
        // 向前移动tail, 使得它指向
        while(head < tail && func(*tail))
            tail--;
        // 交换
        if(head < tail){
            int temp = *head;
            *head = *tail;
            *tail = temp;
        }
    }
}
/*********判断：功能函数**********/
bool isEven(int n)
{
    return (n & 0x1) == 0;
}
/**************用户接口函数*****************/
void ReorderArrray_OddEven_2(int *array, int length)
{
    Reorder(array, length, isEven);
}

/***********数组打印测试*********/
void PrintArray(int *array, int length)
{
    if(length < 0)
        return;
    for(int i=0; i<length; i++)
        printf("%d\t", array[i]);
    putchar('\n');
}

/*********************test code**********************/
void Test(char *name, int *array, int length)
{
    if(name != NULL)
        printf("%s begins:\n", name);

    // 将数组复制一份，对思路三进行测试
    int *copy = malloc(sizeof(int) * length);
    if(copy == NULL){
        printf("The memory is full.\n");
    }
    else {
        for(int i=0; i<length; i++)
            copy[i] = array[i];
    }

    // 测试思路二:
    printf("Test for second solution :\n");
    PrintArray(array, length);
    ReorderArrray_OddEven_1(array, length);
    PrintArray(array, length);
    //测试思路三:
    printf("Test for third solution :\n");
    PrintArray(copy, length);
    ReorderArrray_OddEven_2(copy, length);
    PrintArray(copy, length);

    free(copy);
    copy = NULL;
}

void test1()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7};
    Test("Test1", array, sizeof(array)/sizeof(int));
}

int main(void)
{
    test1();
    return 0;
}