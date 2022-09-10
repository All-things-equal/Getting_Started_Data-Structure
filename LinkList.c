/* 单链表 and 循环链表*/

/*
      ! 循环链表: L.tail->next = L.head;
            * 遍历循环条件: (index->next != head) or (index->next != tail->next)
            * 循环链表并不一定要有头结点的头指针.
            * 尾指针访问第一个结点: tail->next->next
            * 空表: (head->next == head) or (tail == tail->next)

      * 有无环链表的工作指针遍历条件可通用 p != tail->next
*/

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

typedef struct _node
{
      ElemType data;
      struct _node *next;
} Node;

typedef struct _list
{
      int length;
      Node *head;
      Node *tail;
} List;

Status CreateListHead(List *L, int count); // 头插法 创建 count 个随机数数据的结点
Status CreateListTail(List *L, int count); // 尾插法 创建 count 个随机数数据的结点
Status GetElem(List L, int loc, ElemType *e);
Status ListInsert(List *L, int loc, ElemType e);
Status ListDelete(List *L, int loc, ElemType *e);
Status ClearList(List *L); // 清除链表, 保留头结点
void DisplayList(List L);
Status GetMidNode(List L, ElemType *e);   // 快慢指针, 找到链表的中间结点
Node *CreateLoopList(List *L, int count); // 尾插法 创建 count 个随机数数据结点的循环链表
void DisplayLoopList(List L);
Node *Connect(List *La, List *Lb); // 连接两个循环链表, La->Lb. // ! Connect后 Lb 会死链.
int HasLoop_1(List L);             // 计数 判断链表是否有环
int HasLoop_2(List L);             // 快慢指针 判断链表是否有环

int main(int argc, char const *argv[])
{
      printf("\n单链表\n");
      List L = {
          .length = 0,
          .head = (Node *)malloc(sizeof(Node)),
          .tail = L.head,
      };
      if (L.head == NULL)
      {
            exit(OVERFLOW);
      }
      L.tail->next = NULL;
      ElemType e = 0;

      CreateListHead(&L, 10);
      printf("\tCreateListHead L.length = %d\n", L.length);
      CreateListTail(&L, 10);
      printf("\tCreateListTail L.length = %d\n", L.length);

      DisplayList(L);
      GetMidNode(L, &e);
      printf("\te=%d\n", e);

      ListInsert(&L, 21, 123);
      printf("\tListInsert L.length = %d\n", L.length);
      DisplayList(L);

      ListDelete(&L, 21, &e);
      printf("\tListDelete L.length = %d\n", L.length);
      DisplayList(L);

      printf("\n循环链表\n");
      List loopA = {.head = CreateLoopList(&loopA, 10)};
      List loopB = {.head = CreateLoopList(&loopB, 10)};

      printf("\tloopA: ");
      DisplayLoopList(loopA);
      printf("\tCreateLoopList loopA.length = %d\n", loopA.length);
      printf("\tloopB: ");
      DisplayLoopList(loopB);
      printf("\tCreateLoopList loopB.length = %d\n", loopB.length);

      // List loopC = {.head = Connect(&loopA, &loopB, &loopC.length)};

      // printf("\tloopC: ");
      // DisplayLoopList(loopC);
      // printf("\tConnect loopC.length = %d\n", loopC.length);
      Connect(&loopA, &loopB);
      printf("\n\tloopA: ");
      DisplayLoopList(loopA);
      printf("\tConnect loopA.length = %d\n", loopA.length);
      printf("\tloopB: loopB已死\n");
      // DisplayLoopList(loopB);
      // printf("\tConnect loopB.length = %d\n", loopB.length);
      printf("\n\tloopA.head = %p", loopA.head);
      printf("\n\tloopA.tail = %p", loopA.tail);
      printf("\n\tloopB.head = %p", loopB.head);
      printf("\n\tloopB.tail = %p", loopB.tail);
      // printf("\n\tloopC.head = %p", loopC.head);
      // printf("\n\tloopC.tail = %p", loopC.tail);
      // if (loopC.head == loopA.head && loopC.tail == loopA.tail)
      // {
      // printf("\tConnect loopC == loopA");
      // }
      printf("\n");
      printf("\tloopA: ");
      HasLoop_1(loopA);
      HasLoop_2(loopA);
      // printf("\tloopB: ");
      // HasLoop_1(loopB);
      // printf("\tloopC: ");
      // HasLoop_1(loopC);

      return 0;
}

Status CreateListHead(List *L, int count)
{
      Node *p;
      int i = 0;

      srand(time(0));
      for (i = 0; i < count; i++)
      {
            p = (Node *)malloc(sizeof(Node));
            if (p == NULL)
            {
                  return OVERFLOW;
            }
            p->data = rand() % 100 + 1;
            // p->data = i;

            if (L->tail == L->head)
            {
                  L->tail = p;
            }

            p->next = L->head->next;
            L->head->next = p;
            L->length++;
      }
      return SUCCESS;
}

