// // 面试题12：矩阵中的路径
// 题目：请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中任意一格开始，每一步可以在矩阵中向左、右、// 上、下移动一格。
// 如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。例如在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字// 母用下划线标出）。
// 但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
// A B T G
// C F C S
// J D E H

/*
*   1.解题思路
        回溯算法实现：通过栈实现；
        路径不能进入重复格子：通过一个布尔矩阵进行记录；
    2.  hasPath: 回溯算法的调用函数；
        hasPathCore：回溯算法
        在满足条件的前提下：搜索上下左右四个位置
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 函数声明
bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, 
                const char* string, int pathLength, bool* visited_matrix);

/*************************定义布尔矩阵：记录重复的格子****************************/
bool hasPath(const char *matrix, int rows, int cols, const char *string)
{
    if( matrix == NULL || rows<1 || cols<1 || string == NULL){
        puts("Invaild parameters: ");
        return false;
    }
    // 动态申请：一个布尔矩阵进行记录走过的格子
    bool *visited_matrix = malloc(sizeof(bool) * rows * cols);
    memset(visited_matrix, 0, rows*cols);

    int pathLength = 0;
    for( int row = 0; row < rows; row++ ){
        for(int col = 0; col < cols; col++){
            if( hasPathCore( matrix, rows, cols, row, col, string, pathLength, visited_matrix ) )
                return true;
        }
    }

    free(visited_matrix);
    visited_matrix = NULL;
    return false;
}

/**********************回溯算法：路径查找算法************************/ 
bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, 
                const char* string, int pathLength, bool* visited_matrix)
{
    // 一直重复过程， 直到string[pathlength] = '\0'
    if( string[pathLength] == '\0' )
        return true;
    
    bool hasPath = false;   // 这里定义的变量和布尔函数矩阵意思是一样的吗？ 这里应该只是一个变量
    if(row >= 0 && row < rows && col >= 0 && col < cols     // 二维数组边界条件
        && matrix[row * cols + col] == string[pathLength]   // 路径中元素相同
        && !visited_matrix[row * cols + col])               // 布尔矩阵，该位置没有走过
    {   
        // 此时节点A 存在相同元素，且路劲还没有走过
        ++pathLength;
        visited_matrix[row * cols + col] = true;

        // 探索节点A的四个周围节点，是否匹配 pathlength+1的节点
        hasPath = hasPathCore( matrix, rows, cols, row, col-1, string, pathLength, visited_matrix )
                || hasPathCore( matrix, rows, cols, row-1, col, string, pathLength, visited_matrix )
                || hasPathCore( matrix, rows, cols, row, col+1, string, pathLength, visited_matrix )
                || hasPathCore( matrix, rows, cols, row+1, col, string, pathLength, visited_matrix ) ;
        // 如果当前位置不能满足继续往下，回到前一个字符（pathLeng - 1）,重新定位
        if( !hasPath ){
            --pathLength;
            visited_matrix[row * cols + col] = false;
        }
    }
    return hasPath;
}

/*****************************test code******************************/
void test( const char *matrix, int rows, int cols, const char *string, bool expected)
{
    if(hasPath(matrix, rows, cols, string) == expected)
        printf("Passed.\n");
    else 
        printf("Failed.\n");
}

int main(void)
{
    const char *matrix = "abtgcfcsjdeh";
    const char *string = "bfce";
    test(matrix, 3, 4, string, true);
    return 0;
}