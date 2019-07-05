// 面试题33：二叉搜索树的后序遍历序列
// 题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则返回true，否则返回false。假设输入的数组的任意两个数字都互不相同。
// 题目扩展：思路一：判断一棵树是不是二叉树？（1）先得到它的后序遍历；（2）递归后续便利是否满足；
    // 思路二： 直接递归检查，左边不为空的时候，小于其父节点
/* 
*   1.解题思路：
        a.根据后序遍历中，root在最后一个，将序列分为两部分；
        b.左半部分 < root < 右半部分 (当左半部分出现大于 root， 将后面的所有节点归于右半部分)
        c.依次判断每一部分时候满足； （出现错误：右半部分出现了小于root的节点序列）
    2.判断是与否：bool 建立指针；
*/
#include <stdio.h>
#include <stdbool.h>

/*****************二叉搜索树的后序遍历序列 的验证****************/
bool VerifySequence(int sequence[], int length)
{
    // 边界条件
    if(sequence == NULL || length < 1){
        printf("The sequence is null or parameter invailed.\n");
        return false;
    }
    // 以根节点元素进行判断
    int root = sequence[length - 1];
    // 左半部分长度, 记录值的个数
    int i = 0;
    for(; i < length-1; i++){   // 注意：length-1的位置被使用了
        if(sequence[i] > root )
            break;  
    }
    // 右半部分值大于根节点长度
    int j = i;
    for(; j < length-1; j++){
        if(sequence[j] < root)
            return false;       //出现错误：右半部分出现了小于root的节点序列
    }
    
    // 递归判断左子树
    bool left = true;
    if(i > 0)
        left = VerifySequence(sequence, i);
    //递归判断右子树
    bool right = true;
    if(i < length - 1)
        right = VerifySequence(sequence + i, length-i-1);   // 注意:右半部分的起始序列
    
    return (left & right);
}

/*******************Test code*******************/
// 就只需要判断序列
void Test(char *name, int sequence[], int length, bool expected)
{
    if(name != NULL)
        printf (" %s begin: ", name);
    if(VerifySequence(sequence, length) == expected)
        printf(" passed.\n");
    else 
        printf(" failed.\n");
}
// 序列属于二叉树的后序遍历
void test1()
{
    int sequence[] = {4, 8, 6, 12, 16, 14, 10};
    Test("test1", sequence, sizeof(sequence)/sizeof(int), true);
}
// main
int main()
{
    test1();
    return 0;
}