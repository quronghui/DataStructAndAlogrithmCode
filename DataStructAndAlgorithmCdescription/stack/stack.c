/* stack.c
*   1) 入栈和出栈：都是在栈顶进行操作的；
*   2）入栈：新元素加入，分配存储空间；
*   3）top 指向栈顶的，栈顶都是header 空指针，元素的操作都是检查第二个栈；
*   4) 站的空间地址：由高位指向低位的
*/
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

/* test stack is empty*/
int is_empty(stack s)
{
    return s->Next == NULL; //这个 == 表示比较的意思；比较两个的值，返回值是0/1
} 

/* creat empty stack */

void make_empty(stack s)
{
    if(s == NULL)
        printf("must create_stack first");
    else
        while(!is_empty(s))
            pop(s);
}

stack create_stack(void)
{
    stack s;

    s = malloc(sizeof(struct Node));
    if( s == NULL )                     /* 动态存储空间的判断 */
        printf("out of space\n");   
    s->Next == NULL;
    make_empty(s);
    return s;
}

/* push 入栈 */
void push(ElemenType X, stack s)
{
    PtrToNode tmpcell;
    tmpcell = malloc(sizeof(struct Node));  /* 每push一个元素，调用一次malloc */
    if(tmpcell == NULL)
        printf("out of space");
    else
    {
        tmpcell->Element = X;
        tmpcell->Next = s->Next;
        s->Next = tmpcell;
    }
}

/* return top element */
ElemenType top(stack s)
{
    if(!is_empty(s))
        return s->Next->Element;
    else {
        printf("empty stack");
        return 0;
    }
}

/* pop: 没有对弹出元素进行处理 */
void pop(stack s)
{
    PtrToNode firstcell;

    if(is_empty(s))
        printf("empty stack\n");        
    else
    {
        firstcell = s->Next;
        s->Next = s->Next->Next;
        free(firstcell);
    }
}