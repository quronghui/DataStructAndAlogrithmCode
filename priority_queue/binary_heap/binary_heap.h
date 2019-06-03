/* 
*   binary_heap.h
*/
#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

struct HeapStruct;
typedef int ElementType;
typedef struct HeapStruct *PriorityQueue;


PriorityQueue initialize(int maxelements);
void destory(PriorityQueue h);
void make_empty(PriorityQueue h);
void insert(ElementType x, PriorityQueue h);

ElementType delete_min(PriorityQueue h);
ElementType find_min(PriorityQueue h);

int is_empty(PriorityQueue h);  /* 空和满， 指的是元素的个数；不是分配的空间 */
int is_full(PriorityQueue h);   

#endif

/* 定义数组的最小值 */
#define minelements 5

/* binary heap struct */
struct HeapStruct
{
    int capacity;
    int size;
    ElementType *element;   /* 定义数组 */
};
