/*
** free.c for hue in /home/arnaud.alies/rendu/PSU_2016_malloc
**
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
**
** Started on  Tue Jan 24 16:09:56 2017 arnaud.alies
** Last update Thu Jan 26 14:08:01 2017 Arnaud Alies
*/

#include "my_malloc.h"

static void	free_regroup(t_chunk *alloc)
{
  if (alloc->next != NULL && alloc->next->used == 0)
    {
      if (g_prev == alloc->next)
	g_prev = alloc;
      alloc->size += alloc->next->size + sizeof(t_chunk);
      alloc->next = alloc->next->next;
    }
}

void		free(void *ptr)
{
  t_chunk	*alloc;

  if (ptr == NULL)
    return ;
  alloc = ptr - sizeof(t_chunk);
  pthread_mutex_lock(&g_mutex);
  if (alloc->magic != MAGIC)
    {
      pthread_mutex_unlock(&g_mutex);
      return ;
    }
  alloc->used = 0;
  free_regroup(alloc);
  pthread_mutex_unlock(&g_mutex);
}
