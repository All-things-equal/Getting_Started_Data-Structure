/*
    约瑟夫问题
        41个人围圈报数, 3自杀, 接下去报数循环, 16 和 31 活下来.

        number 个人围圈报数, 报 die 出列, 最后剩下几号.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
      int value;
      struct _node *next;
} Jose;

Jose *Create(int number);

int main(int argc, char const *argv[])
{
      int number = 41;
      int die = 3;
      Jose *J = Create(number);
      Jose *death = NULL;
      int i = 0;

      die %= number;

      while (J != J->next)
      {
            // 找到 死者death 的前驱
            for (i = 1; i < die - 1; i++)
            {
                  J = J->next;
            }

            printf("%d -> ", J->next->value);

            death = J->next;
            J->next = death->next;
            free(death);

            J = J->next;
      }

      printf("%d\n", J->value);

      return 0;
}

Jose *Create(int number)
{
      Jose *head = (Jose *)malloc(sizeof(Jose));
      if (head == NULL)
      {
            perror("OVERFLOW");
            return NULL;
      }
      Jose *p = head;
      Jose *s = NULL;
      int cnt = 1;

      if (0 != number)
      {
            while (cnt <= number)
            {
                  s = (Jose *)malloc(sizeof(Jose));
                  if (s == NULL)
                  {
                        perror("OVERFLOW");
                        return NULL;
                  }
                  s->value = cnt++;
                  p->next = s;
                  p = s;
            }
            s->next = head->next;
      }

      free(head);
      return s->next;
}