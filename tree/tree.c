/* 
*   tree.c
*   二叉查找树：用关键字表示
*   1)find tree:查找到叶子节点，还没的话，返回NULL
*   2)find_min _max: 递归和非递归的方式进行实现；
*       非递归：考虑base基准情况
*   3) insert: 插入元素的关键字时：考虑tree是否为空；tree不为空时，元素是否已存在
*   4) delete_x: 遍历得到元素位置，还得考虑该位置包含两个child和一个child的情况、
*/
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

/* make empty tree */
SearchTree make_empty(SearchTree t)
{
    if(t != NULL){
        make_empty(t->left);
        make_empty(t->right);
        free(t);
    }
    return NULL;
}

/* find tree  查找到叶子节点，还没的话，返回NULL*/
position find(ElementType x, SearchTree t)
{
    if(t == NULL)
        return NULL;
    if(x < t->element)
        return find(x, t->left);    
    else if(x > t->element)
        return find(x, t->right);
    else
        return t;
}

/* find_min and find_max: 遍历到T最左边的叶子节点 */
/* 递归实现：考虑基准情况 */
position find_min(SearchTree t)
{
    if(t == NULL)
        return NULL;
    else if(t->left == NULL)
        return t;
    else
        return find_min(t->left);
}
/* 通过非递归实现 */
position find_max(SearchTree t)
{
    if(t != NULL)
        while(t->right != NULL)
            t = t->right;
    return t;
}

/* insert x : 比较的是关键字*/
SearchTree insert(ElementType x, SearchTree t)
{
    if(t == NULL){      /* 还没有树 */
        t = malloc(sizeof(struct TreeNode));
        if(t == NULL)
            printf("out of space!\n");
        else{
            t->element = x;
            t->left = t->right = NULL;
        }
    }
    else if(x < t->element)     /* 关键字插在左半部分 */
        t->left = insert(x, t->left);   
    else if(x > t->element)
        t->right = insert(x, t->right);
    
    /* else c is in the tree already, do nothing */
    return t; 
}

/* delet_x : */
SearchTree delete_x(ElementType x, SearchTree t)
{
    position tmpcell;

    if(t == NULL)
        printf("element not found");

    /* 遍历元素的过程 */
    else if(x < t->element)
        t->left = delete_x(x, t->left);
    else if(x > t->right)
        t->right = delete_x(x, t->right);
     
    /* 找到元素节点：判断其含有几个child */
    /* x == t->element */
    else if(t->left && t->right)    /* 有两个孩子节点：用最小的节点代替这个位置*/
    {
        tmpcell = find_min(t->right);
        t->element = tmpcell->element;
        t->right = delete_x(t->element, t->right);  /*要对删除后的元素建立连接关系 */
    }   
    else    /* 被删除的元素只有一个child */
    {       /* 连同子节点的位置一起删除 */
        tmpcell = t;
        if(t->left == NULL)
            t = t->left;    /*  */
        else if(t->right == NULL)
            t = t->right;
        free(tmpcell);
    }

    return t;
}