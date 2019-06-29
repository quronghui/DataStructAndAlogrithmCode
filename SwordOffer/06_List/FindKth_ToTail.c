// 面试题22：链表中倒数第k个结点
// 题目：输入一个链表，输出该链表中倒数第k个结点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾结点是倒数第1个结点。
// 例如一个链表有6个结点，从头结点开始它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个结点是值为4的结点。

/*
*   1.題目提示：
        a.求的是倒数的第 k 个节点；
            单链表没有逆指针，因此也就是正数 第(n-k +1)个节点；
            但是我们并不知道n的值是多少
        b.计数规则：从头结点记为第一个节点
    2.解题思路
        a.设计一个快慢指针； *front --> (k-1) ; *rear --> 1; 让他们相差（k-1）个节点
            当front走到结尾：需要走 n-(k-1)，也就是需要走 (n-k+1)步
            rear : 也就刚好走了 （n-k+1）步
        b.Parameter
            list *phead : 链表的头结点
            unsigned int k: 节点k为正数
    3. 扩展
        当问题使用一个指针遍历一次解决不了问题时，通过两个指正进行快慢遍历
    
*/          
#include <stdio.h>
#include <stdlib.h>
#include "FindKth_ToTail.h"

List *FindKth_ToTail(List *pHead, unsigned int k)   // 函数，返回值是 list * 的指针
{
    // 基础条件
    if(pHead == NULL || k<=0){
        puts("Phead is null or parameter k is invaild.");
        return NULL;
    }
    // 快慢指针
    List *front = pHead;
    List *rear = NULL;
    // 快指针先走（k-1）步
    for(unsigned int i=0; i<(k-1); i++){
        if(front->pNext != NULL)            // 判断了k < n
            front = front->pNext;
        else{
            puts("The list node n is less than k: ");
            return NULL;
        }
    }
    // 慢指针指向头结点
    rear = pHead;

    // 两个指针此时同时移动，当front移动到尾部时，rear刚好移动（n-k+1）步，找到倒数第k个节点
    while( front->pNext != NULL ){
        front = front->pNext;
        rear = rear->pNext;
    }
    return rear;    // 返回找到的节点
}

// /*********************test code************************/
// void Test()
// {
//     // 创建链表
//     List *phead = malloc(sizeof(List));
//     phead = NULL;
//     addToTail(&phead, 4);
//     addToTail(&phead, 3);
//     addToTail(&phead, 7);
//     addToTail(&phead, 6);
//     addToTail(&phead, 10);

//     // 调用函数
//     print(phead);
//     unsigned int k = 4;
//     printf("Select the %dth\n", k);
//     List *rear = FindKth_ToTail(phead, k);
//     print(rear);

//     // 删除链表
//     DestoryList(phead);
// }   

// int main()
// {
//     Test();
//     return 0;
// }