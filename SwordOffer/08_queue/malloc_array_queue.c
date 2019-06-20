// 题目：通过动态数组实现循环队列

/*
*   1.动态数组实现循环队列：和静态差不多，多了一个创建和删除
*/

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <malloc.h>
#include "queue_interface.h"

static QUEUE_TYPE *queue;   /* 动态数组队列的定义 */
static size_t queue_size;
static size_t ARRAY_SIZE;
static size_t front = 1;
static size_t rear = 0;

/*********************malloc creat queue****************/
void create_queue(size_t size)
{
    assert(queue_size == 0);

    queue_size = size;          /* 循环队列要空着一个位置，用于判断 */
    ARRAY_SIZE = queue_size + 1;

    queue = malloc(sizeof(QUEUE_TYPE) * ARRAY_SIZE );
    assert( queue != NULL );
}

void destory_queue(void)
{
    assert(queue_size > 0);     /* 队列中有元素 */
    queue_size = 0;
    free(queue);
    queue = NULL;
}

/**********************insert delete first********************/
void insert(QUEUE_TYPE value)
{
    assert( !is_full() );
    rear = (rear + 1) % ARRAY_SIZE;     /* 插入一个元素时，rear and front 指向头一个元素 */
    queue[rear] = value;
}

void delete_m(void)
{
    assert( !is_empty() );
    front = ( front + 1 ) % ARRAY_SIZE; /* 删除一个元素时，队头元素向前移动一位 */
}

QUEUE_TYPE first(void)
{
    assert( !is_empty() );
    return queue[front];
}

/**********************is_empty and is_full*************/
int is_empty(void)
{   
    assert(queue_size > 0);
    return (rear + 1) % ARRAY_SIZE == front;    /* front = 1 and rear = 1 */
}
 
int is_full(void)
{
    assert(queue_size > 0);
    return (rear + 2) % ARRAY_SIZE == front;    /* fornt = 1 and rear = 4*/
}