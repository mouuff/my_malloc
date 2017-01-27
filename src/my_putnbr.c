/*
** my_put_nbr.c for hue in /home/arnaud.alies/rendu/PSU_2016_malloc
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Wed Jan 25 09:23:48 2017 arnaud.alies
** Last update Fri Jan 27 11:24:34 2017 arnaud.alies
*/

#include <unistd.h>
#include <string.h>
#include "my_malloc.h"

void		my_putnbr(unsigned long nb)
{
  size_t	x;
  char		c;

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

void		my_puthex(size_t nb)
{
  size_t	x;
  size_t	base;
  char		c;

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
