#ifndef ONE_LIST_H
#define ONE_LIST_H

typedef struct ListNode List;

extern void addToTail(List **pHead, int value);
extern void addToSomewhere(List **pHead, int value);
extern void RemoveNode(List **pHead, int value);
extern void print(List *pHead);



#endif

struct ListNode
{
    int mValue;
    List *pNext;
};