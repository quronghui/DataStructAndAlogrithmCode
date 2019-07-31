// 面试题56（二）：数组中唯一只出现一次的数字
// 题目：在一个数组中除了一个数字只出现一次之外，其他数字都出现了三次。
// 请找出那个只出现一次的数字。
/*
    1.解题思路: 
        a. 其余数字都出现三次, 还是使用位运算;
        b. 一个数字出现三次, 他的二进制表示的每一位(0/1)也出现三次;
        c. 把出现三次的数的每一位分别加起来, 每一位都会被3整除;
        d. 将每一个的二进制位都相加 [1, 1, 1, 4, 3, 3, 3]
        0 0 1                                   sum = [ 1, 3 , 6]
    +  0 0 1               出现一次的数         1 , 0, 0
    +  0 0 1
    +  1 0 0
    +  0 1 1
    +  0 1 1 
    +  0 1 1    
        e. 出现一次的数, 所在的位不能被3整除;
    2. 题目时间和空间
        时间是O(N),对每一个数遍历一遍;
        空间复杂度: 需要一个32位的存储空间; 因为一个int型, 32bit
*/
#include <stdio.h>

/*********************计算每个数的各位之和**********************/
int findAppearingOnce(int number[], int length)
{
    if(number == NULL || length <= 0){
        printf("Invalid input\n");
        return 0;
    }
    // 统计每个数转化为二进制后, 1的个数
    int bitSum[32] = {0};
    for(int i = 0; i < length; i++){
        int bitMask = 1;
        // 统计每一个数中1的个数;
        for(int j = 31; j >=0; j--){
            int bit = number[i] & bitMask;
            if(bit != 0)
                bitSum[j] += 1;
            bitMask = bitMask << 1;     // 左移
        }
    }
    //  通过计算得到出现一次的值
    int result = 0;
    for(int i=0; i<32; i++){
        result = result << 1;
        result += bitSum[i] % 3;
    }

    return result;
}

/*************************Test code*********************/
void Test(const char* testName, int numbers[], int length, int expected)
{
    int result = findAppearingOnce(numbers, length);
    
    if(result == expected)
        printf("%s passed.\n", testName);
    else
        printf("%s FAILED.\n", testName);
}

// 所有数字都是正数，唯一的数字是最小的
void Test1()
{
    int numbers[] = { 1, 1, 2, 2, 2, 1, 3 };
    int expected = 3;
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 所有数字都是正数，唯一的数字的大小位于中间
void Test2()
{
    int numbers[] = { 4, 3, 3, 2, 2, 2, 3 };
    int expected = 4;
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), expected);
}
// 所有数字都是负数
void Test7()
{
    int numbers[] = { -1024, -1024, -1024, -1023 };
    int expected = -1023;
    Test("Test7", numbers, sizeof(numbers) / sizeof(int), expected);
}
// main
int main()
{
    Test1();
    Test2();
    Test7();
    return 0;
}