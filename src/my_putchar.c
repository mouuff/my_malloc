/*
** my_putchar.c for hue in /home/arnaud.alies/rendu/PSU_2016_malloc
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Wed Jan 25 09:52:30 2017 arnaud.alies
** Last update Wed Jan 25 09:52:57 2017 arnaud.alies
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
