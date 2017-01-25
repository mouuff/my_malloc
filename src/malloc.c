/*
** malloc.c for hue in /home/arnaud.alies/rendu/PSU_2016_malloc
**
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
**
** Started on  Tue Jan 24 13:27:39 2017 arnaud.alies
** Last update Wed Jan 25 17:35:03 2017 Fredoddou
*/

#include <string.h>
#include <unistd.h>
#include "my_malloc.h"

t_alloc		*g_start = NULL;
t_alloc		*g_prev = NULL;
pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;

void		*malloc(size_t size)
{
  t_alloc	*alloc;

  pthread_mutex_lock(&g_mutex);
  if ((alloc = reuse(size)) != NULL)
    {
      pthread_mutex_unlock(&g_mutex);
      return (((void*)alloc) + sizeof(t_alloc));
    }
  if ((alloc = sbrk(size + sizeof(t_alloc))) == (void*)-1)
    {
      pthread_mutex_unlock(&g_mutex);
      return (NULL);
    }
  if (g_start == NULL)
    g_start = alloc;
  alloc->magic = MAGIC;
  alloc->size = size;
  alloc->used = 1;
  alloc->next = NULL;
  if (g_prev != NULL)
    g_prev->next = alloc;
  g_prev = alloc;
  pthread_mutex_unlock(&g_mutex);
  return (((void*)alloc) + sizeof(t_alloc));
}
