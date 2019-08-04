/*
*   网易编程题:
            a.  测试函数需要自己写; 
            b. 输入值需要通过scanf进行; 
            c. 以后本地的代码提交到leetcode上进行测试

    题目1: 
*   1. 解题思路
        a. 读入班级人数n
        b. 创建一个动态数组, 保存每个同学的分数;分数有可能有小数
        c. 输入查询的次数
        d. 输出每一同学的百分比 p = ( 超过分数的人数 - 1 ) / n
*/

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

int main(void)
{
    // a. 读入班级人数n
    int n;
    scanf("%d", &n);
    assert(n >= 1);
    int length = n + 1;
    
      // b. 创建一个动态数组, 保存每个同学的分数, 假设分数是有小数的;
    float *grade = (float *)malloc( sizeof(float) * length );
    for( int i=0; i < length; i++ )
        grade[i] = 0.0;
    // 读入每一个同学的分数, i=0的位置不保存分数
    for( int i=0; i < length; i++ ){
        float value;
        scanf("%f ", &value);
        assert(value >=0 ) ;
        assert(value <= 150);
        grade[i+1] = value;
    }

    // c. 读入查询的次数
    int checkN;
    scanf("%d", &checkN);
    assert( checkN <= (n) );

    // d 计算并输出
    int th;
    for (int i = 0; i < checkN; i++)
    {
        // 读入第几次
        scanf("%d", &th);
        assert(th <= n);
        
        // 遍历一遍统计分数的次数
        float value = grade[th];
        int number = 0;
        for(int i=0; i<n; i++){
            if( value >= grade[i+1] )
                number++;
        }
        float p = (number - 1) / n;
        printf("%f\n", p);
    }
    return 0;
}
