// 面试题30：包含min函数的栈
// 题目：定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min函数。
// 在该栈中，调用min、push及pop的时间复杂度都是O(1)。
/*
*   1.解题思路：
        a. 创建两个栈，一个数据栈，一个最小值栈
*/
#include "link_stack_interface.h"
#include <stdio.h>

void MinValue_push(StackNode *stack, STACK_TYPE value);


// 创建两个栈结构
void min_CreatStack()
{   
    // 创建栈
    StackNode *data_stack;
    StackNode *min_stack;

    data_stack = link_create_stack();
    min_stack  = link_create_stack();

    // 进行入栈操作 3
    int value1 = 3;
    push(data_stack, value1);    // 数据栈进行入栈；
    MinValue_push(min_stack, value1);

    // 进行入栈操作 4
    int value2 = 4;
    push(data_stack, value2);    // 数据栈进行入栈；
    MinValue_push(min_stack, value2);

    // 进行入栈操作 2
    int value3 = 2;
    push(data_stack, value3);    // 数据栈进行入栈；
    MinValue_push(min_stack, value3);

    // 进行入栈操作 1
    int value4 = 1;
    push(data_stack, value4);    // 数据栈进行入栈；
    MinValue_push(min_stack, value4);

    // 进行出栈判断是否是最小值
    puts("data_stack is : ");
    while(!is_empty(data_stack)){
        printf("%d\t", top(data_stack));
        pop(data_stack);
    }
    putchar('\n');

    // 最小值的栈
    puts("min_stack is : ");
    while(!is_empty(min_stack)){
        printf("%d\t", top(min_stack));
        pop(min_stack);
    }
    putchar('\n');

    destory_stack(data_stack);
    destory_stack(min_stack);
    
}

void MinValue_push(StackNode *stack, STACK_TYPE value)
{
    if( is_empty(stack) ){
        // 值进入最小栈
        push(stack, value);
    }
    else{
        int minValue = top(stack);
        
        if(value > minValue)
            push(stack, minValue);
        else 
            push(stack, value);
    }
}

/**************test code*****************/
int main()
{
    min_CreatStack();
    return 0;
}