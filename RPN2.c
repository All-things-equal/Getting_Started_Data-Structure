/* 中缀表达式 to 后缀表达式 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define ERROR 0

#define STACK_INIT_SIZE 20
#define SATCKINCREMENT 10

typedef int Status;
typedef char ElemType;

typedef struct
{
      ElemType *base; // 栈底表头
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
      char ch;
      ElemType e;
      InitStack(&S);

      printf("中缀表达式(Enter # to eof): ");
      scanf("%c", &ch);

      while (ch != '#')
      {
            while (isdigit(ch))
            {
                  printf("%c", ch);
                  scanf("%c", &ch);
                  if (!isdigit(ch))
                  {
                        printf(" ");
                  }
            }

            if (')' == ch)
            {
                  StackPop(&S, &e);
                  while ('(' != e)
                  {
                        printf("%c ", e);
                        StackPop(&S, &e);
                  }
            }
            else if ('+' == ch || '-' == ch)
            {
                  if (StackLength(S) == 0)
                  {
                        StackPush(&S, ch);
                  }
                  else
                  {
                        do
                        {
                              StackPop(&S, &e);
                              if ('(' == e)
                              {
                                    StackPush(&S, e);
                              }
                              else
                              {
                                    printf("%c ", e);
                              }

                        } while (StackLength(S) != 0 && '(' != e);
                        StackPush(&S, ch);
                  }
            }
            else if ('*' == ch || '/' == ch || '(' == ch)
            {
                  StackPush(&S, ch);
            }
            else if ('#' == ch)
            {
                  break;
            }
            else
            {
                  printf("\n出错: 输入格式错误!\n");
                  return -1;
            }

            scanf("%c", &ch);
      }

      while (StackLength(S) != 0)
      {
            StackPop(&S, &e);
            printf("%c ", e);
      }

      printf("\n");
      DestroyStack(&S);

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
