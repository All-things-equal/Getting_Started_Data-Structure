// * Diy 链式结构的 队伍

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 6

typedef int ElemType;

typedef struct _nodeQueue
{
      ElemType data;
      struct _nodeQueue *next;
} NodeQueue;

typedef struct _linkQueue
{
      size_t length;
      NodeQueue *front;
      NodeQueue *rear;
} LinkQueue;

int QueueEmpty(LinkQueue Q);
int EnQueue(LinkQueue *Q, ElemType data);
int DeQueue(LinkQueue *Q, ElemType *data);
int GetQueueHead(LinkQueue Q, ElemType *data);
int DestroyQueue(LinkQueue *Q);
int freeQueue(LinkQueue *Q);

int main(int argc, char const *argv[])
{
      LinkQueue Q = {
          .length = 0,
          .front = (NodeQueue *)malloc(sizeof(NodeQueue)),
          .rear = Q.front,
      };
      Q.rear->next = NULL;
      ElemType data;

      while (data < MAXSIZE)
      {
            EnQueue(&Q, data++);
      }
      printf("入队完毕! Q.length=%lu\n\n", Q.length);

      while (GetQueueHead(Q, &data))
      {
            printf("\tGetHead: data=%d\n", data);
            if (DeQueue(&Q, &data))
            {
                  printf("\t离队一个元素: data=%lu\n", data);
                  printf("\tQ.length=%lu\n\n", Q.length);
            }
      }
      printf("离队完毕! Q.length=%lu\n", Q.length);

      if (DestroyQueue(&Q))
      {
            printf("清空! Q.length=%lu\n", Q.length);
      }

      if (freeQueue(&Q))
      {
            printf("\nQ.length=%d\n", Q.length);
      }

      return 0;
}

int QueueEmpty(LinkQueue Q)
{
      int ret = 0;
      if (Q.length == 0)
      {
            ret = 1;
      }
      return ret;
}

int EnQueue(LinkQueue *Q, ElemType data)
{
      NodeQueue *newRear = (NodeQueue *)malloc(sizeof(NodeQueue));
      if (newRear == NULL)
      {
            perror("! Error info");
            return 0;
      }
      newRear->data = data;
      newRear->next = NULL;
      Q->rear->next = newRear;
      Q->rear = newRear;
      Q->length++;
      return 1;
}

int DeQueue(LinkQueue *Q, ElemType *data)
{
      if (Q->length == 0)
      {
            return 0;
      }
      NodeQueue *oldFrontHead = Q->front->next;
      Q->front->next = Q->front->next->next;
      Q->length--;
      if (data)
      {
            *data = oldFrontHead->data;
      }
      free(oldFrontHead);
      return 1;
}

int GetQueueHead(LinkQueue Q, ElemType *data)
{
      if (Q.length == 0)
      {
            return 0;
      }
      *data = Q.front->next->data;
      return 1;
}

int DestroyQueue(LinkQueue *Q)
{
      while (Q->length > 0)
      {
            DeQueue(Q, NULL);
      }
      return QueueEmpty(*Q);
}

int freeQueue(LinkQueue *Q)
{
      DestroyQueue(Q);
      free(Q->front);
      Q->length--;
      return Q->length == -1;
}
