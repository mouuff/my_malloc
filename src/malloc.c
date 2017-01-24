/*
** malloc.c for hue in /home/arnaud.alies/rendu/PSU_2016_malloc
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Tue Jan 24 13:27:39 2017 arnaud.alies
** Last update Tue Jan 24 15:15:16 2017 arnaud.alies
*/

#include <unistd.h>
#include "my_malloc.h"

static t_alloc *start = NULL;
static t_alloc *prev = NULL;

void		*malloc(size_t size)
{
  t_alloc	*alloc;

  alloc = sbrk(size + sizeof(t_alloc));
  if (start == NULL)
    start = alloc;
  alloc->magic = MAGIC;
  alloc->size = size;
  alloc->used = 1;

  if (prev != NULL)
    {
      prev->next = alloc;
    }
  prev = alloc;
  return (((void*)alloc) + sizeof(t_alloc));
}
