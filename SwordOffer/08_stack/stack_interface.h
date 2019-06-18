/* stack.h
*   堆栈接口定义：在函数中以存根的形式存在，便于从一种形式转换为另外一种形式；
        - 静态数组：结构长度固定
        - 动态分配的数组结构：重新构建一个数组，复制原先数组到新数组，并删除原先数组
        - 动态分配的链式结构：每个元素单独分配内存空间
    编写Makefile 的时候，只需要加上对应的 .c 文件就行，接口文件不用变

*/

#ifndef STACK_INTERFACE_H
#define STACK_INTERFACE_H

#define STACK_TYPE int  /* 定义堆栈 元素类型 */

/* 静态数组创建 */
extern void push(STACK_TYPE value);
extern void pop(void);
extern STACK_TYPE top(void);

extern int is_empty(void);
extern int is_full(void);

/* malloc 数组创建 */
extern void create_stack(size_t size );
extern void destory_stack(void);

#endif
