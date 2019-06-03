/*
*   hashval.h
*   1) 多了一个链表数组 存储tablesize
*/

#ifndef LINK_LIST_H
#define LINK_LIST_H

typedef char ElementType;   //自己加上的，假定类型是char
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;     
typedef PtrToNode Position;

struct hashtbl;
typedef struct hashtbl *Hashtable;
Hashtable initialize_table(int tablesize);
void destory_table(Hashtable h);
Position find(ElementType key, Hashtable h);
void insert(ElementType key , Hashtable h);
ElementType retrieve(Position p);
Hashtable rehash(Hashtable h);

typedef unsigned int Index;

#endif

#define MinTableSize (5)

/* 链表的节点 */
struct Node
{
    ElementType Element;
    Position Next;
};

/* 散列表 */
struct hashtbl
{
    int tablesize;
    List *thelists;
};

