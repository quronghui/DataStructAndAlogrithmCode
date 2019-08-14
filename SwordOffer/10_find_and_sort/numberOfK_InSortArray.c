// 面试题53（一）：数字在排序数组中出现的次数
// 题目：统计一个数字在排序数组中出现的次数。
// 例如输入排序数组{1, 2, 3, 3, 3, 3, 4, 5}和数字3，由于3在这个数组中出现了4次，因此输出4
/* 
*   1. 解题思路:
        a. 使用二分法查找, 递归查找到K在数组中的第一个和最后一个数的位置;
        b. 查找得到第一个K: 拿数组中间的数字和K作比较; ( 三种情况 )
        c. 查找得到最后一个K: 如何确定这个k就是最后一个? 
        d. K的个数就可以通过last - first + 1
    2. 注意:
        二分查找的使用: 数组的值和下标是具有一定关系的;
        需要使用递归: 数组的值和下标不是唯一的时候;
  */
#include <stdio.h>

// 函数声明
int getFirstK( int *array, int length, int k, int start , int end );
int getLastK( int *array, int length, int k, int start , int end );

/**********************用户接口函数***********************/
int getNumberOfK( int *array, int length , int k )
{
    int number = 0;
    if( array != NULL || length > 0 ){
        int first = getFirstK(array, length, k, 0, length-1);      
        int last   =  getLastK(array, length, k, 0, length-1);      

        if( first > -1 && last > -1 )       // 两个函数出现错误时, 返回-1;
            number = last - first + 1;
    }
    return number;
}

// 查找得到第一个K
int getFirstK( int *array, int length, int k, int start , int end )
{
    if( start > end )
        return -1;
    // 取中间数组的位置
    int middleIndex = (start + end) / 2;
    int middleData  =   array[middleIndex];
   
    // 存在三种大小的情况
    // 如何确定这个k就是第一个? 
    if( middleData == k ){
        // 查看一下前面一个位置的数   != k
        if( middleIndex > 0 && array[middleIndex - 1] != k || middleIndex==0 )
                return middleIndex;
        else 
            end = middleIndex - 1;      // 继续查找前面的字段
    }
    else if( middleData > k )
        end = middleIndex - 1;      // 继续查找前面的字段
    else 
        start = middleIndex + 1;

    // 上面的三种情况, 需要递归调用
    return getFirstK(array, length, k, start, end);        
}

//查找得到最后一个K
int getLastK( int *array, int length, int k, int start , int end )
{
    if( start > end )
        return -1;
     // 取中间数组的位置
    int middleIndex = (start + end) / 2;
    int middleData  =   array[middleIndex];

    // 存在三种大小的情况
    // 如何确定这个k就是最后一个? 
    if( middleData == k ){
        // 查看后面一个位置的值 != k
        if( middleIndex < length-1 && middleData !=k || middleIndex == length-1 )
            return middleIndex;
        else if(middleData > k )
            end = middleIndex - 1;
        else 
            start = middleIndex + 1;
    }

    return getFirstK(array, length, k, start, end);        
}

/*************Test code*********************/
void Test( char *name, int array[], int length, int k, int expected)
{
    if(name != NULL)
        printf (" %s begin:      ", name);
    
    int result  = getNumberOfK(array, length, k);
    if( result == expected )
        printf( " passed. The result == expected  is %d . \n " , result);
    else
        printf( " failed. The result != expected  is %d . \n " , result);

}

// // 查找的数字出现在数组的中间
void Test1()
{
    int data[] = {1, 2, 3, 3, 3, 3, 4, 5};
    Test("Test1", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数组出现在数组的开头
void Test2()
{
    int data[] = {3, 3, 3, 3, 4, 5};
    Test("Test2", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数组出现在数组的结尾
void Test3()
{
    int data[] = {1, 2, 3, 3, 3, 3};
    Test("Test3", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数字不存在
void Test4()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test4", data, sizeof(data) / sizeof(int), 2, 0);
}

// main
int main()
{
     Test1();
    Test2();
    Test3();
    Test4();
    return 0;
}