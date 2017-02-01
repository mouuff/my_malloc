/*
** free.c for hue in /home/arnaud.alies/rendu/PSU_2016_malloc
**
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
**
** Started on  Tue Jan 24 16:09:56 2017 arnaud.alies
** Last update Wed Feb  1 17:13:34 2017 arnaud.alies
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
  if (alloc->magic != MAGIC)
    {
      my_putstr(ERR_MAGIC);
      return ;
    }
  alloc->used = 0;
  //free_regroup(alloc);
}
