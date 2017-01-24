/*
** my_malloc.h for hue in /home/arnaud.alies/rendu/PSU_2016_malloc
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Tue Jan 24 13:19:13 2017 arnaud.alies
** Last update Tue Jan 24 14:47:25 2017 arnaud.alies
*/

#ifndef MY_MALLOC_H_
#define MY_MALLOC_H_

#include <stddef.h>
#include <stdint.h>

#define MAGIC (0x2142FF42)

typedef struct s_alloc
{
  uint32_t magic;
  size_t size;
} t_alloc;

void show_alloc_mem();

void *malloc(size_t size);
void *realloc(void *ptr, size_t size);
void free(void *ptr);

#endif
