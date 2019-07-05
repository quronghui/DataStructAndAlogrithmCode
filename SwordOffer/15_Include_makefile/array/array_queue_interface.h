/*
*   1. 队列的接口实现：
        队列的实现：数组并不是很适合队列，队列在使用内存的时候
    2. 函数接口
        insert：向队尾 tail 插入元素；
        delete：从队头front 删除元素；
        first： 返回队列中的第一个元素，但不修改值
*/
#ifndef QUEUE_INTERFACE_H
#define QUEUE_INTERFACE_H

#include <stdio.h>
#define QUEUE_TYPE  int     /* 定义队列元素的类型 */
#define EmptyQueueArray (-1)    // 队列为空的判断

// 链式队列的结构体函数
typedef struct array_queue_interface QueueArrayNode;
struct array_queue_interface
{
    int Capacity;   // 队列的容量；
    int front;      // 指向队头的下标
    int rear;       // 指向队尾的下标；
    QUEUE_TYPE *array;  
};


/*************enQueue deLQueue first*****************/
extern void enQueue( QueueArrayNode *queue, QUEUE_TYPE value);
extern void delQueue(QueueArrayNode *queue);
extern QUEUE_TYPE first(QueueArrayNode *queue);

/*****************is_full is_empty*********************/
extern int is_empty(QueueArrayNode *queue);
extern int is_full(QueueArrayNode *queue);

/*****************动态分配创建队列，并进行初始化***********************/
extern QueueArrayNode *array_create_queue(int max_capacity);
extern void destory_queue(QueueArrayNode *queue);


#endif