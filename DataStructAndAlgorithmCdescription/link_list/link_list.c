/*link_list.c 
*   1) 结构体数组中的数据在链表中怎么存储；
*       是不是只能一个个的读入
*   2) 指针结构体：定义了一个position 和 list 的结构体
*   3)malloc(sizeof(struct node))创建元素的存储空间；如果是malloc(sizeof(pointer) 只是指针的存储空间
*   4)删除整个链表,释放链表的每一个元素,将List 置Null；此时定义另外一个指针完成每个元素释放的工作
*/
#include <stdio.h>
#include <stdlib.h>
#include "link_list.h"

/* return Null */
int IsEmpty(List L)
{
    return L->Next == NULL; /* only creat header pointer  */
}

/* return last position */
int IsLast(Position P, List L)
{
    return P->Next == NULL;
}

/* find element */
Position Find(ElementType X, List L)
{
    Position P;
    P = L->Next;    /* 通过位置position结构体进行操作 */
    while (P != NULL && P->Element != X)
    {
        P = P->Next;
    }
    return P;
}

/* FindPrevious: 用的是前面这个元素进行判断 */
Position FindPrevious(ElementType X, List L)
{
        Position P = L;     /* 为了找元素x的前驱；header 是第一个元素的前驱 */
        while( P->Next != NULL && P->Next->Element != X)
            P = P->Next;
        return P;
}

/* delete X */
void Delete(ElementType X, List L)
{
    Position P, TmpCell;

    P = FindPrevious(X,L);

    if(!IsLast(P,L))
    {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}

/* Insert X 没有说在哪个位置，插在了P之后 */
void Insert(ElementType X, List L, Position P)
{
    Position TmpCall;

    TmpCall = malloc(sizeof(struct Node )); //需要元素的存储空间；如果是sizeof(TemCall) 只是指针的存储空间
    if(TmpCall ==NULL )
        printf("out of space!\n");
    TmpCall->Element = X;
    TmpCall->Next = P->Next;
    P->Next = TmpCall;
}   

/* 删除整个链表 */
void DeleteList(List L)
{
    Position P, Tmp;
    P = L->Next;
    L->Next = NULL;     /* 将List 置空 */

    while(P != NULL){   /* 释放链表的每一个元素 */
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}