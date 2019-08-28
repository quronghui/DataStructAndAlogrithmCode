/*
*   sort.h
*/
#ifndef SORT_H
#define SORT_H

struct InsertSort;
typedef int ElementType;
ElementType Element;

/* 冒泡排序 */
void	BubbleSort(int *array, int length);
/* insert order */
void InsertSort(ElementType a[], int N);
/* shell sort */
void shell_Sort(ElementType a[], int N);
/* binary heap sort */
void heapsort(ElementType a[], int N);
/* merge sort */
void Msort(ElementType a[], ElementType tmparray[], int left, int right);
void mergesort(ElementType a[], int N);

#endif

struct InsertSort{
    ElementType Element;
};