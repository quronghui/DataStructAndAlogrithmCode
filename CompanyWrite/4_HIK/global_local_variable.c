//
// Created by quronghui on 2019/8/24.
//
// 题目三: 全局变量和局部变量是可以重名,重名后使用就近原则
#include <stdio.h>

int num = 123;

void num_value()
{
    int num = 789;
    printf("The num value is %d.\n", num);
}

int main()
{
    int num = 456;
    num_value();
    printf("The num value is %d.\n", num);
    return 0;
}