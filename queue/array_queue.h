/*
*   array_queue.h
*   1) 数组的方式实现队列
*/

#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

struct QueueRecord;
typedef char ElementType;
typedef struct QueueRecord *queue;

int is_empty(queue q);
int is_full(queue q);        /* 数组：考虑满的状况 */
queue creat_stack(int maxelements);
void dispose_stack(queue q);
void make_empty(queue q);
void enqueue(ElementType X, queue q);
ElementType front(queue q);     /* 相对于一个栈顶，对队首元素进行出队 */
void dequque(queue q);
ElementType front_and_queue(queue q);

#endif

#define MinQueueSize (5)

struct QueueRecord
{
    int capacity;
    int front;
    int rear;
    int size;
    ElementType *array;
};