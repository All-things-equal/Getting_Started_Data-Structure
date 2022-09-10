/* Select.c - 选择排序 */

// * ***************************************
int count_compare_select;
int count_swap_select;
// * ***************************************

/**
 * @brief 选择排序, 升序
 * @param nums 待排序的数组
 * @param numsSize nums数组的元素个数
 * @retval 无
 */
void SelectSort(int nums[], int numsSize)
{
      int i, j, minIndex;
      int temp;

      for (i = 0; i < numsSize - 1; i++)
      {
            minIndex = i;
            for (j = i + 1; j < numsSize; j++)
            {
                  // * *********************
                  count_compare_select++;
                  // * *********************

                  if (nums[j] < nums[minIndex])
                  {
                        minIndex = j;
                  }
            }
            if (minIndex != i)
            {
                  temp = nums[i];
                  nums[i] = nums[minIndex];
                  nums[minIndex] = temp;

                  // * **********************
                  count_swap_select++;
                  // * **********************
            }
      }
}
