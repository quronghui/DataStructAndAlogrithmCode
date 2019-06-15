/*
*   left_heap.c
*   1) 通过指针实现堆树的合并
*/
#include "left_heap.h"
#include <stdio.h>
#include <stdlib.h>

/* is_empty*/
int is_empty(PriorityQueue h)
{
}
/* is full */
int is_full(PriorityQueue h)
{
}


/* printf string */
void Error(const char *s)
{
    perror(s);  //print a system error message
    exit(1);
}


/* merge programe */
PriorityQueue merge(PriorityQueue h1, PriorityQueue h2)
{
    if(h1 == NULL)  return h2;
    if(h2 == NULL)  return h1;
    if(h1->element < h2->element)
        return merge1(h1, h2);  /* h1插入h2的right，然后调到左边 */
    else
        return merge1(h2, h1);
}
/* swapchildren 将h1的左孩子和右孩子交换*/
static PriorityQueue swapchildren(PriorityQueue h)
{
    PriorityQueue tmpcell;
    
    tmpcell = malloc(sizeof(PriorityQueue));
    if(tmpcell == NULL)
        printf("out of space");
    tmpcell = h->left;
    h->left = h->right;
    h->right = tmpcell;
}

/* merge1 
1)找到h2 应该插入的位置;
2)swapchildren 插入成功后，将h1的左孩子和右孩子交换
*/
static PriorityQueue merge1(PriorityQueue h1, PriorityQueue h2)
{
    if(h1->left == NULL)    /* single node */
        h1->left = h2;  /*h1->right is already null; h1->np1 is alreay 0*/
    else{
        h1->right = merge(h1->right, h2);
        if(h1->left->Npl < h1->right->Npl)
            swapchildren(h1);       /* 插入成功后，将右边调到左边 */
        h1->Npl = h1->right->Npl + 1;
    }
    return h1;
}

/* lest_heap insert1 */
PriorityQueue insert1(ElementType x, PriorityQueue h)
{
    PriorityQueue SingleNode;

    SingleNode = malloc(sizeof(struct TreeNode));
    if(SingleNode == NULL)
        printf("out of space");
    else{
        SingleNode->element = x;
        SingleNode->Npl = 0;
        SingleNode->left = SingleNode->right = NULL;
        h = merge(SingleNode, h);
    }
    return h;
}
/* deletemin return the new tree;
to get the minimum use findmin
this id for convenience
*/
PriorityQueue delete_min1(PriorityQueue h)
{
    PriorityQueue leftheap, rightheap;
    if(is_empty(h)){
        Error("priority queue is empty\n");
        return h;
    }
    leftheap = h->left;
    rightheap = h->right;
    free(h);
    return merge(leftheap, rightheap); 
}

