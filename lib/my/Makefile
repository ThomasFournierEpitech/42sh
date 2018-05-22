##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC	=	src/my_printf.c			\
		src/my_putchar.c		\
		src/my_putstr.c			\
		src/my_put_nbr.c		\
		src/utils.c			\
		src/simple_flags.c		\
		src/medium_flags.c		\
		src/other_flags.c		\
		src/precisions.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
