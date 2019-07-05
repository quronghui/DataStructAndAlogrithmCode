// 面试题32（二）：分行从上到下打印二叉树
// 题目：从上到下按层打印二叉树，同一层的结点按从左到右的顺序打印，每一层打印到一行。
/*
*   1.解题思路：
        a. 和面试题31是一样的思路；
        b. 在打印换行的时候，需要知道每一层有多少个节点，需要两个变量进行表示；
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

    // 先入队根节点，将根节点的地址入队,修改Queue的接口，这样才可行
    BinaryTreeNode *pHead = pTreeRoot;
    enQueue(queue, pHead);  
    
    // 表示每一层多少个节点
    int nextLevel = 0;
    int printNumber = 1;    // 根节点不为空，算一个

    // 当队列不为空的时候，一直循环( return queue->front->pNext->mValue;)
    while(!is_empty(queue))
    {
        // 在出队打印的同时，将其左右两个子节点保存；
        BinaryTreeNode *pNode = first(queue);
        printf("%d\t", pNode->mValue);
        // 保存两个子节点
        if(pNode->pLeft){
            enQueue(queue, pNode->pLeft);
            nextLevel++;
        }
        if(pNode->pRight){
            enQueue( queue, pNode->pRight);
            nextLevel++;
        }
        // 出队一个元素；
        delQueue(queue);
        printNumber--;
        if(printNumber == 0 ){
            // 最后一个空格不打印
            if(nextLevel != 0){
                putchar('\n');
                printNumber = nextLevel;
            }
            nextLevel = 0;
        }
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


