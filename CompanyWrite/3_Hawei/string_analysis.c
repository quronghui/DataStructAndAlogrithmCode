// 题目一: 字符串的解析;   --- 还没有完成
/*
    1. 题目的理解:  字符串的一个解析
    2. 先得到一个字符串数集合
        a. 从字符串末尾往前遍历, 找出'@'字符的位置;
            然后用两个指针, 分别指向两个字符集;
        b. 对于已占用字符集, 构建一个哈希表, 存储以26*2英文字母空间 和 已占用的次数;
            区分英文字母
        c. 每次比较全字符中的字母和数字, 在O(1)时间找到并输出
    3. 注意:
        a. 字母 + 数字:  连接是':'
        b. 字符  之间: 连接是 ','
        c. 输出的时候还要注意, 如果只有一组的话, 最后那个"," 不输出
    4. 哈希表的自加: 要进行自加
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

void FindTheNoUse(char *string, int length)
{
    // 字符串为空
    if(string == NULL)
        return; 

    // 建立一个以字母为下标的哈希表
    int number = 26*2 + 1;
    int array  [number];
    memset(array, 0, number);

    // 先遍历字符串找到字符"@; 从字符串后进行遍历
    for( int i = length - 1 ;  i >= 0  ; i = i-2 ){    
        if( string[i] == '@' )
            break;

        // 对已占用的字符集遍历,构建哈希表;       
        // 判断数字是否都为正整数;
        int value = string[i] - '0';  
        if(value < 0)
            return ;
        i = i - 2;          // 指向字母
        // char gdb = string[i];
        if( ( 'A'  < string[i] && string[i] < 'Z' ) ||   ( 'a'  < string[i] && string[i] < 'z')  )
            array[string[i]]    =     value;
        
        // 判断下一个是不是字符@
        if(string[i-1] == '@')
            break;
    }

    // 如果不存在占用字符, 那么将字符串全部输出
    if(string[length - 1] == '@'){
        printf("%s\n", string);
        return ;
    }
    // 从全量字符进行遍历, 减去相应的值后输出;
    for( int i=0; i < length - 1; i = i + 2 ){
        char ch = string[i];
        int useNumber = array[ch];
        i = i + 2;
        int Nouse   =   string[i] - '0'   -   useNumber;
        
        // 如果只有一组数的话, 
        if(Nouse > 0  ) {
            if ( string[i+1] == '@' )
                printf("%c:%d", ch, Nouse);
            else 
                printf("%c:%d,", ch, Nouse);
        }

        // 判断下一个字符是不是@
        if( string[i+1] == '@' )
            break;
    }
    printf("\n");
}

// // 只存在一个字符串, 不计算
void Test1()
{
    char string[100] = "a:3@a:2";
    int length = strlen(string);
    FindTheNoUse( string, length );
}

void Test2()
{
    char string[100] = "a:1,b:2,c:3@a:1,b=1,c=2";
    int length = strlen(string);
    FindTheNoUse( string, length );
}


/*****************Test code**********************/
int main()
{
    Test1();
    // Test2();

    // char string[100];
    // scanf("%s", string);
    // FindTheNoUse( string, strlen(string) );

    return 0;
}