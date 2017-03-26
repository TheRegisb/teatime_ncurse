##
##  Teatime - A simple ncurses-based timer
##  Copyright (C) 2017 Régis BERTHELOT
##
##  This program is free software: you can redistribute it and/or modify
##  it under the terms of the GNU General Public License as published by
##  the Free Software Foundation, either version 3 of the License, or
##  (at your option) any later version.
##
##  This program is distributed in the hope that it will be useful,
##  but WITHOUT ANY WARRANTY; without even the implied warranty of
##  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
##  GNU General Public License for more details.
##
##  You should have received a copy of the GNU General Public License
##  along with this program.  If not, see <http://www.gnu.org/licenses/>.
##

##
## Makefile for teatime in /home/regisb/Documents/projets/teatime_ncurse
## 
## Made by Régis Berthelot
## Login   <berthelot.regis@gmail.com>
## 
## Started on  Fri Mar 24 17:34:52 2017 Régis Berthelot
## Last update Sun Mar 26 14:18:54 2017 Régis Berthelot
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
