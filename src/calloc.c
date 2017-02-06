/*
** calloc.c for hue in /home/arnaud.alies/rendu/PSU_2016_malloc
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Wed Jan 25 10:28:25 2017 arnaud.alies
** Last update Mon Feb  6 22:49:54 2017 Fredoddou
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
