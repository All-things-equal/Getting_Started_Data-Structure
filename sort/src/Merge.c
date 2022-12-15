/* Merge.c - 归并排序 */

#include <stdlib.h>

/**
 * @brief 归并两个数组, 并把结果存入left数组
 * @param left 
 * @param leftSize 
 * @param right 
 * @param rightSize 
 * @retval 无
 */
void Merging_Recursion(int *left, int leftSize, int *right, int rightSize)
{
      int *temp = (int *)malloc(sizeof(int) * (leftSize + rightSize));
      int i = 0, j = 0, k = 0;

      while (i < leftSize && j < rightSize)
      {
            if (left[i] < right[j])
            {
                  temp[k++] = left[i++];
            }
            else
            {
                  temp[k++] = right[j++];
            }
      }

      while (i < leftSize)
      {
            temp[k++] = left[i++];
      }

      while (j < rightSize)
      {
            temp[k++] = right[j++];
      }

      for (i = 0; i < leftSize + rightSize; i++)
      {
            left[i] = temp[i];
      }

      free(temp);
}

/**
 * @brief 递归实现 归并排序, 升序
 * @param nums 待排序的数组
 * @param numsSize nums数组的元素个数
 * @retval 无
 */
void MergeSort_Recursion(int nums[], int numsSize)
{
      if (numsSize > 1)
      {
            int *left = nums;
            int leftSize = numsSize / 2;
            int *right = nums + numsSize / 2;
            int rightSize = numsSize - numsSize / 2;

            MergeSort_Recursion(left, leftSize);
            MergeSort_Recursion(right, rightSize);

            Merging_Recursion(left, leftSize, right, rightSize);
      }
}

// TODO: 归并排序 - 迭代
/**
 * @brief 迭代实现 归并排序, 升序
 * @param nums 待排序的数组
 * @param numsSize nums数组的元素个数
 * @retval 无
 */
void MergeSort_Iteration(int nums[], int numsSize)
{     
}