// 题目：通过动态数组实现循环队列
/*
*   1.注意问题：通过循环队列的方式实现接口；
        a. 为了判断队列是否为满，循环队列要空出一个位置不用，想当于头结点，空出下标为0的值;
        b. 为了满足条件，数组的大小要比队列的数量多1；
*/

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <malloc.h>
#include "array_queue_interface.h"

static int arrayQuCapacity;     // 动态数组的大小

/******************动态队列的创建,清空*********************/
void MakeEmpty(QueueArrayNode *queue)
{
    queue->front = 1;       // front 要比rear多1
    queue->rear  = 0;       // 下标为0 的位置空着不用
}
// 动态队列的创建
QueueArrayNode *array_create_queue(int max_capacity)
{
    // 边界值条件
    if(max_capacity < 1){
        printf("The max_capacity is small.\n");
    }
    arrayQuCapacity = max_capacity + 1; // 队列空出一个位置；
    // 创建动态队列,引入队列数组
    QueueArrayNode *queue = malloc(sizeof(QueueArrayNode));
    if(queue == NULL){
        printf("Out of space.\n");
        return NULL;
    }
    // 创建动态数组的空间；
    queue->array = malloc(sizeof(QUEUE_TYPE) * arrayQuCapacity);
    if(queue->array == NULL){
        printf("Out of space!\n");
        return NULL;
    }
    // 初始化队列空间的大小，队列数组，重要的是下标；
    queue->Capacity = arrayQuCapacity;

    MakeEmpty(queue);

    return queue;
}

/*****************动态队列的释放******************/
void destory_queue(QueueArrayNode *queue)
{
    // 不能用这个，这个是判断元素 assert( !is_empty(queue)); 
    if(queue != NULL){   // 判断一个头结点是否为空就行
        free(queue->array);
        free(queue);
        queue = NULL;
    }
}

/**********************is_empty and is_full*************/
int is_empty(QueueArrayNode *queue)
{   
    return (queue->rear + 1) % arrayQuCapacity == queue->front;    /* front = 1 and rear = 1 */
}
 
int is_full(QueueArrayNode *queue)
{
    return (queue->rear + 2) % arrayQuCapacity == queue->front;    /* fornt = 1 and rear = 4*/
}

/**********************insert delete first********************/
void enQueue( QueueArrayNode *queue, QUEUE_TYPE value)
{
    assert (!is_full(queue));
    queue->rear = (queue->rear + 1) % arrayQuCapacity;
    queue->array[queue->rear] = value;
}

void delQueue(QueueArrayNode *queue)
{
    assert( !is_empty(queue));
    queue->front = (queue->front + 1) % arrayQuCapacity;
}


extern QUEUE_TYPE first(QueueArrayNode *queue)
{
    assert( !is_empty(queue));
    return queue->array[queue->front];
}
