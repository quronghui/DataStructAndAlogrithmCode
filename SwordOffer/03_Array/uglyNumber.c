//// 面试题49：丑数
// 题目：我们把只包含因子2、3和5的数称作丑数（Ugly Number）。求按从小到
// 大的顺序的第1500个丑数。例如6、8都是丑数，但14不是，因为它包含因子7。
// 习惯上我们把1当做第一个丑数。
/*
*   思路一:     对每一个数进行一次判断;
        a. 如果一个数能被2整除, 那么就一直让其除以2;  3整除, 5整除也是一样;
        b.  直到最后商为1; 这个数是丑数
        c. Test(1500, 859963392);  这时候计算过程已经很慢了;
    
    思路二:       空间换时间效率
        a.  假设一个已经排好序的丑数数组, 最大值为M;
        b.  下一个丑数, 应该是丑数数组里的数 *2 , *3,  *5 , 大于M的最小值;
        c. 不用每一个数都乘, 以*2为列子; 丑数数组中存在一个数K , 使得K前面的数*2 < M; K后面的数*2>M;
        d. 需要建立index大小的数组;
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
/************************ 思路一:     对每一个数进行一次判断;***************************/
// 判断是否为丑数
bool    isUgly( int number )
{
    while( number % 2 ==0 )
        number /= 2;
    while( number % 3 == 0 )
        number  /=  3;
    while(  number  %  5    ==  0 )
        number  /=  5;
    
    return (number  ==   1) ?   true:false;  
}

//  循环找到1500个丑数
int uglyNumber_solution1( int index )
{
    // 边界条件
    if( index <=0 )
        return 0;

    
    // 循环找到第1500个丑数
    int number  = 0;
    int uglyFirst = 0;
    while( uglyFirst < index ){
        number++;
        
        if( isUgly( number ) )
            uglyFirst++;
    }
    return number;
}

/**************************思路二:       空间换时间效率**************************************/
// 比较三个因子和数组乘积的最小值
int Min( int number1, int number2, int number3 ){
    int min = ( number1 < number2 )?    number1:number2;
    min = (min < number3)?  min:number3;
    return min;
}

// loop 
int uglyNumber_solution2(  int index)
{
    // 边界条件
    if( index <=    0 )
        return 0;
    
    // 建立动态数组
    int *uglyArray =    (int *)malloc(sizeof( int ) * (index+1));
    uglyArray[0] = 1;
    int nextUglyindex = 1;  // 第一个丑数

    // 丑数的三个因子, 定义为数组
    int *multiply2 = uglyArray;
    int *multiply3 = uglyArray;
    int *multiply5 = uglyArray;

    //loop  
    while( nextUglyindex < index){
        int min = Min( *multiply2 * 2, *multiply3 *3, *multiply5 * 5 );
        uglyArray[nextUglyindex] = min;

        // 找到丑数数组中的数K 
        while( *multiply2 * 2   <=  uglyArray[nextUglyindex] )
            ++multiply2;
        while( *multiply3 * 3   <=  uglyArray[nextUglyindex] )
            ++multiply3;
        while( *multiply5 * 5   <=  uglyArray[nextUglyindex] )
            ++multiply5;
        
        ++nextUglyindex;
    }
    int ugly = uglyArray[nextUglyindex-1];
    free(uglyArray);
    return ugly;

}

/*****************************Test code********************************/
void    Test(   int index, int expected )
{
    int number = uglyNumber_solution1(index);
    if(  number == expected)
        printf(" The number == expected is %d passed.\n ", number);
    else 
        printf(" The number != expected is %d failed.\n ", number );
    printf("\n");

    int number2 = uglyNumber_solution2(index);
    if(  number2 == expected)
        printf(" The number2 == expected is %d passed.\n ", number2);
    else 
        printf(" The number2 != expected is %d failed.\n ", number2 );
    printf("\n");
}


// main()
int main()
{
    // Test ( 1, 1 );
    // Test(2, 2);
    // Test(3, 3);
    // Test(4, 4);
    // Test(5, 5);
    // Test(6, 6);
    // Test(7, 8);
    // Test(8, 9);
    // Test(9, 10);
    Test(1500, 859963392);  // 
    return 0;
}