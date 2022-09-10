/* Quick.c - 快速排序 */

/**
 * @brief 分割数组, 辅助快速排序
 * @param nums 待排序的数组
 * @param low 待排序数组的起始下标
 * @param high 待排序数组的终止下标
 * @retval int - 分割点
 */
int Partition(int nums[], int low, int high)
{
      int pivot = nums[low];
      while (low < high)
      {
            while (low < high && nums[high] >= pivot)
            {
                  high--;
            }
            nums[low] = nums[high];

            while (low < high && nums[low] <= pivot)
            {
                  low++;
            }
            nums[high] = nums[low];
      }
      nums[low] = pivot;
      return low;
}

/**
 * @brief 实现, 快速排序, 升序
 * @param nums 待排序的数组
 * @param low 待排序的数组的起始下标
 * @param high 待排序的数组的结束下标
 * @retval 无
 */
void FastSort(int nums[], int low, int high)
{
      if (low < high)
      {
            int pivot = Partition(nums, low, high);
            FastSort(nums, low, pivot - 1);
            FastSort(nums, pivot + 1, high);
      }
}

/**
 * @brief 接口, 快速排序, 升序
 * @param nums 待排序的数组
 * @param numsSize nums数组的元素个数
 * @retval 无
 */
void QuickSort(int nums[], int numsSize)
{
      FastSort(nums, 0, numsSize - 1);
}
