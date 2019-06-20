// 题目： 测试队列函数的是否能正常工作 

#include "queue_interface.h"
#include <stdio.h>


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
//     puts("test_malloc_array_queue:  ");

//     /* create queue */
//     create_queue(4);    /* 统一存储4个元素 */

//     /* insert value */
//     for (int i = 15; i < 19; i++)
//     {
//         insert(i);
//     }

//     /* return and delete */
//     while ( !is_empty() ){
//         printf("%d ", first());
//         delete_m();
//     }
//     putchar('\n');

//     /* delete_m */
//     destory_queue();
// }

void test_link_queue()
{
    puts("test_link_queue:  ");

     /* insert value */
    initQueue();
    for (int i = 20; i < 24; i++)
    {
        insert(i);
    }
    
    /* return and delete */
    while ( !is_empty() ){
        printf("%d ", first());
        delete_m();
    }
    putchar('\n');

    /* delete_m */
    destory_queue();
}


/****************main () *****************/
int main()
{
    // test_static_array_aueue();

    //test_malloc_array_queue();    

    test_link_queue();

    return 0;
}
