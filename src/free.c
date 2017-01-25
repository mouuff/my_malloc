/*
** free.c for hue in /home/arnaud.alies/rendu/PSU_2016_malloc
**
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
**
** Started on  Tue Jan 24 16:09:56 2017 arnaud.alies
** Last update Wed Jan 25 17:36:00 2017 Fredoddou
*/

#include "my_malloc.h"

static void	free_regroup(t_alloc *alloc)
{
  if (alloc->next != NULL && alloc->next->used == 0)
    {
      if (g_prev == alloc->next)
	g_prev = alloc;
      alloc->size += alloc->next->size + sizeof(t_alloc);
      alloc->next = alloc->next->next;
    }
}

void		free(void *ptr)
{
  t_alloc	*alloc;

  if (ptr == NULL)
    return ;
  alloc = ptr - sizeof(t_alloc);
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
