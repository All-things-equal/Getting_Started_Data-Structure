/* tree_parent.c - 树的双亲表示法 结点结构定义 */
// ! 伪代码

#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_SIZE 100

typedef int ElemType;

typedef struct PTNode
{
      ElemType data; // 结点数据
      int parent;    // 双亲结点位置
} PTNode;

typedef struct
{
      PTNode nodes[MAX_TREE_SIZE];
      int r; // 根结点位置
      int n; // 结点个数
} PTree;