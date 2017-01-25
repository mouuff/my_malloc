/*
** calloc.c for hue in /home/arnaud.alies/rendu/PSU_2016_malloc
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Wed Jan 25 10:28:25 2017 arnaud.alies
** Last update Wed Jan 25 10:36:26 2017 arnaud.alies
*/

#include <string.h>
#include "my_malloc.h"

void            *calloc(size_t nmemb, size_t size)
{
  void          *new;

  if (size * nmemb == 0)
    return (brk(0));
  if ((new = malloc(size * nmemb)) != NULL)
    memset(new, 0, size * nmemb);
  return (new);
}
