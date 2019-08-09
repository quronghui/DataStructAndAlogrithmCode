// 面试题3（一）：找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3

/*
*   找出数组中重复的数字 : 
*   1) 题目中提示：n个数，每个数的范围是 0-(n-1)
*   2) 关键：找下标和对应数组值的关系。
*   3) 方法：
        方法a. 将数组排序，然后遍历一遍便能得出结果，时间效率是O(nlog(n))
        方法b. 创建哈希表，需要额外的空间，空间效率O(n)
        方法c. 判断条件：下标和值对应相等, 不相等则进行交换；需要对原来数组进行改变
    4. code：选择最优的方法进行编码
        a. 属于参数的判断，鲁棒性的测试
*/

#include <stdio.h>
#include <stdbool.h>

// 功能函数的实现
/* 
parament : 
    number: 整个数组
    length： 数组长度
    duplication： 重复数字,输出
judge： 
    采用的方法
return:
    true: 输入有效，存在重复数字；输出重复数字
    false：输入无效，不存在重复数字；
*/

bool duplicate(int number[], int length, int *duplication)
{
    /* 1. 鲁棒性判断，是否为空*/
    if(number == NULL || length <= 0)   return false;
    
    /* 2. number 值的判断 0 - n-1 */
    for(int i=0; i<length; i++ ){
        if(number[i] < 0 || number[i] > length-1 )
            return false;
    }

    /* fucation  : number[j] != j  下标和值相等 */
    for(int j=0; j<length; j++){
        while(number[j] != j){
            /* 判断交换的那个元素是否重复 */
            if(number[j] == number[number[j]]){
                *duplication = number[j];
                printf("duplication is =  %d \n", number[j]);   /* 保证不了每次都能输出重复数字 */
                return true;
            }
            /* swap numbers[i]和numbers[numbers[i]]  */
            int temp = number[j];
            number[j] = number[number[j]];
            number[temp] = temp;   /* number[number[j]] = temp; 防止重复计算*/
        }
    }
    return false;
}

/* test code 根据功能函数去写*/
// 测试代码很难写
bool contains(int array[], int length, int number)
{
    for(int i = 0; i < length; ++i)
    {
        if(array[i] == number)
            return true;
    }

    return false;
}


void test(char *name, int number[], int lengthnumber, int expected[], int expectedExpected, bool validArgument)
{
    printf("%s begin:", name);

    int duplication;
    bool validInput = duplicate(number, lengthnumber, &duplication);

    if(validArgument == validInput)
    {
        if(validArgument)
        {
            if(contains(expected, expectedExpected, duplication))
                printf("Passed.\n");
            else
                printf("FAILED.\n");
        }
        else
            printf("Passed.\n");
    }
    else
        printf("FAILED.\n");

}


void test1(){
    int number[] = {2, 4, 2, 1, 4}; 
    int duplications[] ={2, 4};
    test("Test1", number, sizeof(number)/sizeof(int), duplications, sizeof(duplications)/sizeof(int), true); 
}
void test2(){
    int number[] = {1, 3, 4, 2, 1}; 
    int duplications[] ={1};
    test("Test2", number, sizeof(number)/sizeof(int), duplications, sizeof(duplications)/sizeof(int), true); 
}

void main(void){
    test1();    /* 函数的调用，后面是有括号的 */

}