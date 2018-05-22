##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c			\
		src/utils.c			\
		src/path.c			\
		src/built_in.c			\
		src/execute.c			\
		src/other.c			\
		src/search_env.c		\
		src/change_dir.c		\
		src/list.c			\
		src/env_handling.c		\
		src/line_handling.c		\
		src/get_next_line.c		\
		src/my_str_to_word_array.c	\
		src/mysh.c			\
		src/pipes.c			\
		src/parse_function.c		\
		src/error_env.c			\
		src/right_redir.c		\
		src/free_all.c			\
		src/redir.c			\
		src/clean_str.c			\
		$(binary_tree)			\
		$(control)

binary_tree =	src/binary_tree/binary_tree_tools.c		\
		src/binary_tree/binary_separator.c		\
		src/binary_tree/binary_info_cmd.c		\
		src/binary_tree/my_str_to_word_array_list.c	\
		src/binary_tree/create_tree_info.c		\
		src/binary_tree/sort_cmd_pos.c			\
		src/binary_tree/normify_cmd.c			\
		src/binary_tree/b_tree_create.c			\
		src/binary_tree/b_tree_error_handling.c		\

control =	src/control/line.c				\
		src/control/short_control.c			\
		src/control/arrow_control.c			\
		src/control/my_strcat.c				\
		src/control/add_character.c			\
		src/control/delete_character.c			\
		src/control/display_terminal.c			\

OBJ	=	$(SRC:.c=.o)

NAME	=	42sh

CFLAGS	=	-W -Wall -Wextra -I./include -g3

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -L./lib/my -lmy

clean:
	make clean -C lib/my
	rm -f $(OBJ)

fclean: clean
	make fclean -C lib/my
	rm -f $(NAME)

re: fclean all
