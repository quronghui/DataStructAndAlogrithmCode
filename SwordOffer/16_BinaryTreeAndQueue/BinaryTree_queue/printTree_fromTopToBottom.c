// 面试题32（一）：不分行从上往下打印二叉树
// 题目：从上往下打印出二叉树的每个结点，同一层的结点按照从左到右的顺序打印。
/*
*   1.解题思路：
        a. 建立一个队列进行存储；
        b. 打印根节点时，顺序入队两个左右子节点；
    2.遇到的问题
        a. 入队的节点是树的节点：这个可以通过改变Queue接口中的QUEUE_TYPE, 修改成BinaryTreeNode * 这样解决；
        b. 但是入队后，队列执行一次后就判断为空: 我一开始写的queue.c有问题，queue->rear没有处理好；
*/
#include "tree_interface.h"
#include "link_queue_interface.h"
#include <stdio.h>
#include <stdlib.h>
 

/***************二叉树的广度优先遍历打印*******************/
void printTree(BinaryTreeNode *pTreeRoot)
{
    // 边界条件
    if(pTreeRoot == NULL){
        printf("The tree is null.\n");
        return ;
    }
    // 创建一个链式队列
    QueueNode *queue = create_queue();

    BinaryTreeNode *pHead = pTreeRoot;
    // 先入队根节点，将根节点的地址入队,修改Queue的接口，这样才可行
    enQueue(queue, pHead);  

    // 当队列不为空的时候，一直循环( return queue->front->pNext->mValue;)
    while(!is_empty(queue))
    {
        // 在出队打印的同时，将其左右两个子节点保存；
        BinaryTreeNode *pNode = first(queue);
        delQueue(queue);
        printf("%d\t", pNode->mValue);
        // 保存两个子节点
        if(pNode->pLeft)
            enQueue(queue, pNode->pLeft);
        if(pNode->pRight)
            enQueue( queue, pNode->pRight);
    }
    destory_queue(queue);
}

/****************test code*******************/
void test()
{
    // 创建一颗二叉树
    BinaryTreeNode *pRoot = CreateTree();
    // pre_order_traverse(pRoot, PrintTree);
    
    printTree(pRoot);
    printf("\n");

    DestoryTree(pRoot);
}
// main
int main()
{
    test();
    return 0;
}


