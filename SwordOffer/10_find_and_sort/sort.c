/* 
*   sort.c
*   1)insert_sort每次取后一个元素，和前面已排好序的数组进行比较；
*   2)shell sort : 希尔排序：缩小增量排序
*   3)binary sort：堆排序。构建一个堆后，进行delete_min，得到排序数组
*   4)merge sort :归并排序，按照中间位置分为两个数字，各自排序后插入到新的数组
*   5) 冒泡排序
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <assert.h>
#include "sort.h"

/* 冒泡排序 */
void	BubbleSort(int *array, int length)
{
	for(int i = 0; i < length-1 ; i++){
        for(int j = i+1; j <length ; j++){
            if( array[i] > array[j] ){    
                int tmp = array[i];
                array[i]    =   array[j];
                array[j]  =   tmp;                
            }
        }
    }
}

/* insert_sort   */
void InsertSort(int *array, int length)
{
    // 从第二个元素才需要插入排序
    for ( int i = 1; i < length; i++){
        int tmp = array[i];                      // 设置哨兵元素
        int j =i;                                           // 前面已经排好序的( i - 1 )个元素
        for(; j > 0 && array[j-1] > tmp;  j--)  
            array[ j ] = array[j-1];                                    // 前面的大于 tmp, 则移动覆盖
        array[ j ] = tmp;                                          // 最后一个位置处理
    }
}

/* shell sort
*   1)希尔排序：缩小增量排序
*   2)元素之间的比较：a[i + h(k)] < a[i - h(k)]，对应元素之间的比较
*   3)每次删除的逆序对，不止一个逆序对；
*/
void shell_Sort(int *array, int length)
{
    int i, j, increment;
    int tmp;

    /* h(k) = N/2 ; 每次一半进行递减*/
    for(increment = length/2; increment > 0; increment /= 2)
        /* 循环：完后后半部分（N/2）每个元素，和前半部分元素之间的比较*/
        for(i = increment; i < length; i++){
            tmp = array[i];                                                                 /* 后半部分数组 */
            for(j = i; j >= increment; j -= increment){      // 消除逆序对
                if( array[j-increment] > tmp  )     
                    array[j] = array[j - increment];
                else 
                    break;  /* 这里break后，就不执行 j -= increment 这条语句 */
            }
            array[j] = tmp;
        }
}

/*)2）binary sort : 类似于一颗二叉树
*   1)现实中构建的堆：和二叉堆的性质相反之处 -- （任一节点的关键字大于其儿子节点的关键字）
*   2)delete_min：得到从小到大的排序数组
*   3)注意:  0位置包含元素的
*/
#define leftchild( i ) (2*(i) + 1)        // 根据层数: 判断树中节点的个数

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
// 堆排序的调用函数
void heapsort(int  *array, int  length)
{
    int i;
    for(i = length/2; i >= 0; i--)   /*build heap*/
        PercDown(array, i, length);
    for(i = length -1; i > 0; i--){
        swap(&array[0], &array[i]);     /* delete_max */
        PercDown(array, 0, i);
    }
}

/* 
*   3）merge sort
*       1)  按照中间位置：将数组不停的分为两部分；
*       2）在两部分中进行排序；
*       3）最后用新的数组进行插入归并排序
*/

/* merge 将两部分元素进行合并为一个数组 */
void merge(int *array, int *tmparray, int lpos, int rpos, int rightEnd )
{
    int leftEnd =   rpos -1;            // 左半部分的最大值
    int tmpPos  =   lpos;               // 新数组起始元素
    int numElement = rightEnd - lpos + 1;       // 每次需要合并的元素个数

    /* main loop  两部分元素个数相等的时候*/
    while(lpos <= leftEnd  && rpos <= rightEnd)
        // 判断两部分元素中, 那一部分比较大
        if(array[lpos] <= array[rpos])
            tmparray[tmpPos++] = array[lpos++];
        else 
            tmparray[tmpPos++] = array[rpos++];
    
    while(lpos <= leftEnd)      /*  左半部分的元素 > 右半部分的元素 */
        tmparray[tmpPos++] = array[lpos++];
    while(rpos <= rightEnd)     /* 或者: 右半部分的元素 > 左半部分的元素 */
        tmparray[tmpPos++] = array[rpos++];
    
    /* 将合并好的元素放到原数组里面*/
    for(int i=0; i < numElement; i++, rightEnd--)
        array[rightEnd] = tmparray[rightEnd];

}

// 将数组划分为: 单一的元素, 在两部分进行合并
// 递归划分, 递归合并;
void Msort(int *array, int *tmparray, int left, int right)
{
    // 将其分为最小的单个数组元素, 然后在一一合并;
    int center = (left + right) / 2;;
    if(left < right){
        Msort(array, tmparray, left, center);
        Msort(array, tmparray, center+1, right);
       
        // 如果两部分数组都已经排好序了, 就直接调用这个函数
        merge(array, tmparray, left, center+1, right);  /* 最后的合并程序*/
    }
}

/* merge sort  */
// 需要建一个N大小的数组空间
void mergesort(int *array, int length)
{
    if(array == NULL || length < 0)
        return ;

    int *tmparray = malloc(length * sizeof(int));
   // 动态分配的数组部位
    if(tmparray != NULL){
        Msort(array, tmparray, 0, length-1);
        free(tmparray);
    }
    else 
        printf("no space for tmp array!!!");
}


/**************BubbleSort test****************/
void test1(int *array, int length)
{
    BubbleSort(array, length);
    
    printf("BubbleSort Test: ");
    for(int i=0; i < length; i++)
        printf("%d ", array[i]);
    printf("\n");
}

/************InsertSort*************/
void test2(int *array, int length)
{
    InsertSort(array, length);
    
    printf("InsertSort Test: ");
    for(int i=0; i < length; i++)
        printf("%d ", array[i]);
    printf("\n");
}

/************shell_Sort*************/
void test3(int *array, int length)
{
    shell_Sort(array, length);
    
    printf("shell_Sort Test: ");
    for(int i=0; i < length; i++)
        printf("%d ", array[i]);
    printf("\n");
}

/************mergesort*************/
void test4(int *array, int length)
{
    mergesort(array, length);
    
    printf("mergesort Test: ");
    for(int i=0; i < length; i++)
        printf("%d ", array[i]);
    printf("\n");
}

/**************Test code***************/
int  main()
{
    int array[] = { 3, 0, 1, 4, 7, 5, 6, 10, 2 };
    int length = sizeof(array) / sizeof(array[0]);
    
    // test1(array, length);
    // test2(array, length);
    // test3(array, length);
    test4(array, length);


    
    return 0;
}