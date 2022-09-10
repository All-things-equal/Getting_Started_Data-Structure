/* 递归 - 逆序输出字符串 */

#include <stdio.h>

void ReverseOutput(void);

int main(int argc, char const *argv[])
{
      printf("Enter a string(Enter '#' to eof): ");
      ReverseOutput();

      printf("\n");
      return 0;
}

void ReverseOutput(void)
{
      char ch;
      ch = getchar();
      if (ch != '#')
      {
            ReverseOutput();
      }
      if (ch != '#')
      {
            printf("%c", ch);
      }
}
