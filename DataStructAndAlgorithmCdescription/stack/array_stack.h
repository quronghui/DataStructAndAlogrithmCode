/*
*   array_stack.h
*   栈：通过数组实现
*   1) 数组定义：定义到结构体中，定义成指针数组；
*   2) 数组做右值的时候，自动转换成指针；数组取元素，其实也是地址取元素
*   3)int TopOfStack; //表示数组的下标地址；int型能够自加；类似于next 
*/

#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

struct stackrecord;
typedef char ElemenType;    /* 数组中的元素声明 */
typedef struct stackrecord *stack;

int is_empty(stack s);
int is_full(stack s);        /* 数组：考虑满的状况 */
stack creat_stack(int maxelements);
void dispose_stack(stack s);
void make_empty(stack s);
void push(ElemenType X, stack s);
ElemenType top(stack s);
void pop(stack s);
ElemenType top_and_pop(stack s);

#endif
/* stack array is alloc array */
#define EmptyTos (-1)           /* 数组下标出错的标志 */
#define MinStackSize (5)        /* 数组空间的大小 */

struct stackrecord
{
    int Capacity;       /* 数组空间的大小 */
    int TopOfStack;     /* 表示数组的下标地址；int型能够自加；类似于next */
    ElemenType *array;  /* 栈的数组定义和声明;类似于元素 */
};