// 题目：如何动态申请二维数组空间
/*
*   1.数组空间的申请：存储某个类型的数据，需要的内存空间
        动态申请的数组使用完之后，要进行释放
    2. 三种方式申请东岱二维数组；
        方法一：利用二级指针申请一个二维数组。
        方法二：用数组指针形式申请一个二维数组。 调试一直在报错
        方法三：用一个单独的一维数组来模拟二维数组。
*/
#include <stdio.h>
#include <stdlib.h>

// 方法一：利用二级指针申请一个二维数组。
void TwoPointMalloc( int rows, int cols)
{
    
    // 基础边界条件
    if(rows<1 || cols<1){
        printf("Invaild patameter .\n");
        return ;
    }

    // 分配所有行的首地址
    int **numbers = (int **)malloc(sizeof(int *) * rows); // sizeof(int *)：行的首地址，也是指针类型
    if(numbers == NULL){
        printf(" The space is null.\n");
        return;
    }
    // 根据行的数量，分配每行的列的个数
    for(int row=0; row < rows; row++){
        numbers[row] = (int *)malloc(sizeof(int) * cols);
    }

    // to do something; 打印数组中元素的空间
    for(int row=0; row < rows; row++){
        for(int col=0; col < cols; col++){
            printf("%p\t", &numbers[row][col]); //printf函数族中对于%p一般以十六进制整数方式输出指针的值，附加前缀0x
        }
        putchar('\n');
    }

    // 释放二维数组, 双指针创建，只需要释放行头指针
    for(int row=0; row < rows; row++)
        free(numbers[row]);
    free(numbers);    // 释放二维指针；
    numbers = NULL;
    
}

// 方法二：用数组指针形式申请一个二维数组
void ArrayPointMalloc( int rows, int cols)
{   
    // 基础边界条件
    if(rows<1 || cols<1){
        printf("Invaild patameter .\n");
        return ;
    }
    // 二维数组的定义：行可以不确定，列需要确定
    int (*numbers)[cols] = (int (*)[cols])malloc(sizeof(int) * rows *cols);
    if(numbers == NULL){
        printf(" The space is null.\n");
        return;
    }

    // to do something; 打印数组中的空间
    for(int row=0; row < rows; row++){
        for(int col=0; col < cols; col++){
            printf("%p\t", &numbers[row][col]); //printf函数族中对于%p一般以十六进制整数方式输出指针的值，附加前缀0x
        }
        putchar('\n');
    }
    // 释放二维数组, 双指针创建，只需要释放行头指针
    free(numbers);
    numbers = NULL;
}

// 方法三：用一个单独的一维数组来模拟二维数组
void OneArrayMalloc(int rows, int cols)
{
    // 基础边界条件
    if(rows<1 || cols<1){
        printf("Invaild patameter .\n");
        return ;
    }

    // 内存空间申请,按照数组元素的个数进行申请
    int *numbers = (int *)malloc(sizeof(int) *rows *cols);
    if(numbers == NULL){
        printf(" The space is null.\n");
        return;
    }

    // to do something; 打印数组中的空间
    for(int row=0; row < rows; row++){
        for(int col=0; col < cols; col++){
            printf("%p\t", &numbers[row*cols + col ]); //printf函数族中对于%p一般以十六进制整数方式输出指针的值，附加前缀0x
        }
        putchar('\n');
    }
    // 释放二维数组, 双指针创建，只需要释放行头指针
    free(numbers);
    numbers = NULL;
}

/********************test code************************/
// 测试：方法一：利用二级指针申请一个二维数组。
void Test1()
{
    int rows = 5;
    int cols = 5;

    TwoPointMalloc( rows, cols);  
    printf("\n");
}

// 测试：方法二：用数组指针形式申请一个二维数组
void Test2()
{
    int rows = 4;
    int cols = 4;


    ArrayPointMalloc(rows, cols);
    printf("\n");

}

// 方法三：用一个单独的一维数组来模拟二维数组
void Test3()
{
    
    int rows = 3;
    int cols = 3;

    OneArrayMalloc(rows,  cols);
    printf("\n");

}
// main 函数
int main()
{
    Test1();
    Test2();
    Test3();
    return 0;
}