// 快速排序的接口文件 quick_sort.h
// 快速排序：基于Partition （划分）的函数；

#ifndef QUICK_SORT_H
#define QUICK_SORT_H

// Partition 划分函数
extern int partition(int *data, int length, int start, int end );

// quick_sort 接口函数
extern void quick_sort( int *numbers, int length, int start, int end );


#endif