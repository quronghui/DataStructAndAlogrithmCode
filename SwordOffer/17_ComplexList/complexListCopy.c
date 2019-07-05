// 面试题35：复杂链表的复制
// 题目：请实现函数ComplexListNode* Clone(ComplexListNode* pHead)，复制一个复杂链表。
// 在复杂链表中，每个结点除了有一个m_pNext指针指向下一个结点外，
// 还有一个m_pSibling 指向链表中的任意结点或者nullptr。
/*
*   1.题目需求：
        1)这个复杂链表已经存在了；需要的是创建一个新的链表，将复杂链表复制，返回一个新的链表头指针；
    2.解题思路：
        a. 先将每一个单节点进行复制，连接在源节点之后；A-A'-B-B'C-C'；
        b. 完成任意节点关系pSibling，关系的构建；A->s = C; A'->s = C'
        c. 将两个链表分开：根据奇偶节点分开
*/
#include "complexList.h"
#include <stdio.h>
#include <stdlib.h>

// 函数声明
void cloneNode(ComplexListNode *pHead);
void connectSibling(ComplexListNode *pHead);
ComplexListNode *divList_OddEven(ComplexListNode *pHead);

// 需要将用户接口函数放在前面；哪怕多写几个函数声明
/****************用户接口函数****************/
ComplexListNode* Clone(ComplexListNode* pHead)
{
    cloneNode(pHead);
    connectSibling(pHead);
    return divList_OddEven(pHead);
}

/***************a.单节点的复制*****************/
void cloneNode(ComplexListNode *pHead)
{
    ComplexListNode *pNode = pHead;
    while(pNode != NULL){
        // 单节点的复制
        ComplexListNode *pClone = malloc(sizeof(ComplexListNode));
        pClone->mVaule = pNode->mVaule;
        pClone->pNext = pNode->pNext;
        pClone->pSibling = NULL;
        // 节点间关系连接 A-A'
        pNode->pNext = pClone;
        // 下一个节点
        pNode = pClone->pNext;
    }
}

/**********b. 完成任意节点关系pSibling的构建******************/
void connectSibling(ComplexListNode *pHead)
{
    ComplexListNode *pNode = pHead;
    while(pNode != NULL){
        ComplexListNode *pClone = pNode->pNext;
        // 关系链接
        if(pNode->pSibling != NULL){
            pClone->pSibling = pNode->pSibling->pNext;
        }
        pNode = pClone->pNext;
    }
}

/***************c.将两个链表分开：根据奇偶节点分开******************/
ComplexListNode *divList_OddEven(ComplexListNode *pHead)
{
    // 创建clone的头结点
    ComplexListNode *pNode = pHead;
    ComplexListNode *pCloneHead = NULL;
    ComplexListNode *pCloneNode = NULL;

    // 得到连个链表的头结点
    if(pNode != NULL){
        pCloneHead = pCloneNode = pNode->pNext;  // 注意这里复制链表头结点的创建，以及操作节点的创建；以及前后关系；
        // 原链表进行连接，删除重复节点
        pNode->pNext = pCloneNode->pNext;
        pNode = pNode->pNext;
    }

    // 进行其余节点的分开
    while(pNode != NULL){
        pCloneNode->pNext = pNode->pNext;
        pCloneNode = pCloneNode->pNext;
        pNode->pNext = pCloneNode->pNext;
        pNode = pNode->pNext;
    }
    return pCloneHead;
}


/***********************test code*************************/
void Test(char *name, ComplexListNode *pHead)
{
    if(name != NULL)
        printf("%s begin:   ", name);
    // 原链表节点
    printf("The original list is:\n");
    printList(pHead);
    // 复制链表节点
    ComplexListNode *pCloneHead = Clone(pHead);

    printf("The clone list is:\n");
    printList(pCloneHead);

}

/*         -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//  |       |      /|\             /|\
//  --------+--------               |
//          -------------------------
*/
// 复杂链表的创建
void test1()
{
    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, pNode3);
    BuildNodes(pNode2, pNode3, pNode5);
    BuildNodes(pNode3, pNode4, NULL);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test1", pNode1);
}

// main
int main()
{
    test1();
    return 0;
}