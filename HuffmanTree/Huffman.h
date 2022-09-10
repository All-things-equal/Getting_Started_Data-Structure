// #pragma once
#ifndef _HUFFMAN_H
#define _HUFFMAN_H

typedef struct _htNode
{
      char symbol;
      struct _htNode *left;
      struct _htNode *right;
} htNode;

typedef struct _huffmanTree
{
      htNode *root;
} HuffmanTree;

typedef struct _hlNode
{
      char symbol;
      char *code;
      struct _hlNode *next;
} hlNode;

typedef struct _hlTable
{
      hlNode *first;
      hlNode *last;
} hlTable;

void TraverseTree(htNode *treeNode, hlTable **table, int index, char code[256]);
hlTable *BuildTable(HuffmanTree *huffmanTree);
HuffmanTree *BuildTree(char *inputString);
void EnCode(hlTable *table, char *stringToEncode);
void DeCode(HuffmanTree *tree, char *stringToDecode);

#endif