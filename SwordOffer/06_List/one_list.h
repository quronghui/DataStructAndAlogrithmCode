#ifndef ONE_LIST_H
#define ONE_LIST_H

typedef struct ListNode List;

extern void addToTail(List **pHead, int value);
extern void addToSomewhere(List **pHead, int value);
extern void RemoveNode(List **pHead, int value);
extern void print(List *pHead);
extern void DestoryList(List *pHead);

// 当传递的参数是指针节点时，需要创建指针节点的关系
extern List *CreatNode(int value);
extern void addTo_withNode(List **pHead, List *pNew);

#endif

struct ListNode
{
    int mValue;
    List *pNext;
};