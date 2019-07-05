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
#define EmptyStackArray (-1)    // 数组栈为空的判断


/* 动态数组栈结构体的创建 */
// 通过下标的方式进行访问，只不过多了一个指针；指向数组结构体
typedef struct array_malloc_stack StackArrayNode;
struct array_malloc_stack
{
    int Capacity;       // 栈数组的容量
    int TopOfStack;     // 栈数组的下标
    STACK_TYPE *array;
};


/* 栈三个函数的接口函数的创建 */
extern void push(StackArrayNode *stack, STACK_TYPE value);
extern void pop(StackArrayNode *stack);
extern STACK_TYPE top(StackArrayNode *stack);

/* 栈是否为空判断 */
extern int is_empty(StackArrayNode *stack);
extern int is_full(StackArrayNode *stack);

/* 动态数组的创建 和销毁*/
extern StackArrayNode *array_create_stack(int max_capacity);

extern void destory_stack(StackArrayNode *stack);

#endif
