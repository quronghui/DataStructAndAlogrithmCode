// 面试题3（二）：不修改数组找出重复的数字
// 题目：在一个长度为n+1的数组里的所有数字都在1到n的范围内，所以数组中至
// 少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的
// 数组。例如，如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6, 7}，那么对应的
// 输出是重复的数字2或者3。

/*
*   1.题目中的提示：n+1个数，数的范围1-n (和前面的题目类似)
*   2.题目中要求：不修改数组
*   3.方法：
        a. 允许使用额外空间：创建一个数组O(n)将原来数组中的元素m,复制到下标为m的位置
        b. 不允许额外空间：二分查找法(递归)，通过数字m将数组分成两部分，遍历得到(1-m)元素的个数，和(m - (length-1) )元素的个数；
            时间: O(nlogn), 空间O(1)
    
*/

#include <stdio.h>

/*
Input:
    numbers: 数组    const int number  保证不改变数组内元素
    length：长度
judge：
    二分查找法
Return:
    1   输入有效，并且数组中存在重复的数字，返回值为重复的数字
    -1  输入无效，或者数组中没有重复的数字
*/

int countRange(const int* numbers, int length, int start, int end);

int getDuplicate(const int *numbers, int length)
{
    /* 鲁棒性判断 */
    if(numbers==NULL || length <= 0) return -1;
    /* number中值判断 */
    for(int i=0; i < length; i++){  /* 数组的下标要从0开始的 */
        if(numbers[i] < 1 || numbers[i] > length-1)   /* 数字的范围 1-n ; n = length-1 */
            return -1;
    }

    /* 二分查找 ： 以中间元素为判断值 */
    int start = 1;      /* 开始和结束 */
    int end = length-1; 
    while(end >= start){
        int middle = ((end - start) >> 1) + start;  /* 中间数的计算 */
        int count = countRange(numbers, length, start, middle);
        if(end == start){
            if(count > 1){
                printf("dupllicate is %d \n", start);
                return start;   /* 返回重复的元素 */
            }  
            else    
                break;
        }
        if(count > (middle - start + 1))
            end = middle;
        else 
            start = middle + 1;
    }
    return -1;
}

/* 计算countrange */
/* 循环调用 logn 次，每次需要遍历O(n) 时间， 时间复杂度是O(nlogn), 空间复杂度是O(1) */
int countRange(const int* numbers, int length, int start, int end)
{
    if(numbers == NULL) return 0;

    int count = 0;
    for(int i =0; i < length; i++)
        if(numbers[i] >= start && numbers[i] <= end)
            ++count;
    return count;
}

/****************** test code ***************************/
void test(const char *name, int *numbers, int length, int *duplications, int duplength )
{
    int result = getDuplicate(numbers, length);

    /* 剩下的两个参数是做判断的 */
    for(int i=0; i<duplength; i++){
        if(result == duplications[i]){
            printf("test1 passed\n");
            return;
        }
    }
    printf("test1 failed\n");
}
/***********不同的测试情况**********/
void test1()
{
    int numbers[] = {2, 3, 5, 4, 3, 2, 6, 7 };
    int duplications[] = {2, 3};
    test("test1", numbers,  sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

void main()
{
    test1();
}