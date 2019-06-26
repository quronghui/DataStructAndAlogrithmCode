// 面试题13：机器人的运动范围
// 题目：地上有一个m行n列的方格。一个机器人从坐标(0, 0)的格子开始移动，它// 每一次可以向左、右、上、下移动一格，
// 但不能进入行坐标和列坐标的数位之和大于k的格子。
// 例如，当k为18时，机器人能够进入方格(35, 37)，因为3+5+3+7=18。但它不能进入方格(35, 38)，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

/*
*   1.解题思路：通过回溯算法
        movingCount：调用回溯算法，创建动态布尔矩阵；
        movingCountCore： 
            回溯算法：在满足限制条件的前提下，对上下左右的四个位置进行递归检查；
            同时给满足的位置，在布尔矩阵里置为1
        check(): 满足调用回溯算法的前提条件
    2.threshold : 上线的计算 -- 上三角位数之和；
        threshold = (k + 1) + f(k-1);   // k+1 是对角线个数和；
                                        // f(k-1): 对角线以上的和
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 函数声明
int movingCountCore( int threshold, int rows, int cols, int row, int col, bool *visited );
bool check(int threshold, int rows, int cols, int row, int col, bool *visited);
int getDigitSum(int number);

/*******************调用回溯算法，创建动态布尔矩阵**********************/
int movingCount(int threshold, int rows, int cols)
{
    if( threshold < 0 || rows <= 0 || cols <= 0 ){
        puts("Invaild parameter.");
        return 0;
    }

    // 布尔矩阵，记录能够满足回溯条件的格子数；
    bool *visited = malloc(sizeof(int) * rows * cols );
    memset(visited, 0, rows * cols);

    // int col, row;
    // col = row = 0;
    int count = movingCountCore(threshold, rows, cols,0, 0, visited);
    printf("movingCountCore is count = %d \n", count);

    free(visited);
    visited = NULL;

    return count;
}

/**********************回溯算法：************************/
int movingCountCore( int threshold, int rows, int cols, int row, int col, bool *visited )
{
    int count = 0;
    if( check(threshold, rows, cols,row, col, visited) ){
        visited[ row * cols + col] = true;

        // 算出每一格是否满足条件，满足条件就加1
        // 每一格子都可以算，不是进行选择
        count = 1 + movingCountCore(threshold, rows, cols, row - 1, col, visited)
                +   movingCountCore(threshold, rows, cols, row, col - 1, visited)
                +   movingCountCore(threshold, rows, cols, row + 1, col, visited)
                +   movingCountCore(threshold, rows, cols, row, col + 1, visited); 
    }
    return count;
}

/*********************是否进行回溯算法的判断条件************************/
bool check(int threshold, int rows, int cols, int row, int col, bool *visited)
{
    if(row >= 0 && row < rows && col >= 0 && col < cols     // 二维数组边界条件
    && getDigitSum(row) +  getDigitSum(col) <= threshold    // 回溯算法进行的条件
    && !visited[row * cols + col])                   // 布尔矩阵，标记走过的位置
    {
        return true;
    }
    
    return false;   // 存在不满足的条件
}
/************************getDigitSum 计算下标的 各个位数之和*********************************/
int getDigitSum(int number)
{
    int sum = 0;
    while( number > 0){
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

/*******************test code***********************/
void test(int threshold, int rows, int cols, int expected)
{
    if(movingCount(threshold, rows, cols) == expected)
        printf("Passed.\n");
    else 
        printf("Failed.\n");
}

/***********************thread_sum **************************/
int threadSum(int threshold)
{
    // 递归太慢了，用循环实现
    int expected = 0;
    for( int i=0; i <= threshold; i++ ){
        expected += (i+1);
    }
    return expected;
}

int main(void)
{   
    int threshold = 2;
    int rows, cols;
    rows = cols = 10;
    int expected = threadSum(threshold);
    printf("Expected conculate is: %d \n", expected);
    
    test(threshold, rows, cols, expected);
}
