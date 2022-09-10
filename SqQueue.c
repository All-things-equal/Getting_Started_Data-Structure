/* Diy 顺序结构的 队列 */
// * 逻辑上为 环
// * 数据上限为 QUEUE_LENGTH - 1
// * 队尾入, 队首出
// * 先进先出

/*
! 链式结构的 队列
                                                      LinkQueue.rear
                                                      ||
      LinkQueue.front -> nodeHead -> ...node... -> nodeTail -> NULL
      * 入队 尾插法
      * 离队 front = front->next
      * 有空置的头指针, 有尾指针
*/

#include <stdio.h>

#define QUEUE_LENGTH 6

typedef int ElemType;

typedef struct
{
      ElemType data[QUEUE_LENGTH];
      int front; // 索引队首元素
      int rear;  // 队尾元素的下一个位置
} SqQueue;

int QueueEmpty_void(SqQueue Q);
int QueueEmpty_fill(SqQueue Q);
int EnQueue(SqQueue *Q, ElemType data);
int DeQueue(SqQueue *Q, ElemType *data);
int GetQueueHead(SqQueue Q, ElemType *data);
int DestoryQueue(SqQueue *Q);

int main(int argc, char const *argv[])
{
      SqQueue Q = {Q.front = 0, Q.rear = 0};
      ElemType data = 0;

      while (!QueueEmpty_fill(Q))
      {
            EnQueue(&Q, data++);
      }
      printf("入队完毕!\nfront=%d,rear=%d\n\n", Q.front, Q.rear);

      while (!QueueEmpty_void(Q))
      {
            if (GetQueueHead(Q, &data))
            {
                  printf("    get队首数据: %d\n", data);
                  if (DeQueue(&Q, &data))
                  {
                        printf("    出队: data=%d\n\n", data);
                  }
            }
      }
      printf("离队完毕!\nfront=%d,rear=%d\n\n", Q.front, Q.rear);

      if (DestoryQueue(&Q))
      {
            printf("清除队列!\nfront=%d,rear=%d\n\n", Q.front, Q.rear);
      }

      return 0;
}

int QueueEmpty_void(SqQueue Q)
{
      int ret = 0;
      if (Q.front == Q.rear)
      {
            ret = 1;
      }
      return ret;
}

int QueueEmpty_fill(SqQueue Q)
{
      int ret = 0;
      if ((Q.rear + 1) % QUEUE_LENGTH == Q.front)
      {
            ret = 1;
      }
      return ret;
}

int EnQueue(SqQueue *Q, ElemType data)
{
      if (QueueEmpty_fill(*Q))
      {
            return 0;
      }
      else
      {
            Q->data[Q->rear] = data;
            Q->rear = (Q->rear + 1) % QUEUE_LENGTH;
            return 1;
      }
}

int DeQueue(SqQueue *Q, ElemType *data)
{
      if (QueueEmpty_void(*Q))
      {
            return 0;
      }
      if (data)
      {
            *data = Q->data[Q->front];
      }
      Q->front = (Q->front + 1) % QUEUE_LENGTH;
      return 1;
}

int GetQueueHead(SqQueue Q, ElemType *data)
{
      if (QueueEmpty_void(Q))
      {
            return 0;
      }
      else
      {
            *data = Q.data[Q.front];
      }
}

int DestoryQueue(SqQueue *Q)
{
      while (!QueueEmpty_void(*Q))
      {
            DeQueue(Q, NULL);
      }
      Q->front = 0;
      Q->rear = 0;
      return QueueEmpty_void(*Q);
}
