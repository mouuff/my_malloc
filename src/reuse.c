/*
** reuse.c for hhue in /home/arnaud.alies/rendu/PSU_2016_malloc
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Wed Jan 25 09:59:26 2017 arnaud.alies
** Last update Wed Jan 25 10:32:42 2017 arnaud.alies
*/

#include <unistd.h>
#include "my_malloc.h"

static int	reuse_alloc(t_alloc *alloc, size_t size)
{
  t_alloc       *new;

  if (alloc == NULL || alloc->magic != MAGIC || alloc->used == 1)
    return (1);
  if (size + MIN_CHUNK + sizeof(t_alloc) < alloc->size)
    {
      new = ALLOC_PTR(alloc) + size;
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

void            *reuse(size_t size)
{
  t_alloc       *tmp;

  tmp = g_start;
  while (tmp != NULL)
    {
      if (tmp->used == 0 && tmp->size >= size)
	{
	  reuse_alloc(tmp, size);
          tmp->used = 1;
          return (tmp);
        }
      tmp = tmp->next;
    }
  return (NULL);
}
