/*
** malloc.c for hue in /home/arnaud.alies/rendu/PSU_2016_malloc
**
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
**
** Started on  Tue Jan 24 13:27:39 2017 arnaud.alies
** Last update Tue Jan 31 10:55:44 2017 arnaud.alies
*/

#include <string.h>
#include <unistd.h>
#include "my_malloc.h"

t_chunk		*g_start = NULL;
t_chunk		*g_prev = NULL;
pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;

t_chunk		*init_node(void *pos, size_t size, int used)
{
  t_chunk	*alloc;

  alloc = pos;
  alloc->magic = MAGIC;
  alloc->size = size;
  alloc->used = used;
  alloc->next = NULL;
  return (alloc);
}

void		*malloc(size_t size)
{
  t_chunk	*alloc;

  if (size == 0)
    return (NULL);
  pthread_mutex_lock(&g_mutex);
  if ((alloc = alloc_reuse(size)) != NULL)
    {
      pthread_mutex_unlock(&g_mutex);
      return (((void*)alloc) + sizeof(t_chunk));
    }
  if ((alloc = sbrk(size + sizeof(t_chunk))) == (void*)-1)
    {
      pthread_mutex_unlock(&g_mutex);
      return (NULL);
    }
  if (g_start == NULL)
    g_start = alloc;
  alloc = init_node(alloc, size, 1);
  if (g_prev != NULL)
    g_prev->next = alloc;
  g_prev = alloc;
  pthread_mutex_unlock(&g_mutex);
  return (((void*)alloc) + sizeof(t_chunk));
}
