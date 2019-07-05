// 面试题32（三）：之字形打印二叉树
// 题目：请实现一个函数按照之字形顺序打印二叉树;
// 即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。
/*
*   1.解题思路：
        a. 之字形打印的思路：通过画图能看出来
        b. 通过栈实现：两个栈结构进行打印
        c. 保存节点的顺序
            打印奇数层：左子节点 --> 右子节点
            打印偶数层：右子节点 --> 左子节点
        d. 需要记录打印的层数；
        e. 之字型打印：默认要分行
            把一个栈打印完了之后就可以分行，不用去记录每一层多少个
*/
#include "tree_interface.h"
#include "link_stack_interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/***************之字形打印树的节点*****************/
void printZigzag(BinaryTreeNode *pRoot)
{
    // 边界条件
    assert( pRoot != NULL);
    // 创建两个栈空间
    StackNode *stack1 = link_create_stack();
    StackNode *stack2 = link_create_stack();
    StackNode *level[] = { stack1, stack2 };
    
    // 标志打印的层数，表示每一层多少个节点
    int current = 0;    // 表明第几个栈
    int next = 1;    
    
    //根节点进行入栈
    BinaryTreeNode *pHead = pRoot;
    push(level[current], pHead);

    //从第二层开始进行判断；
    while ( !is_empty(level[0]) || !is_empty(level[1]) )
    {
        // 将第一个栈的元素出栈；并将第二层的元素push到stack2
        BinaryTreeNode *pNode = top(level[current]);
        pop(level[current]);
        int value = pNode->mValue;
        printf("%d\t", value);        
        // printf("%d\t", pNode->mValue);

        // 根据栈的顺序，判断节点保存的顺序
        if(current == 0){
            if(pNode->pLeft != NULL)
                push(level[next], pNode->pLeft);
            if(pNode->pRight != NULL)
                push(level[next], pNode->pRight);
        }
        else{
            if(pNode->pRight != NULL)
                push(level[next], pNode->pRight);
            if(pNode->pLeft != NULL)
                push(level[next], pNode->pLeft);
        }
        // 打印完每一个栈空间，才换另外一个栈空间；
        if(is_empty(level[current])){   
            putchar('\n');
            current = 1 - current;
            next = 1- next;
        }
    }     
}

/****************test code*******************/
void test()
{
    // 创建一颗二叉树
    BinaryTreeNode *pRoot = CreateTree();
    // pre_order_traverse(pRoot, PrintTree);
    
    printZigzag(pRoot);
    printf("\n");

    DestoryTree(pRoot);
}
// main
int main()
{
    test();
    return 0;
}

