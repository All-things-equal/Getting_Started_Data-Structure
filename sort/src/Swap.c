/**
 * @brief 交换两个数组元素
 * @param target 目标数组
 * @param i 目标数组待交换的其中一个元素的下标
 * @param j 目标数组待交换的另一个元素的下标
 * @retval 无
 */
void Swap(int target[], int i, int j)
{
      int temp = target[i];
      target[i] = target[j];
      target[j] = temp;
}
