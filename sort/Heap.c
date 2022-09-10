/* Heap.c - 堆排序 */

/* -----------------------------------------
外部函数声明
------------------------------------------ */
void Swap(int target[], int i, int j);
/* *************************************** */

// * ***************************************
int count_compare_heapAdjust;
// * ***************************************

void HeapAdjust(int nums[], int s, int size)
{
      int i = s;
      int j = 2 * i + 1;
      int temp = nums[i];
      
      while (j < size)
      {
            // * ****************************
            count_compare_heapAdjust++;
            // * ****************************

            if (j + 1 < size && nums[j + 1] > nums[j])
            {
                  j++;
            }
      
            if (nums[j] > temp)
            {
                  nums[i] = nums[j];
                  i = j;
                  j = 2 * i + 1;
            }
            else
            {
                  break;
            }
      }
      
      nums[i] = temp;
}

/**
 * @brief 堆排序, 升序
 * @param nums 待排序的数组
 * @param numsSize nums数组的元素个数
 * @retval 无
 */
void HeapSort(int nums[], int numsSize)
{
      int i;
      
      for (i = numsSize / 2 - 1; i >= 0; i--)
      {
            HeapAdjust(nums, i, numsSize);
      }
      
      for (i = numsSize - 1; i > 0; i--)
      {
            Swap(nums, 0, i);
            HeapAdjust(nums, 0, i);
      }
}