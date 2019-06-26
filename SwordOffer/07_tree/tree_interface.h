// 二叉搜索树的接口定义

#ifndef TREE_INTERFACE_h
#define TREE_INTERFACE_h

#define TREE_TYPE   int         /* 树种节点的值 */

void insert(TREE_TYPE value);   /* 二叉树的插入，不存在重复节点 */

TREE_TYPE *find(TREE_TYPE value);   /* 查找一个特定的值，看有无重复，返回值应该可以任意 */

void pre_order_traverse( void (*callback)(TREE_TYPE value) );   /* 回调函数 */

void delete(TREE_TYPE value);    /* 删除某一个节点 */ 

#endif