#ifndef ONE_LIST_H
#define ONE_LIST_H

typedef struct ListNode List;
struct ListNode
{
    int mValue;
    List *pNext;
};

//  方法一：根据值进行创建链表，并进行链接  
extern void addToTail(List **pHead, int value); //添加到末尾
extern void addToSomewhere(List **pHead, int value);  // 排序添加

//方法二 当传递的参数是指针节点时，需要创建指针节点的关系
extern List *CreatNode(int value);                      // 创建节点
extern void addTo_withNode(List **pHead, List *pNew);   // 对链表进行排序
extern void ConnectListNodes(List *pNode1, List *pNode2); //每次单独连接两个节点之间的连接关系：

// 删除链表 或者 节点
extern void RemoveNode(List **pHead, int value);    // 移除链表中的某一个节点
extern void DestoryList(List *pHead);               // 删除整个链表

// 打印链表
extern void print(List *pHead);     // 打印整个链表
extern void printNode(List *pNode); // 打印单节点

#endif

