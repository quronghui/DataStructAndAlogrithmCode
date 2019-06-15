// 面试题4：二维数组中的查找
// 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
// 照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
// 整数，判断数组中是否含有该整数。

/*
*   1.题目提示：
        row : left to right  递增   每一行最后的值是最大值
        col : up to down 递增       每一列最小的值是最小值
    2.方法：
        每次取矩阵右上角的值value和number比较；
        value > number: col-1
        value < number: row-1
*/

#include <stdio.h>
#include <stdbool.h>
/*
Parament:
    matrix: 二维矩阵
    rows: 行
    cols: 列
    number： 查找值
judge：
    matrix[row*cols + col] == number) 二维数组的表示 
return:
    true: 存在
    false: 不存在
*/

bool find(int *matrix, int rows, int cols, int number)
{
    bool found = false;

    if(matrix != NULL || rows > 0 || cols > 0 )
    {
        int row = 0;
        int col = cols-1;
        while(row < rows && col >= 0){
            if(matrix[row*cols + col] == number){ /* 二维数组的表示 */
                found = true;
                return found;
            }   
            else if(matrix[row*cols + col] > number)
                --col;
            else 
                ++row;
        }
    }  
    return found;
}
/******************test code*************************/
void test(char *name, int *matrix, int rows, int cols, int number, bool expected)
{
    if(name != NULL)
        printf(" %s begin: ", name);
    bool result = find(matrix, rows, cols, number);
    if(result == expected)
        printf("Passed.\n");
    else 
        printf("Failed.\n");
}

void test1()
{
    int matrix[][4]={{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    test("test1", (int *)matrix, 4, 4, 7, true);
}

int main()
{
    test1();
    return 0;
}