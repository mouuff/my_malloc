##
## Makefile for hue in /home/arnaud.alies/rendu/PSU_2016_malloc
## 
## Made by arnaud.alies
## Login   <arnaud.alies@epitech.eu>
## 
## Started on  Tue Jan 24 13:20:41 2017 arnaud.alies
## Last update Tue Jan 24 16:26:49 2017 arnaud.alies
##

NAME	=	libmy_malloc.so

CC	=	gcc

INC	=	./include/

CFLAGS	=	-I$(INC) -fPIC \
		-Wall -W -Wextra

LDFLAGS	=	-shared

SRC	=	./src/

SRCS	=	$(SRC)malloc.c \
		$(SRC)free.c \

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

