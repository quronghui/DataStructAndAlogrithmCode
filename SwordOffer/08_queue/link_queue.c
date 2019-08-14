// 题目：通过链表实现队列；
// 在创建链式队列时，强烈建议初学者创建一个带有头节点的链表，这样实现链式队列会更简单。

/*
*   1. 动态链表的实现：
        .动态链表，不存在满的情况
    2. 遇到的情况：
        a. struct 结构体的定义和初始化？
        b. queue 何时为空的判断？
        c. delete 删除节点的方式
    3. 问题：只允许一次性入队，入队和出队交叉就会出现错?
        问题解决:  需要保证队列为空的时候，rear and front 都指向头结点
        if(queue->rear == first_node)
            queue->rear = queue->front;
*/

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <malloc.h>
#include "link_queue_interface.h"

#define FALSE 0

/* ***********链式队列的创建和初始化******************8*/
QueueNode *create_queue()
{   
    QueueNode *queue = malloc(sizeof(QueueNode));
    assert(queue != NULL);
    queue->pNext = NULL;    // 初始化队列的头结点

    queue->front = queue;   // 初始化 front and rear 指向头结点
    queue->rear = queue;

    queue->rear->pNext = NULL;
    return queue;
}
// 链式队列的释放 
void destory_queue(QueueNode *queue)
{
    while ( !is_empty(queue) ){
        delQueue(queue);
    }
}

/*******************is_empty is_full******************/
int is_empty(QueueNode *queue)
{
    return queue->front->pNext == NULL; // 头结点的下一个指针才有数据
}

int is_full(QueueNode *queue)
{
    return FALSE;
}


/**************insert delete_m first*****************/
void enQueue(QueueNode *queue, QUEUE_TYPE value)
{   
    // 新节点创建
    QueueNode *new_node;
    new_node = malloc(sizeof (QueueNode));
    assert( new_node != NULL ); 
    new_node->mValue = value;
    new_node->pNext = NULL;
    
    // 创建连接,rear动态链表，不存在满的情况
    queue->rear->pNext = new_node;
    queue->rear = new_node;         /* 插入一个节点后，指向最后一个节点 */

}

void delQueue(QueueNode *queue)
{
    QueueNode *first_node;

    if(!is_empty(queue)){
        first_node = queue->front->pNext;
        queue->front->pNext = first_node->pNext;   /* 问题出在：queue->front 此时指向的是头结点,不是数据 */
    }
    // 这里又是容易错误的地方; 需要保证队列为空的时候，rear and front 都指向头结点
    if(queue->rear == first_node)
        queue->rear = queue->front;
    free(first_node);

}

QUEUE_TYPE first(QueueNode *queue)
{
    if(!is_empty(queue))
        return queue->front->pNext->mValue;     /* queue->front 在插入元素的时候没有进行初始化 */
    else 
        return FALSE;
}



