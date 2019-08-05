// 题目四: 有符号变量（负数）与无符号变量（正数）的相加

/*
    1. 原因是当表达式中存在有符号类型和无符号类型时所有的操作数都自动转换为无符号类型。
    2. 这个例子用的是: 8bit 的插入类型

*/
#include <stdio.h>

char getChar(int x, int y)
{
    char  c  ;
    unsigned int a=x ;
    (a+y>10) ?  (c=1) : (c=2) ;
    return  c ;
}

int main (void)
{
    char c1=getChar( 7 , 4 );
    char c2=getChar( 7 , 3 );
    char c3=getChar( 7,  -7);
    char c4=getChar( 7, -8 );

    printf( " c1 = %d " , c1 );
    printf( " c2 = %d " , c2 );
    printf( " c3 = %d " , c3 );
    printf( " c4 = %d \n" , c4 );

    return 0 ;
}

/*
char c3=getChar( 7,  -7);

        -7：1 1 1 1 1 0 0 1 （补码），   7：0 0 0 0 0 1 1 1
              1 1 1 1 1 0 0 1
   +         0 0 0 0 0 1 1 1
——————————————
            1 0 0 0 0 0 0 0 0         
计算结果产生了进位（第9位），除进位位外，其余8位均为0，因此，计算结果是0

*/
/*
char c4=getChar( 7, -8 );

      -8 ：1 1 1 1 1 0 0 0（补码）， 7：0 0 0 0 0 1 1 1
               1 1 1 1 1 0 0 0 
+             0 0 0 0 0 1 1 1
———————————————
               1 1 1 1 1 1 1 1  

没有产生进位，1 1 1 1 1 1 1 1 所对应的十进制为255，且大于0
*/