// 题目： 通过链式 构建二叉搜索树
// C 和指针上面的内容:
// 在函数内部创建了一棵静态树，

/*
*   1. insert:
        *current:用于检查树中的节点，寻找新值插入的合适位置；
        **link: 指向当前正在检查的节点
    2.find: 
        查找树种是否有和插入节点相同的节点；
    3.do_pre_order
        通过递归的方式：实现三种遍历的方式；
    4. delete_node
        删除某一个节点，有三种情况
*/
#include "tree_interface.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
// #include "link_queue_Binary.h"

static BinaryTreeNode *tree;  /* 指向根节点的指针 */

/*******************insert funcation*********************/
//二叉树的插入，默认不存在重复节点
void insert(TREE_TYPE value)
{
    BinaryTreeNode    *current;
    BinaryTreeNode    **link;
    link = &tree;   /* link 指向tree指针的指针 */

    while( (current = *link) != NULL ){     /* 继续查找值，进入合适的子树 */
        if( value < current->mValue)
            link = &current->pLeft;          /* 防止对值的修改，只进行地址的更改 */
        else{
            assert(value != current->mValue);   /* 二叉搜索树不能有重复节点 */
            link = &current->pRight;
        }
    }
    // 找到查找位置后怎么处理呢？
    current = malloc(sizeof(BinaryTreeNode));
    assert(current != NULL);
    current->mValue = value;
    current->pLeft = NULL;
    current->pRight = NULL;
    
    *link = current;                        /* *link 表示tree树中的某一个位置 */
}

/********************find node**********************/
//查找一个特定的值，插入节点的时候查看无重复，返回值应该可以任意
TREE_TYPE *find(TREE_TYPE value)
{
    BinaryTreeNode *current;
    current = tree; /* 从根节点开始，进入不同的子树 */

    while( current !=NULL && current->mValue != value ){

        if( value < current->mValue)
            current = current->pLeft;
        else 
            current = current->pRight;
    }
    if( current != NULL)
        return &current->mValue;    /* 返回的值是地址，也是一个整形值 */
    else 
        return NULL;
}

/*******************前、中、后序遍历函数**********************/
void do_pre_order_traverse(BinaryTreeNode *current, void (*callback)(TREE_TYPE value))
{
    if( current != NULL ){
        callback(current->mValue);       //前序遍历函数
        do_pre_order_traverse (current->pLeft, callback);
        // callback(current->mValue);          //中序遍历函数
        do_pre_order_traverse (current->pRight, callback);
        // callback(current->mValue);          //后序遍历函数

    }
}

// 回调函数callback:功能实现函数；打印每一个节点的值
void PrintTree( TREE_TYPE value )
{
    assert( value != 0 );
    printf("%d ", value);
}

// 用户接口;前序遍历二叉树; 
//void (*callback)(TREE_TYPE value) 指针函数，接收的是函数
void pre_order_traverse(BinaryTreeNode *pRoot, void (*callback)(TREE_TYPE value) ){
    do_pre_order_traverse(pRoot, callback);
}

/************************删除树********************************/
// Tree的删除
void DestoryTree(BinaryTreeNode *pRoot)
{   
    // 从上到下的释放，要保证树的连接不断开
    if(pRoot != NULL){
        BinaryTreeNode *left = pRoot->pLeft;
        BinaryTreeNode *right = pRoot->pRight;

        free(pRoot);
        pRoot = NULL;

        // 递归释放每一个节点
        DestoryTree(left);
        DestoryTree(right);
    }
}

/*****************根据每一个节点，构建二叉树*******************/
// 创建节点
BinaryTreeNode *CreatTreeNode(double value)
{
    BinaryTreeNode *pNode = malloc(sizeof(BinaryTreeNode));
    pNode->mValue = value;
    pNode->pLeft = NULL;
    pNode->pRight = NULL;

    return pNode;
}
// 节点的链接
void ConnectTree(BinaryTreeNode *pPatent, BinaryTreeNode *left, BinaryTreeNode *right)
{
    if(pPatent != NULL){    // 左右子树是可以为空的
        pPatent->pLeft = left;
        pPatent->pRight = right;
    }
}


// 固定的创建二叉树
BinaryTreeNode *CreateTree()
{
    insert(8);
    insert(6);
    insert(10);
    insert(5);
    insert(7);
    insert(9);
    insert(11);

    return tree;
}

/*********************test funcation*************************/
// void test()
// {
// //     // insert(8);
// //     // insert(6);
// //     // insert(10);
// //     // insert(5);
// //     // insert(7);
// //     // insert(9);
// //     // insert(11);

//     CreateTree();   // 在插入节点的时候，进行二叉树的构建；

//     pre_order_traverse(PrintTree);  // 通过回调函数实现
//     // do_pre_order_traverse(tree, callback);
//     printf("\n");

//     TREE_TYPE value = *find(10);    // 要学会看返回值的类型，根据类型写功能函数
//     printf("%d\n", value);

// }

// int main()
// {
//     test();
//     return 0;
// }
