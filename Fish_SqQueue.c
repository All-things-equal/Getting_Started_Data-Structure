/* 顺序机构的 循环队列 */
/* 
    ! 单向线性队列 不常用
        * 入队操作实质是在队尾追加一个元素, 不需要任何移动, 时间复杂度为O(1).
        * 出队操作则不同, 因为定义0位置是队头, 因此每次出队列操作所有元素都要向前移动, 时间复杂度为O(n).
        * 效率极低.
        
        * 采取移动队头指针的方式来改变逻辑上的0位置在单向队列的定义上会导致 假溢出.

    * 循环队列
        * 逻辑上的环形定长存储空间
        * 有一个空置的位置.
        * 模运算处理: .rear = (.rear + 1) % QueueSize ; .front = (.front + 1) % QueueSize .
         
        
    ! 本程序是伪代码
*/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define ERROR 0

#define MAXSIZE 100

typedef int ElemType;
typedef int Status;

typedef struct
{
    ElemType *base; // 用于存放内存分配基地址, 也可以直接用数组.
    int front;
    int rear;
} SqLoopQueue;

Status InitQueue(SqLoopQueue *Q);
Status InsertQueue(SqLoopQueue *Q, ElemType e);
Status DeleteQueue(SqLoopQueue *Q, ElemType *e);

Status InitQueue(SqLoopQueue *Q)
{
    Q->base = (ElemType *)malloc(sizeof(ElemType) * MAXSIZE);
    if (Q->base == NULL)
    {
        return ERROR;
    }

    Q->front = 0;
    Q->rear = 0;

    return SUCCESS;
}

Status InsertQueue(SqLoopQueue *Q, ElemType e)
{
    if ((Q->rear + 1) % MAXSIZE == Q->front)
    { // 判断队列是否已满
        return ERROR;
    }

    Q->base[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;

    return SUCCESS;
}

Status DeleteQueue(SqLoopQueue *Q, ElemType *e)
{
    if (Q->front == Q->rear)
    { // 判断队列是否为空
        return ERROR;
    }

    *e = Q->base[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;

    return SUCCESS;
}
