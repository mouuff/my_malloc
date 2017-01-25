/*
** free.c for hue in /home/arnaud.alies/rendu/PSU_2016_malloc
**
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
**
** Started on  Tue Jan 24 16:09:56 2017 arnaud.alies
** Last update Wed Jan 25 01:57:08 2017 Fredoddou
*/

#include "my_malloc.h"

void		free(void *ptr)
{
  t_alloc	*alloc;

  if (ptr == NULL)
    return ;
  alloc = ptr - sizeof(t_alloc);
  if (alloc->magic != MAGIC_MALLOC)
    return ;
  alloc->used = false;
}
