//
// Created by quronghui on 2019/9/14.
//
// 题目：双向链表的创建，插入，删除
/*
 * (1) 可以实现双向链表的有序插入；
 * (2) 实现数据插入到链表的末尾；
 * */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct double_list ListNode;
struct double_list{
    int value;
    ListNode *pre;
    ListNode *next;
};

// creat_double_list():通过一个头指针进行维护
ListNode *creat_double_list()
{
    ListNode *pHead = (ListNode *)malloc(sizeof(ListNode));
    assert(pHead != NULL);
    pHead->pre = pHead->next = NULL;  // 初始化链表，使其为空
    return pHead;
}

// insert_double_list():
// （1）头结点的pHead->next指向下一个节点；pHead->pre指向最后一个节点；
// (2)第一个节点的pHead->pre == NULL;
// （3）最后一个节点的pHead->next == NULL
void insert_double_list(ListNode *pHead, int data)
{
    if(pHead == NULL){
        printf("The list is empty.\n"); //头结点未分配成功；
        return;
    }
    // 创建几个临时节点
    ListNode *tmpHead = pHead;  //临时头节点
    ListNode *tmpNext;
    // 检查data值在链表中是够存在，存在就返回，不用插入；
    for (; (tmpNext = tmpHead->next) != NULL ; tmpHead = tmpNext) {
        if(tmpNext->value == data)
            return;
        // (1) 升序插入的关键点；
//        if(tmpNext->value > data)
//            break;
    }
    // 创建新的节点，接收插入的值
    ListNode *pNew = (ListNode *)malloc(sizeof(ListNode));
    assert(pNew != NULL);
    pNew->value = data;
    // 插入新的节点
    pNew->next = tmpNext;
    tmpHead->next = pNew;
    // 是否插入在开头位置
    if(tmpHead != pHead)
        pNew->pre = tmpHead;
    else
        pNew->pre = NULL;
    // 是否插入到末尾
    if(tmpNext != NULL)
        tmpNext->pre = pNew;
    else
        pHead->pre = pNew;
}

// delete_double_list() 节点的删除
void delete_double_list(ListNode *pHead, int value)
{
    if(pHead == NULL)
        return;
    // 查找数据value的位置
    ListNode *tmpHead = pHead->next;    // 指向第一个节点
    ListNode *tmpPre = pHead;           // 指向头结点
    while (tmpPre->next != NULL && tmpHead->value != value){
        tmpPre = tmpHead;
        tmpHead = tmpHead->next;
    }
    // 数据是否存在
    if(tmpPre->next == NULL)
        return;
    // 此时找到数据的位置为tmpHead,前驱位置是tmpPre
    tmpPre->next = tmpHead->next;

    // 只有一个节点
    if(tmpPre == pHead && tmpHead->next == NULL ){
        pHead->pre = pHead->next = NULL;
        return;
    }
    // 节点位于尾部位置
    if(tmpHead->next == NULL )
        pHead->pre = tmpPre;
    else if (tmpPre != pHead)
        tmpHead->next->pre = tmpPre;
    else
        tmpHead->next->pre = NULL;

    free(tmpHead);
}

// traversal_list code
void traversal_list(ListNode *pRoot)
{
    // 节点的前向遍历
    ListNode *preRoot = pRoot;
    printf("The list Forward traversal is: ");
    while (preRoot->next != NULL){
        printf("%d ",preRoot->next->value);
        preRoot = preRoot->next;
    }
    printf("\n");

    // 节点的后向遍历
    ListNode *bacRoot = pRoot;
    printf("The list Backward traversal is: ");
    while (bacRoot->pre != NULL){
        printf("%d ",bacRoot->pre->value);
        bacRoot = bacRoot->pre;
    }
    printf("\n");
}

// Test_del code
void Test_del(ListNode *pRoot)
{
    ListNode *pNode = pRoot;

    // （1）删除头节点
    delete_double_list(pRoot,3);
    // （2）删除中间节点
    delete_double_list(pRoot,5);
    // (3) 删除尾节点
    delete_double_list(pRoot,10);
    // 如果链表中只有一个节点的时候

    // 节点的遍历
    traversal_list(pRoot);

}

// destory_double_list()：
void destory_double_list(ListNode *pHead)
{
    ListNode *pNode = pHead;
    while (pNode->next != NULL){

    }
}

int main()
{
    ListNode *pRoot = creat_double_list();
    // 节点的插入
    insert_double_list(pRoot, 3);
//    insert_double_list(pRoot, 4);
//    insert_double_list(pRoot, 2);
    insert_double_list(pRoot, 5);
    insert_double_list(pRoot, 10);

    traversal_list(pRoot);
    Test_del(pRoot);
    return 0;
}
