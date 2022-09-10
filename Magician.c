/* 魔术师发牌问题 */

#include <stdio.h>
#include <stdlib.h>

#define CardNumber 13

typedef struct _node
{
      int value;
      struct _node *next;
} Magi;

Magi *Create(void);
void Magician(Magi *head);  // 发牌顺序计算
void DestoryList(Magi **M); // 销毁

int main(int argc, char const *argv[])
{
      Magi *M = Create();
      int i = 0;

      Magician(M);

      printf("按如下顺序排列:\n");
      for (i = 0; i < CardNumber; i++)
      {
            printf("黑桃%d ", M->value);
            M = M->next;
      }
      printf("\n");

      DestoryList(&M);

      return 0;
}

Magi *Create(void)
{
      Magi *head = NULL;
      Magi *s = NULL;
      Magi *rear = head;
      int i = 0;

      for (i = 1; i <= CardNumber; i++)
      {
            s = (Magi *)malloc(sizeof(Magi));
            if (s == NULL)
            {
                  perror("OVERFLOW");
                  return NULL;
            }
            s->value = 0; // 0 表无牌

            if (head == NULL)
            {
                  head = s;
            }
            else
            {
                  rear->next = s;
            }
            rear = s;
      }

      rear->next = head;

      return head;
}

void Magician(Magi *head)
{
      Magi *p = head;
      int i = 0;
      int countNumber = 2;

      p->value = 1;

      while (1)
      {
            for (i = 0; i < countNumber; i++)
            {
                  p = p->next;
                  if (p->value != 0) // 处理该位置有牌的情况
                  {
                        // p->next;
                        i--;
                  }
            }

            if (p->value == 0)
            {
                  p->value = countNumber;
                  countNumber++;

                  if (countNumber > CardNumber)
                  {
                        break;
                  }
            }
      }
}

void DestoryList(Magi **M)
{
      Magi *buffer[CardNumber];
      int i = 0;

      while (i < CardNumber)
      {
            buffer[i++] = *M;
            *M = (*M)->next;
      }

      for (i = 0; i < CardNumber; i++)
      {
            free(buffer[i]);
      }

      *M = NULL;
}