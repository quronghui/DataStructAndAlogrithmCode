// 面试题26：树的子结构
// 题目：输入两棵二叉树A和B，判断B是不是A的子结构。
/*
*   1.解题思路 : 从上到下递归判断
    root的判断:使用bool指针
        a. 先判断 ATree-root and BTree-root 是否相等；
            1)不相等： ATree-left, or ATree-ringht 是否相等;
           2) 遍历 : 直到找到一个root相等； 
    ******在root不相同，且左右子树不同的时候，继续遍历树 A*******
    左右子树的判断：
        b. 在判断ATree-left and BTree-left 是否相等
        c. 在判断ATree-right and BTree-ringht 是否相等
    2.异常情况；
        a. 没有说是不是二叉搜索树，二叉搜索树没有重复节点, 还更好判断，不需要遍历； 
        b.  树的值类型

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Substructure_inTree TreeNode;
struct Substructure_inTree
{
    double  m_Value;    // 树的值的类型
    TreeNode *pLeft;
    TreeNode *pRight;
};

bool TreeLeftRight(TreeNode *ARoot, TreeNode *BRoot);
bool Equal(double num1, double num2);

/***************递归查找 ATree-root and BTree-root***************/
bool SubTreeRoot(TreeNode *ARoot, TreeNode *BRoot)
{   
    // 设置异常处理：通过全局变量的返回值进行
    bool result = false;    // 表示root不相同;

    // 这里只判断一次：当时谢了一个while循环，一直在报错；

    if( ARoot !=NULL && BRoot != NULL ){ 
        if(Equal(ARoot->m_Value, BRoot->m_Value))   // root相等，查看子树节点；
            result = TreeLeftRight(ARoot, BRoot);
        // 在root不相同，且左右子树不同的时候，继续遍历树 A
        if(!result)
            result = SubTreeRoot(ARoot->pLeft, BRoot);
        if(!result) 
            result = SubTreeRoot(ARoot->pRight, BRoot);
    }
    return result;
}

/****************在root相同的情况下：判断A/B树的左右子树是否相同*******************/
bool TreeLeftRight(TreeNode *ARoot, TreeNode *BRoot)
{   
    // 边界条件
    if(BRoot == NULL)   // 先检查B树
        return true;    // 当B树的左右子书为空时，只有根节点有值；
    if(ARoot == NULL)
        return false;   // 当B树的左右子书不为空时，A树左右子树为空

    // 每次递归调用时, 要判断节点的值是否相等;
    if( !Equal(ARoot->m_Value, BRoot->m_Value))
        return false;
    // 判断左右子树的结构是否相同
    return TreeLeftRight(ARoot->pLeft, BRoot->pLeft) && TreeLeftRight(ARoot->pRight, BRoot->pRight);
}

/*********************Equal double相等函数的判断********************/
bool Equal(double num1, double num2)
{
    if((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
        return true;
    else 
        return false;
}

/***********************构建两棵树二叉树*******************/
// 创建节点
TreeNode *CreatTreeNode(double value)
{
    TreeNode *pNode = malloc(sizeof(TreeNode));
    pNode->m_Value = value;
    pNode->pLeft = NULL;
    pNode->pRight = NULL;

    return pNode;
}
// 节点的链接
void ConnectTree(TreeNode *pPatent, TreeNode *left, TreeNode *right)
{
    if(pPatent != NULL){    // 左右子树是可以为空的
        pPatent->pLeft = left;
        pPatent->pRight = right;
    }
}
// Tree的删除
void DestoryTree(TreeNode *pRoot)
{   
    // 从上到下的释放，要保证树的连接不断开
    if(pRoot != NULL){
        TreeNode *left = pRoot->pLeft;
        TreeNode *right = pRoot->pRight;

        free(pRoot);
        pRoot = NULL;

        // 递归释放每一个节点
        DestoryTree(left);
        DestoryTree(right);
    }
}

/******************test code**********************/
void Test(char *name, TreeNode *ARoot, TreeNode *BRoot, bool expected)
{
    if(name != NULL)
        printf("%s begin:",name);
    if(SubTreeRoot(ARoot, BRoot) == expected)
        printf(" passed.\n");
    else 
        printf(" failed.\n");
}

// B树是A树的子树
void test1()
{
    // A树广度优先的节点顺序进行
    TreeNode *ANode1 = CreatTreeNode(8);
    TreeNode *ANode2 = CreatTreeNode(9);
    TreeNode *ANode3 = CreatTreeNode(2);
    // TreeNode *ANode4 = CreatTreeNode(9);
    // TreeNode *ANode5 = CreatTreeNode(2);
    // TreeNode *ANode6 = CreatTreeNode(4);
    // TreeNode *ANode7 = CreatTreeNode(7);
    // A树节点间的关系
    ConnectTree(ANode1, ANode2, ANode3);
    // ConnectTree(ANode2, ANode4, ANode5);
    // ConnectTree(ANode5, ANode6, ANode7);

    // B树的建立
    TreeNode *BNode1 = CreatTreeNode(8);
    TreeNode *BNode2 = CreatTreeNode(9);
    TreeNode *BNode3 = CreatTreeNode(2);
    // B树节点间关系建立
    ConnectTree(BNode1, BNode2, BNode3);

    // A ， B 树的测试
    Test("test1", ANode1, BNode1, true);

    DestoryTree(ANode1);
    DestoryTree(BNode1);
}

int main()
{
    test1();
    return 0;
}