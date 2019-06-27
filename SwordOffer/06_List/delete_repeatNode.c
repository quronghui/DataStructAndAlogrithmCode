// 面试题18（二）：删除链表中重复的结点
// 题目：在一个排序的链表中，如何删除重复的结点？将重复的节点全部删除，只保留不重复的
// 5-7-9-9-11;  -->  5-7-11

/*
*   1.题目提示： 排序链表
        a. 如何删除：通过遍历时，节点值是否存在重复，进行节点的释放；
        b. 同一个值，赋值给两个不同指针时，两个指针的地址是一样的；
        c. 但是在删除重复节点时，需要一个节点一个节点的释放
    2.链表的特殊情况；
        a.链表的头结点为空：不存在删除；
        b.链表不为空：重复节点在头结点，需要通过指向指针的指针传递参数；
    3.改进的地方：
        a.再插入链表的时候进行排序；
        b.可打印显示，或者用户输入判断
        c.超过两个重复值都可以删除
        d.所有边界都能测试
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "one_list.h"

/**********************删除重复节点****************************/
void DeleteRepeatNode(List **pHead)
{
    if(pHead == NULL || *pHead == NULL){    // 边界条件
        puts("List is empty.");
        return ;
    }

    List *pPreNode = NULL;
    List *pNode    = *pHead;
    while(pNode != NULL){
        List *pNext = pNode->pNext;
        bool needDelete = false;
        // 判断重复的套件，这里的重复节点，限制在两个，如果是3个就不对了
        if(pNext != NULL && pNext->mValue == pNode->mValue) 
            needDelete = true;
        // 如果在pNode节点这里没有重复
        if(!needDelete){
            pPreNode = pNode;
            pNode = pNode->pNext;
        }
        else{
            int value = pNode->mValue;
            List *pToBeDel = pNode;
            // 释放该指针
            while(pToBeDel != NULL && pToBeDel->mValue == value){
                pNext = pToBeDel->pNext;    // 这两个指针指向同一个地址

                free(pToBeDel);
                pToBeDel = NULL;
                
                pToBeDel = pNext;      // 这个就是循环释放的条件，不管有多少个重复的值，在这列进行一一释放
            }
            // 重复节点在头指针
            if(pPreNode == NULL)
                *pHead = pNext;
            else 
                pPreNode->pNext = pNext;
            
            pNode = pNext;  // 查找后面有没有重复的；
        }

    }
}

/*********************void test**************************/
void Test(char *name, List **pHead, int *expectedValue, int expectedLength)
{
    if(name != NULL)
        printf("%s test begin: ", name);
    
    // 打印检测
    puts("The original list is: ");
    print(*pHead);

    DeleteRepeatNode(pHead);

    puts("Delete node's list is: ");
    print(*pHead);

    /*根据用户输入进行检测*/
    int index = 0;
    List *pNode = *pHead;
    // 判断删除重复节点后的链表和原有链表是否相同
    while(pNode != NULL && index < expectedLength){
        if(pNode->mValue != expectedValue[index])
            break;
        pNode = pNode->pNext;
        index++;
    }
    if(pNode == NULL && index == expectedLength)
        printf("passed.\n");
    else 
        printf("failed.\n");
}

// 某些节点重复
void test1()
{

    List *phead = malloc(sizeof(struct ListNode));
    phead = NULL;
    
    //test addToSomewhere
    addToSomewhere(&phead, 1);
    addToSomewhere(&phead, 4);
    addToSomewhere(&phead, 4);
    addToSomewhere(&phead, 5);
    addToSomewhere(&phead, 6);
    addToSomewhere(&phead, 7);

    int expectedValue[] = { 1, 5, 6, 7 };
    Test("test1", &phead, expectedValue, sizeof(expectedValue)/sizeof(int));

    DestoryList(phead);
}

int main()
{
    test1();
    return 0;
}
