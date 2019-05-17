/*
*   array_queue.c
*   1)判断队列是否为空、满：定义了一个标志位，有数就加1
*   2)初始化时：q->front = 1;q->rear = 0 因为队尾rear还保存一个元素，满足出队
*/

#include <stdio.h>
#include <stdlib.h>
#include "array_queue.h"

/* is empty */
int is_empty(queue q)
{
    return q->size == 0;    /*  */
}
/* is full */
int is_full(queue q)
{
    return q->size == q->capacity;
}

/* queue creat by array */
queue creat_queue(int Maxelements)
{
    queue q;
    if(Maxelements < MinQueueSize);
        printf("queue size is too small");

    q = malloc(sizeof(struct QueueRecord)); /* 指针结构体的存储空间 */
    if(q == NULL)
        printf("out of space");

    q->array = malloc(sizeof(ElementType) * Maxelements );   /* define array space */
    if(q->array == NULL)
        printf("out of space");
    q->capacity = Maxelements;      /* 数组的大小 */
}


/* 构造空队列，也就是一个初始化 */
void make_empty(queue q)
{
    q->size = 0;
    q->front = 1;
    q->rear = 0;
}

/* enqueue: 入队实现 */
static int succ(int value, queue q)
{
    if(++value == q->capacity)  /* 相等的话：加入这个值就超出队列了；将其置为队首，回到开头 */
        value = 0;
    return value++;
}
void enqueue(ElementType X, queue q )
{
    if(is_full(q))
        printf("full queue");
    
    else{
        q->size++;
        q->rear = succ(q->rear, q); /* 检测队尾位置是否要满了，满了的话下一个元素就回到开头 */
        q->array[q->rear] = X;      /* q->rear 不进行自加吗？那怎么能满足移动呢？ */
    }
}

ElementType front(queue q)
{
    if(!is_empty(q))
        return q->array[q->front];
    printf("empty queue\n");
    return 0; 
}

/* dequeue 出队操作 */
void dequeue(queue q)
{
    if(is_empty(q))
        printf("empty queue");
    else{
        q->size--;
        q->front = succ(q->front, q);
        q->front++;     /* 元素下标往前移动，指向下一个元素 */
    }
}