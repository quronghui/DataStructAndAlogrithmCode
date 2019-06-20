/*
*   1. 队列的接口实现：
        队列的实现：数组并不是很适合队列，队列在使用内存的时候
        
        - 静态数组：结构长度固定
        - 动态分配的数组结构：重新构建一个数组，复制原先数组到新数组，并删除原先数组
        - 动态分配的链式结构：每个元素单独分配内存空间
    2. 函数接口
        insert：向队尾 tail 插入元素；
        delete：从队头front 删除元素；
        first： 返回队列中的第一个元素，但不修改值
    
*/
#ifndef QUEUE_INTERFACE_H
#define QUEUE_INTERFACE_H

#include <stdio.h>

#define QUEUE_TYPE  int     /* 定义队列元素的类型 */

/*************insert delete first*****************/
void insert(QUEUE_TYPE value);
void delete_m(void);
QUEUE_TYPE first(void);

/*****************is_full is_empty*********************/
int is_empty(void);
int is_full(void);

/*****************动态分配时才用到的函数接口***********************/
void create_queue(size_t size);
void destory_queue(void);

/*******************链式队列的初始化****************************/
void initQueue();

#endif