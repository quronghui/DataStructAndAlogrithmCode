// 面试题45：把数组排成最小的数
// 题目：输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
// 例如输入数组{3, 32, 321}，则打印出这3个数字能排成的最小数字321323.
/*
*   1.解题思路
        a. 先将数组中的整数, 通过sprintf保存到字符串数组中; 定义了一个字符串数组(二维数组)
        b. 调用qsort函数堆字符串数组进行排序, 
            其中的compare函数: 会将字符串数组的通过strcat进行拼接;
            strcmp进行字符串的比较 ,根据字符串一位位的进行比较大小;
    2.遇到问题
        a. 如果是整数直接连接的话, 造成溢出的现象;
        b. 如何制定比较规则, 并且证明这个规则是否有效;
        c. 数组中的元素超过三个就会出错, 因为我们只连接了两部分;
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 定义两个字符串数组:用于存储拼接在一起的字符串;

const int g_MaxNumberlength = 10;
// char strCombine1[2*g_MaxNumberlength +1];
char strCombine1[20];   // 开头的定义不能使用变量作为下标;
char strCombine2[20];

// 函数声明
int compare(const void *strNumber1, const void *strNumber2);

/**************打印最小的数字**************/
void printMinNumber(int *numbers, int length)
{
    // 基础边界
    if(numbers == NULL || length < 0)
        return ;
    // 定义一个双指针, 根据数组长度定义基本大小
    // 相当于在定义二维数组;
    char **strNumbers = malloc(sizeof(int) * length);
    for(int i=0; i<length; i++){
        strNumbers[i] = malloc(sizeof(char) * g_MaxNumberlength + 1);
        sprintf(strNumbers[i], "%d" , numbers[i]);     // 将数组先转化为字符串
    }
    // qsort sort an array
    qsort(strNumbers, length, sizeof(char *), compare); // compare 比较函数

    // 输出最小的排序值
    for(int i=0; i<length; i++)
        printf("%s", strNumbers[i]);
    printf("\n");

    // 进行二维数组的释放
    for(int i = 0; i<length; i++)
        free(strNumbers[i]);
    free(strNumbers);
    strNumbers = NULL;
}

// compare 比较函数
int compare(const void *strNumber1, const void *strNumber2)
{
    strcpy(strCombine1, *(char **)strNumber1);
    strcat(strCombine1, *(char **)strNumber2);

    // 反过来进行连接
    strcpy(strCombine2, *(char **)strNumber2);
    strcat(strCombine2, *(char **)strNumber1);

    return strcmp(strCombine1, strCombine2);
}

/****************************test code**************************/ 
void Test(const char *name, int *number, int length, const char *expected)
{
    if(name != NULL)
        printf("%s begin: \n", name);
    if(expected != NULL)
        printf("The expexted value is: \t%s\n", expected);
    
    printf("Actual result is : \t");
    printMinNumber(number, length);
    printf("\n");
}
// test1    
void test1()
{
    int numbers[] = {3, 5, 1, 4};   
    Test("Test1", numbers, sizeof(numbers)/sizeof(int), "1345");
}
//test2
void test2()
{
    int numbers[] = {3, 32, 321};
    Test("Test2", numbers, sizeof(numbers)/sizeof(int), "321323");
}
// 数组中只有一个数字
void test3()
{
    int numbers[] = {321};
    Test("Test3", numbers, sizeof(numbers)/sizeof(int), "321");
}


// main
int main()
{
    // test1();
    // test2();
    // test3();
    return 0;
}