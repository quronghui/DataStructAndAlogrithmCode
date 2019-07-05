// 复杂链表的创建

#include "complexList.h"
#include <stdio.h>
#include <stdlib.h>

/**************创建每一个链表节点****************/
ComplexListNode *CreateNode(Type_ComList nValue)
{
    ComplexListNode *pNode = malloc(sizeof (ComplexListNode));

    pNode->mVaule = nValue;
    pNode->pNext = NULL;
    pNode->pSibling = NULL;

    return pNode;
}

/*****************为每一个节点创建链接关系*********************/
void BuildNodes(ComplexListNode *pNode, ComplexListNode *pNextNode, ComplexListNode *pSiblingNode)
{
    if(pNode != NULL){
        pNode->pNext = pNextNode;
        pNode->pSibling = pSiblingNode;
    }
}

void printList(ComplexListNode *pHead)
{
    ComplexListNode *pNode = pHead;
    while(pNode != NULL){
        printf("The value of this node is: %d.\n", pNode->mVaule);
        
        if(pNode->pSibling != NULL)
            printf("The value of its sibling is: %d.\n", pNode->pSibling->mVaule);
        else 
            printf("This node does not have a sibling.\n");
        
        printf("\n");
        pNode = pNode->pNext;
    }
}
