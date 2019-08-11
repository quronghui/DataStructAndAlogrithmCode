// 面试题23：链表中环的入口结点
// 题目：一个链表中包含环，如何找出环的入口结点？
/*
*   1. 题目提示：
        a. 如何判断一个链表中存在环：创建快慢指针，*front, *rear , 
            循环时：每循环一次 ， front 快走两步，rear走一步；（front不能固定一个次数，否则无法相遇）
            当front == rear 时：存在一个环； 
            返回值：返回front的节点
        b. 根据存在的环，得出环中的节点数 k
            通过此时返回的front , front肯定是在 loop中；在定义一个指针从front循环一次；
        c. 找出环形入口节点
            定义两个指针：A 指针先走k步，A B指针同时走； 
            当A=B时，此节点就是环形入口，return B
    2. 解题思路
        先判断环的存在, 得到环中节点的个数;
        根据节点的个数, 定义快慢指针, 找出入口节点;
*/
#include <stdio.h>
#include "one_list.h"

/****************判断链表中是否存在环****************/
List *LoopJudge( List *pHead )
{
    if(pHead == NULL){          // 基础条件
        puts("List is null.");
        return NULL;
    }
    // 定义慢指针
    List *rear = pHead->pNext;
    if(rear == NULL){
        puts("List's pHead->pNext is null.");
        return NULL;
    }
    // 定义快指针
    List *front = rear->pNext;
    while( front != NULL && rear != NULL ){
        // 当他们相遇时，存在环
        if(rear == front)
            return front;
        rear = rear->pNext;
        front = front->pNext;
        // 每循环一次，让front 快指针都加1
        if(front != NULL)
            front = front->pNext;
    }
    printf("The list don't have loop.\n");
    return NULL;
}

/****************判断环中的节点数，并找出入口节点*******************/
List *EnterNodeOfLoop(List *pHead)
{
    List *meetingLoop = LoopJudge(pHead);
    if(meetingLoop == NULL)
        return NULL;        // loopjudge 函数里面都有错误处理报告，这里就不写了
    // 存在环，得到节点数
    List *LoopNode = meetingLoop;   //meetingLoop返回节点就是在环里面
    int loopNumber = 1;             
    while( LoopNode->pNext != meetingLoop ){
        LoopNode = LoopNode->pNext;
        ++loopNumber;
    }
    // 找出入口节点
    List *Loopfront = pHead;   // 快节点先移动loopnumber次
    for(int i=0; i<loopNumber; i++)
        Loopfront = Loopfront->pNext;
    // 同时移动两个指针，相遇时，返回节点
    List *Looprear = pHead;
    while(Loopfront != Looprear){
        Loopfront = Loopfront->pNext;
        Looprear = Looprear->pNext;
    } 
    return Looprear;
}

/*************************void test****************************/
void Test(char *name, List *pHead, List *enterNode)
{
    if(name != NULL)
        printf("%s  begin:", name);

    List *loopEnter = EnterNodeOfLoop(pHead);
    
    if( loopEnter == enterNode )
        printf("passed.\n");
    else 
        printf("failed.\n");

}
// 建立一个带有loop的链表
void test1()
{   
    // 创建单节点
    List *pNode1 = CreatNode(1);
    List *pNode2 = CreatNode(2);
    List *pNode3 = CreatNode(3);
    List *pNode4 = CreatNode(4);
    List *pNode5 = CreatNode(5);
    List *pNode6 = CreatNode(6);
    // 链接节点间的关系
    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode3);
    // 测试函数
    Test("test1", pNode1, pNode3);

    // DestoryList(pNode1);     //这里如果要删除节点，就需要一个节点一个节点的释放，因为有循环
}
// main 函数
int main()
{
    test1();
    return 0;
}