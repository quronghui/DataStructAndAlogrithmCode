// 面试题31：栈的压入、弹出序列
// 题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
// 假设压入栈的所有数字均不相等。例如序列1、2、3、4、5是某栈的压栈序列，序列4、5、3、2、1是该压栈序列对应的一个弹出序列，
// 但4、3、5、1、2就不可能是该压栈序列的弹出序列。
/*
*   1. 解题思路：
        a. 增加一个栈的空间花费，辅助栈；
        b. 输入参数：两个数组序列--pPush, pPop;
        c. 根据pPop中的每一个值，都应该在Stack的栈顶上； 
            入栈的条件：is_empty(stack) || stack->top != pPop[i];
            出栈的条件：stack->top = pPop[i];
            还有一个条件：两个序列的长度要一样
        d. 判断是否是序列：bool类型
*/
#include "link_stack_interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/****************判断函数实现：*******************/
// 循环的条件；入栈的条件；出栈的条件；弹出序列是否全部判断玩的条件
bool isPopOrder(const int *pPush, const int *pPop, int length)
{
    bool possible = false;  // 设置全局遍历处理返回结果；

    // 边界条件
    if(pPush == NULL && pPop == NULL && length > 0){
        puts("The array order is null or parameter invailed\n");
        return possible;
    }
    // 创建一个辅助栈空间
    StackNode *stack = link_create_stack();

    // 创建两个指针，指向不可改变的数组
    const int *pNextPush = pPush;   // 数组序列的首地址,判断是否全部判断玩
    const int *pNextPop  = pPop;    

    // 循环的条件：进行判断pPop序列中的每一个值
    while(pNextPop - pPop < length){    // 判断的值在数组范围以内
        // 入栈的条件：进行入栈操作
        while(is_empty(stack) || top(stack) != *pNextPop){
            // 判断入栈序列是否为全部进行入栈
            if(pNextPush - pPush == length)
                break;  
            push(stack, *pNextPush);
            pNextPush++;
        }
        // 出栈的条件：如果栈顶元素和pPop序列不一样，则跳出循环
        if(top(stack) != *pNextPop)
            break;
        // 否则进行出栈并进行判断
        pop(stack);
        pNextPop++;     // 进行下一个元素的判断
    }
    // 弹出序列是否全部判断玩的条件
    if( is_empty(stack) && pNextPop-pPop == length)
        possible = true;
    
    return possible;
}

/****************test code******************/
void Test(char *name, const int *pPush, const int *pPop, int length, int expected)
{
    if(name != NULL)
        printf("%s is begin: ", name);

    if(isPopOrder(pPush, pPop, length) == expected)
        printf("passed.\n");
    else 
        printf("failed.\n");
}
// 正常出栈的序列
void test1()
{
    const int length = 5;
    int push[] = {1, 2, 3, 4, 5};
    int pop[] = {4, 5, 3, 2, 1};
    
    Test("test1", push, pop, length, true);
}

// main 函数检测
int main()
{
    test1();
    return 0;
}