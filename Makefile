##
## Makefile for hue in /home/arnaud.alies/rendu/PSU_2016_malloc
## 
## Made by arnaud.alies
## Login   <arnaud.alies@epitech.eu>
## 
## Started on  Tue Jan 24 13:20:41 2017 arnaud.alies
## Last update Fri Jan 27 11:22:45 2017 arnaud.alies
##

NAME	=	libmy_malloc.so

CC	=	gcc

INC	=	./include/

CFLAGS	=	-I$(INC) -fPIC \
		-Wall -W -Wextra

LDFLAGS	=	-shared -lpthread

SRC	=	./src/

SRCS	=	$(SRC)malloc.c \
		$(SRC)calloc.c \
		$(SRC)realloc.c \
		$(SRC)free.c \
		$(SRC)show_alloc_mem.c \
		$(SRC)reuse.c \
		$(SRC)my_putnbr.c \
		$(SRC)my_putstr.c \
		$(SRC)my_putchar.c \

OBJS	=	$(SRCS:.c=.o)

RM	=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re

