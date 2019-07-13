/*
*   tree_avl.c
*/

#include "tree_avl.h"
#include <stdio.h>
#include <stdlib.h>

/* 计算AVL的height */
static Height(position p)
{
    if(p == NULL)
        return -1;
    else 
        return p->height;
}

/* insert node */
AvlTree insert(ElementType x, AvlTree t)
{   
    /* 插入节点x */
    if(t == NULL){
        t = malloc(sizeof(struct AvlNode));
        if(t == NULL)
            printf("out of space!!\n");
        else{               
            t->element = x;     
            t->height = 0;
            t->left = t->right = NULL;
        }
    }
    /*insert left*/
    else if(x < t->element){
        t->left = insert(x, t->left);   /* 找到插入的位置.遍历到叶子节点 */

        /* 破坏了avl平衡 */
        if( Height(t->left) - Height(t->right) == 2){
            if(x < t->left->element)    
                t = single_rotate_withleft(t);  /* 第一种插入：左左 */
            else
                t = double_rotate_withleft(t);  /* 第二种插入：左右 */
        }
    }
    /*insert right*/
    else if(x > t->element){
        t->right = insert(x, t->right);
        
        if(Height(t->right) - Height(t->left) ==2 ){
            if(x > t->right->element)
                t = single_rotate_withleft(t);  /* 第四种插入：和第一种对称 右右 */
            else 
                t = double_rotate_withleft(t);
        }
    }

    /* if x is the tree already;we'll do nothing */
    t->height = Max(Height(t->left), Height(t->right)) + 1; /* 给出一个height判断 */
    return t;
}

/* 执行单旋转，对于x < t->element情况 */
/* k2 只有一个左子树；k2 这里的位置：插入x节点后的 grandparent */
static position single_rotate_withleft(position k2) /* k2表示插入：插入节点x的g节点 */
{
    /* 将k1（p） 升级到 k2 (g)的位置 */
    position k1;    /* 插入节点x后：的父节点p */
    k1 = k2->left;
    k2->left = k1->right;   /* 将p节点 p->right 放到k2->left */
    k1->right = k2;

    /* 计算height */
    k2->height = Max(Height(k2->left) - Height(k2->right)) + 1;
    k1->left = Max(Height(k1->left) , k2->height) + 1;

    return k1;
}

/* 执行双旋转 */
/* k3 只有一个左子树 */
static position double_rotate_withleft(position k3)
{
    /* rotate between k1 and k2 */
    k3->left = single_rotate_withright(k3->left);

    /* rotate between k3 and k2 */
    return single_rotate_withleft(k3);
}