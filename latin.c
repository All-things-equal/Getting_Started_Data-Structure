/* Diy 拉丁方阵 */

#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
      int value;
      struct _node *next;
} Node;

typedef struct _list
{
      int count;
      Node *front;
      Node *rear;
} Latin;

void Create(Latin *L);
void Print(Latin L);
void DestroyList(Latin *L);

int main(int argc, char const *argv[])
{
      Latin L = {
          .count = 0,
          .front = NULL,
          .rear = L.front,
      };

      printf("Enter: ");
      scanf("%d", &L.count);

      Create(&L);
      Print(L);

      DestroyList(&L);
      return 0;
}

void Create(Latin *L)
{
      Node *p = NULL;
      int i = 0;

      for (i = 1; i <= L->count; i++)
      {
            p = (Node *)malloc(sizeof(Node));
            if (p == NULL)
            {
                  perror("OVERFLOW");
                  return;
            }
            p->value = i;

            if (L->front == NULL)
            {
                  L->front = p;
            }
            else
            {
                  L->rear->next = p;
            }
            L->rear = p;
      }
      L->rear->next = L->front;
}

void Print(Latin L)
{
      Node *p = NULL;
      int i = 0;
      for (i = 0; i < L.count; ++i)
      {
            p = L.front;
            while (p != L.rear)
            {
                  printf("%d\t", p->value);

                  p = p->next;
            }
            printf("%d\n", p->value);

            L.rear = L.front;
            L.front = L.rear->next;
      }
}

void DestroyList(Latin *L)
{
      Node *p = L->front;

      while (L->count > 0)
      {
            L->front = L->front->next;
            free(p);
            L->count--;

            p = L->front;
      }

      L->front = NULL;
      L->rear = L->front;
}