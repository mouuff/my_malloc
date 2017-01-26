/*
** show_alloc_mem.c for hue in /home/arnaud.alies/rendu/PSU_2016_malloc
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Wed Jan 25 09:54:54 2017 arnaud.alies
** Last update Thu Jan 26 14:08:58 2017 Arnaud Alies
*/

#include <unistd.h>
#include "my_malloc.h"

void            show_alloc_mem()
{
  t_chunk       *tmp;
  
  tmp = g_start;
  while (tmp != NULL)
    {
      my_putnbr(tmp->size);
      my_putchar('\n');
      tmp = tmp->next;
    }
  my_putchar('\n');
}
