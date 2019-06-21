// 在一个单链表中查找一个指定值的函数。它的参数是一个指向链表第一个节点的指针，
// 一个指向我们需要查找的值的指针和一个函数指针，它所指向的函数用于比较存储于链表中的类型的值

/*
*   1.题目理解：查找的值；和被查找的函数；都需要定义为指针进行传递
        需要修改元素的类型为 void *;
        这样会避开编译器的类型检查，容易产生错误

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "one_list.h"

// List *search_list(): search_list是函数，返回值是指向List型的指针
List *search_list( List *node, void const *value,               
                    int (*compare)(void const *, void const *))     // 回调函数：函数指针，返回值是int整形；对其传参数的时候进行初始化定义
{
    while (node != NULL)
    {
        if( compare( &node->mValue, value ) == 0 )
            break;
        node = node->pNext;
    }
    return node;    // 返回值是指向List型的指针
}

/******************** 回调函数的:功能函数************************/
int compare_ints(void const *a, void const *b)
{
    if( *(int *)a == *(int *)b )    /* 比较之前需要强制转换为回调函数的比较类型 */
        return 0;
    else 
        return 1;
}

/******************回调函数的使用********************/
void test()
{
    List *pHead = malloc( sizeof(List));
    assert(pHead != NULL);
    pHead->mValue = 10;
    pHead->pNext = NULL;

    int desired_value = 10; 

    List *desired_node = search_list(pHead, &desired_value, compare_ints);
    
    if( desired_node->mValue == pHead->mValue )
        printf(" find this node\n");
    else 
        printf(" no node\n");
}

/**********************当比较的是字符串，重新编译test函数**************************/
// 修改 one_list 中的int 型为 void 型
//List *desired_node = search_list(pHead, "desired_value", strcmp);



int main()
{
    test();
    return 0;
}