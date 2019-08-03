// 面试题62：圆圈中最后剩下的数字
// 题目：0, 1, …, n-1这n个数字排成一个圆圈，从数字0开始每次从这个圆圈里
// 删除第m个数字。求出这个圆圈里剩下的最后一个数字。
/*
*   1. 解题思路:
        a. 每次删除第m个位置的数字后, 以位置(m+1)作为起始位置;
        b. 约瑟夫环问题
    
    // 没做出来

    2. 方法一: 环形链表模拟圆圈的经典解法
        a. n个节点的链表, 每次从这个链表中删除第m个节点;
        b. 让最后一个节点指向头结点;   

    3. 方法二:   通过数学规律进行
        f(n,m) =                                 0     , n = 1
                        [f(n-1, m) + m] % n,   n>1
*/
#include <stdio.h>

/*****************方法二:   通过数学规律进行********************/
int lastRemaining(unsigned int n, unsigned int  m)
{
    if(n<1 || m<1)
        return -1;
    int last    =   0;
    for(int i = 2; i <= n; i++)
        last    =   (last   +   m)  %   i;
    
    return last;
}

/********************Test code********************/
void Test(const char* testName, unsigned int n, unsigned int m, int expected)
{
    if(testName != NULL)
        printf("%s begins: \n", testName);

    if(lastRemaining(n, m) == expected)
        printf("Solution1 passed.\n");
    else
        printf("Solution1 failed.\n");

    // if(LastRemaining_Solution2(n, m) == expected)
    //     printf("Solution2 passed.\n");
    // else
    //     printf("Solution2 failed.\n");

    printf("\n");
}

void Test1()
{
    Test("Test1", 5, 3, 3);
}

void Test2()
{
    Test("Test2", 5, 2, 2);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();

    return 0;
}
