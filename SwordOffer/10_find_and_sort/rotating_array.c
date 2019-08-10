// 面试题11：旋转数组的最小数字
// 题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
// {3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。

/*
*   1. 题目提示：
        a. 数组是一个排序数组，通过最小值元素将数组分为两部分，两部分都是排序的数组；
        b. 因此题目可以通过快速排序的方式解题
    2. 解题思路一：数组是递增的：无重复数字
        a. 两个指向位置的参数：p1 - 指向开头, p2 - 指向末尾
        b. 取中间枢纽元素：判断center是在前部分还是后半部分；移动p1/p2到center位置；
        c. 不停缩短空间，当p1和p2相邻时，p2- 指向的是最小的值，p1指向的是最大的值 --结束条件
    3. 解题思路二：数组是递增的：不存在重复数字
            只能顺序进行查找
    3. rotating_array_min : 递增排序数组：无重复数字
        *number 形参等待数组传值；
        length  数组长度
*/

#include <stdio.h>

// 函数声明
int MinInOrder(int *number, int index_one, int index_two);

/******************数组是递增的************************/
// 递增排序数组：无重复数字
int rotating_array_min( int *number, int length )
{
    if( number == NULL || length <= 0){
        printf("Invaild parameters:\n");
        return 0;
    }

    int index_one = 0;          //两个指向位置
    int index_two = length - 1;
    int indexMin = index_one;

    while( number[index_one] >= number[index_two] ){  //递增数组：第一个元素是大于最后一个元素的 
        //结束条件
        if( index_two - index_one == 1 ){    
            indexMin = index_two;
            break;  
        }
        // 不停取中间位置
        // 每次都需要取区间的中间位置：indexMin = (length - 1) >> 1
        indexMin = (index_one + index_two) >> 1 ;   //右移一位，相当于除以2
        
        // 解题思路二：数组是递增的：存在重复数字； 只能顺序进行查找
        if(number[index_one] == number[index_two] && number[indexMin] == number[index_one]){
            return MinInOrder(number, index_one, index_two);
        }

        // 解题思路一：数组是递增的：无重复数字
        if( number[indexMin] >= number[index_one] ) //前面数组的元素是大于后面数组的
            index_one = indexMin;                   //缩小位置
        else if(number[indexMin] <= number[index_one])
            index_two = indexMin;
    }
    return number[indexMin];
}

/*****************顺序进行查找***********************/
// 解题思路二：数组是递增的：存在重复数字
int MinInOrder(int *number, int index_one, int index_two)
{
    int result = number[index_one];
    
    for(int i = index_one + 1; i<index_two; i++){
        if(result > number[i])
            result = number[i];
    }
    return result;
}

/*********************test code**************************/
void test(int *number, int length, int expected)
{
    int result = rotating_array_min(number, length);
    puts("Array value is :");
    for( int i=0; i< length; i++)
        printf(" %d ", number[i]);
    putchar('\n');

    if(result == expected)
        printf(" test passed.\n");
    else 
        printf(" test failed.\n");

}

int main()
{
    int array1[] = {3, 0, 1, 2, 2};
    test(array1, sizeof(array1)/sizeof(int) , 0);  //
    return 0;
}