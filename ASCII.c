#include <stdio.h>

int main(void)
{
      char ch;
      int i = 0;

      for (i = 0; i < 128; ++i)
      {
            printf("%d: %c\n", i, ch + i);
      }

      return 0;
}
