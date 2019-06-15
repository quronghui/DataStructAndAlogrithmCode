/*
*   sort.h
*/
#ifndef SORT_H
#define SORT_H

struct InsertSort;
typedef int ElementType;
ElementType Element;

/* insert order */
void insertionSort(ElementType a[], int N);
/* shell sort */
void shell_Sort(ElementType a[], int N);
/* binary heap sort */
void heapsort(ElementType a[], int N);
/* merge sort */
void Msort(ElementType a[], ElementType tmparray[], int left, int right);
void mergesort(ElementType a[], int N);
/* quick sort */
void quick_sort(ElementType a[], int N);
ElementType median3(ElementType a[], int left, int right);  /*三数中值分割*/
void Qsort(ElementType a[], int left, int right);

#endif

struct InsertSort{
    ElementType Element;
};