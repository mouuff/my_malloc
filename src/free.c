/*
** free.c for hue in /home/arnaud.alies/rendu/PSU_2016_malloc
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Tue Jan 24 16:09:56 2017 arnaud.alies
** Last update Tue Jan 24 16:26:27 2017 arnaud.alies
*/

#include "my_malloc.h"

void free(void *ptr)
{
  t_alloc *alloc;

  if (ptr == NULL)
    return ;
  alloc = ptr - sizeof(t_alloc);
  if (alloc->magic != MAGIC)
    return ;
  alloc->used = 0;
}