Status CreateListTail(List *L, int count)
{
      Node *p;
      int i = 0;

      srand(time(0));
      for (i = 0; i < count; i++)
      {
            p = (Node *)malloc(sizeof(Node));
            if (p == NULL)
            {
                  return OVERFLOW;
            }
            p->data = rand() % 100 + 1;
            // p->data = i;
            L->tail->next = p;
            L->tail = p;
            L->length++;
      }
      L->tail->next = NULL;
      return SUCCESS;
}

Status GetElem(List L, int loc, ElemType *e)
{
      Node *p = L.head->next;
      int cnt = 1;

      while (p && cnt < loc)
      {
            p = p->next;
            cnt++;
      }

      if (!p || cnt > loc)
      {
            return ERROR;
      }

      *e = p->data;
      return SUCCESS;
}

Status ListInsert(List *L, int loc, ElemType e)
{
      Node *p = L->head;
      Node *s = (Node *)malloc(sizeof(Node));
      if (s == NULL)
      {
            return OVERFLOW;
      }
      s->data = e;

      int cnt = 1;
      while (p && cnt < loc) // 寻找第 loc 个结点
      {
            p = p->next;
            cnt++;
      }

      if (!p && cnt > loc)
      {
            return ERROR;
      }

      // p 为第 loc 个结点的前驱
      s->next = p->next;
      p->next = s;
      L->length++;
      return SUCCESS;
}

Status ListDelete(List *L, int loc, ElemType *e)
{
      Node *p = L->head;
      Node *q = NULL;

      int cnt = 1;
      while (p->next && cnt < loc)
      {
            p = p->next;
            cnt++;
      }

      if (!(p->next) && cnt > loc)
      {
            return ERROR;
      }

      if (p->next == L->tail)
      {
            L->tail = p;
      }

      q = p->next;
      p->next = p->next->next;
      *e = q->data;
      free(q);
      L->length--;
      return SUCCESS;
}

Status ClearList(List *L)
{
      Node *p, *q;
      p = L->head->next;

      while (p)
      {
            q = p->next;
            free(p);
            p = q;
      }

      L->head->next = NULL;
      return SUCCESS;
}

void DisplayList(List L)
{
      Node *p = L.head->next;

      while (p)
      {
            printf("%d ", p->data);
            p = p->next;
      }
      printf("\n");
}

Status GetMidNode(List L, ElemType *e)
{
      Node *search = L.head->next; // 快 指针
      Node *mid = L.head->next;    // 慢 指针

      while (search->next != NULL)
      {
            // search 移动的速度是 mid 的两倍
            if (search->next->next != NULL)
            {
                  search = search->next->next;
                  mid = mid->next;
            }
            else
            { // 处理奇数个结点的情况
                  search = search->next;
            }
      }

      *e = mid->data;
      return SUCCESS;
}

Node *CreateLoopList(List *L, int count)
{
      Node *p = NULL;
      int i = 0;

      L->head = (Node *)malloc(sizeof(Node));
      if (L->head == NULL)
      {
            perror("OVERFLOW");
            return NULL;
      }
      L->tail = L->head;
      L->length = count;

      srand(time(0));
      for (i = 0; i < count; i++)
      {
            p = (Node *)malloc(sizeof(Node));
            if (p == NULL)
            {
                  perror("OVERFLOW");
                  return L->head;
            }
            p->data = rand() % 100 + 1;
            L->tail->next = p;
            L->tail = p;
      }
      L->tail->next = L->head;
      return L->head;
}

void DisplayLoopList(List L)
{
      Node *p = L.head->next;

      while (p->next != L.head)
      {
            printf("%d ", p->data);
            p = p->next;
      }
      printf("\n");
}

Node *Connect(List *La, List *Lb)
{
      La->tail->next = Lb->tail->next->next;
      free(Lb->head);
      Lb->tail->next = La->head;

      La->length = La->length + Lb->length;

      return La->head;
}

int HasLoop_1(List L) // p一次遍历, q每次都从头遍历, 判断p和q走到同一结点的步数是否相等.
{
      Node *p = L.head;
      int cntP = 0; // 记录 p 指针的步数

      while (p)
      {
            Node *q = L.head;
            int cntQ = 0; // 记录 q 指针的步数

            while (q)
            {
                  if (q == p)
                  {
                        if (cntP == cntQ) // 当p和q到达相同结点时,若走过的步数一样, 说明没有环.
                        {
                              break;
                        }
                        else
                        {
                              printf("环的位置在第%d个结点处.\n", cntQ);
                              return TRUE;
                        }
                  }

                  q = q->next;
                  cntQ++;
            }

            p = p->next;
            cntP++;
      }

      return FALSE;
}

int HasLoop_2(List L)
{
      Node *p = L.head; // 慢指针
      Node *q = L.head; // 快指针

      while (p && q && q->next != NULL)
      {
            p = p->next;

            if (q->next != NULL)
            {
                  q = q->next->next;
            }

            printf("\tp->data: %d, q->data: %d; ", p->data, q->data);
            printf("p: %p, q: %p\n", p, q);

            if (p == q)
            {
                  return TRUE;
            }
      }

      return FALSE;
}
