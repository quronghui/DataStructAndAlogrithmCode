/*
*   题目：单链表 节点的插入和删除
*   1) 每插入一个节点，都要为新节点分配内存；
*   2) 删除节点，需要将其free，避免野指针；
×   
    Parameter：
        a) **phead 头指针：定义为指向指针的指针, 防止（*root）根指针为空时，的内存地址被直接修改；
        b) 单链表：头指针是要保存数据的，和双向链表有点区别。
        
*/


typedef struct ListNode List;

struct ListNode
{
    int mValue;
    List *pNext;
};

#include <stdio.h>
#include <stdlib.h>

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

/**************test code************************/
void print(List *pHead)
{
    while(pHead != NULL){
        printf("list value: %d --> ", pHead->mValue);
        pHead = pHead->pNext;
    }
    printf("\n");
}
void test1()
{
    List *phead = malloc(sizeof(struct ListNode));
    phead->mValue = 5;
    phead->pNext = NULL;
    
    //test addtoTail
    addToTail(&phead, 7);       /* 指向指针的指针调用，传递的是地址； */
    
    //test addToSomewhere
    addToSomewhere(&phead, 4);
    print(phead);
    //test remove
    RemoveNode(&phead, 6);

}



/***********print_list_reverse*****************/
// 面试题6：从尾到头打印链表
// 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。

/*
*   1.题目信息：是否可以改变指针指向
        a.反序打印链表：栈的方式进行push and pop
        b.栈也是递归，通过递归实现
*/

// List creatstack(List s)
// {

// }
// List stackPush(int value)   /* 向栈中插入某个值 */
// {
//     List *stackNode;
//     stackNode = malloc(sizeof(struct ListNode));
//     if(stackNode == NULL)   printf("out of space!")

// }

// void printListStack(List *pHead)
// {
//     List *pNode = pHead;
//     while(pNode != NULL){

//     }
// }

int main()
{
    test1();
    return 0;
}