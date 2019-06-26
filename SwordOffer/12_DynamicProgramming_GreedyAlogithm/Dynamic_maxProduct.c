// 面试题14：剪绳子 :给你一根长度为n绳子，请把绳子剪成m段（m、n都是整数，n>1并且m≥1）。
// 每段的绳子的长度记为k[0]、k[1]、……、k[m]。k[0]*k[1]*…*k[m]可能的最大乘积是多少？
// 例如当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到最大的乘积18。

/*
*   1.题目提示：
        a. 要求最大的乘积：k[0]*k[1]*…*k[m]；
        b. 动态规划算法进行求解
    2.求解思路
        a. 自下而上的求取结果，创建数组保存中间结果；
        b. m、n都是整数，n>1并且m≥1；必须要减一刀
        c. product = max[ f(m) * f(n-m) ];
*/

#include <stdio.h>
#include <stdlib.h>

int maxProductCutting(int length)
{
    // m、n都是整数，n>1并且m≥1；必须要减一刀
    if(length < 2)      // 绳子未剪下之前的处理；
        return 0;
    if(length == 2)
        return 1;
    if(length == 3)
        return 2;       // 3 =1*2
    
    // 建立一个一维数组进行存储
    int *products = malloc(sizeof(int) * (length + 1));
    // 数组中的下标是：剪下后的长度，用于后面做计算
    products[0] = 0; products[1] = 1;   
    products[2] = 2; products[3] = 3;
    
    int max = 0;    // 存取每一次剪短的最大值
    // 由下往上处理
    for( int i=4; i <= length; i++ ){   // 当长度为4 = 1*3 ； 2*2
        max = 0;
        for( int j=1; j <= i/2; j++ ){   // 当绳子的长度大于4 时，每次能剪下的绳子长度
            int product = products[j] * products[ i - j];
            if(max < product)
                max = product; 
            
            products[i] = max;
        }
    }
    max = products[length];
    free(products);
    products = NULL;

    return max;    
}

/****************test code*********************/
void test(int length, int expected)
{
    int result = maxProductCutting(length);
    if(result == expected)
        printf("Max product is: %d passed.\n", result);
    else 
        printf("Invaild parameter, failed.\n");
}

int main()
{
    int length = 8;
    int expected = 18;
    test(length, expected);

    return 0;
}