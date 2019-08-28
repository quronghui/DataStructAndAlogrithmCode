//
// Created by quronghui on 2019/8/24.
//
/*
 * 题目一: 两个变量值的交换;
*/
#include <stdio.h>

/* 问题: 只交换地址, 值是不会变的 */
void swap(int *p, int *q)
{
    int *t = p;
    p = q;
    q = t;
}

/* 交换值,不交换地址: 这样值才能改变 */
void swap_value(int *p, int *q)
{
    int t = *p;
    *p = *q;
    *q = t;
}

int main() {
    int x = 1, y = 2;
    int *p = &x, *q = &y;
//    swap(p, q);
    swap_value(p, q);
    printf("p = %d, q = %d\n", *p, *q);
    return 0;
}