/*
*   hashval.c 
*   1) 散列函数最好的选择；
*   2) nextprime：空间大小是素数，减小不同的key分配到同一空间
*   3) 分散链表的初始化：分配三个存储空间
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "hashval.h"

/* hash funcation */

Index hash(const char *key, int tablesize)
{
    unsigned int hashval = 0;
    while(*key != '\0' )
        hashval = (hashval << 5) + *key++;

    return hashval % tablesize; /* 均分 */
}

/* 散列空间：定义为素数，实现素数 */
int nextprime(int tablesize)
{

}

/* hashtable initialize_table 
1) 分配一个存储空间：存储 0 - tablesize；
2） 每一个 tablisize:分配一个数组，存储相同的值的关键字；
3) 每个数组：分配一个头指针 header
*/
Hashtable initialize_table(int tablesize)
{
    Hashtable h;
    int i;

    if(tablesize < MinTableSize){
        printf("table is too small");
        return NULL;
    }
    /* allocate table: 散列空间分配 */
    h = malloc(sizeof(struct hashtbl));
    if(h == NULL)
        printf("out of space\n");
    
    h->tablesize = nextprime(tablesize);    /* 散列空间：定义为素数 */

    /* allocate array of list */
    h->thelists = malloc(sizeof(List) * h->tablesize);  /* 定义数组的长度 */
    if(h->thelists == NULL )
        printf("out of soace!!\n");
    
    /* allocate list header */
    for(i = 0; i < h->tablesize; i++){
        /* 为每一个元素分配指针 含有头指针 */
        h->thelists[i] = malloc(sizeof(struct Node));
        if(h->thelists[i] == NULL )
            printf("out of soace!!\n");
        else
            h->thelists[i]->Next = NULL; 
    }
    return h;
}

/* find key 
1） 如果element是一个字符串，比较和赋值使用strcmp and strcpy
*/
Position find(ElementType key, Hashtable h)
{
    Position p;
    List l;

    l = h->thelists[hash(key, h->tablesize)];   /* 均分后，数组的大小 */
    p = l->Next;

    while(p != NULL && p->Element != key)
        /* strcmp and strcpy  */
        p = p->Next;
    return p;
}

/* insert 
1) 找到相同的就没有做（应该有个标志位，重复加1）
2）插在开头，尾部；
*/
void insert(ElementType key , Hashtable h)
{
    Position pos, newcell;
    List l;

    pos = find(key, h);

    if(pos == NULL){
        newcell = malloc(sizeof(struct Node));
        if(newcell == NULL)
            printf("out of space");
        else{
            l = h->thelists[hash(key, h->tablesize)];
            newcell->Next = l->Next;
            newcell->Element = key;
            l->Next = newcell;
        }
    }
}

/* 在散列的实现 */
Hashtable rehash(Hashtable h)
{
    int i, oldsize;
    Hashtable *oldcells;

    oldcells = h->thelists;
    oldsize = h->tablesize;

    /* creat a nre empty table */
    h = initialize_table(2*oldsize);

    /* scan old table, reinserting into new */
    for(i = 0; i < oldsize; i++)
        ??
}