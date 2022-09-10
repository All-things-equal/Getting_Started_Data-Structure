/* 静态链表 */

/*
      * 对数组的第一个和最后一个元素做特殊处理, 他们的data不存放数据.
      * 通常把未使用的数组元素成为备用链表.
      * 数组的第一个元素, 即下标为0的那个元素的cursor存放备用链表的第一个结点的下标.
      * 数组的最后一个元素, 即下标为MAXSIZE-1的cursor存放第一个有数据的元素的下标, 相当于单链表的头结点的作用.
*/

#include <stdio.h>

#define MAXSIZE 5

#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define ERROR 0
#define OVERFLOW -1

typedef int ElemType;
typedef int Status;

typedef struct _staticLinkList
{
      ElemType data;
      int cursor; // 游标: 最后一个元素置空,游标表第一个有效元素; 第0个元素置空,游标表最后一个有效元素的下一个空位; 最后一个有效元素的游标为 0 .
} Component, StaticLinkList[MAXSIZE];

Status InitList(StaticLinkList space);
int Malloc_SLL(StaticLinkList space);                       // 获取空闲分量的下标
Status ListInsert(StaticLinkList SLL, int loc, ElemType e); // 在静态链表 SLL 中第 loc 个元素之前插入新的数据元素.
Status ListDelete(StaticLinkList SLL, int loc);             // 在静态链表 SLL 中删除第 loc 个数据元素.
Status Free_SLL(StaticLinkList space, int loc);             // 将下标为 loc 的空闲结点回收到备用链表中.
int ListLength(StaticLinkList SLL);                         // 返回 SLL 中数据元素的个数
void DisplayList(StaticLinkList space);

int main(int argc, char const *argv[])
{
      StaticLinkList SLL;
      InitList(SLL);
      DisplayList(SLL);
      ElemType e = 10;
      while (e < MAXSIZE * 10 / 2)
      {
            ListInsert(SLL, ListLength(SLL) + 1, e);
            e = e << 1;
      }
      printf("\n");
      DisplayList(SLL);
      return 0;
}

Status InitList(StaticLinkList space)
{
      int i = 0;
      for (i = 0; i < MAXSIZE - 1; i++)
      {
            space[i].cursor = i + 1;
      }
      space[MAXSIZE - 1].cursor = 0;
      return SUCCESS;
}

int Malloc_SLL(StaticLinkList space)
{
      int loc = space[0].cursor;
      if (space[0].cursor)
      {
            space[0].cursor = space[loc].cursor;
      }
      return loc;
}

Status ListInsert(StaticLinkList SLL, int loc, ElemType e)
{
      int i, j, k;

      if (loc < 1 || loc > ListLength(SLL) + 1)
      {
            return ERROR;
      }

      i = Malloc_SLL(SLL);
      j = MAXSIZE - 1;
      if (i)
      {
            SLL[i].data = e;
            for (k = 1; k < loc - 1; k++)
            {
                  j = SLL[j].cursor;
            }
            SLL[i].cursor = SLL[j].cursor;
            SLL[j].cursor = i;
            return SUCCESS;
      }

      return ERROR;
}

Status ListDelete(StaticLinkList SLL, int loc)
{
      int i, j;
      if (loc < 1 || loc > ListLength(SLL))
      {
            return ERROR;
      }

      j = MAXSIZE - 1;
      for (i = 0; i < loc - 1; i++)
      {
            j = SLL[j].cursor;
      }

      j = SLL[j].cursor;
      SLL[j].cursor = SLL[i].cursor;

      Free_SLL(SLL, i);
      return SUCCESS;
}

Status Free_SLL(StaticLinkList space, int loc)
{
      space[loc].cursor = space[0].cursor;
      space[0].cursor = loc;
}

int ListLength(StaticLinkList SLL)
{
      int count = 0;
      int index = SLL[MAXSIZE - 1].cursor;

      while (index)
      {
            index = SLL[index].cursor;
            count++;
      }

      return count;
}

void DisplayList(StaticLinkList space)
{
      int index = space[MAXSIZE - 1].cursor;
      while (index != 0)
      {
            printf("space[%d].data = %d\n", index, space[index].data);
            index = space[index].cursor;
      }
}