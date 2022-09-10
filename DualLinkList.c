/* Diy 带头结点的双向循环链表 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define ERROR 0
#define OVERFLOW -1

typedef int ElemType;
typedef int Status;

typedef struct _dualNode
{
      ElemType data;
      struct _dualNode *prior; // 前驱结点
      struct _dualNode *next;  // 后继结点
} DualNode;

typedef struct _dualLinkList
{
      int length;
      DualNode *head;
      DualNode *tail;
} DualList;

Status InitDualList(DualList *DL);
void DisplayDualListHead(DualList DL);
void DisplayDualListTail(DualList DL);
void PrintDualNode(DualNode *p);
Status CreateDualListHead(DualList *DL, int count);
Status CreateDualListTail(DualList *DL, int count);
Status DualListInsert(DualList *DL, int loc, ElemType e);
Status DualListDelete(DualList *DL, int loc, ElemType *e);
void DestroyDualList(DualList *DL);

int main(int argc, char const *argv[])
{
      DualList DL;
      InitDualList(&DL);
      ElemType e = 666;

      CreateDualListHead(&DL, 10);
      CreateDualListTail(&DL, 10);
      printf("DL.length = %d\n", DL.length);
      DisplayDualListHead(DL);
      DisplayDualListTail(DL);

      DualListInsert(&DL, 21, 123);
      printf("DL.length = %d\n", DL.length);
      DisplayDualListHead(DL);
      DisplayDualListTail(DL);

      DualListDelete(&DL, 21, &e);
      printf("DL.length = %d\n", DL.length);
      DisplayDualListHead(DL);
      DisplayDualListTail(DL);
      printf("e = %d\n", e);

      DestroyDualList(&DL);
      return 0;
}

Status InitDualList(DualList *DL)
{
      DL->head = (DualNode *)malloc(sizeof(DualNode));
      if (DL->head == NULL)
      {
            perror("OVERFLOW");
            return OVERFLOW;
      }

      DL->length = 0;
      DL->tail = DL->head;

      // // 无环
      // DL->tail->prior = NULL;
      // DL->tail->next = NULL;

      // 有环
      DL->tail->prior = DL->head;
      DL->tail->next = DL->head;

      return SUCCESS;
}

void DisplayDualListHead(DualList DL)
{
      DualNode *p = DL.head->next;
      while (p != DL.tail->next)
      {
            PrintDualNode(p);

            p = p->next;
      }
      printf("\n");
}

void DisplayDualListTail(DualList DL)
{
      DualNode *p = DL.tail;
      while (p != DL.head)
      {
            PrintDualNode(p);

            p = p->prior;
      }
      printf("\n");
}

void PrintDualNode(DualNode *p)
{
      printf("%d ", p->data);
}

Status CreateDualListHead(DualList *DL, int count)
{
      DualNode *p = NULL;
      int i = 0;

      srand(time(0));
      for (i = 0; i < count; i++)
      {
            p = (DualNode *)malloc(sizeof(DualNode));
            if (p == NULL)
            {
                  perror("OVERFLOW");
                  return OVERFLOW;
            }
            // p->data = rand() % 100 + 1;
            p->data = i;

            p->next = DL->head->next;
            p->prior = DL->head;
            DL->head->next = p;
            if (p->next != NULL)
            {
                  p->next->prior = p;
            }
            DL->length++;

            if (DL->tail == DL->head)
            {
                  DL->tail = p;
            }
      }

      return SUCCESS;
}

Status CreateDualListTail(DualList *DL, int count)
{
      DualNode *p = NULL;
      int i = 0;

      srand(time(0));

      for (i = 0; i < count; i++)
      {
            p = (DualNode *)malloc(sizeof(DualNode));
            if (p == NULL)
            {
                  perror("OVERFLOE");
                  return OVERFLOW;
            }
            // p->data = rand() % 100 + 1;
            p->data = i * 100;

            p->next = DL->tail->next;
            p->prior = DL->tail;
            DL->tail->next = p;
            DL->length++;
            DL->tail = p;
      }

      return SUCCESS;
}

Status DualListInsert(DualList *DL, int loc, ElemType e)
{
      DualNode *p = DL->head;
      DualNode *s = (DualNode *)malloc(sizeof(DualNode));
      if (s == NULL)
      {
            perror("OVERFLOW");
            return OVERFLOW;
      }
      s->data = e;

      int cnt = 1;
      while (p != DL->tail && cnt < loc) // 寻找第 loc 个结点
      {
            p = p->next;
            cnt++;
      }

      if (p == DL->tail && cnt > loc)
      {
            return ERROR;
      }

      // p 为第 loc 个结点的前驱
      s->next = p->next;
      s->prior = p;
      p->next->prior = s;
      p->next = s;
      DL->length++;
      if (p == DL->tail)
      {
            DL->tail = DL->head->prior;
      }

      return SUCCESS;
}

Status DualListDelete(DualList *DL, int loc, ElemType *e)
{
      DualNode *p = DL->head;
      DualNode *q = NULL;

      int cnt = 1;
      while (p->next != DL->tail->next && cnt < loc)
      {
            p = p->next;
            cnt++;
      }

      if (p->next == DL->tail->next && cnt > loc)
      {
            return ERROR;
      }

      q = p->next;

      if (p == DL->tail->prior)
      {
            DL->tail = p;
      }

      q->next->prior = p;
      p->next = q->next;

      *e = q->data;

      free(q);
      DL->length--;

      return SUCCESS;
}

void DestroyDualList(DualList *DL)
{
      DualNode *p = DL->head;
      while (DL->length-- >= 0)
      {
            DL->head = DL->head->next;
            free(p);
            p = DL->head;
      }
}
