// * Diy 链式结构的 栈

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 6

typedef int ElemType;

typedef struct _nodeStack
{
      ElemType data;
      struct _nodeStack *next;
} NodeStack;

typedef struct _linkStack
{
      size_t length;
      NodeStack *top; // 头结点上的头指针
} LinkStack;

int StackEmpty(LinkStack S);
int StackPush(LinkStack *S, ElemType data);
int StackPop(LinkStack *S, ElemType *data);
int GetStackTop(LinkStack S, ElemType *data);
int DestroyStack(LinkStack *S);

int main(int argc, char const *argv[])
{
      LinkStack S = {
          .length = 0,
          .top = NULL,
      };
      ElemType data = 0;

      while (data < MAXSIZE)
      {
            StackPush(&S, data++);
      }
      printf("入栈完毕! S.length=%lu\n\n", S.length);

      while (GetStackTop(S, &data))
      {
            printf("\tGetTop: data=%d\n", data);
            if (StackPop(&S, &data))
            {
                  printf("\t出栈一个元素: data=%d\n", data);
                  printf("\tS.length=%lu\n\n", S.length);
            }
      }
      printf("出栈完毕! S.length=%lu\n", S.length);

      if (DestroyStack(&S))
      {
            printf("清空! S.length=%lu\n", S.length);
      }

      return 0;
}

int StackEmpty(LinkStack S)
{
      int ret = 0;
      if (S.length == 0)
      {
            ret = 1;
      }
      return ret;
}

int StackPush(LinkStack *S, ElemType data)
{
      NodeStack *oldTop = S->top;
      NodeStack *newNode = (NodeStack *)malloc(sizeof(NodeStack));
      if (newNode == NULL)
      {
            perror("! Error info");
            return 0;
      }
      newNode->data = data;
      S->top = newNode;
      newNode->next = oldTop;
      S->length++;
      return 1;
}

int StackPop(LinkStack *S, ElemType *data)
{
      if (S->length == 0)
      {
            return 0;
      }
      NodeStack *newTop = S->top->next;
      NodeStack *oldTop = S->top;
      S->top = newTop;
      S->length--;
      if (data)
      {
            *data = oldTop->data;
      }
      free(oldTop);
      return 1;
}

int GetStackTop(LinkStack S, ElemType *data)
{
      if (S.length == 0)
      {
            return 0;
      }
      *data = S.top->data;
      return 1;
}

int DestroyStack(LinkStack *S)
{
      while (S->length > 0)
      {
            StackPop(S, NULL);
      }
      return StackEmpty(*S);
}
