/*
*   unweight.h
*/

#ifndef UNWEIGHT_H
#define UNWEIGHT_H

typedef char ElementType;   //自己加上的，假定类型是char
struct Node;
typedef struct Node *UnweightNode;
typedef UnweightNode table;

struct unweight;
typedef struct unweight *Unweight;
typedef Unweight vertex;

#endif

#define MinTableSize (5)

/* 链表的节点 */
struct Node
{
    ElementType Element;
    table Next;
};

/* 散列表 */
struct unweight
{
    int known;
    int dist;
    table *path;
};
