/*
*   题目：双链表 节点的插入和删除
*   1) 双链表的插入有四种情况：
*       a.插入到链表中间；b.插入到起始位置；  
*       c.插入到末尾节点；d.插入到空链表中;   
*   2)Parameter:
        *phead; 头指正；
        *fwd: 前向指针
        *bwd: 后向指针   
        *preview 插入节点的前驱节点；
        *pNode : 插入节点的后一个节点；
    3)双链表 需要 根节点, 保存两个指针
        a. root->pwd：指向最后一个节点； 第一个节点的 fwd = null; 这样才能从头后者末尾开始访问
        b. fwd 指向第一个节点； 
        c. pwd 指向最后一个节点；
    4) 链表通过画图，得到控制条件
        a.  先遍历找出插入点的位置： 
        a.  previous != pHead
        b.  pNode != Null 
*/
typedef struct doubleListNode List;

struct doubleListNode
{
    int mValue;
    List *fwd;
    List *pwd;
};

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/****************** insertValue*******************/
bool insertValue(List *pHead, int value)
{
    List *previous = pHead; 
    List *pNode = previous->fwd;

    while(pNode != NULL ){         /* 查看value 是否重复，相同值赋值给指针，就会重复*/
        if(pNode->mValue == value){        /* 头结点的值 */
            printf("Repeat value.\n");            
            return false;
        }
        else if(pNode->mValue < value){  /* 找出插入节点的前驱节点 */
            previous = pNode;
            pNode = pNode->fwd;
        }
        else 
            break;  
    }

    List *pNew = malloc(sizeof(struct doubleListNode));
    if(pNew == NULL ){    
        printf("out of space!\n");  /* 指针未分配成功 */
        return false;
    }
    pNew->mValue = value;
    
    /* 根据previous是否为头节点 and pNode 是否为空作为判断  */
    pNew->fwd = pNode;        
    previous->fwd = pNew;
    
    /*previous != pHead*/
    if(previous != pHead)
        pNew->pwd = previous;
    else 
        pNew->pwd = NULL;
    
    /* pNode != Null */
    if(pNode != NULL)
        pNode->pwd = pNew;
    else 
        pHead->pwd = pNew;      /* 根节点的指针指向最后节点 */
    
    // // 添加到链表中
    // if(pNode != NULL){      /* 插入点之后中有节点，插入的位置不在末尾 */
    //     pNew->fwd = pNode;         /* 重复代码 */
    //     if(previous != pHead){    /* a. 前驱节点不等于头结点 插入在中间位置 */
    //         // pNew->fwd = pNode;   
    //         previous->fwd = pNew;
    //         pNew->pwd = previous;
    //         // pNode->pwd = pNew;
    //     }
    //     else{                   /* b. 插入在开头位置 */
    //         // pNew->fwd = pNode;
    //         pHead->fwd = pNew;  /* 双链表有头结点 */
    //         pNew->pwd = NULL;
    //         // pNode->pwd = pNew;
    //     }
    //     pNode->pwd = pNew;          /* 重复代码 */
    // }
    // else {  /* 插入点之后没有节点，插入的位置在末尾 */
    //     pNew->fwd = NULL;
    //     if(previous != pHead){  /* a. 前驱节点不等于头结点 插入在末尾位置 */
    //         // pNew->fwd = NULL;
    //         previous->fwd = pNew;
    //         pNew->pwd = previous;
    //         // pHead->pwd = pNew;      /* 根指针pwd指向最后一个节点 */
    //     }
    //     else{
    //         // pNew->fwd = NULL;
    //         pHead->fwd = pNew;
    //         pNew->pwd = NULL;
    //         // pHead->pwd = pNew;
    //     }
    //     pHead->pwd = pNew;
    // }
    return true;
}
/**************test insert*******************/
void print(List *pHead)
{
    while(pHead != NULL){
        printf("list value: %d --> ", pHead->mValue);
        pHead = pHead->fwd;
    }
    printf("\n");
}

void test()
{
    List *root = malloc(sizeof(struct doubleListNode));
    root->fwd = root->pwd = NULL;                    /* 指针定义后要初始化 */
    
    int result = insertValue(root, 5);
    if(result)  printf("insert successful\n");
    else    printf("insert failed.\n");

    //print(root); 

}

int main()
{   
    test();
    return 0;
}
