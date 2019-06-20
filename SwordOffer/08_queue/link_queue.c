// 题目：通过动态链表实现

/*
*   1. 动态链表的实现：
        a.不需要创建数组，只需要创建一个结构体
        b.动态链表，不存在满的情况
    2. 遇到的情况：
        a. struct 结构体的定义和初始化？
        b. queue 何时为空的判断？
        c. delete 删除节点的方式
    3. Paraemter
        *front: 指向队列的头部； 代表的就是队列
        *rear:  指向最后一个元素； 
        *pNext: 用于指向下一个元素
*/

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <malloc.h>
#include "queue_interface.h"

#define FALSE 0

typedef struct link_queue QueueNode;
struct link_queue
{
    QUEUE_TYPE mValue;
    QueueNode *pNext;
    QueueNode *rear;
    QueueNode *front;
};

/* 定义链式队列 */
static QueueNode *queue;

void initQueue()
{   
    queue = malloc(sizeof(QueueNode));
    queue->pNext = NULL;
    queue->front = queue;
    queue->rear = queue;
}

/******************destory queue******************/
void create_queue(size_t size)
{
    // 链式队列，不用创建其长度大小
}

void destory_queue(void)
{
    while ( !is_empty() ){
        delete_m();
    }
}

/**************insert delete_m first*****************/
void insert(QUEUE_TYPE value)
{
    QueueNode *new_node;
    new_node = malloc(sizeof (QueueNode));
    assert( new_node != NULL ); 
    new_node->mValue = value;
    new_node->pNext = NULL;
  
    // 创建连接,rear动态链表，不存在满的情况
    queue->rear->pNext = new_node;
    queue->rear = new_node;         /* 插入一个节点后，指向最后一个节点 */

}

void delete_m(void)
{
    QueueNode *first_node;

    assert( !is_empty() );
    first_node = queue->front;
    queue->front = first_node->pNext;   /* 问题出在：queue->front 此时指向的是头结点 */

    free(first_node);
}

QUEUE_TYPE first(void)
{
    assert( !is_empty() );
    return queue->front->pNext->mValue;     /* queue->front 在插入元素的时候没有进行初始化 */
}

/*******************is_empty is_full******************/
int is_empty()
{
    return queue->front->pNext == NULL;
}

int is_full()
{
    return FALSE;
}

