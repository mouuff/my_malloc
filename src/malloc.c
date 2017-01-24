/*
** malloc.c for hue in /home/arnaud.alies/rendu/PSU_2016_malloc
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Tue Jan 24 13:27:39 2017 arnaud.alies
** Last update Tue Jan 24 14:57:27 2017 arnaud.alies
*/

#include <unistd.h>
#include "my_malloc.h"

void		*malloc(size_t size)
{
  t_alloc	*alloc;
  void		*res;

  res = sbrk(size + sizeof(t_alloc));
  alloc = res;
  alloc->magic = MAGIC;
  alloc->size = size;
  return (res + sizeof(t_alloc));
}
