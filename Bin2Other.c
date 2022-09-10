#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
      int strSize = sizeof(int) * 8 / 4 + 1;
      int num = 0b11001001;
      char *o;
      char hx[sizeof(int) * 8 / 4 + 1];
      int flag = 0;

      printf("%d == %#o == %#x\n", num, num, num);

      o = (char *)malloc(strSize);
      if (o)
      {
            flag = snprintf(o, strSize, "%#o", num);
            if (flag > 0 && flag < strSize)
            {
                  puts(o);
            }
            free(o);
      }

      flag = snprintf(hx, sizeof(hx), "%#x", num);
      if (flag > 0 && flag < strSize)
      {
            puts(hx);
      }

      return 0;
}
