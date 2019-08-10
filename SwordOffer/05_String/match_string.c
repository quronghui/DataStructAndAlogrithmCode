// 面试题19：正则表达式匹配
// 题目：请实现一个函数用来匹配包含'.'和'*'的正则表达式。
// 模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。
// 在本题中，匹配是指字符串的所有字符匹配整个模式。
// 例如，字符串"aaa"与模式"a.a"和"ab*ac*a"(b,c 选择0次)匹配，但与"aa.a"及"ab*a"均不匹配。

/*
*   1. 题目提示：匹配是指字符串的所有字符匹配整个模式。
        a. string = “bab” 中的第一个字符匹配有几种形式 
        b. pattern : 1) b; 2) '.'; 3) .*b;
            判断条件：查看pattern 第二个字符是否是 *

        c. 针对string中的每一个字符，需要考虑这三种情况；
            所以可以使用递归来实现；
    2.解题思路：
        a. 使用bool类型；
*/
#include <stdio.h>
#include <stdbool.h>

// 函数声明 
bool matchCore(char *str, char *pattern);   

/*************匹配函数接口：***************/
bool match(char *str, char *pattern)
{
    if(str == NULL || pattern == NULL){
        puts("String is null.");
        return false;
    }
    return matchCore(str, pattern);     // 这样写函数：要进行递归调用
}

/***************递归调用：正则匹配函数***************/
bool matchCore(char *str, char *pattern)
{
    /* 边界情况 */
    if(*str == '\0' && *pattern == '\0')     // 字符串以'\0'结尾
        return true;
    if(*str != '\0' && *pattern == '\0'){    // 正则表达式为空
        puts("Regular expression is null: ");
        return false;
    }

    // 当 pattern 第二个字符是 '*'时
    if( *(pattern + 1) == '*' ){
        if( *pattern == *str || (*pattern == '.' && *str != '\0')) {  // 第一个字符相等了
            return matchCore(str+1, pattern+2)  // * 代表前面字符出现一次；比较下一个字符；
                || matchCore(str+1, pattern)    // 查看str+1 下一个字符：是否是重叠的；
                || matchCore(str, pattern+2);   // 忽略 pattern 的前两个字符；比较第三个字符；
        }
        else 
            return matchCore(str, pattern+2);   // 忽略 *
    }
    // 当第二个字符不是 * :但是第一个字符得满足相等
    if( *str == *pattern || (*pattern == '.' && *str != '\0') )
        return matchCore(str+1, pattern+1);
    
    return false;
}

/*************test code******************/
void Test(char *name, char *str, char *pattern, bool expected)
{
    if(name != NULL)
        printf("%s test begin: ", name);
    if(match(str, pattern) == expected)
        printf("passed.\n");
    else 
        printf("failed.\n");
}

int main(void)
{
    Test("Test01", "", "", true);
    Test("Test02", "", ".*", true);
    Test("Test03", "", ".", false);
    Test("Test04", "", "c*", true);

    Test("Test05", "a", ".*", true);    // 查看第一个字符
    Test("Test06", "a", "a.", false);
    Test("Test07", "a", "", false);
    Test("Test08", "a", ".", true);
    Test("Test09", "a", "ab*", true);
    Test("Test10", "a", "ab*a", false);

    Test("Test11", "aa", "aa", true);  // 查看str+1 下一个字符：是否是重叠的；
    Test("Test12", "aa", "a*", true);
    Test("Test13", "aa", ".*", true);
    Test("Test14", "aa", ".", false);

    Test("Test15", "ab", ".*", true);
    Test("Test16", "ab", ".*", true);
    Test("Test17", "aaa", "aa*", true);
    Test("Test18", "aaa", "aa.a", false);
    Test("Test19", "aaa", "a.a", true);
    Test("Test20", "aaa", ".a", false);
    Test("Test21", "aaa", "a*a", true);
    Test("Test22", "aaa", "ab*a", false);
    Test("Test23", "aaa", "ab*ac*a", true);
    Test("Test24", "aaa", "ab*a*c*a", true);
    Test("Test25", "aaa", ".*", true);
    Test("Test26", "aab", "c*a*b", true);
    Test("Test27", "aaca", "ab*a*c*a", true);
    Test("Test28", "aaba", "ab*a*c*a", false);
    Test("Test29", "bbbba", ".*a*a", true);
    Test("Test30", "bcbbabab", ".*a*a", false);

    return 0;
}

