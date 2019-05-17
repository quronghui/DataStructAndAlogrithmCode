/*
*   tree.h
*   1)树的操作，类似于栈指针的操作
*/
#ifndef TREE_H
#define TREE_H

typedef char ElementType;
typedef struct TreeNode *position;
typedef struct TreeNode *SearchTree;

SearchTree make_empty(SearchTree t);
position find(ElementType x, SearchTree t); /* 查找过程中的赋值，从新定义指针进行操作 */
position find_min(SearchTree t);
position find_max(SearchTree t);

SearchTree insert(ElementType x, SearchTree t);
SearchTree delete_x(ElementType x, SearchTree t);

ElementType retriece(position p);   /* 取回的是位置参数，不是元素本身 */

#endif

/* struct file */
struct TreeNode
{
    ElementType element;
    SearchTree left;
    SearchTree right;
};
