#include <stdio.h>
#include <stdbool.h>

bool g_InvaildInput = false;

// 不能直接进行 == 比较
void test_double()
{
    double i = 0.000001;
    double j = 0.02;
    if(i == 0.0)
        printf("Double value is i = %f\n", i);
    else if(i == j) 
        printf("i == j\n");
    else     
        printf("Invaild input.\n");
    
}

// 全局变量否会影响局部变量
void all_parameter()
{
    g_InvaildInput = false;
    int i=0;
    if( i == 0)
        g_InvaildInput = true;

    printf("all_parameter g_InvaildInput is : %d\n", g_InvaildInput);        
}


int main()
{   
    test_double();
    
    printf("main1 g_InvaildInput is : %d\n", g_InvaildInput);        
    all_parameter();
    printf("main2 g_InvaildInput is : %d\n", g_InvaildInput);        

    return 0;
}