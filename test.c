/*
** test.c for test in /home/arnaud.alies/rendu/PSU_2016_malloc
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Tue Jan 24 16:54:55 2017 arnaud.alies
** Last update Thu Jan 26 16:55:37 2017 arnaud.alies
*/

#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "./include/my_malloc.h"


int	main()
{
  char *truc = malloc(30);
  show_alloc_mem();
  return (0);
}
