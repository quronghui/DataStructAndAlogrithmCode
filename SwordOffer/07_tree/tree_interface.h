// 二叉搜索树的接口定义
// 在使用接口函数的时候，注意将Test函数注释

#ifndef TREE_INTERFACE_h
#define TREE_INTERFACE_h

#define TREE_TYPE   int         /* 树中节点的类型 */

typedef struct link_binary_search_tree BinaryTreeNode;
struct link_binary_search_tree
{
    TREE_TYPE           mValue;
    BinaryTreeNode    *pLeft;
    BinaryTreeNode    *pRight;
};

/*************construct_binary_tree 前序中序构建二叉树接口***********/
extern BinaryTreeNode *Construct(int *preorder, int *inorder, int length);

/******link_binary_search_tree 链表构建二叉树的接口*********/
extern void insert(TREE_TYPE value);   /* 二叉树的插入，默认不存在重复节点 */

extern TREE_TYPE *find(TREE_TYPE value);   /* 查找一个特定的值，插入节点的时候查看无重复，返回值指针 */

extern void pre_order_traverse( void (*callback)(TREE_TYPE value) );   /* 前序遍历二叉树：回调函数 */

void DestoryTree(BinaryTreeNode *pRoot);    /* 删除整棵树 */



#endif