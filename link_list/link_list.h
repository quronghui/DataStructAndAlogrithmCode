/* link_list */
/* 定义了位置和链表的结构体指针 */
/* 头文件也可用在数组的实现中 */

#ifndef LINK_LIST_H
#define LINK_LIST_H

typedef char ElementType;   //自己加上的，假定类型是char
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;     
typedef PtrToNode Position;

List MakeEmpty(List L); 
int IsEmpty(List L);
int IsLast(Position P, List L);

Position Find(ElementType X, List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Insert(ElementType X, List L, Position P);

void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);

#endif
struct Node
{
    ElementType Element;
    Position Next;
};
