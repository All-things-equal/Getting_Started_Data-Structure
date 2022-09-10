/* Diy 凯撒密码  双向循环链表 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define ERROR 0
#define OVERFLOW -1

#define MAXSIZE 26

typedef char ElemType;

typedef struct DualNode
{
      ElemType data;
      struct DualNode *prior;
      struct DualNode *next;
} Caesar;

Caesar *Create(void);
void DestroyDualNode(Caesar **C);
void PrintCaesar(Caesar *head);
Caesar *Transform(Caesar *C, int count);

int main(int argc, char const *argv[])
{
      Caesar *C = Create();
      // PrintCaesar(C);

      int input = 0;
      printf("Enter: ");
      scanf("%d", &input);
      PrintCaesar(Transform(C, input % MAXSIZE));
      return 0;
}

Caesar *Create(void)
{
      Caesar *head = (Caesar *)malloc(sizeof(Caesar));
      if (head == NULL)
      {
            perror("OVERFLOW");
            return NULL;
      }
      Caesar *tail = head;
      tail->prior = head;
      tail->next = head;
      Caesar *p;

      int i = 0;
      for (i = 0; i < MAXSIZE; i++)
      {
            p = (Caesar *)malloc(sizeof(Caesar));
            if (p == NULL)
            {
                  perror("OVERFLOW");
                  return NULL;
            }
            p->data = 'A' + i;

            p->next = tail->next;
            p->prior = tail;
            tail->next = p;
            tail = p;
      }
      tail->next = head->next;
      head->next->prior = tail;
      free(head);

      return head->next;
}

void DestroyDualNode(Caesar **C)
{
      Caesar *p = *C;
      int count = 0;
      do
      {
            *C = (*C)->next;
            free(p);
            p = *C;
      } while (count++ < MAXSIZE);
}

void PrintCaesar(Caesar *head)
{
      Caesar *p = head;
      if (p != NULL)
      {
            p->prior = NULL; // 暂时解环
            do
            {
                  printf("%c ", p->data);
                  p = p->next;
            } while (p != head);
            printf("\n");
      }
}

Caesar *Transform(Caesar *C, int count)
{
      Caesar *p = C;
      int cnt = 0;
      if (count >= 0)
      {
            while (cnt++ < count)
            {
                  p = p->next;
            }
      }
      else
      {
            while (cnt-- > count)
            {
                  p = p->prior;
            }
      }
      return p;
}
