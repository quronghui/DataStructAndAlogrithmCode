// 面试题47：礼物的最大价值
// 题目：在一个m×n的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于0）。
// 你可以从棋盘的左上角开始拿格子里的礼物，并每次向左或者向下移动一格直到到达棋盘的右下角。
// 给定一个棋盘及其上面的礼物，请计算你最多能拿到多少价值的礼物？
/*
*   1.解题思路一: 通过二维矩阵去保存
        a. 题目中计算出最优的礼物和, 因此只要每一步最优, 礼物和就是最大的;
        b. 题目的思路求最大值的, 因此属于动态规划问题;
        c. 二维矩阵的建立;
        d. 位置(i,j)到达的方式两种(i-1,j)和(i,j-1);
    2.解题思路二: 通过一维矩阵保存
        a.通过列坐标进行操作和记录
*/ 
#include <stdio.h>
#include <stdlib.h>

/***************思路一: 得到礼物的最大值******************/
int getMaxValue(const int *values, int rows, int cols)
{
    if(values == NULL && rows <=0 && cols <=0)
        return 0;
    // 定义二维数组: 利用二级指针申请一个二维数组。
    int **maxValue = malloc(sizeof(int *) *rows);
    // 定义每一个行指针
    for(int i=0; i<rows; i++)
        maxValue[i] = malloc(sizeof(int) * cols);
    
    // 进行值的累加
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            int left = 0;
            int up = 0;
            if(i>0)
                up = maxValue[i-1][j];  
            if(j>0)
                left = maxValue[i][j-1];
            int max = (up > left)?up:left;          // 比较表达式
            
            maxValue[i][j] = max + values[i*cols +j]; // 二维数组中值的查找
        }
    }
    int sumValue = maxValue[rows-1][cols-1];

    // 释放二维数组
    for(int i=0; i<rows; i++)
        free(maxValue[i]);
    free(maxValue);

    return sumValue;
}

/******************思路二: 建立一维数组*******************/
// 通过列坐标进行操作和记录
int getMaxValue_second(const int *values, int rows, int cols)
{
    if(values == NULL || rows<=0 || cols<=0)
        return 0;
    // 定义一维数组进行存储遍历
    int *maxValues = (int *)malloc(sizeof(int) * cols);    //定义一维数组, 以列数为准;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            int left=0;
            int up =0;
            if(i>0)
                up = maxValues[j];      // 注意:这里的取值
            if(j>0)
                left = maxValues[j-1];
            int max = (up>left)?up:left;

            maxValues[j] = max + values[i*cols + j];
        }
    }
    int sumValue = maxValues[cols-1];
    free(maxValues);

    return sumValue;
}

/*********************test code*******************/
void Test(char *name , const int *value, int rows, int cols, int expected)
{
    if(name != NULL)
        printf("%s begin: \n", name);
    
    printf("Resolution one:\n");
    int maxSumvalue = getMaxValue(value, rows, cols);
    if(maxSumvalue == expected)
        printf(" the maxSumvalue == expected is %d passed\n", maxSumvalue);
    else 
        printf(" the maxSumvalue != expected is %d failed\n", maxSumvalue);

    printf("\nThe second resolution.\n ");
    int second_maxSumvalue = getMaxValue_second(value, rows, cols);
    if(second_maxSumvalue == expected)
        printf(" the second_maxSumvalue == expected is %d passed\n", second_maxSumvalue);
    else 
        printf(" the second_maxSumvalue != expected is %d failed\n", second_maxSumvalue);

}

// test1()
void test1()
{
        // 三行三列
    int values[][3] = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };
    int expected = 29;
    Test("test1", (const int*) values, 3, 3, expected);
}

// main
int main()
{
    test1();
    return 0;
}