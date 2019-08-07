// 面试题67(二)：Int型整数，转化为字符串；
/*
*   1. 解题思路：
        a. 去掉整数的的十位，百位和千位..., 只保留数字；
        b. 注意：转换后的顺序是倒的；
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*************整数转换为字符串************/

char *itoa(int num, char *str, int radix)
{
    char index[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";  //索引表
    unsigned unum ;     // 存放需要转换整数的绝对值；
    int i = 0;
    // 转换整数
    if(num < 0 && radix==10){
        unum = (unsigned)-num;
        str[i++] = '-';
    }
    else 
        unum = (unsigned) num;
    
    // 整数进行转换,得到的是逆序数
    do{
        str[i++] = index[unum % (unsigned)radix];   // 得到整数的最后一位
        unum /= radix;  
    }while(unum);
    str[i] = '\0';  //最后一个字符置为'\0'
    
    // 调整顺序
    int j_start = 0;  //逆序起始位 
    if(str[0] == '-')
        j_start = 1;
    for( int start=j_start; start <= (i-1)/2; start++ ){
        int temp = str[start];
        str[start] = str[i-1-start];
        str[i-1-start] = temp;
    }

    return str;        
}

/****************Test code*****************/
void Test(char *name, int num, char *str, int radix)
{
    if(name != NULL)
        printf("%s begin:   ", name);
    
    printf("the string is %s\n", itoa(num, str, radix));
}
// test1
void test1()
{
    int num = 123456;
    char *str = malloc(sizeof(char) * 12);
    memset(str, 0, 12);
    // char str[12] = {0};
    Test("test1", num, str, 10);
}

// main 
int main()
{
    test1();
    return 0;
}