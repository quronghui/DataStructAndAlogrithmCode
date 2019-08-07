// 面试题17：打印1到最大的n位数

/*  相当于考察数据结构[字符串]，算法实现[递归和循环]
*   方法一：  字符串上模拟数字加法，把字符串表达的数字打印
        1. 题目隐含：n没有规定范围，因此需要考虑大数问题？
            a. 大数的存储：采用字符串或数组进行表示 : char i : 表示 0-9
            b. 判断n位的最大值，进行打印    
        2. 数据结构：字符串；
            算法：通过对数加1，进行循环打印
    方法二： 推荐递归，代码数少一些
        1. 解题思路： n位的十进制数，相当于 n 个从0到9的全排列
            a. 字符串的最后一个字符:  手动进行初始化, 设置为'\0'
            b. 打印数的时候, 为了符合读数字的规则, 前面那个0是不能打印的;
        2. 数据结构： 递归实现全排列

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/************************************************************************/
/*********************************方法一*********************************/
void PrintNumber(char *number);
bool Increment(char *number);

/***************基本的功能函数：接口********************/
void Print_OneToMax_Loop(int n)
{   /*边界条件*/ 
    if( n < 0){                   
        puts("Invaild input parameter.\n");
        return ;
    }
    char *number = malloc(sizeof(char) * (n + 1));      // 动态创建：字符串保存大数
    memset(number, '0', n);                    
    number[n] = '\0';                // 字符数组的最后一位初始化

    /* 循环条件，判断 */
    while( !Increment(number) ){    // 判断是否达到最大值
        PrintNumber(number);
    }

    /* 释放动态内存 */
    free(number);
    number = NULL;
}

/****************Increment 判断是够达到最大值********************/
// 判断方法: 在 number上增加1,如果做加法溢出，则返回true；否则为false, 继续进行数的加1
bool Increment(char *number)
{
    bool isOverflow = false;    // 标志位
    int nTackOver   = 0;
    int nLength     = strlen(number);        // 遇到'\0'就停止，字符串有多少位

    for(int i = nLength - 1; i >= 0; i--){
        int nSum = number[i] -'0' + nTackOver;  // 将字符转化为整数
        
        if( i == nLength - 1)   // 在最高位做加法，看是否溢出（就加一次，没有循环）
            nSum++;

        /* 判断是不是最高位溢出，还是其他位溢出 */
        if( nSum >= 10){
            if(i == 0)
                isOverflow = true;
            else{
                nSum -= 10;
                nTackOver = 1;
                number[i] = '0' + nSum;
            }
        }
        else {
            number[i] = '0' + nSum;    /* 如果number 自符不是 '9'，那么将其加1 */ 
            break;
        }
    }
    return isOverflow;
}

/*****************PrintNumber：打印数字***********************/
// 符合阅读习惯：098 只打印 98；从第一个非0开始打印
void PrintNumber(char *number)
{
    bool isBeginnint = true;
    int nLength = strlen(number);                // 遇到'\0'就停止，字符串有多少位

    for(int i=0; i < nLength; i++){             //打印number中包含的数字
        if( isBeginnint && number[i] != '0')    //开头的0不打印
            isBeginnint = false;
        if(!isBeginnint)
            printf("%c", number[i]);
    }
    printf("\t");    
}

/************************************************************************/
/*********************************方法二*********************************/
void Recursive_number(char *number, int length, int index);

void Print_OneToMax_Recursive( int n )
{
    if(n < 0){                   
        puts("Loop invaild input parameter.\n");
        return ;
    }

    char *number = malloc( sizeof(char) * (n + 1) );    // 字符串存储数据
    if(number == NULL){
        puts("Memory is full, segment failed.\n");
        return ;
    }
    number[n] = '\0';       // 保证字符串以、\0结尾

    /*调用打印函数*/
    for(int i=0; i<10; i++){
        number[0] = i + '0';
        Recursive_number(number, n, 0);
    }

    free(number);
    number = NULL;
}

/*******************Recursive print*******************/
void Recursive_number(char *number, int length, int index)
{
    if(index == length - 1){
        PrintNumber(number);
        return;
    }
    for(int i=0; i<10; i++){
        number[index + 1] = i + '0';
        Recursive_number(number, length, index+1);
    }
}


/**********************test code**************************/
void test1(int n)
{
    Print_OneToMax_Loop(n);
    putchar('\n');
}
void test2(int n)
{
    Print_OneToMax_Recursive(n);
    putchar('\n');
}

int main()
{
    test1 (2);
    test2(2);
    return 0;
}