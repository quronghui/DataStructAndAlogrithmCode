// 题目： 测试队列函数的是否能正常工作 

#include <stdio.h>
#include "link_queue_interface.h"
// #include "array_queue_interface.h"

/***********test static_array_queue.c************/
// void test_static_array_aueue()
// {
//     puts("test_static_array_aueue:  ");
//     /* insert value */
//     for (int i = 10; i < 14; i++)
//     {
//         insert(i);
//     }

//     /* return and delete */
//     while ( !is_empty() ){
//         printf("%d ", first());
//         delete_m();
//     }
//     putchar('\n');
// }

/***********test static_array_queue.c************/
// void test_malloc_array_queue()
// {
//     puts("test_malloc_array_queue: ");

//     /* create queue */
//     QueueArrayNode *queue = array_create_queue(5);    /* 统一存储4个元素 */

//     /* insert value */
//     for (int i = 15; i < 20; i++)
//     {
//         enQueue(queue, i);
//     }

//     /* return and delete */
//     while ( !is_empty(queue) ){
//         printf("%d ", first(queue));
//         delQueue(queue);
//     }
//     putchar('\n');

//     /* delete_m */
//     destory_queue(queue);
// }


/***********test test_link_queue.c************/
void test_link_queue()
{
    puts("test_link_queue:  ");

    // 链式队列的创建
    QueueNode *queue = create_queue();
    // 入队
    for (int i = 20; i < 24; i++)
    {
        enQueue(queue, i);
    }

    while ( !is_empty(queue) ){
        
        printf("%d ", first(queue));
        delQueue(queue);
    }
    putchar('\n');

    /* delete_m */
    destory_queue(queue);
}


/****************main () *****************/
int main()
{
    // test_static_array_aueue();

    // test_malloc_array_queue();    

    test_link_queue();

    return 0;
}
