// 面试题18（一）：在O(1)时间删除链表结点
// 题目：给定单向链表的头指针和一个结点指针，定义一个函数在O(1)时间删除该结点。

/*
*   1. 题目思路：
        a. 在O(1)时间删除：假设--不需要遍历节点是否在链表中
        b. O(1)时间限制：不能按照常规思路，查找前驱节点；
        c. 给的是一个指针，不是一个值
        d. 创建链表的时候，常见的是指针节点的关系，不只是value的关系
    2.解题思路： 
        将pToBeDeleted 的 Next_node 复制到删除节点位置，删除的是Next_node：
        a. pToBeDeleted 的下一个节点不为空；  (n-1)O(1) --> 不是尾节点的有n-1
        b. 链表中只有一个头结点； -- 指向指针的指针保证链表删除后，地址不会变
        c. 删除节点位于尾部： 需要遍历得到前驱节点 O(n) --> 一个尾节点
    3. 时间复杂度：
        [ (n-1)O(1) + O(n) ] / n  平均时间复杂度，假设删除每一个节点
*/
#include <stdio.h>
#include <stdlib.h>
#include "one_list.h"

void DeleteNode( List **pListHead, List *pToBeDeleted )
{
    if(!pListHead || !pToBeDeleted){            // 边界检测
        puts("Invailed parameter.");
        return ;
    }
    /* 功能函数实现 */
    if(pToBeDeleted->pNext != NULL){           //要删除的结点不是尾结点
        List *Next_Node = pToBeDeleted->pNext;
        pToBeDeleted->mValue = Next_Node->mValue;
        pToBeDeleted->pNext = Next_Node->pNext;

        free(Next_Node);    // 删除的是下一个节点
        Next_Node = NULL;
    }
    else if( pToBeDeleted == *pListHead ){      //  链表只有一个结点，删除头结点（也是尾结点）
        free(pToBeDeleted);
        pToBeDeleted = NULL;

        *pListHead = NULL;      // 将头指针置为空
    }
    else{                                       // 链表中有多个结点，删除尾结点
        List *pNode = *pListHead;
        while( pNode->pNext != pToBeDeleted ){
            pNode = pNode->pNext;
        }
        pNode->pNext = NULL;
        free(pToBeDeleted);
        pToBeDeleted = NULL;
    }
}

/****************test code***********************/
void test(List *pHead, List *pNode)
{
    puts("The original list is: ");
    print(pHead);

    puts("The node to be deleted is: ");
    printf("%d\n", pNode->mValue);

    DeleteNode( &pHead, pNode );
    puts("Delete node's list is: ");
    print(pHead);
}

// 创建链表的时候，常见的是指针节点的关系，不只是value的关系
void createList()
{
    List *phead = malloc(sizeof(struct ListNode));
    phead = NULL;
    
    // 创建节点
    List *pNode1 = CreatNode(4);
    List *pNode2 = CreatNode(5);
    List *pNode3 = CreatNode(12);
    List *pNode4 = CreatNode(6);   
    List *pNode5 = CreatNode(9);

    //test addTo_withNode 创建节点的关系
    addTo_withNode(&phead, pNode1);
    addTo_withNode(&phead, pNode2);
    addTo_withNode(&phead, pNode3);
    addTo_withNode(&phead, pNode4);
    addTo_withNode(&phead, pNode5);

    //ptoDelete
    test(phead, pNode3);
}

int main()
{
    createList();
    return 0;
}