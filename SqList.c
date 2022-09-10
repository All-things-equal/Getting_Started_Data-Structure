#include <stdio.h>

#define MAXSIZE 20

#define TRUE 1
#define FALSE 0
#define ERROR 0
#define SUCCESS 1
#define OVERFLOW -1

typedef int ElemType;
typedef int Status; // Status 表函数执行结果的状态

typedef struct _SqList
{
      int length;
      ElemType data[MAXSIZE];
} SqList;

Status InitList(SqList *L);                         // 初始化, 建立一个空的线性表 L .
Status ListEmpty(SqList L);                         // 判断线性表是否为空
Status ClearList(SqList *L);                        // 将线性表清空
Status GetElem(SqList L, int loc, ElemType *e);     // 将线性表L中的第 loc 个位置的元素值返回给 e
Status LocateElem(SqList L, ElemType e);            // 在线性表 L 中查找与给定值 e 相等的元素, 如果查找成功, 返回该元素在表中序号表示成功, 否则返回0表示失败.
Status ListInsert(SqList *L, int loc, ElemType e);  // 在线性表 L 中的第 loc 个位置插入新元素 e .
Status ListDelete(SqList *L, int loc, ElemType *e); // 删除线性表 L 中第 loc 个位置的元素, 并用 e 返回其值.
Status ChangeEmpty(SqList *L, int loc, ElemType e); // 将线性表 L 第 loc 个位置的数据修改为 e .
int ListLength(SqList L);                           // 返回线性表 L 的元素个数
void DisplayList(SqList L);                         // 查看线性表所有数据.
Status UnionL(SqList *La, SqList Lb);               // La = La并Lb, 将Lb中不存在于La中的元素插入到La中

int main(int argc, char const *argv[])
{
      SqList L;
      ElemType e = 0;

      InitElem(&L);
      if (ListEmpty(L))
      {
            printf("ListEmpty True!\n");
      }

      printf("InitList ==> L.length = %d\n\n", L.length);

      while (e < MAXSIZE / 2)
      {
            printf("e=%d, %d\n", e, ListInsert(&L, L.length + 1, e));
            e++;
      }
      DisplayList(L);
      printf("\nL.length = %d\n\n", L.length);

      GetElem(L, 2, &e);
      printf("\nGetElem e = %d\n\n", e);

      ListDelete(&L, 3, &e);
      printf("\ndel e = %d, L.length = %d\n\n", e, L.length);
      DisplayList(L);

      ChangeEmpty(&L, 1, 100);
      GetElem(L, 1, &e);
      printf("\nChangeEmpty e = %d\n\n", e);
      DisplayList(L);

      ClearList(&L);
      printf("\nClearList ==> L.length = %d\n", L.length);
      DisplayList(L);
      return 0;
}

Status InitElem(SqList *L)
{
      L->length = 0;
      return SUCCESS;
}

Status ListEmpty(SqList L)
{
      if (L.length != 0)
      {
            return TRUE;
      }
      return FALSE;
}

Status ClearList(SqList *L)
{
      L->length = 0;
      if (ListEmpty(*L))
      {
            return SUCCESS;
      }
}

Status GetElem(SqList L, int loc, ElemType *e)
{
      if (L.length == 0 || loc < 1 || loc > L.length)
      {
            return ERROR;
      }
      *e = L.data[loc - 1];
      return SUCCESS;
}

Status LocateElem(SqList L, ElemType e)
{
      int i = 0;
      for (i = 0; i < L.length; i++)
      {
            if (e == L.data[i])
            {
                  return TRUE;
            }
      }
      return FALSE;
}

Status ListInsert(SqList *L, int loc, ElemType e)
{
      if (L->length == MAXSIZE) // 判断线性表是否已满
      {
            return OVERFLOW;
      }

      if (loc < 1 || loc > L->length + 1)
      {
            return ERROR;
      }

      if (loc <= L->length) // 若插入数据的位置不在表尾
      {                     // 为待插入的数据元素腾出位置
            int i = 0;
            for (i = L->length; i >= loc - 1; i--) // 将要插入位置后的数据元素向后移动一位
            {
                  L->data[i + 1] = L->data[i];
            }
      }

      L->data[loc - 1] = e;
      L->length++;
      return SUCCESS;
}

Status ListDelete(SqList *L, int loc, ElemType *e)
{
      if (L->length == 0 || loc < 1 || loc > L->length)
      {
            return ERROR;
      }

      *e = L->data[loc - 1];
      int i = 0;
      for (i = loc - 1; i < L->length; i++)
      {
            L->data[i] = L->data[i + 1];
      }
      L->length--;
      return SUCCESS;
}

Status ChangeEmpty(SqList *L, int loc, ElemType e)
{
      if (loc < 1 || loc > L->length)
      {
            return ERROR;
      }

      L->data[loc - 1] = e;
      return SUCCESS;
}

int ListLength(SqList L)
{
      return L.length;
}

void DisplayList(SqList L)
{
      int i = 0;
      for (i = 0; i < L.length; i++)
      {
            printf("L.data[%d] = %d\n", i, L.data[i]);
      }
}

Status UnionL(SqList *La, SqList Lb)
{
      ElemType e;
      int i = 0;
      for (i = 0; i < Lb.length; i++)
      {
            GetElem(Lb, i, &e);
            if (!LocateElem(*La, e))
            {
                  if (!ListInsert(La, La->length++, e))
                  {
                        break;
                  }
            }
      }
      if (i == Lb.length || Lb.length == 0)
      {
            return SUCCESS;
      }
      else
      {
            return OVERFLOW;
      }
}
