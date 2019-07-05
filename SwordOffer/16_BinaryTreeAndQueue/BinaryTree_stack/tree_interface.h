// 二叉搜索树的接口定义
// 在使用接口函数的时候，注意将Test函数注释

#ifndef TREE_INTERFACE_h
#define TREE_INTERFACE_h

#define TREE_TYPE   int         /* 树中节点的类型 */

typedef struct link_binary_search_tree BinaryTreeNode;
struct link_binary_search_tree
{
    TREE_TYPE          mValue;
    BinaryTreeNode    *pLeft;
    BinaryTreeNode    *pRight;
};

/*************函数：construct_binary_tree 前序中序构建二叉树接口***********/
extern BinaryTreeNode *Construct(int *preorder, int *inorder, int length);


/******函数：link_binary_search_tree 链表构建二叉树的接口*********/
// 固定创建的二叉搜索树
extern BinaryTreeNode *CreateTree();// 我自己插入了一个二叉树

//单个节点创建后进行连接，可以不是二叉搜索树
extern  BinaryTreeNode *CreatTreeNode(double value);
extern void ConnectTree(BinaryTreeNode *pPatent, BinaryTreeNode *left, BinaryTreeNode *right);

 
extern void insert(TREE_TYPE value);   /* 二叉树的插入，默认不存在重复节点 */

extern TREE_TYPE *find(TREE_TYPE value);   /* 查找一个特定的值，插入节点的时候查看无重复，返回值指针 */

// 用户传递想要执行的回调函数：
extern void pre_order_traverse( BinaryTreeNode *pRoot, void (*callback)(TREE_TYPE value) );   /* 前序遍历二叉树：回调函数 */
extern void PrintTree( TREE_TYPE value );   // 打印每个节点值的函数

void DestoryTree(BinaryTreeNode *pRoot);    /* 删除整棵树 */


#endif