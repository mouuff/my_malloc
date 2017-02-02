/*
** my_puthex.c for hue in /home/arnaud.alies/rendu/PSU_2016_malloc
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Fri Jan 27 11:25:30 2017 arnaud.alies
** Last update Fri Jan 27 11:26:49 2017 arnaud.alies
*/

#include <unistd.h>
#include <string.h>
#include "my_malloc.h"

void            my_puthex(size_t nb)
{
  size_t        x;
  size_t        base;
  int		c;

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
