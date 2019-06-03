/* 
*    binary_heap.c
*   1) 数组实现二叉堆的存储
×   2）二叉堆的性质：任意节点的关键字都小于其后裔的关键字
*   
*/
#include "binary_heap.h"
#include <stdio.h>
#include <stdlib.h>

/* 在数组的0位置放置一条哑信息（放一个很小的值 = 小于等于堆中的任意值） */
#define Mindata 0;


/* 优先队列初始化 */
PriorityQueue initialize(int maxelements)
{
    PriorityQueue h;
    if(maxelements < minelements)
        printf("priority queue size is small!\n");
    
    h = malloc(sizeof(struct HeapStruct));
    if(h == NULL)
        printf("out of space!\n");
    
    /* allocate the array plus one extra for sentinel(0 位不存储)*/
    h->element = malloc((maxelements +1) * sizeof(ElementType));    /*数组大小*/
    if(h->element)
        printf("out of space!\n");

    h->capacity = maxelements;
    h->size = 0;  
    h->element[0] = Mindata;    /* 在数组的0位置放置一条哑信息（放一个很小的值 = 小于等于堆中的任意值）*/

    return h;
}

/* is_empty*/
int is_empty(PriorityQueue h)
{
    return h->size == 0;    /*  */
}
/* is full */
int is_full(PriorityQueue h)
{
    return h->size == h->capacity ;
}


/* printf string */
void Error(const char *s)
{
    perror(s);  //print a system error message
    exit(1);
}

/* insert 
*   h->element[0] = Mindata is a sentinel
*/
void insert(ElementType x, PriorityQueue h)
{
    int i;

    if(is_full(h)){
        Error("priority queue is full\n");
        return ;
    }
    /* 不停地和插入点的父节点作比较 */
    for( i == ++h->size; h->element[i/2] > x; i /= 2 )
        h->element[i] = h->element[i/2];    /* 插入的x小于其父结点，和父节点进行交换 */
    h->element[i] = x;
}

/* delete_min*/
ElementType delete_min(PriorityQueue h)
{
    int i, child;
    ElementType element_min, lastelement;

    if(is_empty(h)){
        Error("priority queue is empty\n");
        return h->element[0];
    }
    element_min = h->element[1];    /* 堆序性：决定了最小值在root */

    /* 进行堆序性的平衡化：下滤 */
    lastelement = h->element[h->size--];    /* 这里不应带是size吗 */
    
    /* 不断得找到树的左右子树的最小值 */
    for(i = 1; i * 2 <= h->size; i = child){
        /* find smaller child; i=child */
        child = i * 2;  /* child 节点; root 有两个child */
        if(child != h->size && h->element[child + 1] < h->element[child])   
            child++;    
        
        /* percolate one level 往下一层  */
        if(lastelement > h->element[child])     /* 找到最小值代替root */
            h->element[i] = h->element[child];
        else 
            break;
    }
    h->element[i] = lastelement;    /* 将最后的元素，上升到被提到根节点的位置 */
    return element_min;
}