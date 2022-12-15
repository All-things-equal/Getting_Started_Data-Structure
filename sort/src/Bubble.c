/* Bubble.c - 冒泡排序 */

// * ***************************************
int count_compare_bubble;
int count_swap_bubble;
// * ***************************************

/**
 * @brief 冒泡排序, 升序
 * @param nums 待排序的数组
 * @param numsSize nums数组的元素个数
 * @retval 无
 */
void BubbleSort(int nums[], int numsSize)
{
      int i, j;
      int temp;
      int flag = 1;

      for (i = 0; i < numsSize && flag; i++)
      {
            flag = 0;
            for (j = numsSize - 1; j > i; j--)
            {
                  // * *********************
                  count_compare_bubble++;
                  // * *********************

                  if (nums[j] < nums[j - 1])
                  {
                        temp = nums[j];
                        nums[j] = nums[j - 1];
                        nums[j - 1] = temp;
                        flag = 1;

                        // * ****************
                        count_swap_bubble++;
                        // * ****************
                  }
            }
      }
}
