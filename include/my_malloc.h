/*
** my_malloc.h for hue in /home/arnaud.alies/rendu/PSU_2016_malloc
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Tue Jan 24 13:19:13 2017 arnaud.alies
** Last update Wed Jan 25 10:03:07 2017 arnaud.alies
*/

#ifndef MY_MALLOC_H_
#define MY_MALLOC_H_

#include <stddef.h>
#include <stdint.h>

#define MAGIC (0x2142FF42)
#define MIN_CHUNK (128)
#define ALLOC_PTR(alloc) ((void*)(((void*)alloc) + sizeof(t_alloc)))

typedef struct s_alloc
{
  uint32_t magic;
  size_t size;
  int used;
  struct s_alloc *next;
} t_alloc;

void my_putchar(char c);
void my_put_nbr(unsigned long nb);
void *reuse(size_t size);

void show_alloc_mem();

void *malloc(size_t size);
void *realloc(void *ptr, size_t size);
void free(void *ptr);

extern t_alloc *g_start;

#endif
