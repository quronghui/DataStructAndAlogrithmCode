//  题目: 将链表按照块进行反转
//  题目(一) : 块之间进行反转, 块内不反转;
// 题目(二): 块之间不反转, 但是块内要反转;

/*
*******************题目(一)*******************
    1. 解题思路
        a. 将每一个块看成一个指针:  得到这个块的第一个节点的指针, 和最后一个节点的指针
        b. 三个块进行反转:
            pPrevious pNode  pNext : 保证链表不会断开
*/
#include "one_list.h"
#include <stdio.h>

List    *reverseListBlock(List *pHead, unsigned int number)
{
    // 链表为空
    if(pHead == NULL || number < 1)
        return pHead;
    // 定义三个指针保证链表不会断开
    List *pPrevious = NULL;
    List  *pLast    =   NULL;     
    List *pNode     = pHead;
    List *pNodeNext     = NULL;
    List *pRevHead  = NULL;

    // 先找到每一个块的首尾节点
    while(pNode != NULL){
        // 找到每一个块的首尾
        pPrevious   =   pNode;
        for(  int   time  =  number ; time > 0 && pNodeNext != NULL; time--  ){
            pNodeNext   =   pNode->pNext;
        }
        pLast   =   pNodeNext;      // 尾部节点找到;
        // 下一个块的查找
        pNode   =   pNodeNext->pNext;

    }
    
}