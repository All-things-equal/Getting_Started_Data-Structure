#include <cstdio>
#include <cstdlib>
#include "Queue.h"

void InitPQueue(pQueue **queue)
{
      *queue = (pQueue *)malloc(sizeof(pQueue));
      (*queue)->size = 0;
      (*queue)->first = NULL;
}

void AddPQueue(pQueue **queue, TYPE value, unsigned int priority)
{
      if (MAX_SZ == (*queue)->size)
      {
            printf("Queue is full!\n");
            return;
      }

      pQueueNode *aux = (pQueueNode *)malloc(sizeof(pQueueNode));
      aux->priority = priority;
      aux->value = value;

      if ((*queue)->size == 0 || (*queue)->first == NULL)
      {
            aux->next = NULL;
            (*queue)->first = aux;
            (*queue)->size = 1;

            return;
      }
      else
      {
            if (priority <= (*queue)->first->priority)
            {
                  aux->next = (*queue)->first;
                  (*queue)->first = aux;
                  (*queue)->size++;

                  return;
            }
            else
            {
                  pQueueNode *iterator = (*queue)->first;
                  while (iterator->next != NULL)
                  {
                        if (priority <= iterator->next->priority)
                        {
                              aux->next = iterator->next;
                              iterator->next = aux;
                              (*queue)->size++;

                              return;
                        }

                        iterator = iterator->next;
                  }

                  if (iterator->next == NULL)
                  {
                        aux->next = NULL;
                        iterator->next = aux;
                        (*queue)->size++;

                        return;
                  }
            }
      }
}

TYPE GetPQueue(pQueue **queue)
{
      TYPE returnValue;

      if ((*queue)->size > 0)
      {
            returnValue = (*queue)->first->value;
            (*queue)->first = (*queue)->first->next;
            (*queue)->size--;
      }
      else
      {
            printf("Queue is empty!\n");
            return NULL;
      }

      return returnValue;
}