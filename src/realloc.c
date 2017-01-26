/*
** realloc.c for hue in /home/arnaud.alies/rendu/PSU_2016_malloc
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Wed Jan 25 10:15:58 2017 arnaud.alies
** Last update Thu Jan 26 14:08:38 2017 Arnaud Alies
*/

#include <string.h>
#include "my_malloc.h"

void		*realloc(void *ptr, size_t size)
{
  t_chunk	*alloc;
  void		*res;

  if (ptr == NULL)
    return (malloc(size));
  alloc = ptr - sizeof(t_chunk);
  if (alloc->magic != MAGIC)
    return (NULL);
  if ((res = malloc(size)) == NULL)
    return (NULL);
  memcpy(res, ptr, (alloc->size < size ? alloc->size : size));
  free(ptr);
  return (res);
}
