// 面试题57（二）：为s的连续正数序列
// 题目：输入一个正数s，打印出所有和为s的连续正数序列（至少含有两个数）。
// 例如输入15，由于1+2+3+4+5=4+5+6=7+8=15，所以结果打印出3个连续序列1～5、4～6和7～8。
/*
*   1. 解题思路
        a. 定义两个变量并将其初始化, small = 1, big = 2;
        b. 计算两个数 数组之间的和Cursum[small + big]  与 sum 之间的关系;
        c.   Cursum[small + big]  <  sum  : big往后移动, 增加[small, big]之间的个数;
        d.  Cursum[small + big]  >  sum  :  small 向后移动, 减少 [small, big]之间的个数
        e.  Cursum[small + big]  =  sum , 输出序列; 
        f.  继续循环 small < (1+sum)/2 , 向后移动 big 和small
*/
#include <stdio.h>

//  函数申明 
void PrintContinuousSequence(int small, int big);

/*************找出序列***************/
void findContinueSequence(int sum)
{   
    // 初始化的small+big = 3;
    if( sum < 3 )
        return ;
    // 初始化序列的首尾
    int small = 1;
    int big = 2;
    int middle = (1 + sum);     //循环的判断条件 
    int curSum = small + big;

    // 循环判断: big> small
    while( small < middle ){
        if(curSum == sum)
            PrintContinuousSequence(small, big);
        // 当 Cursum[small + big] >  sum;
        while( curSum > sum && sum < middle ){
            curSum -= small;
            small ++;
           
            if( curSum == sum )
                PrintContinuousSequence(small, big);
        }
        // 当 Cursum[small + big] <  sum;
        big++;
        curSum += big;
    }
}

// 打印序列
void PrintContinuousSequence(int small, int big)
{
    for(int i = small ; i <= big; i++)
        printf("%d\t", i);
    printf("\n");
}

/**************Test code*****************/
void Test(char *name, int sum)
{
    if( name != NULL )
        printf("%s begin:   ", name);
    findContinueSequence(sum);
    
    printf("\n");    
}
// main
int main()
{
    Test("test1", 1);
    Test("test2", 3);
    Test("test3", 4);
    Test("test4", 9);
    Test("test5", 15);
    Test("test6", 100);
    return 0;
}