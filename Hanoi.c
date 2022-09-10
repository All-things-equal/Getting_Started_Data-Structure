/* 递归 - 汉诺塔问题 */

#include <stdio.h>

void move(int n, char x, char y, char z); // 将 n 个盘子从 x 借助 y 移动到 z .

long long count = 0;

int main(int argc, char const *argv[])
{
      int n;
      printf("输入汉诺塔的层数: ");
      scanf("%d", &n);
      printf("移动的步骤如下:\n");
      move(n, 'x', 'y', 'z');
      return 0;
}

void move(int n, char x, char y, char z)
{
      if (1 == n)
      {
            printf("NO.%llu: %c --> %c\n", ++count, x, z);
      }
      else
      {
            move(n - 1, x, z, y);                          // 将 n-1 个盘子从 x 借助 z 移到 y 上.
            printf("NO.%llu: %c --> %c\n", ++count, x, z); // 将第 n 个盘子从 x 移到 z 上.
            move(n - 1, y, x, z);                          // 将 n-1 个盘子从 y 借助 x 移到 z 上.
      }
}