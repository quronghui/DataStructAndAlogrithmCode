// 面试题24(四)：反转链表，从链表的倒数第 H 个节点进行反转
// 为了方便：链表指针都从第一个节点开始计数为1

/* 
*   1.解题思路：
        a. 直接调用 函数FIndKth_ToTail.c （得到倒数第k个节点）
            得到需要反转的节点，或者是报错；
        b. 在调用函数reverseList中的题目一的解题思路；
            此时需要查找一下这个节点的前驱节点,链接两部分；
            对于尾部的话就不需要链接了；
*/
#include <stdio.h>
#include <stdlib.h>
// #include "one_list.h"
#include "FindKth_ToTail.h"
#include "reverseList.h" 

/**************反转链表，从链表的倒数第 H 个节点进行反转*******************/
// 返回的是：反转以后的头结点
List *reverseList_FromTailH(List *pHead, unsigned int H)
{
    if(pHead == NULL || H<=0){      // 边界条件
        puts("Phead is null or parameter k is invaild.");
        return NULL;
    }
    // a.直接调用 函数FIndKth_ToTail.c；得到反转节点
    List *RevNode = FindKth_ToTail(pHead, H);   // 函数，返回值是 list * 的指针
    printNode(RevNode);

    List *pJudge = RevNode;
    // 此时要做一个判断:是够直接从第1个节点进行反转
    List *pPreNode = NULL;    
    if(pJudge != pHead){
        List *pNode = pHead;
        while( pNode != RevNode && pNode->pNext != NULL){
            pPreNode = pNode;
            pNode = pNode->pNext;
        }
    }
    //printNode(pPreNode);

    //在调用函数reverseList中的题目一的解题思路；
    List *RevHeadNode = reverseList(RevNode);
    // 此时要做一个判断:是够直接从第1个节点进行反转
    if(pJudge == pHead){
        return RevHeadNode;
    }
    else{   
        pPreNode->pNext = RevHeadNode;
        return pHead;
    }
}


// /*********************test code************************/
void Test( char *name,  List *pHead, unsigned int H)
{
    if(name != NULL)
        printf("%s begin:\n", name);
    // 打印原来链表；
    printf("The original list is: \n");
    print(pHead);   

    List *pRevHead = reverseList_FromTailH(pHead, H);
    
    // 打印反转链表
    printf("The reversed list is: \n");
    print(pRevHead);   

    DestoryList(pRevHead);

}

// 链表中有节点
void test1()
{
    // 创建链表，并进行连接，采用方法一，按顺序
    List *pHead = malloc(sizeof(List));
    pHead = NULL;
    addToSomewhere(&pHead, 1);
    addToSomewhere(&pHead, 2);
    addToSomewhere(&pHead, 3);
    addToSomewhere(&pHead, 4);
    addToSomewhere(&pHead, 5);
    addToSomewhere(&pHead, 6);
    // 反转链表
    Test("test1", pHead, 1);

}

// main 函数
int main(void)
{
    test1();
    return 0;
}