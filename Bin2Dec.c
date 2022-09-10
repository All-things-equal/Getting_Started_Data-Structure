/* 二进制 to 十进制 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10

#define SUCCESS 1
#define ERROR 0

typedef int Status;
typedef char ElemType;

typedef struct
{
      ElemType *base;
      ElemType *top;
      int stackSize;
} SqStack;

Status InitStack(SqStack *S);
Status StackPush(SqStack *S, ElemType e);
Status StackPop(SqStack *S, ElemType *e);
int StackLength(const SqStack *const S);

int main(int argc, char const *argv[])
{
      ElemType e;
      SqStack S;
      int i = 0;
      int count = 0;
      int digit = 0;
      int input = EOF;
      InitStack(&S);

      printf("Enter not '0' or not '1' to EOF.\nEnter 二进制: ");
      while ((input = getchar()) != EOF && isdigit(input))
      {
            if (input == '0' || input == '1')
            {
                  if (StackPush(&S, (ElemType)input) == ERROR)
                  {
                        break;
                  }
            }
      }
      while (input != '\n' && '\n' != getchar())
      {
            continue;
      }

      count = StackLength(&S);
      if (count > 0)
      {
            for (i = 0; i < count; i++)
            {
                  if (StackPop(&S, &e) == SUCCESS)
                  {
                        digit = digit + ((e - '0') << i);
                  }
            }

            printf("十进制: %d\n", digit);
      }

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

int StackLength(const SqStack *const S)
{
      return (S->top - S->base);
}