##
## Makefile for teatime in /home/regisb/Documents/projets/teatime_ncurse
## 
## Made by Régis Berthelot
## Login   <berthelot.regis@gmail.com>
## 
## Started on  Fri Mar 24 17:34:52 2017 Régis Berthelot
## Last update Sat Mar 25 10:22:53 2017 Régis Berthelot
##

CC	=	gcc

RM	=	rm -f

SRCS	=	analysts.c	\
		graphics.c	\
		messages.c	\
		parsers.c	\
		main.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	teatime

CFLAGS	+=	-W -Wall -Wextra -pedantic

LIB	=	-I. -lncurses

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIB) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
