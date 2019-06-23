// 题目： 通过链式构建二叉搜索树

/*
*   1. insert:
        *current:用于检查树中的节点，寻找新值插入的合适位置；
        **link: 指向当前正在检查的节点
    2.find: 
        查找树种是否有和插入节点相同的节点；
    3.do_pre_order
        通过递归的方式：实现三种遍历的方式；
*/
#include "tree_interface.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct link_binary_search_tree TreeNode;
struct link_binary_search_tree
{
    TREE_TYPE   mValue;
    TreeNode    *left;
    TreeNode    *right;
};

static TreeNode *tree;  /* 指向根节点的指针 */

/*******************insert funcation*********************/
void insert(TREE_TYPE value)
{
    TreeNode    *current;
    TreeNode    **link;
    link = &tree;   /* link 指向tree指针的指针 */

    while( (current = *link) != NULL ){     /* 继续查找值，进入合适的子树 */
        if( value < current->mValue)
            link = &current->left;          /* 防止对值的修改，只进行地址的更改 */
        else{
            assert(value != current->mValue);   /* 二叉搜索树不能有重复节点 */
            link = &current->right;
        }
    }
    // 找到查找位置后怎么处理呢？
    current = malloc(sizeof(TreeNode));
    assert(current != NULL);
    current->mValue = value;
    current->left = NULL;
    current->right = NULL;
    
    *link = current;                        /* *link 表示tree树中的某一个位置 */
}

/********************find node**********************/
TREE_TYPE *find(TREE_TYPE value)
{
    TreeNode *current;
    current = tree; /* 从根节点开始，进入不同的子树 */

    while( current !=NULL && current->mValue != value ){

        if( value < current->mValue)
            current = current->left;
        else 
            current = current->right;
    }
    if( current != NULL)
        return &current->mValue;    /* 返回的值是地址，也是一个整形值 */
    else 
        return NULL;
}

/*******************前序遍历函数**********************/
static void do_pre_order_traverse(TreeNode *current, void (*callback)(TREE_TYPE value))
{
    if( current != NULL ){
        callback(current->mValue);       //前序遍历函数
        do_pre_order_traverse (current->left, callback);
        // callback(current->mValue);          //中序遍历函数
        do_pre_order_traverse (current->right, callback);
        // callback(current->mValue);          //后序遍历函数

    }
}
// 回调函数callback:功能实现函数；
static void pre_order_print( TREE_TYPE value )
{
    assert( value != 0 );
    printf("%d ", value);
}

// 用户接口，调用函数
void pre_order_traverse( void (*callback)(TREE_TYPE value) ){
    do_pre_order_traverse(tree, callback);
}

/*********************test funcation*************************/
void test()
{
    insert(8);
    insert(6);
    insert(10);
    insert(5);
    insert(7);
    insert(9);
    insert(11);

    do_pre_order_traverse(tree, pre_order_print);

    TREE_TYPE value = *find(10);    // 要学会看返回值的类型，根据类型写功能函数
    printf("%d", value);

}

int main()
{
    test();
    return 0;
}
