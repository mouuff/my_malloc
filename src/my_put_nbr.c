/*
** my_put_nbr.c for hue in /home/arnaud.alies/rendu/PSU_2016_malloc
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Wed Jan 25 09:23:48 2017 arnaud.alies
** Last update Wed Jan 25 09:25:02 2017 arnaud.alies
*/

#include <unistd.h>

void		my_put_nbr(unsigned long nb)
{
  unsigned long	x;
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
