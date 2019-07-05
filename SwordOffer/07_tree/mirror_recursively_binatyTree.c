// 面试题27：二叉树的镜像
// 题目：请完成一个函数，输入一个二叉树，该函数输出它的镜像。
/*
*   1.解题思路：
        a.镜像的概念：从根节点开始，根节点含有左 or 右子树；交换左右子树；
        b.判断条件：root->pLeft != NULL || root->pRight != NULL;
*/
#include <stdio.h>
#include <stdlib.h>
#include "tree_interface.h"

/********************镜像二叉树***********************/
void MirrorRecursively(BinaryTreeNode *pRoot)
{
    // 边界条件
    if( pRoot == NULL ){
        printf("The binaryTree is null.\n");
        return ;
    }
    // 满足可镜像交换的条件
    if(pRoot->pLeft == NULL && pRoot->pRight == NULL){
        // printf("The binaryTree leftTree and ringhtTree are null.\n");
        return ;
    }
    // 进行交换；
    BinaryTreeNode *Temp = pRoot->pLeft;
    pRoot->pLeft = pRoot->pRight;
    pRoot->pRight = Temp;
    // 递归左右子树
    if(pRoot->pLeft)
        MirrorRecursively(pRoot->pLeft);
    if(pRoot->pRight)
        MirrorRecursively(pRoot->pRight);
}

/*******************test code********************/
void test()
{
    // 创建二叉树
    BinaryTreeNode *pRoot =  CreateTree();  // 创建一颗二叉树；
    // 前序遍历
    pre_order_traverse(PrintTree);
    putchar('\n');

    //镜像二叉树；
    MirrorRecursively(pRoot);
    
    //镜像之后就不是二叉树了
    pre_order_traverse(PrintTree);
    putchar('\n');

}
int main(void)
{
    test();
    return 0;
}