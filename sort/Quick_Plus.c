/* Quick.c - 快速排序Plus */

/* -----------------------------------------
外部函数声明
------------------------------------------ */
void Swap(int target[], int i, int j);
/* *************************************** */

/* -----------------------------------------
宏定义 - 版本控制
------------------------------------------ */
#define VERSION_1 0 // 优化选取基准点, 三数取中法
#define VERSION_2 0 // 优化不必要的交换
#define VERSION_3 0 // 优化小数组时的排序方案
#define VERSION_4 1 // 优化递归操作, 尾递归
/* *************************************** */

#if VERSION_1
/**
 * @brief 分割数组, 辅助快速排序Plus
 * @param nums 待排序的数组
 * @param low 待排序数组的起始下标
 * @param high 待排序数组的终止下标
 * @retval int - 分割点
 */
int Partition_Plus(int nums[], int low, int high)
{
      int pivot;
      int mid = low + (high - low) / 2;

      if (nums[low] > nums[high])
      {
            Swap(nums, low, high);
      }
      if (nums[mid] > nums[high])
      {
            Swap(nums, mid, high);
      }
      if (nums[mid] > nums[low])
      {
            Swap(nums, mid, low);
      }

      pivot = nums[low];

      while (low < high)
      {
            while (low < high && nums[high] >= pivot)
            {
                  high--;
            }
            Swap(nums, low, high);

            while (low < high && nums[low] <= pivot)
            {
                  low++;
            }
            Swap(nums, low, high);
      }

      return low;
}

/**
 * @brief 实现, 快速排序Plus, 升序
 * @param nums 待排序的数组
 * @param low 待排序的数组的起始下标
 * @param high 待排序的数组的结束下标
 * @retval 无
 */
void FastSort_Plus(int nums[], int low, int high)
{
      if (low < high)
      {
            int pivot = Partition_Plus(nums, low, high);
            FastSort_Plus(nums, low, pivot - 1);
            FastSort_Plus(nums, pivot + 1, high);
      }
}
#endif // VERSION_1

#if VERSION_2
/**
 * @brief 分割数组, 辅助快速排序Plus
 * @param nums 待排序的数组
 * @param low 待排序数组的起始下标
 * @param high 待排序数组的终止下标
 * @retval int - 分割点
 */
int Partition_Plus(int nums[], int low, int high)
{
      int pivot;
      int mid = low + (high - low) / 2;

      if (nums[low] > nums[high])
      {
            Swap(nums, low, high);
      }
      if (nums[mid] > nums[high])
      {
            Swap(nums, mid, high);
      }
      if (nums[mid] > nums[low])
      {
            Swap(nums, mid, low);
      }

      pivot = nums[low];
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
 * @brief 实现, 快速排序Plus, 升序
 * @param nums 待排序的数组
 * @param low 待排序的数组的起始下标
 * @param high 待排序的数组的结束下标
 * @retval 无
 */
void FastSort_Plus(int nums[], int low, int high)
{
      if (low < high)
      {
            int pivot = Partition_Plus(nums, low, high);
            FastSort_Plus(nums, low, pivot - 1);
            FastSort_Plus(nums, pivot + 1, high);
      }
}
#endif // VERSION_2

#if VERSION_3

#define MAX_LENGTH_INSERT_SORT 7 // ! 魔法数, 快速排序效率最高的分界点

/**
 * @brief 接口 - 二次封装的插入排序, 辅助FastSort_Plus()
 * @param nums 待排序的数组
 * @param low 待排序的数组的起始下标
 * @param high 待排序的数组的结束下标
 * @retval 无
 */
void Insert_FastSort(int nums[], int low, int high)
{
      void InsertSort(int nums[], int numsSize); // 声明 - 插入排序函数

      InsertSort(nums + low, high - low + 1);
}

/**
 * @brief 分割数组, 辅助快速排序Plus
 * @param nums 待排序的数组
 * @param low 待排序数组的起始下标
 * @param high 待排序数组的终止下标
 * @retval int - 分割点
 */
int Partition_Plus(int nums[], int low, int high)
{
      int pivot;
      int mid = low + (high - low) / 2;

      if (nums[low] > nums[high])
      {
            Swap(nums, low, high);
      }
      if (nums[mid] > nums[high])
      {
            Swap(nums, mid, high);
      }
      if (nums[mid] > nums[low])
      {
            Swap(nums, mid, low);
      }

      pivot = nums[low];
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
 * @brief 实现, 快速排序Plus, 升序
 * @param nums 待排序的数组
 * @param low 待排序的数组的起始下标
 * @param high 待排序的数组的结束下标
 * @retval 无
 */
void FastSort_Plus(int nums[], int low, int high)
{
      if (high - low > MAX_LENGTH_INSERT_SORT)
      {
            int pivot = Partition_Plus(nums, low, high);
            FastSort_Plus(nums, low, pivot - 1);
            FastSort_Plus(nums, pivot + 1, high);
      }
      else
      {
            Insert_FastSort(nums, low, high);
      }
}
#endif // VERSION_3

#if VERSION_4

#define MAX_LENGTH_INSERT_SORT 7 // ! 魔法数, 快速排序效率最高的分界点

/**
 * @brief 接口 - 二次封装的插入排序, 辅助FastSort_Plus()
 * @param nums 待排序的数组
 * @param low 待排序的数组的起始下标
 * @param high 待排序的数组的结束下标
 * @retval 无
 */
void Insert_FastSort(int nums[], int low, int high)
{
      void InsertSort(int nums[], int numsSize); // 声明 - 插入排序函数

      InsertSort(nums + low, high - low + 1);
}

/**
 * @brief 分割数组, 辅助快速排序Plus
 * @param nums 待排序的数组
 * @param low 待排序数组的起始下标
 * @param high 待排序数组的终止下标
 * @retval int - 分割点
 */
int Partition_Plus(int nums[], int low, int high)
{
      int pivot;
      int mid = low + (high - low) / 2;

      if (nums[low] > nums[high])
      {
            Swap(nums, low, high);
      }
      if (nums[mid] > nums[high])
      {
            Swap(nums, mid, high);
      }
      if (nums[mid] > nums[low])
      {
            Swap(nums, mid, low);
      }

      pivot = nums[low];
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
 * @brief 实现, 快速排序Plus, 升序
 * @param nums 待排序的数组
 * @param low 待排序的数组的起始下标
 * @param high 待排序的数组的结束下标
 * @retval 无
 */
void FastSort_Plus(int nums[], int low, int high)
{
      if (high - low > MAX_LENGTH_INSERT_SORT)
      {
            // 尾递归
            while (low < high)
            {
                  int pivot = Partition_Plus(nums, low, high);
                  if (pivot - low < high - pivot)
                  {
                        FastSort_Plus(nums, low, pivot - 1);
                        low = pivot + 1;
                  }
                  else
                  {
                        FastSort_Plus(nums, pivot + 1, high);
                        high = pivot - 1;
                  }
            }
      }
      else
      {
            Insert_FastSort(nums, low, high);
      }
}
#endif // VERSION_4

/**
 * @brief 优化版本, 接口 - 快速排序Plus, 升序
 * @param nums 待排序的数组
 * @param numsSize nums数组的元素个数
 * @retval 无
 */
void QuickSort_Plus(int nums[], int numsSize)
{
      FastSort_Plus(nums, 0, numsSize - 1);
}
