/* Diy 顺序结构的 栈*/
// * 先进后出

/*
! 共享栈
      ********** <- bottom 2
      **********
      **********
      ********** <- top 2
      ********** <- top 1
      **********
      **********
      ********** <- bottom 1
      *共享空间满 => top1 + 1 = top2
*/

/*
! 链式结构的 栈
      LinkStack.head == (栈顶节点)nodeTop -> ...node... -> (栈底节点)nodeBottom -> NULL
      * 栈顶top == 单链表的头指针
      * 入栈 头插法
      * 出栈 去头法
      * top 栈顶不存放有效数据
*/

#include <stdio.h>

#define STACK_LENGTH 6

typedef int ElemType;

typedef struct
{
      ElemType data[STACK_LENGTH];
      int top;
} SqStack;

int StackEmpty_void(SqStack S);             // 判断栈是否为空, 空返回1
int StackEmpty_fill(SqStack S);             // 判断栈是否已满, 满返回1
int StackPush(SqStack *S, ElemType data);   // 入栈
int StackPop(SqStack *S, ElemType *data);   // 出栈
int GetStackTop(SqStack S, ElemType *data); // 读取栈顶的数据
int DestroyStack(SqStack *S);               // 清空栈

int main(int argc, char const *argv[])
{
      SqStack S = {S.top = -1};
      ElemType data = 0;

      while (!StackEmpty_fill(S))
      {
            StackPush(&S, data++);
      }
      printf("入栈完毕: top=%d\n\n", S.top);

      while (!StackEmpty_void(S))
      {
            if (GetStackTop(S, &data))
            {
                  printf("    get栈顶, data=%d\n", data);
                  if (StackPop(&S, &data))
                  {
                        printf("    出栈, data=%d\n", data);
                  }
                  printf("    出栈一次: top=%d\n\n", S.top);
            }
      }
      printf("出栈完毕, top=%d\n\n", S.top);

      if (DestroyStack(&S))
      {
            printf("清空栈, top=%d\n", S.top);
      }

      return 0;
}

int StackEmpty_void(SqStack S)
{
      int ret = 0;
      if (S.top == -1)
      {
            ret = 1;
      }
      return ret;
}

int StackEmpty_fill(SqStack S)
{
      int ret = 0;
      if (S.top == STACK_LENGTH - 1)
      {
            ret = 1;
      }
      return ret;
}

int StackPush(SqStack *S, ElemType data)
{
      if (StackEmpty_fill(*S))
      {
            return 0;
      }
      else
      {
            S->data[++S->top] = data;
            return 1;
      }
}

int StackPop(SqStack *S, ElemType *data)
{
      if (StackEmpty_void(*S))
      {
            return 0;
      }
      if (data)
      {
            *data = S->data[S->top];
      }
      S->top--;
      return 1;
}

int GetStackTop(SqStack S, ElemType *data)
{
      if (StackEmpty_void(S))
      {
            return 0;
      }
      else
      {
            *data = S.data[S.top];
            return 1;
      }
}

int DestroyStack(SqStack *S)
{
      while (!StackEmpty_void(*S))
      {
            StackPop(S, NULL);
      }
      return StackEmpty_void(*S);
}
