// 面试题50（一）：字符串中第一个只出现一次的字符
// 题目：在字符串中找出第一个只出现一次的字符。如输入"abaccdeff"，则输出 'b'。
/*
   1. 解题思路:  建立Hash表
            a.  Hash表的键值(Key)是字符,  value 是出现的次数
            b. 无符号字符(char 是一个8bit的类型), 总共有256种可能, 创建一个大小为256的数组; 

    2. 注意:
        字符串为NULL时, 字符返回的是'\0';

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*********************Hash-key进行查找**********************/
char firstNotRepeatingChar( const char *string )
{
    // 边界条件: 字符返回的是'\0'
    if( string == NULL)
        return '\0';                
    
    // 定义哈希数组, 并进行初始化;
    // 也可以动态进行定义
    const  int table = 256;
    unsigned int    hashTable[table];
    memset(hashTable, 0, 256);  

    // hash-Key -value :  第一遍的遍历, 更新每一个字符 , 以及每一个字符出现的次数出现的次数;
    // 将字符作为数组的下标;
    const char *hashKey = string;
    while( *hashKey !=  '\0' ){
        // hashTable[ *(hashKey++) ]++;
        // 能否进行分级替换
        char key = *hashKey;
        hashTable[key]++;       // 字符串中含有对应的下标字符, 则加1;
        hashKey++;
    }   

    // hash-value; 第二遍的遍历, 在O(1)时间内读出每一个字符的次数,  时间复杂度仍然是O(N)
    hashKey = string;
    while(  *hashKey != '\0' ){
        if( hashTable[*hashKey] == 1 )      // 第一个出现一次的值
            return *hashKey;

        hashKey++;
    }
    return '\0';
}

/************************Test code************************/
void Test(const char *string, char expected)
{
    char keyValue = firstNotRepeatingChar(string);
    if( keyValue == expected )
        printf("The keyValue == expected  is %c passed.\n", keyValue);
    else
        printf("The keyValue != expected  is %c failed.\n", keyValue);
}

// main()
int main()
{
    Test( "aaccdefgg", 'd' );
    // Test( "google", 'l' );

    return 0;
}