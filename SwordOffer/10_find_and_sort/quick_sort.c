// 快速排序算法的实现
/*
*   1. 快速排序算法： 
        通过枢纽元将数组元素分为两部分；a [left] = { x < v }；a[center] = {v} ; a[right] = { x > v }；
        对每一部分再次执行快速排序，最后排序；
    2. 函数功能
        partition   根据枢纽元素：划分数组为两部分
        quick_sort  递归实现 快速排序，并且完成两部分的排序
*/

#include <stdio.h>
#include "quick_sort.h"
/******************swap交换函数*************************/
static void swap( int *one , int *two)
{
    int temp;       // 我交换的是地址中的元素
    temp = *one;
    *one = *two;
    *two = temp;
}

/***************根据枢纽元素：划分数组为两部分***************/
int partition(int *data, int length, int start, int end )
{
    if(data == NULL || length < 0 || start < 0 || end >= length){
        printf("Invaild parameters:\n");
        return 0;
    }
    
    int center = (start + end)/2;       // 中间枢纽元素
    swap( &data[center], &data[end] );  /* 将枢纽元放在最后一个位置 */

    // 排序所有的元素，除了最后位置的枢纽元素；
    int small = start - 1;  // 为了排序时避免涉及到枢纽元素
    for( center = start; center < end; ++center ){
        // 小于中间枢纽的元素进行交互
        if( data[center] < data[end] ){      //比较的还是枢纽元素
            ++ small;
            if( small != center )
                swap(&data[center], &data[small]);
        }
    }

    // 将枢纽元素放回中间位置
    ++ small;   //一开始是减1的
    swap(&data[small], &data[end]);

    return small;   // 返回枢纽元素的位置
}

/***************递归：实现左右两部分的快速排序******************/
void quick_sort( int *numbers, int length, int start, int end )
{
    //assert( start != end);    // 这个直接把代码停了
    if(start == end)
        return;  
    int index = partition( numbers, length, start, end);
    if(index > start)
        quick_sort( numbers, length, start, index-1 );
    if( index < end )
        quick_sort( numbers, length, index+1, end );    
}

/********************test code***********************/
// void test()
// {
//     int data[] = { 3, 10, 6, 8, 2, 5, 1, 7, 9, 4 };
//     int length = sizeof(data) / sizeof(int);
//     for(int i=0; i<length; i++)
//         printf(" %d ", data[i]);
//     printf("\n");

//     // 快速排序
//     quick_sort(data, length, 0, length-1);
//     for(int i=0; i<length; i++)
//         printf(" %d ", data[i]);
//     printf("\n");
// }   

// int main()
// {
//     test();
//     return 0;
// }