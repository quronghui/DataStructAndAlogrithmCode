/* stack.h
*   1. 堆栈接口实现：在函数中以存根的形式存在，便于从一种形式转换为另外一种形式；
        - 静态数组：结构长度固定
        - 动态分配的数组结构：重新构建一个数组，复制原先数组到新数组，并删除原先数组
        - 动态分配的链式结构：每个元素单独分配内存空间
    2. 函数接口：
         push: 数组下标加1，存入元素
         pop: 数组下标减一；
         top：返回此时下标的数组元素

*/

#ifndef STACK_INTERFACE_H
#define STACK_INTERFACE_H


#include <stdio.h>

#define STACK_TYPE int  /* 定义堆栈 元素类型 */

// // 定义析构函数的结构体:可以定义多个变量进行访问
// typedef  struct stack_interface StackFuncation;
// struct stack_interface
// {
//     void (*push)(STACK_TYPE value); // 指针函数实现
//     void (*pop)(void);
//     STACK_TYPE (*top)(void);
// };

/* 链式栈结构体的创建 */
typedef strucStackNode;
struct link_stack
{
    STACK_TYPE mValue;
    StackNode *pNext;
};



/* 栈三个函数的接口函数的创建 */
extern void push(StackNode *stack, STACK_TYPE value);
extern void pop(StackNode *stack);
extern STACK_TYPE top(StackNode *stack);

/* 栈是否为空判断 */
extern int is_empty(StackNode *stack);
extern int is_full(StackNode *stack);

/* 链式栈的动态创建*/
extern StackNode *link_create_stack(void);

extern void destory_stack(StackNode *stack);

#endif
