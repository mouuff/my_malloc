/*
** malloc.c for hue in /home/arnaud.alies/rendu/PSU_2016_malloc
**
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
**
** Started on  Tue Jan 24 13:27:39 2017 arnaud.alies
** Last update Mon Feb  6 23:11:51 2017 Fredoddou
*/

#include <string.h>
#include <unistd.h>
#include "my_malloc.h"

t_chunk		*g_start = NULL;
t_chunk		*g_prev = NULL;
pthread_mutex_t	g_mutex0 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t	g_mutex1 = PTHREAD_MUTEX_INITIALIZER;

void		*malloc(size_t size)
{
  t_chunk	*ptr;

  pthread_mutex_lock(&g_mutex0);
  if ((ptr = chunk_reuse(size)) != NULL)
    {
      pthread_mutex_unlock(&g_mutex0);
      return (((void *)((void *)ptr + sizeof(t_chunk))));
    }
  if ((ptr = sbrk(size + sizeof(t_chunk))) == (void*)-1)
    {
      pthread_mutex_unlock(&g_mutex0);
      return (NULL);
    }
  ptr->size = size;
  ptr->next = NULL;
  ptr->used = 1;
  ptr->magic = MAGIC;
  if (g_start == NULL)
    g_start = ptr;
  if (g_prev != NULL)
    g_prev->next = ptr;
  g_prev = ptr;
  pthread_mutex_unlock(&g_mutex0);
  return (((void *)((void *)ptr + sizeof(t_chunk))));
}
