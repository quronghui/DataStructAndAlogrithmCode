// 题目三:  结构体和联合体的内存字节对齐计算?
/*
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
#if __WORDSIZE == 64
typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;
*/

#include <stdio.h>

// 结构体的定义
struct A
{
    __int16_t   a;      //结构体是所有成员的总和: 需要内存对齐
    __int16_t   b;      // #pragram pack(n) 默认为4 
    __int16_t   c;
};

struct B{
    __int8_t    a;
    __int32_t   b;
    __int16_t   c;
};

// 联合体的定义
union C{
    __int32_t   a;      // 联合体取最大的
    __int8_t    b;
    __int16_t   c;
};

union D{
    __int8_t    a;
    __int16_t   b;
    __int32_t   c;
};

int main()
{
    printf("struct A is %ld.\n", sizeof(struct A));
    printf("struct B is %ld.\n", sizeof(struct B));

    printf("union C is %ld.\n", sizeof(union  C));
    printf("union D is %ld.\n", sizeof(union  D));

    return 0;
}

/*结果
struct A is 6.
struct B is 12.
union C is 4.
union D is 4.
*/