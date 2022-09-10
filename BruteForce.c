/* BF算法 - Brute Force, BoyFriend */
// * 时间复杂度O(M*N), 最坏情况进行M*(N-M+1)次比较

/* Diy BruteForce.c - 确认 t 是否为 str 的子串 */

#include <stdio.h>
#include <string.h>

int BruteForce(char *t, char *str);

int main(int argc, char const *argv[])
{
      char str[] = "iLoveFishC.com";
      char t[] = "FishC";
      printf("%d\n", BruteForce(t, str));

      return 0;
}

int BruteForce(char *t, char *str)
{
      int ret = 0;

      char *search = strchr(str, *t);
      int i = 0;

      while (NULL != search)
      {
            while ('\0' != *(search + i))
            {
                  if ('\0' == *(t + i) || *(search + i) != *(t + i))
                  {
                        break;
                  }
                  i++;
            }

            if ('\0' == *(t + i))
            {
                  ret = 1;
                  break;
            }

            if ('\0' != *(++search))
            {
                  search = strchr(search, *t);
            }
      }

      return ret;
}
