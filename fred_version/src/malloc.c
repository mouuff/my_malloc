/*
** malloc.c for hue in /home/arnaud.alies/rendu/PSU_2016_malloc
**
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
**
** Started on  Tue Jan 24 13:27:39 2017 arnaud.alies
** Last update Wed Jan 25 13:00:22 2017 Frederic ODDOU
*/

#include <unistd.h>
#include <string.h>
#include "my_malloc.h"

static t_alloc *start = NULL;
static t_alloc *prev = NULL;

static int	reuse(t_alloc *alloc, size_t size)
{
  t_alloc	*new;

  new = ALLOC_PTR(alloc) + size;
  new->magic = MAGIC_MALLOC;
  new->used = false;
  new->size = alloc->size - sizeof(t_alloc) - size;
  new->next = alloc->next;
  alloc->next = new;
  alloc->size = size;
  alloc->used = true;
  if (prev == alloc)
    prev = new;
  return (0);
}

void		*malloc(size_t size)
{
  t_alloc	*alloc;

  alloc = sbrk(size + sizeof(t_alloc));
  //TODO: -1
  if (start == NULL)
    start = alloc;
  alloc->magic = MAGIC_MALLOC;
  alloc->size = size;
  alloc->used = true;
  alloc->next = NULL;
  if (prev != NULL)
    prev->next = alloc;
  prev = alloc;
  return (ALLOC_PTR(alloc));
}

static void	*find_memory(t_alloc *ptr, size_t size)
{
  t_alloc	*tmp;
  void		*new;

  tmp = start;
  if (MARGE_SIZE(size) > ptr->size)
    {
      while (tmp != NULL && !(tmp->used == false && tmp->size >= MARGE_SIZE(size)))
	tmp = tmp->next;
      if (tmp == NULL)
	{
	  ptr->used = false;
	  if ((new = malloc(size)) != NULL)
	    memcpy(new, ALLOC_PTR(ptr), ptr->size);
	  return (new);
	}
    }
  else
    tmp = ptr;
  new = ALLOC_PTR(tmp);
  memcpy(new, ALLOC_PTR(ptr), ptr->size);
  if (ptr != tmp)
    free(ptr);
  reuse(tmp, size);
  return (new);
}

void		*realloc(void *ptr, size_t size)
{
  t_alloc	*alloc;
  void *new;

  if (ptr == NULL)
    return (malloc(size));
  alloc = ptr - sizeof(t_alloc);
  if (alloc->magic == MAGIC_MALLOC)
    {
      new = find_memory(alloc, size);
      show_alloc_mem();
      return (new);
    }
  return (NULL);
}

void		*calloc(size_t nmemb, size_t size)
{
  void		*new;

  if (size * nmemb == 0)
    return (NULL);
  if ((new = malloc(size * nmemb)) != NULL)
    memset(new, 0, size * nmemb);
  return (new);
}

void		free(void *ptr)
{
  t_alloc	*alloc;
  t_alloc *tmp = start;

  if (ptr == NULL)
    return ;
  alloc = ptr - sizeof(t_alloc);
  if (alloc->magic != MAGIC_MALLOC)
    return ;
  alloc->used = false;
  if (alloc->next != NULL && alloc->next->used == false)
    {
      if (prev == alloc->next)
	prev = alloc;
      alloc->size += alloc->next->size + sizeof(t_alloc);
    }
  while (tmp != NULL && tmp->next != alloc)
    tmp = tmp->next;
  if (tmp != NULL && tmp->used == false)
    {
      tmp->size = tmp->next->size + sizeof(t_alloc);
      if (prev == tmp->next)
	prev = tmp;
      tmp->next = tmp->next->next;
    }
}

#include <stdio.h>
void		show_alloc_mem()
{
  t_alloc	*tmp;

  tmp = start;
  while (tmp != NULL)
    {
      printf("%p - %p :  %li bytes %d\n", tmp, tmp + tmp->size, tmp->size, (tmp->used) ? 1 : 0);
      tmp = tmp->next;
    }
  printf("\n\n");
}
