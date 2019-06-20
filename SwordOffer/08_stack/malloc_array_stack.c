// 动态分配数组的堆栈实现

/*
*   1. 解题思路：
        a. 堆栈数组的创建，可以动态分配数组的大小；
        b. 动态分配的堆栈，需要进行销毁；
        c. 不同于static之处  is_empty and is_full 
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include "stack_interface.h"

/* 用于存储堆栈元素和指向栈顶部分的指针 */
static STACK_TYPE *stack;
static size_t stack_size;       /* 堆栈数组的动态分配大小 */
static int top_element = -1;    /* 数组的下标 */

void create_stack(size_t size )     /* 动态堆栈的创建 */
{
    assert( stack_size == 0 );    //未创建
    stack_size = size;
    stack = malloc(sizeof(STACK_TYPE) * stack_size);
    assert( stack != NULL );
}

void destory_stack(void)
{
    assert( stack_size > 0 );
    stack_size = 0;
    free(stack);
    stack = NULL;
}

/**************** push pop top *****************/
// 不同于static之处  is_empty and is_full 

void push(STACK_TYPE value)
{
    assert( !is_full() );
    top_element += 1;
    stack[top_element] = value;
}

void pop(void)
{
    assert( !is_empty() );
    top_element -= 1;
}

STACK_TYPE top(void)
{
    assert( !is_empty() );
    return stack[top_element];
}

/***************** is_empty and is_full ***************************/
int is_empty(void)
{
    assert( stack_size > 0 );
    return top_element == -1;
}

int is_full(void)
{
    assert( stack_size > 0 );
    return top_element == stack_size - 1;
}