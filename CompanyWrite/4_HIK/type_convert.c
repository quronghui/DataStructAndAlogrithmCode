//
// Created by quronghui on 2019/8/24.
//
// 题目二: 数据基本类型的强制转换,查看test_p[1]的地址

#include <stdio.h>

/* 数据基本类型的强制转换 */
void type_convert()
{
    char test[8] = {0x01,0x02,0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
    int *test_p = (int *)test;
    printf("test_p address is %p\n", test_p);
    printf("test_p address is %#x\n", *test_p);
}

int main()
{
    type_convert();
    return 0;
}
