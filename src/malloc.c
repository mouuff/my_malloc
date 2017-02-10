/*
** malloc.c for hue in /home/arnaud.alies/rendu/PSU_2016_malloc
**
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
**
** Started on  Tue Jan 24 13:27:39 2017 arnaud.alies
** Last update Fri Feb 10 14:31:56 2017 arnaud.alies
*/

#include <string.h>
#include <unistd.h>
#include "my_malloc.h"

t_chunk		*g_start = NULL;
t_chunk		*g_prev = NULL;
pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;

static void	*malloc_chunk(size_t size)
{
  t_chunk	*ptr;

  if (((intptr_t)size) < 0)
    return (NULL);
  if ((ptr = chunk_reuse(size)) != NULL)
    {
      return (ptr + 1);
    }
  if ((ptr = sbrk(size + sizeof(t_chunk))) == (void*)-1)
    {
      return (NULL);
    }
  ptr->size = size;
  ptr->next = NULL;
  ptr->used = 1;
  ptr->magic = MAGIC;
  if (g_start == NULL)
    g_start = ptr;
  if (g_prev != NULL)
    g_prev->next = ptr;
  g_prev = ptr;
  return (ptr + 1);
}

void	*malloc(size_t size)
{
  void	*res;

  pthread_mutex_lock(&g_mutex);
  res = malloc_chunk(size);
  pthread_mutex_unlock(&g_mutex);
  return (res);
}
