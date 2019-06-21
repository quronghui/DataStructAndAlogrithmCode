// 动态链表实现堆栈

/*
    1. 解题思路：
        a. 动态链表实现堆栈，不需要动态创建一个size大小的数组；
        b. 每push 一个元素的时候，分配一个内存空间
    2. Parameter
        struct : 指向栈的结构体；
            value 
            pNext
        *stack : 指向栈的指针
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include "stack_interface.h"

#define FALSE 0

typedef struct link_stack StackNode;

/***********Parameter************/ 
struct link_stack
{
    STACK_TYPE mValue;
    StackNode *pNext;
};

static StackNode *stack;

/*************funcation******************/

/* 创建函数的存根功能函数，不使用可以空置 */ 
void create_stack(size_t size)  
{

}

void destory_stack(void)
{
    while( !is_empty() )
        pop();
}

/****************push pop top*****************/
void push(STACK_TYPE value)
{
    StackNode *newNode;
    newNode = malloc(sizeof( StackNode ));
    assert( newNode != NULL );
    newNode->mValue = value;
    newNode->pNext = stack;
    stack = newNode;            /* 将最新节点放在栈顶上 */
}

void pop(void)
{
    StackNode *first_node;

    assert( !is_empty());
    first_node = stack;
    stack = first_node->pNext;
    free(first_node);
}

STACK_TYPE top(void)
{
    assert( !is_empty() );
    return stack->mValue;
}

/****************is_empty and is_full**********************/
int is_empty(void)
{
    return stack == NULL;
}

int is_full(void)
{
    return FALSE;
}