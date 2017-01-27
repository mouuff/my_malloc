/*
** show_alloc_mem.c for hue in /home/arnaud.alies/rendu/PSU_2016_malloc
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Wed Jan 25 09:54:54 2017 arnaud.alies
** Last update Fri Jan 27 11:42:28 2017 arnaud.alies
*/

#include <unistd.h>
#include "my_malloc.h"

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
  my_putchar('\n');
}
