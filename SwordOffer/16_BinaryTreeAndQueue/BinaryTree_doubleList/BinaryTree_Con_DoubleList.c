// 面试题36：二叉搜索树与双向链表
// 题目：输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
// 要求不能创建任何新的结点，只能调整树中结点指针的指向。转换为的链表是排序
/*
*   1.题目注意：
        a. 不能创建新的任何节点：意味着我们在遍历的时候，就需要对每一个节点进行转换（节点需要动态分配，指针初始化一个地址）
        b. 转换为的转换为的链表是排序：选择中序遍历
    2.解题思路：
        a. 带头指针的双向链表,可以双向的访问：第一个节点的前指针fwd = null; 最后一个节点的pwd = phead; 
            但是题目说不能创建新的节点；所以不能创建phead。
            1) 建立两个指针：一个指向头结点，用于反回给用户；
        b. 将树中的每一个节点：
            指向左子树的指针：指向前一个节点；
            指向右子树的指针：指向后一个节点
            左子树中最大节点 --> 指向根节点 --> 右子树中的最小节点 
        c. 算法：递归实现
*/
#include "tree_interface.h"
#include <stdio.h>
#include <stdlib.h>

// 函数声明
void ConvertNode(BinaryTreeNode *pNode, BinaryTreeNode **pLastNode_inList);

/***************用户接口函数*****************/
BinaryTreeNode *Convert(BinaryTreeNode *pRootTree)
{
    BinaryTreeNode *pLastNode_inList = NULL;    
    ConvertNode(pRootTree, &pLastNode_inList);  // 防止空指针被修改

    // pLastNode_inList 指向双向链表的尾节点；中序遍历中的最后一个节点
    BinaryTreeNode *pHeadOfList = pLastNode_inList; // 将双向链表的尾节点赋值给头指针
   
    // pHeadOfList->pLeft指向前一个节点
    while( pHeadOfList != NULL && pHeadOfList->pLeft != NULL )
        pHeadOfList = pHeadOfList->pLeft;   // 得到中序遍历中的第一个节点
    
    return pHeadOfList;
}

/******************转换每一个节点*********************/
// pLastNode_inList 从中序遍历中第一个节点到最后一个节点；
void ConvertNode(BinaryTreeNode *pNode, BinaryTreeNode **pLastNode_inList)
{
    if(pNode == NULL){
        printf("The binaryTree is null.\n");
        return;
    }
    // 进行中序遍历
    BinaryTreeNode *current = pNode;
    /***************遍历左子树*************/
    if(current->pLeft != NULL)
        ConvertNode(current->pLeft, pLastNode_inList);
    
    //左子树：构建和根节点的指向关系
    // 改变树节点：的左指针为指向前一个节点的值；右指针指向后一个(中序遍历-根节点)节点
    current->pLeft = *pLastNode_inList;
    if( *pLastNode_inList != NULL)
        (*pLastNode_inList)->pRight = current;
    
    // 得到中序遍历中的每一个节点；
    *pLastNode_inList = current;  

    /**************遍历右子树*******************/
    if(current->pRight != NULL)
        ConvertNode(current->pRight, pLastNode_inList);
}

/**********************打印双向链表*************************/
void PrintDoubleLinkedList(BinaryTreeNode* pHeadOfList)
{
    BinaryTreeNode *pNode = pHeadOfList;

    // 从左到右打印链表；
    printf("The nodes from left to right are:\n");
    while( pNode != NULL ){
        printf("%d ", pNode->mValue);
        if(pNode->pRight == NULL)
            break;
        pNode = pNode->pRight;
    }
    // 从右到左打印链表
    printf("\n The nodes from right to left are:\n");
    while (pNode != NULL){       
        // 此时pNode 指向最后一个节点；
        printf("%d ", pNode->mValue);
        if(pNode->pLeft == NULL)
            break;
        pNode = pNode->pLeft;
    } 
    printf("\n");
}
/**********************双向链表的释放********************/
void Destory_doubleList(BinaryTreeNode *pHeadList)
{
    BinaryTreeNode *pNode = pHeadList;

    while(pNode != NULL){
        BinaryTreeNode *pNext = pNode->pRight;

        free(pNode);
        pNode = pNext;
    }
}

/******************test code*******************/
void Test(char *name, BinaryTreeNode *pRootTree)
{
    if(name != NULL)
        printf("%s begins: \n", name);
    // 中序遍历树
    pre_order_traverse(pRootTree, PrintTree);
    printf("\n");
    
    // 二叉搜索树，转换为双链表
    BinaryTreeNode *pHeadList = Convert(pRootTree);

    PrintDoubleLinkedList(pHeadList);

    Destory_doubleList(pHeadList);
}

// test1
void test1()
{
    // 创建二叉树
    BinaryTreeNode *pRootTree = CreateTree();

    Test("test1", pRootTree);
}

// main
int main()
{
    test1();
    return 0;
}