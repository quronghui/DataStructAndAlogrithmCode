// 面试题60：n个骰子的点数
// 题目：把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。
// 输入n，打印出s的所有可能的值出现的概率。
/*
*   1. 解题思路:
        a. 骰子的排列数的总和是: 6^n;
        b.  n个骰子的点数之和: n < sum < 6n;
        c.  统计出每一个sum的排列数 / 除以总的排列数 = 概率;
    2. 思路一: 递归的方式进行解题
        d. 数据结构:　数组骰子的点数和sum有 (6n - n+1)情况,  和为sum 的次数保存在 (sum-n)的位置;
        e. 内在规律:  递归的方式, 将骰子分为 一个, 和 (n-1)个, 求他们的排列;  
    3. 思路二: loop
        f. 考虑用两个数组进行存储: 骰子点数和为n 出现的次数;
        g. 第一轮循环, 第一个数组中的第n个数字表示骰子和为n出现的次数;
            第二轮循环中, 加上一个新的骰子, 此时和为n的筛子出现的次数 = 上一轮骰子点数和为 n-1, n-2, n-3 , n-4, n-5, n-6的次数总和;
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int g_maxValue = 6;     // 全局变量, 骰子的最大点数;

/*******************************思路一: 递归实现 *************************************/
void    Probability(int number, int *pProbabilities);
void CulProbability(int original, int current, int sum, int *pProbabilities);

// 构建数据结构, 并计算概率
void PrintProbability_Recursion(int number)
{
    if(number < 1)
        return ;
    
    // 定义点数之和sum并初始化
    int maxSum  =   number  *   g_maxValue;
    // 数据结构定义并初始化
    int *pProbabilities  =   (int    *)malloc(sizeof(int)    *   (maxSum - number + 1 ) );
    for(int i = number;  i <= maxSum; i++)
        pProbabilities[ i - number   ]   =   0;

    // 统计每个和sum: 出现的概率
    Probability(number, pProbabilities);
    // 总的排列次数;
    int total   =   pow( (double)g_maxValue, number );
    for(int i = number; i<= maxSum; i++){
        double  ratio   =   (double)pProbabilities[ i - number ] / total;
        //     printf("%e\n", f);   // 以指数形式输出3.141593e+000
        printf("sum is %d ,  probablity is %e. \n", i, ratio);
    }
    free(pProbabilities);
}

// 第一次递归
void    Probability(int number, int *pProbabilities)
{
    for( int i  = 1; i<= g_maxValue; i++ )
        CulProbability(number, number, i, pProbabilities);
}
// 第二次及其以后的递归
void CulProbability(int original, int current, int sum, int *pProbabilities)
{
    if(current == 1)
        pProbabilities[sum - original]++;
    else {
        for(int i = 1; i<= g_maxValue; i++)
            CulProbability(original, current-1, i+sum, pProbabilities);
    }
}


//*******************************************************************/
/***********************思路二: 循环******************************/
void PrintProbability_Loop(int number)
{
    if(number < 1)
        return;
    // 定义两个数组进行存储, 初始化
    int *pProbabilities[2];
    pProbabilities[0]   =   (int *)malloc(sizeof(int) * (g_maxValue*number + 1) );  // 数组的定义和递归有点不同;
    pProbabilities[1]   =   (int *)malloc(sizeof(int) * (g_maxValue*number + 1) );
    for(int i=0; i <= (g_maxValue*number+1); i++ ){
        pProbabilities[0][i] = 0;
        pProbabilities[1][i] = 0;
    }

    // 进行第一次循环
    int flag = 0;           // 用于标识哪一个数组;
    for(int i = 1; i<= g_maxValue; i++)
        pProbabilities[flag][i] = 1;
    
    // 第二次循环
    for(int k =2; k <= number; k++){
        for(int i = 0; i < k; i++)
            pProbabilities[1-flag][i] = 0;
        
        for(int i = k; i <= g_maxValue*k; i++){
            pProbabilities[1-flag][i] = 0;
            for(int j = 1; j <= i && j<=g_maxValue; j++ )
                pProbabilities[1-flag][i]    +=    pProbabilities[flag][i-j];
        }
        flag    =   1 - flag;    
    }

    // 计算概率
    double  total   =   pow((double)g_maxValue, number  );
    for(int i = number; i <= g_maxValue*number; i++ ){
        double ratio = (double ) pProbabilities[flag][i]    /   total;
        printf("sum is %d ,  probablity is %e. \n", i, ratio);
    }
    free(pProbabilities[0]);
    free(pProbabilities[1]);
}


/**********************Test Code************************/
void Test(int number)
{
    printf("Test for %d begins:\n", number);
    
    printf("Test for solution1\n");
    PrintProbability_Recursion(number);

    printf("Test for solution2\n");
    PrintProbability_Loop(number);

    printf("\n");
}

// main
int main()
{
    Test(3);
    // Test(2);
    return 0;
}