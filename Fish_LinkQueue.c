/* 链 队列 */
// * First In First Out (FIFO)

/*
    * 队头指针front 指向 链队列的头结点
    * 队尾指针rear  指向 链队列的终端结点
    * ps: 头结点不是必要的, 此程序为方便操作so有头结点
    
    ! 本程序是伪代码 
*/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

typedef struct QueueNode
{
    ElemType data;
    struct QueueNode *next;
} QueueNode;

typedef struct QueueLink
{
    QueueNode *front; // 队头指针
    QueueNode *rear;  // 队尾指针
} LinkQueue;

Status InitQueue(LinkQueue *Q);
Status InsertQueue(LinkQueue *Q, ElemType e);
Status DeleteQueue(LinkQueue *Q, ElemType *e);
Status DestroyQueue(LinkQueue *Q);

Status InitQueue(LinkQueue *Q)
{
    Q->front = (QueueNode *)malloc(sizeof(QueueNode));
    if (Q->front == NULL)
    {
        return ERROR;
    }

    Q->rear = Q->front;
    Q->rear->next = NULL;

    return SUCCESS;
}

Status InsertQueue(LinkQueue *Q, ElemType e)
{
    QueueNode *p = (QueueNode *)malloc(sizeof(QueueNode));
    if (p == NULL)
    {
        return ERROR;
    }

    p->data = e;
    p->next = Q->rear->next;
    Q->rear->next = p;
    Q->rear = p;

    return SUCCESS;
}

Status DeleteQueue(LinkQueue *Q, ElemType *e)
{
    QueueNode *p = NULL;
    if (Q->front == Q->rear)
    { // 判断是否空队列
        return ERROR;
    }

    p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    if (Q->rear == p)
    { // 处理p是仅剩的最后一个元素的情况
        Q->rear = Q->front;
    }
    free(p);

    return SUCCESS;
}

Status DestroyQueue(LinkQueue *Q)
{
    while (Q->front != NULL)
    {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
    return SUCCESS;
}
