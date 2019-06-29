// reverseList.h 
// 反转链表的头文件；
#ifndef REBERSELIST_H
#define REBERSELIST_H

#include "one_list.h"

// 从头开始反转链表;
extern List *reverseList(List *pHead); 
// 从链表的第 k位 到第 m位反转；
extern List *reverseList_optimizem(List *pHead, unsigned int k, unsigned int m);



#endif