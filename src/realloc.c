/*
** realloc.c for hue in /home/arnaud.alies/rendu/PSU_2016_malloc
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Wed Jan 25 10:15:58 2017 arnaud.alies
** Last update Wed Jan 25 10:23:36 2017 arnaud.alies
*/

#include <string.h>
#include "my_malloc.h"

void		*realloc(void *ptr, size_t size)
{
  t_alloc	*alloc;
  void		*res;
  int		min_size;

  alloc = ptr - sizeof(t_alloc);
  if (alloc->magic != MAGIC)
    return (NULL);
  if ((res = malloc(size)) == NULL)
    return (NULL);
  if (alloc->size > size)
    min_size = size;
  else
    min_size = alloc->size;
  memcpy(res, ptr, min_size);
  return (res);
}
