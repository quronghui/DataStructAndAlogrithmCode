// 面试题48：最长不含重复字符的子字符串
// 题目：请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子
// 字符串的长度。假设字符串中只包含从'a'到'z'的字符。
// 扩展: 将这个长的字符串打印出来:
        // 通过position 的下标和: 
/*
*   1.解题注意
        a. 知道如何记录前面的字符串; 使用一个26大小的hash数组,进行记录;
    2.解题思路一:
        暴力法: 枚举
    3. 解题思路二: 动态规划
        a. 函数f(i): 以第i个字符结尾,不重复的最长长度;
        b. 如果第i 个字符前面没有出现: f(i) = f(i-1) + 1;
        c. 如果第i个字符前面出现过: 记录他们间的距离d
            d <= f(i-1): i上次出现在f(i-1)中; f(i) = d;
                同时意味着: 第i个字符所夹的字符串中没有其他重复字符;
            d > f(i-1): 第i个字符出现在f(i-1)对应的最长字符串之前;
                f(i) = f(i-1)+1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/****************解题思路二: 动态规划******************/
int longSubstring(const char *string)
{
    int curLength = 0;
    int maxLength = 0;
    // 定义hash数组保存重复字符下标
    int *position = (int *)malloc(sizeof(int) * 26);
    memset(position, -1, sizeof(int)*26);   // int 一个是占4byte的
    // for(int i=0; i<26; i++)
    //     position[i] = -1;

    int length = strlen(string);
    // 对string进行遍历
    for(int i=0; i<length; i++){
        // 将字符转化为 0-26 之间的整数, 用作position的下标;
        int preIndex = position[string[i] - 'a'];
        // 如果这个字符没有出现过, 或者之间的 d>f(i-1)
        // 第i个字符长度 f(i) = f(i-1) + 1
        if(preIndex < 0 || (i-preIndex) > curLength)
            curLength++;    
        else{
            if(curLength > maxLength)
                maxLength = curLength;
            curLength = i - preIndex;
        }
        position[string[i] - 'a'] = i;  // 将出现的字符, 数组元素设置为i;
    }
    // 遍历完成
    if(curLength > maxLength)
        maxLength = curLength;
    
    free(position);

    return maxLength;
}

/**************************test code*************************/
void Test(char *name, const char *string, int expected)
{
    if(name != NULL)
        printf("%s test begin: ", name);
    
    int maxLength = longSubstring(string);
    if(maxLength == expected)
        printf("maxLength == expected is %d passed.\n", maxLength);
    else
        printf("maxLength != expected is %d failed.\n", maxLength);

}

//test1()
void test1()
{
    const char *string = "abcacdefghi";
    int expected = 3;
    Test("test1", string, expected);
}

//main
int main()
{
    test1();
    return 0;
}