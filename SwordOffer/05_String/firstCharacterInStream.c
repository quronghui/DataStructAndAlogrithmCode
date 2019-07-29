// 面试题50（二）：字符流中第一个只出现一次的字符
// 题目：请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从
// 字符流中只读出前两个字符"go"时，第一个只出现一次的字符是'g'。当从该字
// 符流中读出前六个字符"google"时，第一个只出现一次的字符是'l'。
/*
    1. notes:
        a. 字符流和字符串的区别: 字符流只能一个字符一个字符的读入;
    2. 解题思路
        a. 通过建立hash表, 以字符作为下标; 初始的value = -1;
        b. 当一个字符是第一次读入, 将其的value 更新为 index--它的位置;
        c. 当一个字符是第二次读入时, 将其的index更新为特殊值-2;
        d. 当所有字符流数据输入完后, 遍历一遍数组, 找到值   >=0的字符就行;
    3. 问题:
        a. 为啥在初始化哪里就会一直错误?
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

const int  table = 256;
unsigned int hashStream[256];

// 通过结构体实现, 简单的析构函数
typedef struct firstCharacterInStream
{
    int index;              // 初始化字符流的个数;
    unsigned int  *hashTable;
} stream ;

// 初始化
void init_stream(stream *s ){
    s->index = 0;
    s->hashTable  = hashStream;
    memset(s->hashTable, -1, table);
    // return s;
}

// 读入一个字符
void insert( stream *s,  char ch){
    if(s->hashTable[ch] == -1 )
        s->hashTable[ch]    =   s->index;

    else if( s->hashTable[ch] >=0 )     // 当字符流第二次出现;
        s->hashTable[ch]    =   -2;
    
    s->index ++;
}

// 从数组中找出第一个出现的, 只出现一次的字符
char firstCharacterStream(  stream *s )
{
    // 边界条件
    if( s ==  NULL)
        printf(" The stream is null.\n ");
    
    char chstream = '\0';

    // 遍历数组
    for( int i=0 ; i < table;  i++ ){
        if( s->hashTable[i] >= 0 && ( i <= s->index) ){
            // ru 如何通过字符的位置, 得到数组的下标
            chstream = (char )i;
            return chstream;
        }
    }
    return chstream;

}

/*************************Test code****************************/
void Test( char *name, stream *s, char expected )
{
    if(name != NULL)
        printf("%s begin:    ", name);
    
    char ch = firstCharacterStream(s);
        if( ch == expected )
        printf("The ch == expected  is %c passed.\n", ch);
    else
        printf("The ch != expected  is %c failed.\n", ch);
}

// main()
int main()
{
    stream *s = NULL; 
    init_stream(s);

    // Test("Test1", s, '\0');

    insert(s, 'g');
    Test("Test2", s, 'g');

    return 0;
}