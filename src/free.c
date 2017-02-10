/*
** free.c for hue in /home/arnaud.alies/rendu/PSU_2016_malloc
**
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
**
** Started on  Tue Jan 24 16:09:56 2017 arnaud.alies
** Last update Fri Feb 10 15:11:47 2017 arnaud.alies
*/

#include "my_malloc.h"

static void	regroup_alloc(t_chunk *alloc)
{
  if (alloc->next != NULL && alloc->next->used == 0)
    {
      if (g_prev == alloc->next)
	g_prev = alloc;
      alloc->size += alloc->next->size + sizeof(t_chunk);
      alloc->next = alloc->next->next;
    }
}

static void		regroup()
{
  register t_chunk	*tmp;

  tmp = g_start;
  while (tmp != NULL)
    {
      regroup_alloc(tmp);
      tmp = tmp->next;
    }
}

void		free(void *ptr)
{
  t_chunk	*alloc;

  if (ptr == NULL)
    return ;
  pthread_mutex_lock(&g_mutex);
  alloc = ((t_chunk*)ptr) - 1;
  if (alloc->magic != MAGIC)
    {
      pthread_mutex_unlock(&g_mutex);
      return ;
    }
  alloc->used = 0;
  regroup();
  pthread_mutex_unlock(&g_mutex);
}
