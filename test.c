/*
** test.c for test in /home/arnaud.alies/rendu/PSU_2016_malloc
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Tue Jan 24 16:54:55 2017 arnaud.alies
** Last update Wed Jan 25 11:27:36 2017 arnaud.alies
*/

#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "./include/my_malloc.h"

static t_alloc *start = NULL;

void            my_put_nbr(unsigned long nb)
{
  unsigned long x;
  char          c;

  x = 1;
  while ((nb / (x * 10)) > 0)
    x *= 10;
  while (x > 0)
    {
      c = (nb / x) % 10 + '0';
      write(1, &c, 1);
      x /= 10;
    }
}

void            show_alloc_mem()
{
  t_alloc       *tmp;
  char		c = '\n';

  tmp = start;
  while (tmp != NULL)
    {
      my_put_nbr(tmp->size);
      
      write(1, &c, 1);
      tmp = tmp->next;
    }
  write(1, &c, 1);
}

int	main()
{
  char *truc = malloc(30 + sizeof(t_alloc) + 1);
  memset(truc, 'a', 30 + sizeof(t_alloc) + 1);
  start = (void*)truc - sizeof(t_alloc);
  char *hue = malloc(100);

  
  show_alloc_mem();
  free(truc);
  show_alloc_mem();
  truc = malloc(30);
  show_alloc_mem();

  char *c = malloc(1);
  /*
  *c = 'a';
  t_alloc *test = c - sizeof(t_alloc);
  assert(test->magic == MAGIC);
  */
  show_alloc_mem();
  write(1, c, 1);
  return (0);
}
