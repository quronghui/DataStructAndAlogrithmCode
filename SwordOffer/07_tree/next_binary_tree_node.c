// 面试题8：二叉树的下一个结点
// 题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
// 树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。

/*
*   1.题目提示：
        a. 中序遍的规则：父节点在中间访问；
        b. 每个节点有一个指向父节点的指针；
    2.解题思路:通过举例子得出具体情况
        a.pNode 节点有右子树：下一个节点是它右子树的最左节点；
        b.pNode 节点没有右子树：
            b1. pNode是它父节点的 左子节点： 下一个节点是它的父节点
            b2. pNode是它父节点的 右子节点： 先找到一个是 它 父节点的左子节点的节点；
                如果存在，那么这个节点的父节点便是下一个节点
            b3. 注意b1.b2最后的情况都是关于父节点的情况
    3.GetNext_Parameter
        pNode: 树中的节点
    4.辅助函数
        CreateBinaryTreeNode : 创建每一个节点，按照广度优先的方式排列
        ConnectTreeNode：       通过一个父节点，两个儿子节点，创建树的整个连接
        PrintTree 打印树中的节点： 父节点加两个子节点的方式打印
        DestoryTree：           释放整棵树
*/

typedef struct next_binary_tree_node BinaryTreeNode;

struct next_binary_tree_node
{
    int mValue;
    BinaryTreeNode *pLeft;
    BinaryTreeNode *pRight;
    BinaryTreeNode *pParent;
};

#include <stdio.h>
#include <stdlib.h>

/****************** 得到下一个节点 **********************/
BinaryTreeNode *GetNext(BinaryTreeNode *pNode)
{
    if(pNode == NULL){
        return NULL;
    }

    BinaryTreeNode *pNext = NULL;
    /* 解题a的情况 */
    if(pNode->pRight != NULL){
        BinaryTreeNode *nextringht = pNode->pRight;
        while(nextringht->pLeft != NULL)
            nextringht = nextringht->pLeft;     /* 右子树的最左节点 */
        pNext = nextringht; /* 右子树的中间节点 */
    }
    /* 解题b的情况 */
    else if(pNode->pParent != NULL){
        BinaryTreeNode *pCurrent = pNode;
        BinaryTreeNode *previous = pNode->pParent;
        /* b2情况作为判断的情况 */
        while(previous != NULL && pCurrent == previous->pRight){
            pCurrent = previous;
            previous = previous->pParent;
        }
        /* b3 情况 */
        pNext = previous;
    }
    return pNext;
}

/********************创建二叉树的单节点**********************/
BinaryTreeNode *CreateBinaryTreeNode(int value)
{
    BinaryTreeNode *pNode = malloc(sizeof(struct next_binary_tree_node));
    pNode->mValue = value;
    pNode->pLeft = NULL;
    pNode->pRight = NULL;
    pNode->pParent = NULL;

    return pNode;
}

/******************连接二叉树的节点：二叉树的连接，太不智能了，需要改一下******************/
// 父节点加上两个儿子节点
void ConnectTreeNode(BinaryTreeNode *parent, BinaryTreeNode *left, BinaryTreeNode *right)
{
    if(parent != NULL){
        parent->pLeft = left;
        parent->pRight = right;

        /* 题目中提示有指向父节点的指针 */
        if(left != NULL)
            left->pParent = parent;
        if(right != NULL)
            right->pParent = parent;
    }
}

/**************打印二叉树节点****************/
/* 打印树中的某一个节点 */
void PrintTreeNode(BinaryTreeNode *pNode)
{
    if(pNode != NULL){
        printf("value of this node is: %d\n", pNode->mValue);

        if(pNode->pLeft != NULL)
            printf("value of its left child is %d.\n", pNode->pLeft->mValue);
        else 
            printf("left child is null.\n");
        if(pNode->pRight != NULL)
            printf("value of its ringht child is %d.\n", pNode->pRight->mValue);
        else 
            printf("right child is null.\n");
    }
    else 
        printf("this node is null.\n");
    printf("\n");
}

/* 前序遍历打印树 */
void PrintTree(BinaryTreeNode *pRoot)
{
    PrintTreeNode(pRoot);
    
    if(pRoot != NULL){
        if(pRoot->pLeft != NULL)
            PrintTree(pRoot->pLeft);    /* 左子树打印 */
        if(pRoot->pRight != NULL)
            PrintTree(pRoot->pRight);
    }
}

/*******************删除二叉树********************/
// 二叉树的释放, 先释放根节点, 在释放左右子树
void DestoryTree(BinaryTreeNode *pRoot)
{
    if(pRoot != NULL){

        BinaryTreeNode *left = pRoot->pLeft;
        BinaryTreeNode *right = pRoot->pRight;
        /* free 释放指针 */
        free(pRoot);

        DestoryTree(left);
        DestoryTree(right);
    }
}

/**********************************************/
/****************Test code*********************/
void Test(char *name, BinaryTreeNode *pNode, BinaryTreeNode *expected)
{
    if(name != NULL)
        printf("%s begins: ", name);
    
    BinaryTreeNode *pNext = GetNext(pNode);
    if(pNext == expected)
        printf("Passed.\n");
    else 
        printf("failed\n");
}

void test1_7node()
{   
    /* 按照广度优先的方式，创建节点 */
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

    /* 连接节点 */
    ConnectTreeNode(pNode8, pNode6, pNode10);
    ConnectTreeNode(pNode6, pNode5, pNode7);
    ConnectTreeNode(pNode10, pNode9, pNode11);

    /* 打印树的结构 */
    PrintTree(pNode8);

    /* test 下一个节点 */
    Test("test1", pNode8, pNode9);
    Test("Test2", pNode6, pNode7);
    Test("Test3", pNode10, pNode11);
    Test("Test4", pNode5, pNode6);
    Test("Test5", pNode7, pNode8);
    Test("Test6", pNode9, pNode10);
    Test("Test7", pNode11, NULL);


    DestoryTree(pNode8);
}

int main()
{
    test1_7node();
    return 0;
}

//main_error.png