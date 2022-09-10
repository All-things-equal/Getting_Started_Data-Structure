// * 链式 栈
// ! 不常用

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

typedef struct StackNode
{
    ElemType data;
    struct StackNode *next;
} StackNode;

typedef struct LinkStack
{
    int length;
    StackNode *top;
} LinkStack;

Status StackEmpty(const LinkStack *const S);
Status StackPush(LinkStack *S, const ElemType *ReadOnly_e);
Status StackPop(LinkStack *S, ElemType *e);
Status DestroyStack(LinkStack *S);

int main(int argc, char const *argv[])
{
    LinkStack S = {
        .length = 0,
        .top = NULL,
    };
    StackEmpty(&S);
    return 0;
}

Status StackEmpty(const LinkStack *const S)
{
    if (S->length == 0)
    {
        return TRUE;
    }
    return FALSE;
}

Status StackPush(LinkStack *S, const ElemType *ReadOnly_e)
{
    StackNode *p = (StackNode *)malloc(sizeof(StackNode));
    if (p == NULL)
    {
        return ERROR;
    }
    p->data = *ReadOnly_e;

    p->next = S->top;
    S->top = p;
    S->length++;

    return SUCCESS;
}

Status StackPop(LinkStack *S, ElemType *e)
{
    StackNode *p = S->top;
    if (StackEmpty(S) == TRUE)
    {
        return ERROR;
    }

    *e = S->top->data;
    S->top = S->top->next;
    free(p);
    S->length--;

    return SUCCESS;
}

Status DestroyStack(LinkStack *S)
{
    StackNode *p = S->top;
    while (p != NULL)
    {
        S->top = S->top->next;
        free(p);
        p = S->top;
    }
    S->length = 0;

    return SUCCESS;    
}