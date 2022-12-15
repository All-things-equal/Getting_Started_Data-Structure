/* Insert.c - 直接插入排序 */

/**
 * @brief 直接插入排序, 升序
 * @param nums 待排序的数组
 * @param numsSize nums数组的元素个数
 * @retval 无
 */
void InsertSort(int nums[], int numsSize)
{
      int i, j;
      int temp;

      for (i = 1; i < numsSize; i++)
      {
            temp = nums[i];
            for (j = i - 1; j >= 0 && nums[j] > temp; j--)
            {
                  nums[j + 1] = nums[j];
            }
            nums[j + 1] = temp;
      }
}
