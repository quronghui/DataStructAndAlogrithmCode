/*
*   tree_avl.h
*/
#ifndef TREE_AVL_H
#define TREE_AVL_H

typedef int ElementType;
typedef struct AvlNode *AvlTree;
typedef struct AvlNode *position;

AvlTree make_empty(AvlTree t);
position find(ElementType x, AvlTree t);
position find_min(AvlTree t);
position find_max(AvlTree t);

AvlTree insert(ElementType x, AvlTree t);
AvlTree delete_x(ElementType x, AvlTree t);
ElementType retrieve(position p);


#endif

/* struct file */
struct AvlNode{

    ElementType element;
    AvlTree left;
    AvlTree righe;
    int height;
};