// 题目一：动态链表实现堆栈,传递两个参数（stack and value）;
/*
    1. 解题思路：
        a. Create stack: 通过Create 创建函数后，就不需要在测试函数进行创建了，只需要接受返回值就行；
        b. push(stack, value): 这样才符合插入的逻辑，给定插入的对象和插入的值；不然只给一个值，很容易造成误解；
        c. 函数设计，我就只给一个接口，外部看不到设计，保留头指针与否，取决于自己设计的习惯；
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include "link_stack_interface.h"

#define FALSE 0

/*************Create ， MakeEmpty and Destoryfuncation******************/
void MakeEmpty(StackNode *stack)
{
    if( stack == NULL)
      printf("Must createStack first.\n");
    else{
        while(!is_empty(stack))
            pop(stack);
    }  
}

// Craete_stack 
StackNode *link_create_stack(void)  
{
    StackNode *stack = malloc(sizeof(StackNode));
    if(stack == NULL){
        printf("Out of space!\n");
        return NULL;
    }
    stack->pNext = NULL;    // 不是栈本身为空，是下一个节点为空

    return stack;
}

// Destory_stack
void destory_stack(StackNode *stack)
{
    while( !is_empty(stack) )
        pop(stack);
}

/****************push pop top*****************/
void push(StackNode *stack, STACK_TYPE value)
{
    StackNode *newNode;
    newNode = malloc(sizeof( StackNode ));
    assert( newNode != NULL );
    newNode->mValue = value;

    newNode->pNext = stack->pNext;
    stack->pNext = newNode;         // 保留栈顶指针，链表是没有头指针  
}

void pop(StackNode *stack)
{
    StackNode *first_node;

    assert( !is_empty(stack));
    first_node = stack->pNext;
    stack->pNext = first_node->pNext;   // 考虑头指针为空，不能修改头指针的位置；
    
    free(first_node);
}

// 这个函数，我就只给一个接口，外部看不到设计，保留头指针与否，取决于自己
STACK_TYPE top(StackNode *stack)
{
    assert( !is_empty(stack) );
    return stack->pNext->mValue;
}


/****************is_empty and is_full**********************/
int is_empty(StackNode *stack)
{
    return stack->pNext == NULL;    // 考虑的是下一个节点
}

int is_full(StackNode *stack)
{
    return FALSE;
}