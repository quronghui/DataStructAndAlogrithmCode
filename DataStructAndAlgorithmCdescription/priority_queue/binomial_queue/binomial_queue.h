#ifndef BINOMIAL_QUEUE_H
#define BINOMIAL_QUEUE_H

struct BinNode;
typedef int ElementType;
typedef struct BinNode *position;
typedef struct BinNode *bintree;
typedef struct collection *binquene;



#endif

/* 定义数组的最小值 */
#define minelements 5

/* binomial struct 左儿子和兄弟节点组成*/
struct BinNode
{
    position leftchild;
    position nextsibling;   
    ElementType element;  
};

#define maxtrees 10
struct collection
{
    int currentsize;
    bintree thetrees[maxtrees]
}