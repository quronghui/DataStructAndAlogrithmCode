/*
*   题目：单链表 节点的插入和删除
*   1) 每插入一个节点，都要为新节点分配内存；
*   2) 删除节点，需要将其free，避免野指针；
×   3) 重复节点也适用
    Parameter：
        a) **phead 头指针：定义为指向指针的指针, 防止（*root）根指针为空时，的内存地址被直接修改；
        b) 单链表：头指针是要保存数据的，和双向链表有点区别。
        
*/

#include <stdio.h>
#include <stdlib.h>
#include "one_list.h"

/*********************创建的节点间的关系，不是之的关系**********************/
// 当函数传递的是节点时，因此我们需要单独创建节点
List *CreatNode(int value)
{
    List *pNode = malloc(sizeof(List));
    pNode->mValue = value;
    pNode->pNext = NULL;

    return pNode;
}
/* 需要考虑顺序 */
void addTo_withNode(List **pHead, List *pNew)
{
    if(pNew == NULL){
        printf("pNode is invaild parameter.\n ");
        return ;
    }
 
    List *pNode = *pHead;
    List *previous = NULL;
    /* 找出插入value的 前驱节点, 先找出前驱位置 */
    while(pNode != NULL && pNode->mValue < pNew->mValue){
        previous = pNode;
        pNode = pNode->pNext;
    }

    /* 先将后面的节点放在新节点后 */
    pNew->pNext = pNode;        
    if(previous == NULL)      /* 头结点为空,要进行判断 */
        *pHead = pNew;      
    else{
        previous->pNext = pNew;
    }      
}

/************************** insert node to tail**************** */
void addToTail(List **pHead, int value)     /* **pHead 指向指针的指针，插入节点的时候改变头指针； */
{                                           /* 需要指向指针的指针 */
    List *pNew = malloc(sizeof(struct ListNode));
    if(pNew ==NULL ){    
        printf("out of space!\n");  /* 指针未分配成功 */
        return ;
    }
    pNew->mValue = value;
    pNew->pNext = NULL;             /* 创建新的指针，直接赋值为null,防止野指针出现 */

    if(*pHead == NULL)  /* 插入新的节点，便是头指针（如果链表需要头指正呢？） */
        *pHead = pNew;
    else{
        List *pNode = *pHead;   

        while(pNode ->pNext != NULL)
            pNode = pNode->pNext;
        pNode->pNext = pNew;
    }
}
/*****************insert node to somewhere***********/
// 需要一个插入位置的前驱节点，升序插入节点
void addToSomewhere(List **pHead, int value)
{
    List *pNew = malloc(sizeof(struct ListNode));
    if(pNew ==NULL ){    
        printf("out of space!\n");  /* 指针未分配成功 */
        return ;
    }
    pNew->mValue = value;
    pNew->pNext = NULL;   

    List *pNode = *pHead;
    List *previous = NULL;
    /* 找出插入value的 前驱节点, 先找出前驱位置 */
    while(pNode != NULL && pNode->mValue < value){
        previous = pNode;
        pNode = pNode->pNext;
    }

    /* 先将后面的节点放在新节点后 */
    pNew->pNext = pNode;        
    if(previous == NULL)      /* 头结点为空,要进行判断 */
        *pHead = pNew;      
    else{
        previous->pNext = pNew;
    }  
}

/*****************RemoveNode***************************************/
void RemoveNode(List **pHead, int value)
{
    if(pHead == NULL || *pHead == NULL) return ;

    List *pToBeDelete = NULL;

    if((*pHead)->mValue == value ){ /* 判断头结点的值是不是 */
        pToBeDelete = *pHead;
        *pHead = (*pHead)->pNext;
    } 
    else
    {
        List *pNode = *pHead;
        /* 找节点的前驱位置 */
        while(pNode -> pNext !=NULL && pNode->pNext->mValue != value)
            pNode = pNode->pNext;
        
        if(pNode->pNext !=NULL && pNode->pNext->mValue == value)    /* 判断下一个节点是不是value */
        {
            pToBeDelete = pNode->pNext; /* 取出这个节点 */
            pNode->pNext = pNode->pNext->pNext;     
        }
    }
    /* 释放删除节点 */
    if(pToBeDelete != NULL){
        free(pToBeDelete);
    }
}
/* 释放整个动态链表 */
void DestoryList(List *pHead)
{
    while( pHead != NULL){
        List *pNode = pHead;
        free(pHead);
        pHead = pNode->pNext;
    }
}


/**************test code************************/
void print(List *pHead)
{
    while(pHead != NULL){
        printf("%d\t", pHead->mValue);
        pHead = pHead->pNext;
    }
    printf("\n");
}
// void test()
// {
//     List *phead = malloc(sizeof(struct ListNode));
//     phead->mValue = 5;
//     phead->pNext = NULL;
    
//     //test addtoTail
//     addToTail(&phead, 7);       /* 指向指针的指针调用，传递的是地址； */
    
//     //test addToSomewhere
//     addToSomewhere(&phead, 4);
//     print(phead);
//     //test remove
//     RemoveNode(&phead, 6);

// }

// /* 函数单独测试 */
// int main()
// {
//     test();
//     return 0;
// }