// 测试栈的几种实现方式是否正确
/* 三种测试方式：由于函数存在交叉，不能一起编译 */

#include "stack_interface.h"
#include <stdio.h>
#include <assert.h>

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

//     create_stack(4);    /* 创建一个大小为N=4 的动态数组 */
    
//     /**********入栈*************/
//     for (int i = 15; i < 19; i++)
//     {
//         push(i);
//     }

//     /***********return and delete***************/
//     while( !is_empty() ){
//         printf("%d ", top());
//         pop();
//     }
//     putchar('\n');

//     destory_stack();    /* 释放动态空间 */

// }

/**************动态分配的链式结构********************/
/*******************link_stack.c******************/
void test_link_stack()
{
    puts("test_link_stack: ");

    /**********入栈*************/
    for (int i = 20; i < 24; i++)
    {
        push(i);
    }
    /***********return and delete***************/
    while( !is_empty() ){
        printf("%d ", top());
        pop();
    }
    putchar('\n'); 

    destory_stack();
}

/********************int main*******************/
int main()
{
    // test_static_array_stack();

    // test_malloc_array_stack();

    test_link_stack();

    return 0;
}