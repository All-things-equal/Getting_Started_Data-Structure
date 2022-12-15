/* Hill.c - 希尔排序 */

/**
 * @brief 希尔排序, 升序
 * @param nums 待排序的数组
 * @param numsSize nums数组的元素个数
 * @retval 无
 */
void HillSort(int nums[], int numsSize)
{
      int i, j, k;
      int gap;
      int temp;

      for (gap = numsSize / 2; gap > 0; gap /= 2)
      {
            for (i = gap; i < numsSize; i++)
            {
                  temp = nums[i];
                  for (j = i - gap; j >= 0 && nums[j] > temp; j -= gap)
                  {
                        nums[j + gap] = nums[j];
                  }
                  nums[j + gap] = temp;
            }
      }
}
