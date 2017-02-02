/*
** show_alloc_mem.c for hue in /home/arnaud.alies/rendu/PSU_2016_malloc
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Wed Jan 25 09:54:54 2017 arnaud.alies
** Last update Thu Feb  2 16:52:50 2017 arnaud.alies
*/

#include <string.h>
#include <unistd.h>
#include "my_malloc.h"

static void	my_putnbr(unsigned long nb)
{
  size_t        x;
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

static void	my_puthex(size_t nb)
{
  size_t        x;
  size_t        base;
  int           c;

  my_putstr("0x");
  base = strlen(HEX_TABLE);
  x = 1;
  while ((nb / (x * base)) > 0)
    x *= base;
  while (x > 0)
    {
      c = (nb / x) % base;
      write(1, HEX_TABLE + c, 1);
      x /= base;
    }
}

void            show_alloc_mem()
{
  t_chunk       *tmp;

  my_putstr("break : ");
  my_puthex((size_t)sbrk(0));
  my_putstr("\n");
  tmp = g_start;
  while (tmp != NULL)
    {
      my_puthex((size_t)(((void*)tmp) + sizeof(t_chunk)));
      my_putstr(" - ");
      my_puthex((size_t)(((void*)tmp) + sizeof(t_chunk) + tmp->size));
      my_putstr(" : ");
      my_putnbr(tmp->size);
      my_putstr(" bytes\n");
      tmp = tmp->next;
    }
  my_putstr("\n");
}
