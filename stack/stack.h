/* stack.h
*   1) 栈：通过指针实现
*/

#ifndef STACK_H
#define STACK_H

struct Node;
typedef char ElemenType;
typedef struct Node *PtrToNode;
typedef PtrToNode stack;

int is_empty(stack s);      /* int 型：判断0/1 */
stack create_stack(void);   /* 如何去创建一个新的栈 */
void dispose_stack(stack s);
void make_empty(stack s);
void push(ElemenType x, stack s);
ElemenType top(stack s);
void pop(stack s);

#endif

struct Node
{
    ElemenType Element;
    PtrToNode Next;
};