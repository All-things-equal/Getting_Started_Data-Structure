/* BinaryTree_LinkList.c - 二叉链表, 前序遍历 */
// TODO: malloc() 之后没有 free()

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

typedef char ElemType;
typedef int Status;

typedef struct BiTNode
{
      ElemType data;
      struct BiTNode *lchild; // 左孩子
      struct BiTNode *rchild; // 右孩子
} BiTNode, *BiTree;

Status CreateBiTree(BiTree *T); // 创建一颗二叉树
                                // * 先决条件: <用户> 遵照 前序遍历 的方式输入数据

void PreOrderTraverse(BiTree T, int level); // 前序遍历, 输出结点数据
void Output(BiTree T, int level);           // 访问结点

int main(int argc, char const *argv[])
{
      BiTree T = NULL;

      CreateBiTree(&T);
      PreOrderTraverse(T, 1);

      return 0;
}

Status CreateBiTree(BiTree *T)
{
      ElemType ch;
      scanf("%c", &ch);

      if (' ' == ch)
      {
            *T = NULL;
      }
      else
      {
            *T = (BiTree)malloc(sizeof(BiTNode));
            if (!(*T))
            {
                  return FAILURE;
            }

            (*T)->data = ch;

            CreateBiTree(&(*T)->lchild);

            CreateBiTree(&(*T)->rchild);
      }

      return SUCCESS;
}

void PreOrderTraverse(BiTree T, int level)
{
      if (T)
      {
            Output(T, level);

            PreOrderTraverse(T->lchild, level + 1);

            PreOrderTraverse(T->rchild, level + 1);
      }
}

void Output(BiTree T, int level)
{
      printf("level %d: ", level);
      printf("%c\n", T->data);
}