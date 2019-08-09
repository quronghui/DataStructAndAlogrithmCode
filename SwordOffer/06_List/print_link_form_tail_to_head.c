// 面试题6：从尾到头打印链表
// 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。

/*
*   1.题目要求：from tail to head print link
*   2.ways:
        a. 栈的方法：栈也是递归
    3. Parament
        *pHead: 链表的地址

*/

#include <stdio.h>
#include <stdlib.h>

#include "one_list.h"

void printByRecursively(List *pHead)
{
    if(pHead != NULL){
        if(pHead->pNext != NULL){
            printByRecursively(pHead->pNext);
        }
        printf("%d\t",pHead->mValue);      /* 递归输出最后元素 */
    }
}

/******************test***************************/
void test()
{
    /* 得先向链表中插入元素 */
    List *phead = malloc(sizeof(struct ListNode));  /* 需要头文件stdlib.h */
    phead = NULL;
    addToSomewhere(&phead, 4);
    addToSomewhere(&phead, 5);
    addToSomewhere(&phead, 6);
    addToSomewhere(&phead, 7);
    print(phead);

    /* 从头到尾输出 */
    printByRecursively(phead);
    printf("\n");
}

/* test print */
int main()
{
    test();
    return 0;
}