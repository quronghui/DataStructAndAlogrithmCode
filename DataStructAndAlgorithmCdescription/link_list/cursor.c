/* cursor.c 
*   1)链表的游标实现;
*   2) 指针的空用NULL; 数组的空用0
*   3) 数组中的链表：作为下标使用
*/
#include <stdio.h>
#include <stdlib.h>
#include "cursor.h"

/* return empty */
int IsEmpty(List L)
{
    return CursorSpace[L].Next == 0;
}

/* return last position */
int IsLast(Position P, List L)
{
    return CursorSpace[P].Next == 0;
}

/* find X */
Position Find(ElementType X, List L)
{
    Position P;
    P = CursorSpace[L].Next;

    while( P != 0 && CursorSpace[P].Element != X)
        P = CursorSpace[P].Next;
    return P;
}
