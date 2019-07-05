// 动态分配数组的堆栈实现
/*
*   1. 解题思路：
        a. 还是创建一个指针，通过指针间接引用数组，数组的下标；
        b. 创建动态栈数组时：创建一个指针，创建一个数组；
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include "array_stack_interface.h"


/********************动态栈数组的创建，清空*************************/
void MakeEmpty(StackArrayNode *stack)
{
    stack->TopOfStack = EmptyStackArray;    // 将其下标置为-1
}

StackArrayNode *array_create_stack(int max_capacity)
{   
    // 边界条件
    if(max_capacity < 1){
        printf("The ArrayStack is small.\n");
        return NULL ;
    }
    // 创建一个栈，为了引用栈数组
    StackArrayNode *stack = malloc(sizeof(StackArrayNode));
    if(stack == NULL){
        printf("Out of space!\n");
        return NULL;
    }
    // 创建栈数组的空间大小；
    stack->array = malloc(sizeof(STACK_TYPE) * max_capacity);
    if(stack->array == NULL){
        printf("Out of space!\n");
        return NULL;
    }
    // 初始化栈数组的空间大小，栈数组其实就是数组，重要的就是下标；
    stack->Capacity = max_capacity;
    
    MakeEmpty(stack);

    return stack;
}

/*****************动态数组空间的释放******************/
void destory_stack(StackArrayNode *stack)
{
    if(stack != NULL){
        free(stack->array);
        free(stack);
    }
}

/**************** push pop top *****************/
// 不同于static之处  is_empty and is_full 
void push(StackArrayNode *stack, STACK_TYPE value)
{
    assert( !is_full(stack) );
    stack->array[++stack->TopOfStack] = value;  // 通过下标的方式进行访问，只不过多了一个指针；指向数组结构体
}

void pop(StackArrayNode *stack)
{
    assert( !is_empty(stack) );
    stack->TopOfStack --;       // 下标减一
}

STACK_TYPE top(StackArrayNode *stack)
{
    assert( !is_empty(stack) );
    return stack->array[stack->TopOfStack];
}


/***************** is_empty and is_full ***************************/
int is_empty(StackArrayNode *stack)
{
    return stack->TopOfStack == EmptyStackArray;    // EmptyStackArray = -1
}

int is_full(StackArrayNode *stack)
{
    return stack->TopOfStack == stack->Capacity - 1;
}