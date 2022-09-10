/* 逆波兰计算 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10
#define MAXBUFFER 10

#define SUCCESS 1
#define ERROR 0

typedef int Status;
typedef double ElemType;

typedef struct
{
      ElemType *base;
      ElemType *top;
      int stackSize;
} SqStack;

Status InitStack(SqStack *S);
Status StackPush(SqStack *S, ElemType e);
Status StackPop(SqStack *S, ElemType *e);
Status DestroyStack(SqStack *S);
int StackLength(const SqStack *const S);

int main(int argc, char const *argv[])
{
      SqStack S;
      char ch;
      ElemType a, b, e;
      char buffer[MAXBUFFER] = {'\0'};
      int i = 0;

      InitStack(&S);
      printf("后缀表达式(Enter # to eof): ");
      scanf("%c", &ch);

      while (ch != '#')
      {
            while (isdigit(ch) || ch == '.')
            {
                  buffer[i++] = ch;
                  if (i >= 10)
                  {
                        printf("出错, 输入的单个数据过大!\n");
                  }
                  scanf("%c", &ch);
                  if (ch == ' ')
                  {
                        e = atof(buffer);
                        StackPush(&S, e);
                        i = 0;
                  }
            }

            switch (ch)
            {
            case '+':
                  StackPop(&S, &b);
                  StackPop(&S, &a);
                  e = a + b;
                  StackPush(&S, e);
                  break;

            case '-':
                  StackPop(&S, &b);
                  StackPop(&S, &a);
                  e = a - b;
                  StackPush(&S, e);
                  break;

            case '*':
                  StackPop(&S, &b);
                  StackPop(&S, &a);
                  e = a * b;
                  StackPush(&S, e);
                  break;

            case '/':
                  StackPop(&S, &b);
                  StackPop(&S, &a);
                  if (b != 0)
                  {
                        e = a / b;
                        StackPush(&S, e);
                  }
                  else
                  {
                        printf("\n出错了, 除数为0!\n");
                        return -1;
                  }
                  break;

            default:
                  break;
            }

            scanf("%c", &ch);
      }

      StackPop(&S, &e);
      printf("result: %lf\n", e);
      DestroyStack(&S);

      return 0;
}

Status InitStack(SqStack *S)
{
      S->base = (ElemType *)malloc(sizeof(ElemType) * STACK_INIT_SIZE);
      if (S->base == NULL)
      {
            return ERROR;
      }

      S->top = S->base;
      S->stackSize = STACK_INIT_SIZE;

      return SUCCESS;
}

Status StackPush(SqStack *S, ElemType e)
{
      if (S->top - S->base >= S->stackSize)
      {
            void *ptr = realloc(S->base, sizeof(ElemType) * (S->stackSize + STACKINCREMENT));
            if (ptr == NULL)
            {
                  return ERROR;
            }
            S->base = (ElemType *)ptr;

            S->top = S->base + S->stackSize;
            S->stackSize = S->stackSize + STACK_INIT_SIZE;
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

int StackLength(const SqStack *const S)
{
      return (S->top - S->base);
}