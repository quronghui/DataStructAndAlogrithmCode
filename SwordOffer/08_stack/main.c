// 测试栈的几种实现方式是否正确
/* 三种测试方式：由于函数存在交叉，不能一起编译 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// #include "array_stack_interface.h"
#include "link_stack_interface.h"

/************- 静态数组：结构长度固定 *******************/
/*****************static_array_stack.c***************/
// void test_static_array_stack()
// {
//     puts("test_static_array_stack: ");
//     /**********入栈*************/
//     for (int i = 10; i < 14; i++)
//     {
//         push(i);
//     }

//     /***********return and delete***************/
//     while( !is_empty() ){
//         printf("%d ", top());
//         pop();
//     }
//     putchar('\n');
// }

/***************动态分配的数组结构********************/
/*************malloc_array_stack.c***************/
// void test_malloc_array_stack()
// {
//     puts("test_malloc_array_stack: ");

//     StackArrayNode *stack = array_create_stack(10);    /* 创建一个大小为N=4 的动态栈数组 */
    
//     /**********入栈*************/
//     for (int i = 15; i < 19; i++)
//     {
//         push(stack, i);
//     }

//     /***********return and delete***************/
//     while( !is_empty(stack) ){
//         printf("%d ", top(stack));
//         pop(stack);
//     }
//     putchar('\n');

//     destory_stack(stack);    /* 释放动态空间 */

// }


/**************传递两个参数的：动态分配的链式结构********************/
/*******************link_ParamterStack.c******************/
void test_link_stack()
{
    puts("test_link_stack: ");

    // 定义一个栈顶；
    StackNode *stack = link_create_stack();

    /**************进行入栈*************/ 
    for (STACK_TYPE i = 25; i < 27; i++)
    {
        push(stack, i);
    }
    /***********return and delete***************/
    StackNode *copy = link_create_stack();
    StackNode *recode = stack;
    // 复制栈进行入栈
    while ( !is_empty(stack) ){
        printf("%d ", top(stack));
        push(copy, top(stack));
        // pop(stack);
        stack = stack->pNext;
    }
    putchar('\n'); 
    // 复制栈进行出栈，从而实现队列的功能；
    while ( !is_empty(copy) ){
        printf("%d ", top(copy));
        pop(copy);
    }
    // 恢复初始栈的栈顶；
    stack = recode;    
    putchar('\n'); 
    printf("%d ", top(stack));
    
    destory_stack(copy);
}

// 测试栈构造的析构函数
// void test_stack_funcation()
// {
//     puts("test_stack_funcation: ");

//     /***定义析构函数的结构体,初始化****/
//     StackFuncation *Stack = malloc(sizeof(StackFuncation));
//     Stack->push = push;
//     Stack->pop = pop;
//     Stack->top = top;

//     /*入栈*/
//     for (int i = 20; i < 24; i++)
//     {
//         Stack->push(i);
//     }
//      /***********return and delete***************/
//     while( !is_empty() ){
//         printf("%d ", Stack->top());
//         Stack->pop();
//     }
//     putchar('\n'); 

//     destory_stack();
// }


/********************int main*******************/
int main()
{
    // test_static_array_stack();

    // test_malloc_array_stack();

    test_link_stack();

    // test_stack_funcation();



    return 0;
}