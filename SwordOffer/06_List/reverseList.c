// // 面试题24：反转链表
// 题目一：定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的头结点。
// 题目二：定义一个函数，输入一个链表头结点，从链表中的第 k 个节点到 m个位置进行反转，返回反转链表的头结点；
// 题目扩展三：将链表前面k个节点进行反转； 用题目二的思路
// 题目扩展四：将链表倒数第 H 个节点进行反转；  使用快慢指针 加题目二的解题思路进行
/* 
* ******************* 题目一*******************
  1.解题思路： 画图理解
        a. 反转链表后的头结点：链表的最后一个节点；
        b. 链表的反转：通过三个指针
            pPrevious pNode  pNext : 保证链表不会断开
    2. 返回值：最后一个节点
    3. 链表的几种情况： a. 空链表  b. 只有一个节点； c. 多个节点

*********************题目二**************************
    方便处理：链表的第一个节点表示位置1
    1. 基础条件： k < m
    2. 先找出区间 [k, m]：调用反转函数；
    3. 然后链接前后区间，组成新的链表；
*/
#include <stdio.h>
#include <stdlib.h>
#include "reverseList.h"


/****************题目一: 从头开始反转链表*******************/
List *reverseList(List *pHead)
{
    if(pHead == NULL){      // 异常情况一：链表为空欧
        puts("List is null.");
        return NULL;
    }
    // 定义三个指针，保证链表不断
    List *pPrevious = NULL;     
    List *pNode     = pHead;
    List *pNext     = NULL;
    List *pRevHead  = NULL;
    // 建立三指针之间的关系
    while( pNode != NULL ){         // 判断条件：链表中循环的判断条件 pHead != NULL 
        // pnext 保证链表不会断开
        pNext = pNode->pNext;
        // 设置反转链表的头结点
        if(pNext == NULL){
            puts("List just have one node.");
            pRevHead = pNode;
        }
        // 链表的反转
        pNode->pNext = pPrevious;
        // 下移一个节点
        pPrevious = pNode;
        pNode = pNext; 
    }
    return pRevHead;
}

/**************************题目二************************************/
/***************从链表的第 k位 到第 m位反转；并将其打印出来******************/
// 增加了指针的错误处理函数，并进行了优化
List *reverseList_optimizem(List *pHead, unsigned int k, unsigned int m)
{
    // 保证基础边界条件
    if(pHead == NULL || k<0 || m<0 || k > m){
        puts("The list is null or parameter invaild.");
        return NULL;
    }
    // 定义参数
    List *pPreviousNode = NULL;      // 保存反转区间节点前一个节点
    List *pBellowNode   = NULL;     // 保存反转区间的后一个节点
    List *pNode = pHead;
    List *ReverNode = NULL;         // 用于反转链表的头结点；
    List *pReverseRear;             // 此时的头结点就是反转节点的尾部节点;   
    
    unsigned int count = 1  ;          //定义计数
    // 找出循环区间，并对异常进行处理
    while(pNode != NULL && count!=m){
        // 先遍历，找出k节点的指针
        for(count = 1; count < k; count++)
        {
            // 判断指针的下一个节点是否为空
            if( pNode->pNext == NULL){
                puts("List node number is less than k.");
                return NULL; 
            }
            else{
                pPreviousNode = pNode;       
                pNode = pNode->pNext;
            }
        }
        // 判断count 和节点 k之间的关系；
        if(count != k){
            puts("List node number is less than k.");
            return NULL; 
        }
        else{
            //保存反转链表的头结点，用于调用函数，并且用于反转；
            pReverseRear = pNode;             // 此时的头结点就是反转节点的尾部节点;
            ReverNode = pNode;
        }

        //在循环遍历找出 m的节点
        for(count = k; count < m; count++)
        {
            // 判断下一个节点是否为空
            if(pNode->pNext == NULL){
                puts("List node number is more than K and less than m.");
                return NULL;
            }
            else{
                pNode = pNode->pNext;
                pBellowNode = pNode->pNext;    // 将反转区间的后一个节点的关系保存下来了
            }
        }
        // 判断count和m之间的关系
        if(count != m){
            puts("List node number is more than K and less than m.");
            return NULL;
        }
        else{
            pNode->pNext = NULL;    // 找到了这个区间 从k --> m的区间
        }
    }
    
    // 调用反转链表的函数
    List *reverseHeadNode = reverseList( ReverNode );

    // 判断是否是从第一个节点开始的
    pReverseRear->pNext = pBellowNode;  // 尾部都是要接起来的
    
    if(pReverseRear == pHead){
        pReverseRear->pNext = pBellowNode;
        return reverseHeadNode;
    } 
    else{
        pPreviousNode->pNext = reverseHeadNode;
        return pHead;
    }  
}

/***************TEST vode*****************/
// 题目二：反转链表：从第k个节点到 第m个节点
void Test( char *name,  List *pHead, unsigned int k, unsigned int m)
{
    if(name != NULL)
        printf("%s begin:\n", name);
    // 打印原来链表；
    printf("The original list is: \n");
    print(pHead);   

    List *pPreHead = reverseList_optimizem(pHead, k, m);
    
    // 打印反转链表
    printf("The reversed list is: \n");
    print(pPreHead);   

    DestoryList(pPreHead);

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
    // 反转链表，题目二的调用
    Test("test1", pHead, 1, 5);


}

// main 函数
int main(void)
{
    test1();
    return 0;
}