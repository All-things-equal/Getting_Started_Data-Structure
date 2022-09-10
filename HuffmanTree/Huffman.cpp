#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "Huffman.h"
#include "Queue.h"

void TraverseTree(htNode *treeNode, hlTable **table, int index, char code[256])
{
      if (treeNode->left == NULL && treeNode->right == NULL)
      {
            code[index] = '\0';
            hlNode *aux = (hlNode *)malloc(sizeof(hlNode));
            aux->code = (char *)malloc(sizeof(char) * (strlen(code) + 1));
            strcpy(aux->code, code);
            aux->symbol = treeNode->symbol;
            aux->next = NULL;

            if ((*table)->first == NULL)
            {
                  (*table)->first = aux;
                  (*table)->last = aux;
            }
            else
            {
                  (*table)->last->next = aux;
                  (*table)->last = aux;
            }
      }

      if (treeNode->left != NULL)
      {
            code[index] = '0';
            TraverseTree(treeNode->left, table, index + 1, code);
      }

      if (treeNode->right != NULL)
      {
            code[index] = '1';
            TraverseTree(treeNode->right, table, index + 1, code);
      }
}

hlTable *BuildTable(HuffmanTree *huffmanTree)
{
      hlTable *table = (hlTable *)malloc(sizeof(hlTable));
      table->first = NULL;
      table->last = NULL;

      char code[256];

      TraverseTree(huffmanTree->root, &table, 0, code);
      return table;
}

HuffmanTree *BuildTree(char *inputString)
{
      int *probability = (int *)malloc(sizeof(int) * 256); // 用于记录每个字符出现的次数

      // 初始化为0
      for (int i = 0; i < 256; i++)
      {
            probability[i] = 0;
      }

      // 统计待编码的字符串中各个字符出现的次数
      for (int i = 0; inputString[i] != '\0'; i++)
      {
            probability[(unsigned char)inputString[i]]++;
      }

      pQueue *huffmanQueue; // pQueue队列的头指针
      InitPQueue(&huffmanQueue);

      // 填充队列
      for (int i = 0; i < 256; i++)
      {
            if (probability[i] != 0)
            {
                  htNode *aux = (htNode *)malloc(sizeof(htNode));
                  aux->left = NULL;
                  aux->right = NULL;
                  aux->symbol = (char)i;

                  AddPQueue(&huffmanQueue, aux, probability[i]);
            }
      }

      free(probability);

      // 生成Huffman树
      while (huffmanQueue->size != 1)
      {
            int priority = huffmanQueue->first->priority;
            priority += huffmanQueue->first->next->priority;

            htNode *left = GetPQueue(&huffmanQueue);
            htNode *right = GetPQueue(&huffmanQueue);

            htNode *newNode = (htNode *)malloc(sizeof(htNode));
            newNode->left = left;
            newNode->right = right;

            AddPQueue(&huffmanQueue, newNode, priority);
      }

      HuffmanTree *tree = (HuffmanTree *)malloc(sizeof(HuffmanTree));

      tree->root = GetPQueue(&huffmanQueue);

      return tree;
}

void EnCode(hlTable *table, char *stringToEncode)
{
      hlNode *traversal;

      printf("Encoding...\n\nInput string: \n%s\n\nEncoded string: \n", stringToEncode);

      for (int i = 0; stringToEncode[i] != '\0'; i++)
      {
            traversal = table->first;

            while (traversal->symbol != stringToEncode[i])
            {
                  traversal = traversal->next;
            }

            printf("%s", traversal->code);
      }

      printf("\n");
}

void DeCode(HuffmanTree *tree, char *stringToDecode)
{
      htNode *traversal = tree->root;

      printf("Decoding...\n\nEncoded string: \n%s\n\nDecoded string: \n", stringToDecode);

      for (int i = 0; stringToDecode[i] != '\0'; i++)
      {
            if (traversal->left == NULL && traversal->right == NULL)
            {
                  printf("%c", traversal->symbol);
                  traversal = tree->root;
            }

            if (stringToDecode[i] == '0')
            {
                  traversal = traversal->left;
            }
            else
            {
                  traversal = traversal->right;
            }

            if (stringToDecode[i] != '0' && stringToDecode[i] != '1')
            {
                  printf("\nError: The input string is not coded correctly!\n");
                  return;
            }
      }

      printf("\n");
}