// 面试题54：二叉搜索树的第k个结点
// 题目：给定一棵二叉搜索树，请找出其中的第k大的结点。
/*
    1. 解题思路:
        a. 二叉搜索树的特点: left < root < right;
        b. 根据中序遍历, 数值顺序由小到大, 找出第k个大节点
    2. 测试有问题? 
        就第一个值能成功;
*/
#include "tree_interface.h"
#include <stdio.h>
#include <stdbool.h>
// 函数申明
BinaryTreeNode *KthNodeCore(BinaryTreeNode *pRoot, unsigned int k);

/******************kthNode interface*********************/
BinaryTreeNode *KthNode( BinaryTreeNode *pRoot, unsigned int k )
{
    // 第k大的节点, 保证k是>0
    if ( pRoot == NULL || k == 0 )
        return NULL;

    return KthNodeCore(pRoot, k);
}

/******************* 功能函数, 中序遍历**********************/
BinaryTreeNode *KthNodeCore( BinaryTreeNode *pRoot, unsigned int k)
{
    BinaryTreeNode *target = NULL;
    if(pRoot->pLeft != NULL)
        target = KthNodeCore(pRoot->pLeft, k);
    
    if(target == NULL){
        if(k == 1)
            target = pRoot;
        k--;
    }

    if(target == NULL && pRoot->pRight != NULL)
        target = KthNodeCore(pRoot->pRight, k);
    
    return target;
}

/**************Test code*****************/
void Test(char *name,  BinaryTreeNode *pRoot, unsigned int k, bool isNull, int expected )
{
    if(name != NULL)
        printf ("%s begin:  ", name);

    pre_order_traverse(pRoot, PrintTree);

    BinaryTreeNode *target = KthNode(pRoot, k);
    if( (isNull && target==NULL)  ||    (!isNull && target->mValue == expected)  )
        printf("Passed.\n");
    else 
        printf("Failed.\n");
}
// 完整二叉树
void Test1()
{
    BinaryTreeNode *pNode8 = CreatTreeNode(8);
    BinaryTreeNode *pNode6 = CreatTreeNode(6);
    BinaryTreeNode *pNode10 = CreatTreeNode(10);
    // BinaryTreeNode *pNode5 = CreatTreeNode(5);
    // BinaryTreeNode *pNode7 = CreatTreeNode(7);
    // BinaryTreeNode *pNode9 = CreatTreeNode(9);
    // BinaryTreeNode *pNode11 = CreatTreeNode(11);

    ConnectTree(pNode8, pNode6, pNode10);
    // ConnectTree(pNode6, pNode5, pNode7);
    // ConnectTree(pNode10, pNode9, pNode11);

    // Test
//            8
//        6      10
//       5 7    9  11
    // Test("TestA0", pNode8, 0, true, -1);
    Test("TestA1", pNode8, 1, false, 6);
    // Test("TestA2", pNode8, 2, false, 8);
    // Test("TestA3", pNode8, 3, false, 10);
    // Test("TestA4", pNode8, 4, false, 8);
    // Test("TestA5", pNode8, 5, false, 9);
    // Test("TestA6", pNode8, 6, false, 10);
    // Test("TestA7", pNode8, 7, false, 11);
    // Test("TestA8", pNode8, 8, true, -1);

    DestoryTree(pNode8);
    printf("\n\n");
}
// main
int main()
{
    Test1();
    return 0;
}

