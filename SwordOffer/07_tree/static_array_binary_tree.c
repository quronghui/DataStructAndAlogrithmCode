// 题目：静态数组实现二叉搜索树，能实现节点的插入，搜索，前序遍历

/*
*   1.解题思路：数组实现节点的存储，关键点在于 确定插入节点的下标；
*   2.Parameter
        current: 寻找插入点的位置；
*/

#include "tree_interface.h"
#include <stdio.h>
#include <assert.h>

#define TREE_SIZE   100
#define ARRAY_SIZE  (TREE_SIZE + 1)

static TREE_TYPE  tree[ARRAY_SIZE];   /* 定义静态数组树 */

/***************如何计算插入节点的下标********************/
static int left_child(int current)
{
    return  current * 2;
}

static int right_child(int current)
{
    return current * 2 + 1;
}

/******************insert value****************************/
void insert(TREE_TYPE value)
{
    assert( value != 0);   /* 确保值为非零，因为零值用于提示未使用的节点 */

    int current = 1;    /* 从根节点开始存储 */
    
    while( tree[current] != 0 ){
        /* 根据情况进入左子树和右子树 */
        if( value < tree[current] )
            current = left_child(current);
        else{
            assert(value != tree[current]);     /* 二叉搜索树插入，保证没有重复 */
            current = right_child(current);
        }
        assert( current < ARRAY_SIZE);          /* current 的值小于数组的大小,才将值插入 */
    }
    /* 1. 值最后的存储方式，找到插入点*/
    tree[current] = value;  
}

/*****************find value is't repeat*******************/
// 返回的是相同value所在的位置，通过指针指向
TREE_TYPE *find(TREE_TYPE value)
{
    int current = 1;    /* 从根节点开始 */
    while( current < ARRAY_SIZE && tree[current] != value){
        /* 根据情况进入左子树和右子树 */
        if(value < tree[current])
            current = left_child(current);
        else 
            current = right_child(current);
        if(current < ARRAY_SIZE)            /* current < ARRAY_SIZE 不满足条件：tree[current] != value */
            return tree + current;          /* 指针+偏移的数量current，也可以当做下标值，或者指针 */
        else 
            return 0;
    }
}

/**********************do_pre_order_traverse**********************/
// 不属于用户接口，属于内部功能函数
static void do_pre_order_traverse( int current, void (*callback)(TREE_TYPE value) )
{
    if(current < ARRAY_SIZE && tree[current] != 0){

        callback( tree[current] );      /* 回调函数，执行自己的功能 */

        do_pre_order_traverse( left_child(current), callback );
        do_pre_order_traverse( right_child(current), callback );
    }
}
// 用户接口函数
void pre_order_traverse( void (*callback)(TREE_TYPE value) )
{
    do_pre_order_traverse( 1, callback);
}