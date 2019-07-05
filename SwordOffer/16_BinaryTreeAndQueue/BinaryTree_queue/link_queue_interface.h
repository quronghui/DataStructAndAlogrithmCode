/*
    1. 函数接口
        insert：向队尾 tail 插入元素；
        delete：从队头front 删除元素；
        first： 返回队列中的第一个元素，但不修改值
    
*/
#ifndef QUEUE_INTERFACE_H
#define QUEUE_INTERFACE_H

#include <stdio.h>
#include "tree_interface.h"

#define QUEUE_TYPE  BinaryTreeNode *     /* 定义队列元素的类型 */

// 链式队列的结构体函数
typedef struct queue_interface QueueNode;
struct queue_interface
{
    QUEUE_TYPE mValue;
    QueueNode *pNext;
    QueueNode *front;
    QueueNode *rear;
};


/*************enQueue deLQueue first*****************/
void enQueue( QueueNode *queue, QUEUE_TYPE value);
void delQueue(QueueNode *queue);
QUEUE_TYPE first(QueueNode *queue);

/*****************is_full is_empty*********************/
int is_empty(QueueNode *queue);
int is_full(QueueNode *queue);

/*****************动态分配创建队列，并进行初始化***********************/
QueueNode *create_queue();
void destory_queue(QueueNode *queue);


#endif