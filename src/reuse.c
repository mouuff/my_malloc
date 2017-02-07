/*
** reuse.c for hhue in /home/arnaud.alies/rendu/PSU_2016_malloc
**
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
**
** Started on  Wed Jan 25 09:59:26 2017 arnaud.alies
** Last update Tue Feb  7 16:38:53 2017 arnaud.alies
*/

#include <unistd.h>
#include "my_malloc.h"

static int		shrink_alloc(t_chunk *alloc, size_t size)
{
  t_chunk		*new;

  if (alloc->magic != MAGIC)
    {
      my_putstr(ERR_MAGIC);
      return (1);
    }
  if (alloc == NULL || alloc->used == 1)
    return (1);
  if (size + sizeof(t_chunk) < alloc->size)
    {
      new = (t_chunk*)(((char*)alloc) + sizeof(t_chunk) + size);
      new->magic = MAGIC;
      new->used = 0;
      new->size = alloc->size - sizeof(t_chunk) - size;
      new->next = alloc->next;
      alloc->next = new;
      if (g_prev == alloc)
	g_prev = new;
    }
  alloc->size = size;
  alloc->used = 1;
  return (0);
}

t_chunk			*chunk_reuse(size_t size)
{
  register t_chunk	*tmp;

  tmp = g_start;
  while (tmp != NULL)
    {
      if (tmp->size >= size)
	{
	  if (shrink_alloc(tmp, size) == 0)
	    return (tmp);
        }
      tmp = tmp->next;
    }
  return (NULL);
}
