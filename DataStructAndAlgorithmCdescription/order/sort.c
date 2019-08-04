/*
*   sort.c
*   1)insert_sort每次取后一个元素，和前面已排好序的数组进行比较；
*   2)shell sort : 希尔排序：缩小增量排序
*   3)binary sort：堆排序。构建一个堆后，进行delete_min，得到排序数组
*   3)merge sort :归并排序，按照中间位置分为两个数字，各自排序后插入到新的数组
*   4)quick sort  : 快速排序，取中间枢纽元素
*/
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/* insert_sort   */
void insertionSort(ElementType a[], int N)
{
    ElementType tmp;
    int j;
    for ( int i = 1; i < N; i++){
        tmp = a[i];         // 下一个需要插入的元素

        // 前面已排好序的 ( i-1 ) 个元素;
        for(int j = i; j>0 && a[j-1]>tmp; j--)  
            a[ j ] = a[j-1];                                    // 前面的大于 tmp, 则移动覆盖
        
        a[ j ] = tmp;                                          // 最后一个位置处理
    }
}

/* shell sort
*   1)希尔排序：缩小增量排序
*   2)元素之间的比较：a[i + h(k)] < a[i - h(k)]，对应元素之间的比较
*   3)每次删除的逆序对，不止一个逆序对；
*/
void shell_Sort(ElementType a[], int N)
{
    int i, j, increment;
    ElementType tmp;

    /* h(k) = N/2 ; 每次一半进行递减*/
    for(increment = N/2; increment > 0; increment /= 2)
        /* 循环：完后后半部分（N/2）每个元素，和前半部分元素之间的比较*/
        for(i = increment; i < N; i++){
            tmp = a[i];     /* 后半部分数组 */
            for(j = i; j >= increment; j -= increment)
                /* 包含在fork循环中的，if-else是一条语句 */
                if(tmp < a[j-increment])
                    a[j] = a[j - increment];
                else 
                    break;  /* 这里break后，就不执行 j -= increment 这条语句 */
            a[j] = tmp;
        }
}

/*)2）binary sort
*   1)现实中构建的堆：和二叉堆的性质相反之处 -- （任一节点的关键字大于其儿子节点的关键字）
*   2)delete_min：得到从小到大的排序数组
*   3)0位置包含元素的
*/
#define leftchild(i) (2*(i) + 1)

void PercDown(ElementType a[], int i, int N)
{
    int child;
    ElementType tmp;
    for(tmp = a[i]; leftchild(i) < N; i = child){
        child = leftchild(i);                       /* 找元件标号 */
        if(child != N-1 && a[child + 1] > a[child])
            child++;
        if(tmp < a[child])
            a[i] = a[child];
        else 
            break;
    }
    a[i] = tmp;
}

/* 元素交换 */
void swap(int *i, int *j)
{
    int *k;
    k = i;
    i = j;
    j = k;
}

void heapsort(ElementType a[], int N)
{
    int i;
    for(i = N/2; i >= 0; i--)   /*build heap*/
        PercDown(a, i, N);
    for(i = N -1; i > 0; i--){
        swap(&a[0], &a[i]);     /* delete_max */
        PercDown(a, 0, i);
    }
}

/* 
*   3）merge sort
*       1)按照中间位置：将数组不停的分为两部分；
×       2）在两部分中进行排序；
×       3）最后用新的数组进行插入归并排序
*/
/* Msort 驱动程序：调用程序 */
void merge(ElementType a[], ElementType tmparray[], int left, int center, int right )
{

}
void Msort(ElementType a[], ElementType tmparray[], int left, int right)
{
    int center;
    if(left < right){
        center = (left + right) / 2;
        Msort(a, tmparray, left, center);
        Msort(a, tmparray, center+1, right);
        merge(a, tmparray, left, center+1, right);  /* 最后的合并程序*/
    }
}
/* merge sort  */
void mergesort(ElementType a[], int N)
{
    ElementType *tmparray;

    tmparray = malloc(N * sizeof(ElementType));
    if(tmparray != NULL){
        Msort(a, tmparray, 0, N-1);
        free(tmparray);
    }
    else 
        printf("no space for tmp array!!!");
}

/* quick sort
    1) quick_sort：启动快速排序的驱动程序；
    2） Qsort：快速排序的实现；
    3） median3;三数中值分割法
*/
void quick_sort(ElementType a[], int N)
{
    Qsort( a, 0, N-1 ); /* 数组a, 下标 0-(n-1) */
}
/* 三数中值分割法*/
ElementType median3(ElementType a[], int left, int right) /*三数中值分割*/
{
    int center = (left + right)/2;
    /* 将大的元素放在右边 */
    if(a[left] > a[center])
        swap(&a[left], &a[center]);
    if(a[left] > a[right])
        swap(&a[left], &a[right]);
    if(a[center] > a[right])
        swap(&a[center], &a[right]);
    /* incariant a[left]<= a[center] <= a[right] */
    swap(&a[center], &a[center -1]);    /* 将枢纽元放在最后一个位置 */
    return a[right - 1] ;      
}
/*quick sort*/
#define cutoff (3)
void Qsort(ElementType a[], int left, int right)
{
    int i, j;
    ElementType pivot;  /*枢纽元*/

    if(left + cutoff <= right){
        pivot = median3(a, left, right);
        i = left; j = right - 1;
        for(;;){
            while(a[++i] < pivot) {}
            while(a[--j] > pivot) {}
            if(i < j)
                swap(&a[i], &a[j]);
            else 
                break;
        }
        swap(&a[i], &a[j-1]);   /* restore pivot */

        /* 分成两部分后，递归调用快排 */
        Qsort(a, left, i-1);
        Qsort(a, i+1, right);
    }
    else 
        insertionSort(a+left, right-left+1);    /* 当元素很小的时候，用插入排序 */
}