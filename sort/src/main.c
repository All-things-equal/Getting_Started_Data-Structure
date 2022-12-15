/* main.c - 测试 排序函数 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sort.h"

/* -----------------------------------------
宏定义 - 测试 排序函数 升序
------------------------------------------ */
#define __BubbleSort 0
#define __SelectSort 0
#define __InsertSort 0
#define __HillSort 0
#define __HeapSort 0
#define __MergeSort_Recursion 0
#define __MergeSort_Iteration 0 /* TODO: 归并排序 - 迭代 */
#define __QuickSort 1
#define __QuickSort_Plus 1
/* *************************************** */

int main(int argc, char const *argv[])
{
      int buffer[] = {5, 8, 9, 1, 3, 4, 7, 2, 6, 10}; // 初始化 初始数组

      int *nums = (int *)malloc(sizeof(buffer));
      int i;

      if (nums == NULL)
      {
            fprintf(stderr, "malloc failed\n");
            exit(EXIT_FAILURE);
      }

      memcpy(nums, buffer, sizeof(buffer));
      printf("Before sort:\n");
      for (i = 0; i < sizeof(buffer) / sizeof(*buffer); i++)
      {
            printf("\t%p: nums[%d] = %d\n", &nums[i], i, nums[i]);
      }
      printf("\n");

      printf("\n");

      /* -----------------------------------
      test: 冒泡排序
      -------------------------------------*/
#if __BubbleSort

      memcpy(nums, buffer, sizeof(buffer));

      BubbleSort(nums, sizeof(buffer) / sizeof(*buffer));

      printf("After BubbleSort:\n");
      for (i = 0; i < sizeof(buffer) / sizeof(*buffer); i++)
      {
            printf("\t%p: nums[%d] = %d\n", &nums[i], i, nums[i]);
      }
      printf("\n");

      // * **********************************
      printf("\t\tcount_compare_bubble: %d\n", count_compare_bubble);
      printf("\t\tcount_swap_bubble: %d\n", count_swap_bubble);
      printf("\n\n");
      // * **********************************

#endif // __BubbleSort, 冒泡排序
      /* ********************************* */

      /* -----------------------------------
      test: 选择排序
      -------------------------------------*/
#if __SelectSort

      memcpy(nums, buffer, sizeof(buffer));

      SelectSort(nums, sizeof(buffer) / sizeof(*buffer));

      printf("After SelectSort:\n");
      for (i = 0; i < sizeof(buffer) / sizeof(*buffer); i++)
      {
            printf("\t%p: nums[%d] = %d\n", &nums[i], i, nums[i]);
      }
      printf("\n");

      // * **********************************
      printf("\t\tcount_compare_select: %d\n", count_compare_select);
      printf("\t\tcount_swap_select: %d\n", count_swap_select);
      printf("\n\n");
      // * **********************************

#endif // __SelectSort, 选择排序
      /* ********************************* */

      /* -----------------------------------
      test: 直接插入排序
      -------------------------------------*/
#if __InsertSort

      memcpy(nums, buffer, sizeof(buffer));

      InsertSort(nums, sizeof(buffer) / sizeof(*buffer));

      printf("After InsertSort:\n");
      for (i = 0; i < sizeof(buffer) / sizeof(*buffer); i++)
      {
            printf("\t%p: nums[%d] = %d\n", &nums[i], i, nums[i]);
      }
      printf("\n");

#endif // __InsertSort, 直接插入排序
      /* ********************************* */

      /* -----------------------------------
      test: 直接插入排序
      -------------------------------------*/
#if __HillSort

      memcpy(nums, buffer, sizeof(buffer));

      HillSort(nums, sizeof(buffer) / sizeof(*buffer));

      printf("After HillSort:\n");
      for (i = 0; i < sizeof(buffer) / sizeof(*buffer); i++)
      {
            printf("\t%p: nums[%d] = %d\n", &nums[i], i, nums[i]);
      }
      printf("\n");

#endif // __HillSort 直接插入排序
      /* ********************************* */

      /* -----------------------------------
      test: 堆排序
      -------------------------------------*/
#if __HeapSort

      memcpy(nums, buffer, sizeof(buffer));

      HeapSort(nums, sizeof(buffer) / sizeof(*buffer));

      printf("After HeapSort:\n");
      for (i = 0; i < sizeof(buffer) / sizeof(*buffer); i++)
      {
            printf("\t%p: nums[%d] = %d\n", &nums[i], i, nums[i]);
      }
      printf("\n");

      // * **********************************
      printf("\t\tcount_compare_heapAdjust: %d\n", count_compare_heapAdjust);
      printf("\n\n");
      // * **********************************

#endif // __HeapSort, 堆排序
      /* ********************************* */

      /* -----------------------------------
      test: 归并排序 - 递归
      -------------------------------------*/
#if __MergeSort_Recursion

      memcpy(nums, buffer, sizeof(buffer));

      MergeSort_Recursion(nums, sizeof(buffer) / sizeof(*buffer));

      printf("After MergeSort_Recursion:\n");
      for (i = 0; i < sizeof(buffer) / sizeof(*buffer); i++)
      {
            printf("\t%p: nums[%d] = %d\n", &nums[i], i, nums[i]);
      }
      printf("\n");

#endif // __MergeSort_Recursion, 归并排序 - 递归
      /* ********************************* */

      /* -----------------------------------
      test: 归并排序 - 迭代
      -------------------------------------*/
#if __MergeSort_Iteration

      memcpy(nums, buffer, sizeof(buffer));

      MergeSort_Iteration(nums, sizeof(buffer) / sizeof(*buffer));

      printf("After MergeSort_Iteration:\n");
      for (i = 0; i < sizeof(buffer) / sizeof(*buffer); i++)
      {
            printf("\t%p: nums[%d] = %d\n", &nums[i], i, nums[i]);
      }
      printf("\n");

#endif // __MergeSort_Iteration, 归并排序 - 迭代F
      /* ********************************* */

      /* -----------------------------------
      test: 快速排序
      -------------------------------------*/
#if __QuickSort

      memcpy(nums, buffer, sizeof(buffer));

      QuickSort(nums, sizeof(buffer) / sizeof(*buffer));

      printf("After QuickSort:\n");
      for (i = 0; i < sizeof(buffer) / sizeof(*buffer); i++)
      {
            printf("\t%p: nums[%d] = %d\n", &nums[i], i, nums[i]);
      }
      printf("\n");

#endif // __QuickSort, 快速排序
      /* ********************************* */

      /* -----------------------------------
      test: 快速排序Plus
      -------------------------------------*/
#if __QuickSort_Plus

      memcpy(nums, buffer, sizeof(buffer));

      QuickSort_Plus(nums, sizeof(buffer) / sizeof(*buffer));

      printf("After QuickSortPlus:\n");
      for (i = 0; i < sizeof(buffer) / sizeof(*buffer); i++)
      {
            printf("\t%p: nums[%d] = %d\n", &nums[i], i, nums[i]);
      }
      printf("\n");

#endif // __QuickSort_Plus, 快速排序Plus
      /* ********************************* */

      free(nums);
      return 0;
}
