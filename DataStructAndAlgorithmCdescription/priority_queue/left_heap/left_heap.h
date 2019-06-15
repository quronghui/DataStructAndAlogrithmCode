/* 
*   left_heap.h
*   1) 和二叉堆的区别：增加指针
*/
#ifndef LEFT_HEAP_H
#define LEFT_HEAP_H

struct TreeNode;
typedef int ElementType;
typedef struct TreeNode *PriorityQueue;

/* leftist heap after a merge;must make sure to not use the old leftist heaps */
PriorityQueue initialize(void);
void destory(PriorityQueue h);
void make_empty(PriorityQueue h);

ElementType find_min(PriorityQueue h);
PriorityQueue merge(PriorityQueue h1, PriorityQueue h2);

int is_empty(PriorityQueue h);  /* 空和满， 指的是元素的个数；不是分配的空间 */
int is_full(PriorityQueue h);   

/* 左式堆和二叉堆的insert不兼容的：指针有返回值，这个操作可以使得其兼容 */
#define insert(x, h) (h = insert1((x), h))
#define delete_min(h) (h = delete_min1(h))

PriorityQueue insert1(ElementType x, PriorityQueue h);
PriorityQueue delete_min1(PriorityQueue h);


#endif

/* 定义数组的最小值 */
#define minelements 5

/* binary heap struct */
struct TreeNode
{
    PriorityQueue left;
    PriorityQueue right;
    int Npl;    /* 零路径长度 */
    ElementType *element;   /* 定义数组 */
};
