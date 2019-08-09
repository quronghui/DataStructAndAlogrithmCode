// 题目: 实现查找的API
/*
*   1. 二分查找的实现:
        a. 每次都进行折半
        b. 注意: 对于树的结构, 下标为0的位置是不保存数据的;
*/

#include  <stdio.h>

/*************二分查找的实现**************/
int BinarySearch(int    *array, int length,  int key)
{
    int low =   0;
    int high    =   length-1;
    while(low   <   high){
        int mid =   (high   + low)  /   2;
        if(key < array[mid])
            high    =   mid -   1;
        else if(key >   array[mid])
            low =   mid +   1;
        else 
            return  mid;
    }
    return  0;
}