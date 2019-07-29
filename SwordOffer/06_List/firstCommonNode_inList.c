// 面试题52：两个链表的第一个公共结点
// 题目：输入两个链表，找出它们的第一个公共结点。
/*
*   1. 解题思路一:  蛮力法, 每遍历一个链表A的节点, 就遍历一次链表B;
    2. 解题思路二:
        a. 通过两个栈: 从链表的尾部开始遍历查找.(先入后出)
        b. 通过空间换时间. 时间复杂度O(m+n);
    3. 解题思路三:  
        a. 先遍历得到链表的长度, 求出他们长度之差;
        b. 判断那个链表比较长
        c. 让长的链表先走
        d. 链表的创建, 构建一个Y字型的链表; 之前构造和两个不同的链表, 这样是没有交点的;
*/
#include "one_list.h"
#include <stdio.h>
#include <stdlib.h>

/*******************遍历得到链表的长度*********************/
unsigned int    getListLength( List *pHead )
{
    unsigned int    length  =   0;
    List *pNode = pHead;
    while( pNode != NULL ){
        ++length;
        pNode = pNode->pNext;
    }
    return length;
}

/********************找寻两个链表的公共节点********************/
List    *findFirstCommonNode( List  *pHead1, List *pHead2 )
{
    if( pHead1 == NULL || pHead2 == NULL )
        return NULL;
    
    // 得到两个链表的长度
    unsigned int    length1 = getListLength(pHead1);
    unsigned int    length2 = getListLength(pHead2);
    int lengthDir    =   length1 - length2;

    // 判断链表的长短
    List    *listHeadLong = pHead1;
    List    *listHeadShort  =   pHead2;
    if( length2 > length1 ){
        listHeadLong  =   pHead2;
        listHeadShort =   pHead1;
        lengthDir   =   length2 -   length1;
    }
    // 先让长的链表先走
    for(int i = 0; i < lengthDir; i++)
        listHeadLong = listHeadLong->pNext;
    
    // 两个链表一起走, 值相等的情况下, 两个指针也是相同的
    while( listHeadLong != NULL && listHeadShort != NULL && (listHeadLong != listHeadShort) ){
        listHeadLong    =   listHeadLong->pNext;
        listHeadShort   =   listHeadShort->pNext;
    }
    // 得到第一个公共的节点;
    List    * listFistCommonNode    =   listHeadLong;

    return  listFistCommonNode  ;
}

/**********************Test code***********************/
void Test( char *name, List *pHead1,    List    *pHead2,    List *expected )
{
    if( name != NULL )
        printf( "%s, begin:     \n", name );
    
    // 打印链表
    printf(" pHead1 is : ");
    print(pHead1);
    printf(" pHead2 is : ");
    print(pHead2);
    
    // 公共节点
    List *listCommonNode = findFirstCommonNode(pHead1, pHead2);
    
    if(listCommonNode == expected)
        printf( "Passed. The   listCommonNode value is %d.  \n", listCommonNode->mValue);
    else
        printf( "Failed. The   listCommonNode value is %d.  \n", listCommonNode->mValue);
}
// test1
void test1()
{
    // 找链表的公共节点, 不需要对插入的链表进行排序的, 直接添加到尾部就行
    List* pNode1 = CreatNode(1);
    List* pNode2 = CreatNode(2);
    List* pNode3 = CreatNode(3);
    List* pNode4 = CreatNode(4);
    List* pNode5 = CreatNode(5);
    List* pNode6 = CreatNode(6);
    List* pNode7 = CreatNode(7);
    List* pNode8 = CreatNode(8);
    List* pNode9 = CreatNode(9);



    // 链表的创建, 构建一个Y字型的链表;
     ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode6);
    ConnectListNodes(pNode6, pNode7);
    ConnectListNodes(pNode7, pNode8);

    
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);
    ConnectListNodes(pNode7, pNode9);


    Test("Test1", pNode1, pNode4, pNode6);

    // 链表的删除
    DestoryList(pNode1);
    DestoryList(pNode4);

}

// void main
int main()
{
    test1();
    return 0;
}