/*
** calloc.c for hue in /home/arnaud.alies/rendu/PSU_2016_malloc
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Wed Jan 25 10:28:25 2017 arnaud.alies
** Last update Wed Feb  1 17:48:50 2017 arnaud.alies
*/

#include <string.h>
#include "my_malloc.h"

void            *calloc(size_t nmemb, size_t size)
{
  void          *new;

  size *= nmemb;
  if ((new = malloc(size)) != NULL)
    memset(new, '\0', size);
  return (new);
}
