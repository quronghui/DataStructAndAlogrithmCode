//
// Created by quronghui on 2019/9/3.
//
/*
 * 实现memcpy复制函数， 以及对其进行优化
 *  方法一：没有考虑到内存重叠情况
 * 方法二：考虑到存在内存空间覆盖的问题；
 * 方法三：对memcpy复制效率的改进
 * */
#include <iostream>
#include <assert.h>
#include <stdlib.h>

using namespace std;

/*
 * 方法一：没有考虑到内存重叠情况
 * */
// (1)类型全部是void *，可是是任何类型；
// (2)src：修饰为const，只读元素；
void *mymemcpy(void *dst, const void *src, size_t num)
{
    assert((dst != nullptr) && (src != nullptr));
    unsigned char *psrc = (unsigned char *)src;
    unsigned char *pdst = (unsigned char *)dst;
    while( num-- > 0 )
        *pdst++ = *psrc++;
    return dst;
}

/*
 * 方法二：考虑到存在内存空间覆盖的问题；
 * （1）栈空间的增长：高地址到低地址增长；会造成内存覆盖现象
 * （2）将src和dest都移动 n-1个位置，这样我们就可以从低址值向高地址进行拷贝
 * */
void *my_memcpy_two(void *dst, const void *src, size_t num)
{
    assert((dst != nullptr) && (src != nullptr));
    //如何移动
    char *res = (char *)dst;
    char *p   = (char *)dst;
    const char *q = (const char *)src;
    // 不会发生内存覆盖的现象：首地址，dst<=src；或者dst >= src+num
    if(p <= q || p >= q+num){
        while(num--)
            *p++ = *q++;
    }
    // 发生内存覆盖的现象：src < dst < src+num;
    else{
        p = p + num - 1; //将两个地址移动num-1的位置
        q = q + num - 1;
        while(num--)
            *p-- = *q--;
    }
    return res; //返回首地址才行
}

/*
 * 方法三：对memcpy复制效率的改进
 * */
void *my_memcpy_three(void *dst, const void *src, size_t num)
{
    assert((dst != nullptr) && (src != nullptr));
    int wordnum = num / 4;  //计算有多少个32bit，按四个字节进行复制
    int slice = num % 4;    //剩余的按照字节数拷贝；
    // 通过整形指针进行指向
    int *psrc = (int *)src;
    int *pdst = (int *)dst;
    while(wordnum--)
        *pdst++ = *psrc++;
    while(slice--)
        *((char *)pdst++) = *((char *)psrc++);
    return dst;
}

/*
 * Test1 code
 * */
void Test1()
{
    char dst[7] = {0};
    char src[6] = "hello";
    char *p = (char *)mymemcpy(dst,src,5);
    cout << p << endl;
}

/*
 * Test2 code
 * */
void Test2()
{
    char dst[7] = {0};
    char src[6] = "hello";
    char *p = (char *)my_memcpy_two(dst,src,5);
    cout << p << endl;
}

/*
 * Test3 code
 * */
void Test3()
{
    char dst[7] = {0};
    char src[6] = "hello";
    char *p = (char *)my_memcpy_three(dst,src,5);
    cout << p << endl;
}


int main()
{
//    Test1();
//    Test2();
    Test3();
    return 0;

}
