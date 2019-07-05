// 面试题34：二叉树中和为某一值的路径
// 题目：输入一棵二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
// 从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
/*
*   1.解题思路
        a. 路径：起始于根节点，结束于叶子节点；
        b. 前序遍历：需要将路径中的节点进行入栈，作为路劲的保存
        c. 节点遍历后，需要回溯到上一个节点；
    2.注意的是：
        压入栈后的节点：如何顺序打印路径；
        方法：通过双栈模拟队列，实现栈的打印；
*/
#include "tree_interface.h"
#include "link_stack_interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 函数声明
void findTreepath(BinaryTreeNode *pRoot, int expectedSum, StackNode *path, int currentSum);
bool is_leaf(BinaryTreeNode *pNode);
/*****************用户接口函数********************/
void findPath(BinaryTreeNode *pRoot, int expectedSum)
{
    // 边界条件
    if(pRoot == NULL){
        printf("The tree is null.\n");
        return ;
    }
    // 创建一个栈空间；
    StackNode *path = link_create_stack();
    int currentSum = 0;

    findTreepath(pRoot, expectedSum, path, currentSum);
}

/********************路径查找功能函数**********************/
void findTreepath(BinaryTreeNode *pRoot, int expectedSum, StackNode *path, int currentSum)
{
    //先加入根节点的值
    currentSum += pRoot->mValue;
    // 和剑指offer上面的代码不同，我这里入栈的是节点，不是值
    push(path, pRoot);

    // 如果是叶子节点，并且值相等，则打印；
    if(currentSum == expectedSum && is_leaf(pRoot))
    {   
        // 让两个栈模拟队列，实现路径的打印
        StackNode *orderStack = link_create_stack();    // 用于顺序保存栈
        StackNode *record = path;
        // 入栈为顺序栈
        while( !is_empty(path)){
            push(orderStack, top(path));
            path = path->pNext;
        }
        // 顺序打印栈，双栈实现队列功能
        printf("The tree road is: \n");
        while( !is_empty(orderStack) ){
            BinaryTreeNode * pNode = top(orderStack);
            printf("%d\t", pNode->mValue);
            pop(orderStack);
        }
        printf("\n");

        // 恢复路径栈
        path = record;

        // 释放栈
        destory_stack(orderStack);
    }
    // 如果不是叶子节点，遍历左右节点
    if(pRoot->pLeft != NULL)
        findTreepath(pRoot->pLeft, expectedSum, path, currentSum);
    if(pRoot->pRight != NULL)
        findTreepath(pRoot->pRight, expectedSum, path, currentSum);

    // 返回父节点前，删除此节点；并且减去该节点的值
    currentSum -= pRoot->mValue;
    pop(path);
}   

// 叶子节点的判断
bool is_leaf(BinaryTreeNode *pNode)
{
    if(pNode->pLeft == NULL && pNode->pRight == NULL)
        return true;
    else 
        return false;
}

/*********************test code**********************/
void Test(char *name, BinaryTreeNode *pRoot, int expectedSum)
{
    if(name != NULL)
    printf("%s begins:\n", name);
    findPath(pRoot, expectedSum);
    printf("\n");
}
// 路劲中的和为22；
void test1()
{
    // 创建一棵树
    BinaryTreeNode *pRoot = CreateTree();
    //test
    Test("test1", pRoot, 22);

    DestoryTree(pRoot);
}
// main
int main()
{
    test1();
    return 0;
}