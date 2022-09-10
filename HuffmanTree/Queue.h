// #pragma once
#ifndef _PQUEUE_H
#define _PQUEUE_H

#include "Huffman.h"

#define TYPE htNode *

#define MAX_SZ 256

typedef struct _pQueueNode
{
      TYPE value;
      unsigned int priority;
      struct _pQueueNode *next;
} pQueueNode;

typedef struct _pQueue
{
      unsigned int size;
      pQueueNode *first;
} pQueue;

void InitPQueue(pQueue **queue);
void AddPQueue(pQueue **queue, TYPE value, unsigned int priority);
TYPE GetPQueue(pQueue **queue);

#endif