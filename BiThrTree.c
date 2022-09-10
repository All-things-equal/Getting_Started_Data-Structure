/* BiThrTree.c - 线索二叉树 */

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

typedef char ElemType;

typedef enum
{             // 线索存储标志位
      Link,   // Link(0) 表 指向左右孩子的指针
      Thread, // Thread(1) 表 指向前驱后继的指针
} PointerTag;

typedef int Status;

typedef struct BiThrNode
{
      ElemType data;
      struct BiThrNode *lchild; // 左孩子
      struct BiThrNode *rchild; // 右孩子
      struct BiThrNode *parent; // 父结点
      PointerTag lTag;          // 左标志
      PointerTag rTag;          // 右标志
} BiThrNode, *BiThrTree;

BiThrTree pre; // 全局变量, 始终指向刚刚访问过的结点

Status CreateBiThrTree(BiThrTree *T); // 创建一颗二叉树
                                      // * 先决条件: <用户> 遵照 前序遍历 的方式输入数据
Status InThreading(BiThrTree T);      // 中序遍历线索化
Status InOrderThreading(BiThrTree *p, BiThrTree T);
void InOrderTraverse(BiThrTree T); // 中序遍历, 非递归

int main(int argc, char const *argv[])
{
      BiThrTree T = NULL;
      BiThrTree p;

      CreateBiThrTree(&T);

      InOrderThreading(&p, T);

      printf("中序遍历输出结果为: ");
      InOrderTraverse(p);

      printf("\n");
      return 0;
}

Status CreateBiThrTree(BiThrTree *T)
{
      ElemType ch;

      scanf("%c", &ch);

      if (' ' == ch)
      {
            *T = NULL;
      }
      else
      {
            *T = (BiThrNode *)malloc(sizeof(BiThrNode));
            if (!(*T))
            {
                  return FAILURE;
            }

            (*T)->data = ch;
            (*T)->lTag = Link;
            (*T)->rTag = Link;

            CreateBiThrTree(&(*T)->lchild);

            CreateBiThrTree(&(*T)->rchild);
      }

      return SUCCESS;
}

Status InThreading(BiThrTree T)
{
      if (T)
      {
            InThreading(T->lchild); // 递归左孩子线索化

            if (!(T->lchild)) // 如果该结点没有左孩子, 设置lTag为Thread, 并把lchild指向刚刚访问过的结点
            {
                  T->lTag = Thread;
                  T->lchild = pre;
            }

            if (!(pre->rchild))
            {
                  pre->rTag = Thread;
                  pre->rchild = T;
            }
            pre = T; // 更新pre

            InThreading(T->rchild); // 递归右孩子线索化
      }
}

Status InOrderThreading(BiThrTree *p, BiThrTree T)
{
      *p = (BiThrTree)malloc(sizeof(BiThrNode));
      if (!(*p))
      {
            return FAILURE;
      }

      (*p)->lTag = Link;
      (*p)->rTag = Thread;
      (*p)->rchild = *p;
      if (!T)
      {
            (*p)->lchild = *p;
      }
      else
      {
            (*p)->lchild = T;
            pre = *p;
            InThreading(T);
            pre->rchild = *p;
            pre->rTag = Thread;
            (*p)->rchild = pre;
      }

      return SUCCESS;
}

void InOrderTraverse(BiThrTree T)
{
      BiThrTree p = T->lchild;

      while (p != T)
      {
            while (Link == p->lTag)
            {
                  p = p->lchild;
            }

            printf("%c ", p->data);

            while (Thread == p->rTag && p->rchild != T)
            {
                  p = p->rchild;

                  printf("%c ", p->data);
            }

            p = p->rchild;
      }
}
