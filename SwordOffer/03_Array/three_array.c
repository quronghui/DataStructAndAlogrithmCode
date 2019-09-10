//
// Created by quronghui on 2019/9/9.
//
// 题目：实现一个三维数组的遍历

#include <stdio.h>

int main()
{
    int g[2][3][4]; //三维数组
    int n1 = sizeof(g) / sizeof(int[3][4]); // 得到第一维度数据
    int n2 = sizeof(g) / sizeof(int[2][4]); // 得到第二维度数据
    int n3 = sizeof(g) / sizeof(int[2][3]); // 得到第三维度数据
    int n11 = sizeof(g) / sizeof(g[0]);     //通过维度首个元素计算维度
    int n22 = sizeof(g[0]) / sizeof(g[0][0]);  //
    int n33 = sizeof(g[0][0]) / sizeof(g[0][0][0]);
    printf("n1 = %d, n2 = %d, n3 = %d\n",n1,n2,n3);
    printf("n11 = %d, n22 = %d, n33 = %d\n",n11,n22,n33);
    // 先对三维数组进行初始化
    int fk = 0;
    for(int i=0; i< sizeof(g)/ sizeof(g[0]); ++i){
        for (int j = 0; j < sizeof(g[0])/sizeof(g[0][0]); ++j) {
            for (int k = 0; k < sizeof(g[0][0])/ sizeof(g[0][0][0]) ; ++k) {
                g[i][j][k] = fk++;
            }
        }
    }
    //将其值打印出来
    for(int i=0; i< sizeof(g)/ sizeof(g[0]); ++i){
        for (int j = 0; j < sizeof(g[0])/sizeof(g[0][0]); ++j) {
            for (int k = 0; k < sizeof(g[0][0])/ sizeof(g[0][0][0]) ; ++k) {
                printf("g[%d][%d][%d]=%d\n", i, j, k, g[i][j][k]);

            }
        }
    }
    return 0;
}