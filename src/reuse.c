/*
** reuse.c for hhue in /home/arnaud.alies/rendu/PSU_2016_malloc
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Wed Jan 25 09:59:26 2017 arnaud.alies
** Last update Wed Jan 25 12:55:54 2017 arnaud.alies
*/

#include <unistd.h>
#include "my_malloc.h"

static int	shrink_alloc(t_alloc *alloc, size_t size)
{
  t_alloc       *new;

  if (alloc == NULL || alloc->magic != MAGIC || alloc->used == 1)
    return (1);
  if (size + sizeof(t_alloc) < alloc->size)
    {
      new = ((void*)alloc) + sizeof(t_alloc) + size;
      new->magic = MAGIC;
      new->used = 0;
      new->size = alloc->size - sizeof(t_alloc) - size;
      new->next = alloc->next;
      alloc->next = new;
      alloc->size = size;
    }
  alloc->used = 1;
  return (0);
}

t_alloc		*reuse(size_t size)
{
  t_alloc       *tmp;

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
