// 通过静态数组实现循环队列

/*
* 1. 队列的接口：
    insert()：队列的插入函数，相当于入队；
    delete_m(): 删除元素，想当于出队；
    first():    返回队列的第一个元素

1.静态数组实现循环队列麻烦之处：
        a. 判断何时达到队列循环的条件：(rear = (rear+1) % QUEUE_SIZE)
        b. 判断何时为空，何时为满
            数组中有一个位置空着不用；
            (rear+1) % QUEUE_SIZE == front      队列为空
            (rear+2) %  QUEUE_SIZE == front     队列为满
        c. a % b :  if(a<b),那么输出的直接是元素a
*/
#include <stdio.h>
#include <assert.h>

#define QUEUE_TYPE int

#define QUEUE_SIZE  4                  /* 队列中元素最大值 */
#define ARRAY_SIZE  (QUEUE_SIZE + 1)    /* 数组实现的时候，需要多一个空位置 */

static QUEUE_TYPE queue[ARRAY_SIZE];    /* 队列定义 */
static size_t front = 1;                /* 队头位置 */
static size_t rear = 0;                 /* 对尾位置 */

/**************************funcation****************************/
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
    return (rear + 1) % ARRAY_SIZE == front;    /* front = 1 and rear = 1 */
}
 
int is_full(void)
{
    return (rear + 2) % ARRAY_SIZE == front;    /* fornt = 1 and rear = 4*/
}