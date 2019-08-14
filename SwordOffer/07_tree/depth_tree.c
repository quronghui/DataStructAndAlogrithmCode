// 面试题55（一）：二叉树的深度
// 题目：输入一棵二叉树的根结点，求该树的深度。从根结点到叶结点依次经过的
// 结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
/*
    1. 解题思路一:　
        a. 和面试题34一样: 我们通过一个栈空间保存走过的路劲;
        b. 这样太麻烦了;
    2. 解题思路二:
        a. 通过递归的思路来解决:
        b. 如果一棵树只有一个节点, depth == 1;
        c. 如果一棵树有左子树和右子书, depth = 1+ (nleft > nright)? nleft : nright;
    3. 题目扩展: 
        求节点的高度;
*/
#include "tree_interface.h"
#include <stdio.h>

/**************通过递归和遍历的方法, 很快的找到最大的深度***************/
int depthTree(BinaryTreeNode *pRoot)
{
    if( pRoot == NULL )
        return 0;
    int nLeft   =   depthTree(pRoot->pLeft);
    int nRight  =   depthTree(pRoot->pRight);

    return (nLeft > nRight)? (nLeft+1) : ( nRight +1) ; 
}

/******************Test code*********************/
void Test( char *name, BinaryTreeNode *pRoot, int expected )
{
    if(name != NULL)
        printf("%s begin:   ", name);
    int result = depthTree(pRoot);
    if(result == expected)
        printf("Passed. The result == expected is %d.\n", result);
    else 
        printf("Failed. The result != expected is %d.\n", result);
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
    ConnectTree(pNode10, NULL, pNode11);

    Test("Test1", pNode8, 3);

    DestoryTree(pNode8);
    printf("\n\n");
}

// main
int main()
{   
    Test1();
    return 0;
}