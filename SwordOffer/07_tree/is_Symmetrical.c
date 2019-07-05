// 面试题28：对称的二叉树
// 题目：请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。
// 不是二叉搜索树
/*
*   1. 思路一：
        a. 利用以前的代码：先将树A进行镜像，得到树B; mirror_recursively_binatyTree.c
        b. 然后判断 树A 和树 B 的结构是否一样 Substructure_inTree.c
        c. 也可以通过前序遍历得到两棵树的数组，比较数组是否相同；
    2. 思路二：
        a. 不用直接得到镜像的树B，假定一种遍历方式：先遍历root，然后遍历右子树，最后遍历左子书；
        b. 在遍历的时候，同时判断和 A树的关系
        c. 特殊情况
            Aroot 树为空 ，镜像树对应相等
            树中某一些节点为NULL，这时候镜像树是不对称的;
*/
#include <stdio.h>
#include <stdbool.h>
#include "tree_interface.h"

// 函数声明
bool TreeLeftRight(BinaryTreeNode *ARoot, BinaryTreeNode *BRoot);
/****************************思路二***********************************/
/***************递归查找 ATree-root ***************/
// 镜像的树 B 根节点是一定相同的
bool isSymmerticalRoot(BinaryTreeNode *ARoot)
{   
    return TreeLeftRight(ARoot, ARoot);
}

/****************在root相同的情况下：判断A, 和镜像树B的 左右子树*******************/
bool TreeLeftRight(BinaryTreeNode *ARoot, BinaryTreeNode *BRoot)
{   
    if(ARoot == NULL && BRoot == NULL)   // Aroot 树为空 
        return true;    
    
    if(ARoot == NULL || BRoot == NULL)  // 树中某一些节点为null，这时候镜像树是不对称的
        return false;   

    // 判断值是否相同
    if( ARoot->mValue != BRoot->mValue)
        return false;

    // 遍历树 B 的时候，通过一种新的遍历方式
    return TreeLeftRight(ARoot->pLeft, BRoot->pRight) && TreeLeftRight(ARoot->pRight, BRoot->pLeft);
}

/****************TEST CODE*******************/
void Test(char *name, BinaryTreeNode *pRoot, bool expected)
{
    if(name != NULL)
        printf("%s begins: ", name);
    if(isSymmerticalRoot(pRoot) == expected)
        printf("passed.\n");
    else 
        printf("failed.\n");
}
//            8
//        6      6
//       5 7    7 5
// 建立一棵对称树
void test1()
{
    // 创建一棵树, 不能通过二叉搜索树，因为有重复节点；
    BinaryTreeNode *pNode1 = CreatTreeNode(8);
    BinaryTreeNode *pNode2 = CreatTreeNode(6);
    BinaryTreeNode *pNode3 = CreatTreeNode(6);
    BinaryTreeNode *pNode4 = CreatTreeNode(5);
    BinaryTreeNode *pNode5 = CreatTreeNode(7);
    BinaryTreeNode *pNode6 = CreatTreeNode(7);
    BinaryTreeNode *pNode7 = CreatTreeNode(5);

    ConnectTree(pNode1, pNode2, pNode3);
    ConnectTree(pNode2, pNode4, pNode5);
    ConnectTree(pNode3, pNode6, pNode7);
    
    pre_order_traverse(pNode1, PrintTree);
    putchar('\n');

    Test("test1", pNode1, true);

    DestoryTree(pNode1);
}

// main
int main(void)
{
    test1();
    return 0;
}