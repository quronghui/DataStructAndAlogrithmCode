// 面试题7：重建二叉树
// 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
//例如输入前序遍历序列{1, 2, 4, 7, 3, 5, 6, 8}和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}，则重建出二叉树并输出它的头结点。

/*
*   1.题目信息：
        a. 根据两个数组，构建一颗二叉树；
        b. 不含重复的数字。
    2.解题目思路
        a. 前序遍历数组和中序遍历数组 与树的关系；
    3. Construct_Parameter:
        *preorder   前序遍历数组；
        *inorder    中序便利的数组；
        length      作为数组访问的下标，数组长度
    4. ConstructTree_Parameter
        *startPreorder -- preorder          指向前序数组第一个元素
        *endPreorder -- preorder+length-1   指向前序数组最后一个元素
        *startInorder  --  inorder          指向中序数组第一个元素
        *endInorder  --  inorder+length-1   指向中序数组最后一个元素
    5. 递归的条件
        a.根据前序遍历的第一个值，在中序遍历中找出位置； 
        b.根据中序遍历的root，划分出左右子树的长度；
        c.递归划分 ConstructTree_Parameter 四个参数，完成二叉树的构建
*/

typedef struct construct_binary_tree BinaryTreeNode;

struct construct_binary_tree
{
    int mValue;
    BinaryTreeNode *pLeft;
    BinaryTreeNode *pRight;
};

#include <stdio.h>
#include <stdlib.h>

#define arrayLength 8

/*  */
BinaryTreeNode *ConstructTree(int *startPreorder, int *endPreorder, int *startInorder, int *endInorder);

/* 两个遍历数组传入函数Construct，用来调用ConstructTree */
BinaryTreeNode *Construct(int *preorder, int *inorder, int length)
{
    if(preorder == NULL || inorder == NULL || length <=0){
        printf("Input preorder_tree or inorder_tree is invaild\n");
        return NULL;
    }
    return ConstructTree(preorder, preorder+length-1, inorder, inorder+length-1);   /* 指针加1，指向数组中的下一个元素 */
}

/* ConstructTree : 创建四个指针，指向数组的最开始和结束为止 */
BinaryTreeNode *ConstructTree(int *startPreorder, int *endPreorder, int *startInorder, int *endInorder)
{
    /* 前序遍历中第一个元素，便是树的根节点值 */
    int rootValue = startPreorder[0];
    BinaryTreeNode *root = malloc(sizeof(struct construct_binary_tree));
    root->mValue = rootValue;
    root->pLeft = root->pRight = NULL;

    /* 只有一个节点的树 */
    if(startPreorder == endPreorder){
        if(startInorder == endInorder && *startPreorder == *startInorder){
            printf("Tree is only have one Node\n");
            return root;
        }
        // else{ 
        //     printf("startPreorder == endPreorder is a invaild input\n");
        //     // return NULL;
        // }
    }

    /* 在中序遍历中找到根节点 */
    int *rootInorder = startInorder;

    while(rootInorder <= endInorder && *rootInorder != rootValue)   /* 找出根节点在中序遍历数组的位置 */
        ++rootInorder;

    if(rootInorder == endInorder && *rootInorder != rootValue){     
        printf("Inorder is a invaild input\n");
        return NULL;
    }

    int leftLength = rootInorder - startInorder;    /* 求出左子树在中序遍历数组的长度  */
    int *leftPreorderEnd = startInorder + leftLength;

    if(leftLength > 0){
        //构建左子树,前序遍历和中序遍历的数组，只在左边进行
        root->pLeft = ConstructTree(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
    }
    if(leftLength < endPreorder - startPreorder){
        // 构建右子树
        root->pRight = ConstructTree(leftPreorderEnd+1, endPreorder, rootInorder+1, endInorder);
    }
    return root;
}

/*******************test code****************************/
// void print(BinaryTreeNode *tree)
// {
//     int depth = 0;
//     if(tree -> pLeft != NULL || tree->pRight !=NULL)
//         depth++;
    
// }
void test()
{
    //const int length = 9;   /*使用变量定义长度时，不可在定义时同时进行初始化赋值，需要在之后进行赋值*/
    int preorder[arrayLength] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[arrayLength] = {4, 7, 2, 1, 5, 3, 8, 6};

    printf("The preorder sequence is: ");
    for(int i=0; i<arrayLength; ++i)
        printf("%d ",preorder[i]);
    printf("\n");

    printf("The inorder sequence is: ");
    for(int i=0; i<arrayLength; ++i)
        printf("%d ",inorder[i]);
    printf("\n");

    BinaryTreeNode *root = Construct(preorder, inorder, arrayLength);

    /* 二叉树的打印 */
    printf("\t %d\n", root->mValue);
    printf("%d\n", root->pLeft->mValue);

}

int main()
{
    test();
    return 0;
}