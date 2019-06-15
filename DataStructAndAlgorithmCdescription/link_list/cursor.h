 /* 链表游标实现的方法 */

#ifndef CURSOR_H
#define CURSOR_H

#define SpaceSize 100
typedef int ElementType;   //自己加上的，假定类型是char

typedef int PtrToNode;
typedef PtrToNode List;     
typedef PtrToNode Position;

void InitializeCursorSpace(void);

List MakeEmpty(List L); 
int IsEmpty(const List L);
int IsLast(const Position P, const List L);

Position Find(ElementType X, const List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Insert(ElementType X, List L, Position P);

void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);

ElementType Retrieve(const Position P);
#endif

struct Node
{
    ElementType Element;
    Position Next;
};

struct Node CursorSpace[SpaceSize];
