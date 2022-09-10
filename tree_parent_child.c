/* tree_parent_child.c - 树的双亲孩子表示法 */
// ! 伪代码

#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_SIZE 100

typedef char ElemType;

// 孩子结点
typedef struct CTNode
{
      int child;           // 孩子结点的下标(位置）
      struct CTNode *next; // 指向下一个孩子结点的指针
} * ChildPtr;

// 表头结构
typedef struct
{
      ElemType data;       // 结点数据
      int parent;          // 父结点的下标(位置）
      ChildPtr firstchild; // 指向第一个孩子结点的指针
} CTBox;

// 树结构
typedef struct
{
      CTBox nodes[MAX_TREE_SIZE];
      int r; // 根结点位置
      int n; // 结点个数
} CTree;