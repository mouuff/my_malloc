/*
** my_malloc.h for hue in /home/arnaud.alies/rendu/PSU_2016_malloc
**
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
**
** Started on  Tue Jan 24 13:19:13 2017 arnaud.alies
** Last update Thu Feb  2 11:00:19 2017 Frederic ODDOU
*/

#ifndef MY_MALLOC_H_
# define MY_MALLOC_H_

# include <stddef.h>
# include <stdint.h>
# include <pthread.h>

# define MAGIC (0x2142FF42)
# define ERR_MAGIC ("BROKEN MAGIC ID.\n")
# define HEX_TABLE ("0123456789ABCDEF")

typedef struct		s_chunk
{
  uint32_t		magic;
  size_t		size;
  int			used;
  struct s_chunk	*next;
  struct s_chunk	*prev;
}			t_chunk;

void my_putstr(char const *str);
void my_putnbr(unsigned long nb);
void my_puthex(size_t nb);
t_chunk *alloc_reuse(size_t size);

void show_alloc_mem();

void *malloc(size_t size);
void *realloc(void *ptr, size_t size);
void *calloc(size_t nmemb, size_t size);
void free(void *ptr);

extern t_chunk *g_start;
extern t_chunk *g_prev;
extern pthread_mutex_t g_mutex;

#endif
