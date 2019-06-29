// // 面试题25：合并两个排序的链表
// 题目：输入两个递增排序的链表，合并这两个链表并使新链表中的结点仍然是按照递增排序的。
// 例如: list_one: 1-3-5-7; list_two: 2-4-6-8; 
// 链表合并之后：1-2-3-4-5-6-7-8; 
/*
    1.解题思路：
        a.当两个链表都不为空的时候：同时比较两个链表头结点；
        b.注意：保证链表间的关系不断开；
                    插入后新的链表是递增排序的；
        c.插入过程：
            将值小的节点当做头结点，进行递归调用；
*/
#include <stdio.h>
#include <stdlib.h>
#include "one_list.h"

List *MergeList(List *pHead1, List *pHead2)
{
    // 边界条件
    if(pHead1 == NULL)  
        return pHead2;
    else if(pHead2 == NULL)
        return pHead1;
    // 定义一个新的头结点
    List *mergeHead = NULL;
    // 链表合并
    if(pHead1->mValue < pHead2->mValue){
        mergeHead = pHead1;
        mergeHead->pNext = MergeList(pHead1->pNext, pHead2); 
    }
    else{
        mergeHead = pHead2;
        mergeHead->pNext = MergeList(pHead1, pHead2->pNext);
    }
    return mergeHead;
}

/********************test code***********************/
List *Test(char* testName, List* pHead1, List* pHead2)
{
    if(testName != NULL)
        printf("%s begins:\n", testName);

    printf("The first list is:\n");
    print(pHead1);

    printf("The second list is:\n");
    print(pHead2);

    printf("The merged list is:\n");
    List* pMergedHead = MergeList(pHead1, pHead2);
    print(pMergedHead);
    
    printf("\n");

    return pMergedHead;
}
// test1: 两个不为空的链表
void test1()
{
    // 创建链表，并进行连接，采用方法一，按顺序
    List *pHead1 = malloc(sizeof(List));
    pHead1 = NULL;
    addToSomewhere(&pHead1, 1);
    addToSomewhere(&pHead1, 5);
    addToSomewhere(&pHead1, 3);

    List *pHead2 = malloc(sizeof(List));
    pHead2 = NULL;
    addToSomewhere(&pHead2, 4);
    addToSomewhere(&pHead2, 2);
    addToSomewhere(&pHead2, 6);
    // 反转链表
    Test("test1", pHead1, pHead2);

}
// main
int main()
{
    test1();
    return 0;
}