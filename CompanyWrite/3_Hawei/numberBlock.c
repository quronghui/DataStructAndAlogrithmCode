// 题目: 在一个整数的查找和5相同的二进制块;
// 比如输入 21 -- 10101; 输出出现的次数time = 2, locate = 1;
/*
*   1. 解题思路一: 
        a. 对一个整数和1按位与, 得到其二进制的数; number 为这个数
        b. 对应的比特块5, 同时进行按位与;   block 为比较的块
    2. 解题思路二:
        a. 直接对数先取后三位, 通过按位与7实现;
        b. 然后在和5, 异或就行;
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// 初始化全局变量
int time  = 0;      // 出现的次数
int locate = -1;    // 出现的位置;


bool mystrncmp(int *array, int *string, int length)
{
    for(int i = 0; i < length; i++){
        if(array[i] != string[i])
            return false;
    }
    return true;
}

void NumberBlock(int number, int block)
{
    // 边界条件
    if( number < block || block != 5)
        return ;
    
    // 定义一个数组, 循环保存移位的三个数;
    int arrayNumber[3];
    memset(arrayNumber, -1, sizeof(int) * 3);
    int arrayBlock[3] = {1, 0, 1};

    // 1)对整数进行移位保存;
    while( number  ){
        // 单独定义一个值, 保存数组的第三位的值
        int value3 = arrayNumber[2];
        int value2 = arrayNumber[1];

        int locatCopy = -1;
        // 2)移位保存数的值
        for(int i = 0; i < 3; i++){
            arrayNumber[i]  =   number & 1;
            number = number >> 1;
            locatCopy ++ ;
        }
        //  3)比特位存在重复使用的话?, 只有第三位为1时在下一个比特块才起作用;
        // 保证这个是第一次
        if(  value3 == 1 && ( arrayNumber[0] == arrayBlock[1] )  &&  (arrayNumber[1] = arrayBlock[2]) ){
            if(locate == -1)
                locate = (locatCopy % 2) - 1;
            time++;
        }
        if(value2 == 1 && value3 == 0 &&  (arrayNumber[0] = arrayBlock[2]) ){
             if(locate == -1)
                locate = (locatCopy % 2) ;
            time++;
        }
        // 如果两个字符串此时是相等的;
        else if( mystrncmp(arrayNumber, arrayBlock, 3) ){
            if(locate == -1)
                locate  = locatCopy %  2 ;     // 此时取余数就好
            time++;
        }
    }
}

/**************思路二***************/
void NumberBlock_2(unsigned int number, int block)
{   
    int value = 0;

    while (number)
    {
        if ( ( (number & 7 ) ^ 5)  == 0){
            time++ ;
            if( locate == -1)
                locate = value;
        }
        number = number >> 1;
        value ++;
    }
    
}

int main(void )
{
    int number;
    int block = 5;
    scanf("%d", &number);
    // NumberBlock(number, block);

    NumberBlock_2(number, block);

    printf("%d %d\n", time, locate);
    return 0;
}