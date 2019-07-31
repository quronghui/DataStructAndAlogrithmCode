// 面试题55（二）：平衡二叉树
// 题目：输入一棵二叉树的根结点，判断该树是不是平衡二叉树。如果某二叉树中
// 任意结点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
/* 
    1. 解题思路一:
        a. 可以使用面试题55(一)depthTree()的方法;
        b. 对每一个节点的左右子数都进行一次判断;
        c. 这样会对同一个节点遍历多次;
    2. 解题思路二:
        a. 使用递归和后序遍历的思路进行解题: 只需要遍历一次
        b. 在后序遍历的时候, 记录每个节点的最大的深度
*/
#include "tree_interface.h"
#include <stdio.h>
#include <stdbool.h>

/*************解题思路一:*****************/
int depthTree(BinaryTreeNode *pRoot)
{
    if( pRoot == NULL )
        return 0;
    int nLeft   =   depthTree(pRoot->pLeft);
    int nRight  =   depthTree(pRoot->pRight);

    return (nLeft > nRight)? (nLeft+1) : ( nRight +1) ; 
}

// 每个节点都判断一次左右子树
bool isBanlancedSolution1(BinaryTreeNode *pRoot)
{
    if(pRoot == NULL)
        return true;
    int left = depthTree(pRoot->pLeft);
    int right = depthTree(pRoot->pRight);
    int diff = left -right;

    if( diff > 1 || diff < -1 )
        return false;
    return isBanlancedSolution1(pRoot->pLeft) && isBanlancedSolution1(pRoot->pRight);
}

/************* 解题思路二::*****************/
bool isBalancedSolution2(BinaryTreeNode *pRoot, int *pDepth)
{
    if(pRoot == NULL){
        *pDepth = 0;
        return true;
    }

    int left , right;
    if( isBalancedSolution2(pRoot->pLeft, &left)    &&    isBalancedSolution2(pRoot->pRight, &right) ){
        int diff = left - right;
        if( diff <= 1 && diff >= -1 ){
            *pDepth = 1 + ((left > right) ? left : right);
            return true;
        }
    }
    return false;
}
// 用户接口函数
bool isBanlanced(BinaryTreeNode *pRoot)
{
    int depth = 0;  //用于记录节点
    return isBalancedSolution2(pRoot, &depth); 
}


/*******************test code*****************/
void Test(const char* testName,  BinaryTreeNode* pRoot, bool expected)
{
    if(testName != NULL)
        printf("%s begins:\n", testName);

    printf("Solution1 begins: ");
    if(isBanlancedSolution1(pRoot) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");

    printf("Solution2 begins: ");
    if(isBanlanced(pRoot) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// test1
void Test1()
{
    BinaryTreeNode *pNode8 = CreatTreeNode(8);
    BinaryTreeNode *pNode6 = CreatTreeNode(6);
    BinaryTreeNode *pNode10 = CreatTreeNode(10);
    BinaryTreeNode *pNode5 = CreatTreeNode(5);
    BinaryTreeNode *pNode7 = CreatTreeNode(7);
    BinaryTreeNode *pNode9 = CreatTreeNode(9);
    BinaryTreeNode *pNode11 = CreatTreeNode(11);

    ConnectTree(pNode8, pNode6, pNode10);
    ConnectTree(pNode6, pNode5, pNode7);
    ConnectTree(pNode10, pNode9, pNode11);

    Test("Test1", pNode8, true);

    DestoryTree(pNode8);
    printf("\n\n");
}

// main
int main()
{
    Test1();
    return 0;
}