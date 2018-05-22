/*
** EPITECH PROJECT, 2017
** sh
** File description:
** sh
*/

#include "my.h"

int	unsetenv_err(char **line, path_t *path)
{
	if (my_tab_len(line) == 1) {
		path->exit = 1;
		my_printf("unsetenv: Too few arguments.\n");
		return (1);
	}
	return (0);
}
