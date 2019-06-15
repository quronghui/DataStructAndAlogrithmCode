/*
*   array_stack.c
*   栈：通过数组实现
*       除了数据的操作是通过数组的形式：下标进行访问元素
*   1) 数组大小,通过变量传进去；和malloc 创建的内存单元
*   2) s->TopOfStack 表示的是下标，数组下标的错误应该是负数; 判断栈数组是空的还是满的；通过下标判断
*   3) s->array[ ++s->TopOfStack ] 通过数组的方式：进行出栈和进栈
*/
#include "array_stack.h"
#include <stdio.h>
#include <stdlib.h>

/* stack creat by array */
stack creat_stack(int Maxelements)
{
    stack s;
    if(Maxelements < MinStackSize)
        printf("stack size is too small");

    s = malloc(sizeof(struct stackrecord)); /* 定义头指针 */
    if(s == NULL)
        printf("out of space");
    
    s->array = malloc(sizeof(ElemenType) * Maxelements );   /* define array space */
    if(s->array == NULL)
        printf("out of space");
    s->Capacity = Maxelements;      /* 数组大小；和malloc 创建的数组大小不冲突吗？ */

    make_empty(s);        
}

/* is empty stack */
int is_empty(stack s)
{
    return s->TopOfStack == EmptyTos;   /* s->TopOfStack 表示的是下标，数组下标的错误应该是负数 */
}
/* is full stack */
int is_full(stack s)
{
    return s->TopOfStack == s->Capacity ;   /*  */
}

/* make_empty stack */
void make_empty(stack s)
{
    s->TopOfStack = EmptyTos;   /* 栈顶元素 */
}

/* push stack */
void push(ElemenType X, stack s)
{
    if(is_full(s))
        printf("full stack");
    else
        s->array[ ++s->TopOfStack ] = X;    /* 通过数组下标：进行进栈；下表从-1 到 0 */
}

/* return top stack; 函数类型为元素的类型，返回的值是stack保存的类型 */
ElemenType top(stack s)
{
    if(!is_empty(s))
        return s->array[s->TopOfStack];
    printf("empty stack\n");
    return 0;               
}

void pop(stack s)
{
    if(is_empty(s))
        printf("empty stack");
    else 
        s->TopOfStack--;/* 返回栈顶元素的时候，数组此时是最大的下标，如果为空的话就下标减一 */
}