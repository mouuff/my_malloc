/*
** realloc.c for hue in /home/arnaud.alies/rendu/PSU_2016_malloc
**
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
**
** Started on  Wed Jan 25 10:15:58 2017 arnaud.alies
** Last update Tue Feb  7 16:49:44 2017 arnaud.alies
*/

#include <string.h>
#include "my_malloc.h"

void		*realloc(void *ptr, size_t size)
{
  t_chunk	*alloc;
  void		*new;

  if ((new = malloc(size)) == NULL)
    {
      return (NULL);
    }
  if (ptr == NULL)
    {
      return (new);
    }
  alloc = ((t_chunk*)ptr) - 1;
  if (alloc->magic != MAGIC)
    {
      my_putstr(ERR_MAGIC);
      return (NULL);
    }
  memcpy(new, ptr, (alloc->size < size ? alloc->size : size));
  free(ptr);
  return (new);
}
