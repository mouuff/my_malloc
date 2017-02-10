/*
** test.c for test in /home/arnaud.alies/rendu/PSU_2016_malloc
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Tue Jan 24 16:54:55 2017 arnaud.alies
** Last update Fri Feb 10 12:20:19 2017 arnaud.alies
*/

#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "./include/my_malloc.h"

int	main()
{
  char *truc = malloc(1000);
  free(truc);
  char *hue = malloc(300);
  char *huea = malloc(200);
  int *array;

  array = calloc(sizeof(int), 30);
  memset(hue, 0, 300);
  show_alloc_mem();
  return (0);
}
