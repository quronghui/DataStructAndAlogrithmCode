// 复杂链表的复制，头文件

#ifndef COMPLEXLIST_H
#define COMPLEXLIST_H

#include <stdio.h>
#define Type_ComList int

typedef struct complexList ComplexListNode;

struct complexList
{
    Type_ComList mVaule;
    ComplexListNode *pNext;
    ComplexListNode *pSibling;  // 指向任意节点的指针；
};

// 复杂链表的创建
extern ComplexListNode *CreateNode(Type_ComList nValue);
extern void BuildNodes(ComplexListNode *pNode, ComplexListNode *pNextNode, ComplexListNode *pSiblingNode);
extern void printList(ComplexListNode *pHead);

#endif