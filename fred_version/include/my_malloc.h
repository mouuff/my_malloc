/*
** my_malloc.h for hue in /home/arnaud.alies/rendu/PSU_2016_malloc
**
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
**
** Started on  Tue Jan 24 13:19:13 2017 arnaud.alies
** Last update Wed Jan 25 01:57:48 2017 Fredoddou
*/

#ifndef MY_MALLOC_H_
# define MY_MALLOC_H_

# include <stddef.h>
# include <stdint.h>
# include <stdbool.h>

# define MAGIC_MALLOC (0x2142FF42)
# define MIN_CHUNK (10)
# define ALLOC_PTR(alloc) ((void*)(((void*)alloc) + sizeof(t_alloc)))
# define MARGE_SIZE(size) (size + MIN_CHUNK + sizeof(t_alloc))

typedef struct		s_alloc
{
  uint32_t		magic;
  size_t		size;
  bool			used;
  struct s_alloc	*next;
}			t_alloc;

void show_alloc_mem();

void *malloc(size_t size);
void *realloc(void *ptr, size_t size);
void free(void *ptr);

#endif
