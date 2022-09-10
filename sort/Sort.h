#ifndef __SORT_H__
#define __SORT_H__

/* -----------------------------------------
test: 排序模块 循环计数
----------------------------------------- */
// * ***************************************
extern int count_compare_bubble;
extern int count_swap_bubble;

extern int count_compare_select;
extern int count_swap_select;

extern int count_compare_heapAdjust;
// * ***************************************
/* ************************************** */

void Swap(int target[], int i, int j);

void BubbleSort(int nums[], int numsSize);
void SelectSort(int nums[], int numsSize);
void InsertSort(int nums[], int numsSize);
void HillSort(int nums[], int numsSize);
void HeapSort(int nums[], int numsSize);
void MergeSort_Recursion(int nums[], int numsSize);
void MergeSort_Iteration(int nums[], int numsSize);
void QuickSort(int nums[], int numsSize);
void QuickSort_Plus(int nums[], int numsSize);

#endif