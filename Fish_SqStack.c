/* 可动态扩容的 顺序结构的 栈 */
// * Last In First Out (LIFO)

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define ERROR 0

#define STACK_INIT_SIZE 20
#define SATCKINCREMENT 10

typedef int Status;
typedef int ElemType;

typedef struct
{
      ElemType *base; // 存放栈的基地址, 栈底表头
      ElemType *top;  // 栈顶表尾, 栈顶不存放有效数据
      int stackSize;  // 栈当前可用的最大容量
      // (.top) - (.base) == 栈当前已使用的容量
} SqStack;

Status InitStack(SqStack *S);
Status StackPush(SqStack *S, ElemType e);
Status StackPop(SqStack *S, ElemType *e);
Status ClearStack(SqStack *S);
Status DestroyStack(SqStack *S);
int StackLength(SqStack S);

int main(int argc, char const *argv[])
{
      SqStack S;
      if (InitStack(&S) == SUCCESS)
      {
            printf("空栈get, S has %d size.\n", StackLength(S));
      }

      ElemType e = 0;
      while (e < STACK_INIT_SIZE * 2)
      {
            if (StackPush(&S, e++) == SUCCESS)
            {
                  printf("\tS has %d size.\n", StackLength(S));
            }
      }
      printf("Push, S has %d size.\n", StackLength(S));

      while (StackLength(S) > STACK_INIT_SIZE)
      {
            if (StackPop(&S, &e) == SUCCESS)
            {
                  printf("\tS has %d size. e = %d\n", StackLength(S), e);
            }
      }
      printf("Pop, S has %d size.\n", StackLength(S));

      DestroyStack(&S);
      printf("Destroy, S has %d size.\n", StackLength(S));

      return 0;
}

Status InitStack(SqStack *S)
{
      S->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
      if (S->base == NULL)
      {
            return ERROR;
      }

      S->top = S->base; // 最初, 空栈: 栈顶==栈底
      S->stackSize = STACK_INIT_SIZE;

      return SUCCESS;
}

Status StackPush(SqStack *S, ElemType e)
{
      // 如果栈满, 追加空间
      if (S->top - S->base >= S->stackSize)
      {
            void *ptr = realloc(S->base, (S->stackSize + SATCKINCREMENT) * sizeof(ElemType));
            if (ptr == NULL)
            {
                  return ERROR;
            }
            S->base = (ElemType *)ptr;

            S->top = S->base + S->stackSize;              // 重新设置栈顶
            S->stackSize = S->stackSize + SATCKINCREMENT; // 重新设置栈的最大容量
      }

      *(S->top) = e;
      S->top++;

      return SUCCESS;
}

Status StackPop(SqStack *S, ElemType *e)
{
      if (S->top == S->base)
      {
            return ERROR;
      }

      *e = *(--(S->top));
      return SUCCESS;
}

Status ClearStack(SqStack *S)
{
      S->top = S->base;

      return SUCCESS;
}

Status DestroyStack(SqStack *S)
{
      // int i = 0;
      // int count = S->stackSize;
      // for (i = 0; i < count; i++)
      // {
      //     free(S->base);
      //     S->base++;
      // }

      free(S->base);

      S->base = NULL;
      S->top = S->base;
      S->stackSize = 0;

      return SUCCESS;
}

int StackLength(SqStack S)
{
      return (S.top - S.base);
}
