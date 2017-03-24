CC	=	gcc

RM	=	rm -f

SRCS	=	analysts.c	\
		parsers.c	\
		main.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	teatime

CFLAGS	+=	-W -Wall -Wextra

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
