/*
** malloc.c for hue in /home/arnaud.alies/rendu/PSU_2016_malloc
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Tue Jan 24 13:27:39 2017 arnaud.alies
** Last update Wed Jan 25 09:39:01 2017 arnaud.alies
*/

#include <string.h>
#include <unistd.h>
#include "my_malloc.h"

static t_alloc *start = NULL;
static t_alloc *prev = NULL;

int		reuse(t_alloc *alloc, size_t size)
{
  t_alloc	*new;

  if (alloc->magic != MAGIC || alloc->used == 1)
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

void		*find_free(size_t size)
{
  t_alloc	*tmp;

  tmp = start;
  while (tmp != NULL)
    {
      if (tmp->used == 0 && tmp->size >= size)
	{
	  //reuse() here
	  tmp->used = 1;
	  return (tmp);
	}
      tmp = tmp->next;
    }
  return (NULL);
}

void		*malloc(size_t size)
{
  t_alloc	*alloc;

  alloc = sbrk(size + sizeof(t_alloc));
  //TODO : if alloc -1
  if (start == NULL)
    start = alloc;
  alloc->magic = MAGIC;
  alloc->size = size;
  alloc->used = 1;
  alloc->next = NULL;
  if (prev != NULL)
    {
      prev->next = alloc;
    }
  prev = alloc;
  return (ALLOC_PTR(alloc));
}

void *realloc(void *ptr, size_t size)
{
  
}
