// 题目：静态数组的方式实现堆栈

/*
*   1.解题思路：
        a. 静态数组实现：数组大小的限制； 宏定义实现
        b. push: 数组下标加1，存入元素
        c. pop: 数组下标减一；
        d. top：返回此时下标的数组元素
*/

#include <stdio.h>
#include <assert.h>     /* 断言函数，用于判断表达式正确与否 */
#include "stack_interface.h"

#define STACK_SIZE 4

/* 静态数组实现方式，堆栈已经定义了 */

static STACK_TYPE   stack[STACK_SIZE];  /* 定义一个堆栈数组 */
static int          top_element = -1;   /* 定义堆栈数组下标的起始值 */

void push(STACK_TYPE value)
{
    assert( !is_full() );   /* 为真，继续执行 */
    top_element += 1;
    stack[top_element] = value;
}

void pop(void)
{
    assert( !is_empty());
    top_element -= 1;
}

STACK_TYPE top(void)
{
    assert( !is_empty() );
    return stack[top_element];
}

int is_empty(void)
{
    return top_element == -1;   //这个 == 表示比较的意思；比较两个的值，返回值是0/1
}

int is_full(void)
{
    return top_element == STACK_SIZE - 1;
}

