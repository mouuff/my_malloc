/*
** malloc.c for hue in /home/arnaud.alies/rendu/PSU_2016_malloc
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Tue Jan 24 13:27:39 2017 arnaud.alies
** Last update Wed Jan 25 13:04:05 2017 arnaud.alies
*/

#include <string.h>
#include <unistd.h>
#include "my_malloc.h"

t_alloc *g_start = NULL;
static t_alloc *prev = NULL;

void		*malloc(size_t size)
{
  t_alloc	*alloc;

  if ((alloc = reuse(size)) != NULL)
    return (((void*)alloc) + sizeof(t_alloc));
  if ((alloc = sbrk(size + sizeof(t_alloc))) == (void*)-1)
    return (NULL);
  if (g_start == NULL)
    g_start = alloc;
  alloc->magic = MAGIC;
  alloc->size = size;
  alloc->used = 1;
  alloc->next = NULL;
  if (prev != NULL)
    {
      prev->next = alloc;
    }
  prev = alloc;
  return (((void*)alloc) + sizeof(t_alloc));
}
