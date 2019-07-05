// 面试题29：顺时针打印矩阵
// 题目：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
        // 考察边界条件的判断：全部梳理出来之后；就是顺序书写代码；
// 题目扩展：逆时针打印呢？
/* 
*   1.通过画图的方式：将问题形象化
        a.圈循环能 --> 进行的条件：(cols > startX*2) && (rows > startY*2); 
        b.每个圈的第一个节点的位置：（0,0），（1,1）... (start,start)
        c.完成一个圈要经过四步； 
            第一步：从左到右打印第一行，只要二维数组不为空，就必须；
            第二步：从上到下打印 一列---row_end > row_start;
            第三步：从右到左打印 一行---至少两行两列 ；(row_end > row_start)&&(col_end > col_start)
            第四步：从下到上打印 一列---至少三行两列；(row_end > row_start*2)&&(col_end > col_start)
     2.逆时针打印呢？
        将：完成一个圈要经过四步反过来进行打印；
        行和列之间的关系：差别改动有点多
*/
#include <stdio.h>
#include <stdlib.h>

// 函数声明
void PrintMatrixCricle(int **numbers, int rows, int cols, int start);       // 顺时针打印
void ReverPrintMatrixCricle(int **numbers, int rows, int cols, int start); // 逆时针打印

/***********************先判断能否进行循环************************************/
void MatrixClockwisely(int **numbers, int rows, int cols)   
{
    if(numbers == NULL || cols <=0 || rows <= 0){    // 数组：多山行和列 不为空条件>=1
        printf("The matrix is null or invailed parameter.\n");
        return ;
    }    

    // 判断是够能够进行圈循环的条件；
    int start = 0;
    while( cols > start*2 && rows > start*2 ){
        // 调用顺时针打印函数        
        // PrintMatrixCricle(numbers, rows, cols, start);
        // putchar('\n');  // 循环一个圈，打一个回车
        
        // 调用逆时针打印函数
        ReverPrintMatrixCricle(numbers, rows, cols, start);

        putchar('\n');  // 循环一个圈，打一个回车
        
        ++ start;   // 相当于在判断主对角线上元素的位置；
    }
}

/******************按顺时针：循环调用四步打印*******************/
void PrintMatrixCricle(int **numbers, int rows, int cols, int start)
{   
    // startX = startY = start;
    int endX = cols-1 - start;    // X方向打印终止的条件取决与 cols数目；
                                    // 每打印一圈：丢弃外圈的行数和列数；
    int endY = rows-1 - start; 
    // 第一步：从左到右打印第一行，只要二维数组不为空，就必须；
    for(int startX = start; startX <= endX; startX++){
        int number = numbers[start][startX];
        printf(" %d ", number);
    }
    // 第二步：从上到下打印 一列---row_end > row_start;
    if( start < endY ){
        for(int startY = start + 1; startY <= endY; startY++){
            int number = numbers[startY][endX];
            printf(" %d ", number);        
        }
    }
    // 第三步：从右到左打印 一行---至少两行两列 ；(row_end > row_start)&&(col_end > col_start)
    if( start < endX && start < endY){
        for(int startX = endX-1; startX >= start; startX--){
            int number = numbers[endY][startX];
            printf(" %d ", number);        
        }
    }
    // 第四步：从下到上打印 一列---至少三行两列；(row_end > row_start*2)&&(col_end > col_start)
    // 最后一行打印的关系
    if( start < endX && start <endY - 1 ){
        for(int startY = endY-1; startY >= start+1; startY--){
            int number = numbers[startY][start];
            printf(" %d ", number);        
        }
    }
}

/********************按逆时针：循环调用四步打印**********************/

void ReverPrintMatrixCricle(int **numbers, int rows, int cols, int start)
{
    // 其实打印 startX = startY= start
    int endX = cols-1 - start;    // X方向打印终止的条件取决与 cols数目；
                                    // 每打印一圈：丢弃外圈的行数和列数；
    int endY = rows-1 - start; 
    // 第一步：从上到下打印第一列，只要二维数组不为空，就必须；
    for(int startY = start; startY <= endY; startY++){
        int number = numbers[startY][start];
        printf(" %d ", number);
    }
    // 第二步：从左到右打印 一行--至少有两列;
    if( start < endX ){
        for(int startX = start+1; startX <= endX; startX++){
            int number = numbers[endY][startX];
            printf(" %d ", number);
        }
    }
    // 第三步：从右下到左上打印 一列---至少两行两列
    if(start < endY && start < endX){
        for(int startY = endY-1; startY >= start; startY--){
            int number = numbers[startY][endX];
            printf(" %d ", number);
        }
    }
    // 第四步：从右到左打印 一行---至少两行三列；
    if(start < endX-1 && start < endY){
        for(int startX = endX-1; startX >= start+1; startX--){
            int number = numbers[start][startX];
            printf(" %d ", number);
        }
    }
}

/*********************test code***********************/
// Test 测试接口；
void Test(int rows, int cols)
{
    printf("Test begin %d rows, %d cols.\n", rows, cols);

    if(rows < 1 || cols < 1)
        return;
    
    // 动态二维数组的分配如何进行
    int **numbers = (int **)malloc(sizeof(int *) * rows);   // 动态申请二维数组，分配所有行的首地址
    if(numbers == NULL){
        printf("The numbers is null.\n");
        return ;
    }
    for(int i=0; i<rows; i++)      // 按行分配每一列
    {
        numbers[i] = (int *)malloc(sizeof(int) * cols);    // 动态申请每一行具有的元素个数
        
        // 二维数组的初始化
        for(int j=0; j < cols; j++){
            numbers[i][j] = i * cols + j + 1;   
        }
    }

    // 调用打印函数接口
    MatrixClockwisely(numbers, rows, cols);  
   
    
    putchar('\n');
    // 释放二维数组, 双指针创建，只需要释放行头指针
    for(int row=0; row < rows; row++)
        free(numbers[row]);
    free(numbers);    // 释放二维指针；
    numbers = NULL;
}

//main 函数
int main()
{
    // Test(1,9);  //

    Test(3,3);  //
    

    return 0;
}