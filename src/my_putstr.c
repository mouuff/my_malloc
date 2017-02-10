/*
** my_putstr.c for hue in /home/arnaud.alies/rendu/PSU_2016_malloc
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Fri Jan 27 11:20:52 2017 arnaud.alies
** Last update Fri Feb 10 15:10:32 2017 arnaud.alies
*/

#include <unistd.h>
#include "my_malloc.h"

void		my_putstr(char const *str)
{
  size_t	x;

  x = 0;
  while (str[x] != '\0')
    {
      write(1, &(str[x]), 1);
      x += 1;
    }
}
