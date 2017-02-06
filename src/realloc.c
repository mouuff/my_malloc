/*
** realloc.c for hue in /home/arnaud.alies/rendu/PSU_2016_malloc
**
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
**
** Started on  Wed Jan 25 10:15:58 2017 arnaud.alies
** Last update Mon Feb  6 22:47:49 2017 Frederic ODDOU
*/

#include <string.h>
#include "my_malloc.h"

void		*realloc(void *ptr, size_t size)
{
  t_chunk	*alloc;
  void		*new;

  pthread_mutex_lock(&g_mutex1);
  if ((new = malloc(size)) == NULL)
    {
      pthread_mutex_unlock(&g_mutex1);
      return (NULL);
    }
  if (ptr == NULL)
    {
      pthread_mutex_unlock(&g_mutex1);
      return (new);
    }
  alloc = (((t_chunk *)((void *)ptr - sizeof(t_chunk))));
  if (alloc->magic != MAGIC)
    {
      pthread_mutex_unlock(&g_mutex1);
      my_putstr(ERR_MAGIC);
      return (NULL);
    }
  memcpy(new, ptr, (alloc->size < size ? alloc->size : size));
  free(ptr);
  pthread_mutex_unlock(&g_mutex1);
  return (new);
}
