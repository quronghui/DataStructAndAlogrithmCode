// 面试题67(一)：字符串转换到int类型，将字符串里的*数字字符*转化为整形数。 
/*
*   1.模拟atoi函数:
        a. 首字符为 '0', 'space'， '+' , '-' ：设置一个标志位，其余直接跳过
        b. 转换函数：atio只转化'0'-'9'的数字字符，像a,b,c...不进行转换；
        c. 注意设置符号标志位
        d. 注意：当数字之后再次出现空格，符号位，0，'\0' 停止在这个位置；
*/  
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/************atoi实现************/
int Atio(const char *src)
{
    assert( src != NULL);
    
    int num = 0;
    int sign = 0;
    // 当首个字符为以下情况，跳到下一个字符
    while( *src=='0' || *src==' ' || *src=='-' || *src=='+' )
    {
        if(*src == '-')
            sign = 1;   //如果为负数，先保存符号位；
        src++;  // 忽略其他的字符
    }    
    // 只需要0-9这部分的ASCII
    while ( *src >= '0' && *src <= '9'){
        num = num*10 + *src - '0';  // '0'是数字48，减去后得到对应的数字类型
        src++;
    }
    // 判断是否为负数
    if(sign == 1)
        return -num;
    else 
        return num;
}
/************test code*************/
void Test(char *name, char *src)
{   
    if(name != NULL)
        printf("%s begin:   ", name);
    
    printf("The string is %s\n", src);
    int index_Atio = Atio(src);
    printf("Atio convert interger is %d\n", index_Atio);

    int result_atio = atoi(src);
    printf("The stdlib funcation of atio is %d \n", result_atio);
}

// test1:
void Test1()
{
    char src[] = " 009 123";   // atoi() = 123;
    Test("test1", src);
    printf("\n");
}
// test2:
void Test2()
{
    char src[] = "-a3289a32";
    Test("test2", src);
    printf("\n");
}

// main()
int main()
{
    Test1();
    Test2();
    return 0;
}