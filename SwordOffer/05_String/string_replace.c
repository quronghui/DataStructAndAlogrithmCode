// 面试题5：替换空格
// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
// 则输出“We%20are%20happy.”。

/*
*   1.题目注意：
        a.字符串隐含一个 '\0'
        b.是否允许额外的空间；直接复制插入值
    2.方法：
        字符串
        a.遍历一遍统计空格数，计算出替换后总的大小；
        b.设置两个指针分别指向末尾，由后往前进行替换
        c.保证字符串的长度足够大
*/

#include <stdio.h>
#include <string.h>

/*
Parament:
    char string[]   字符串
    int length      字符串长度
judge：
    字符串的两个下标值的计算
    originalLength
    newLength = originalLength + numberblank*2;
return：
    string[]        新的字符串
*/
void ReplaceBlank(char string[], int length)
{
    if(string == NULL && length <= 0)   return ;

    /* 统计空格数量 */
    int originalLength = 0; /* string[] 原先的长度 */
    int numberblank = 0;
    int i = 0;
    while(string[i] != '\0'){    /* 没有包含‘\0’ ? */
        ++originalLength;
        if(string[i] == ' ')    /* 字符串的空格 */
            ++numberblank;
        ++i;                
    }

    /* 判断字符串有没有超过限制 */
    int newLength = originalLength + numberblank*2;
    if(newLength > length)  return ;     

    /* 移动替换 */
    int indexofOriginal = originalLength;
    int indexNew    =   newLength;
    while(indexofOriginal >= 0 && indexNew > indexofOriginal){
        if(string[indexofOriginal] == ' '){
            string[indexNew--] = '0';
            string[indexNew--] = '2';
            string[indexNew--] = '%';
        }
        else{
            string[indexNew--] = string[indexofOriginal--];     /* 条件写错了 debug 半天 */
        }
    }
}

/*********************test code****************************/
/* 测试代码知道输入和输出结果的 */
void test(char *name, char string[], int length, char expected[])
{
    if(name != NULL)    printf("%s begin: ", name);
    
    ReplaceBlank(string, length);

    if(expected == NULL && string == NULL)  printf("passed.\n");
    else if (expected == NULL && string != NULL)    printf("failed1.\n");
    else if(strcmp(string, expected) == 0)  printf("passed.\n");
    else printf("failed2.\n");
}

void test1()
{
    const int length = 100; 

    char string[length] ;   /*使用变量定义长度时，不可在定义时同时进行初始化赋值，需要在之后进行赋值*/
    strcpy(string, "hello world");
    //char newstr[length] = "hello%20world";
    test("test1", string, length, "hello%20world");
}

int main()
{
    test1();
    return 0;
}