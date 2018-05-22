/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** BATEN
*/

#include "my.h"

void	add_character_str(char c, line_t *all)
{
	char *add = malloc(sizeof(char) * 2);

	all->pos += 1;
	add[0] = c;
	add[1] = '\0';
	all->str = my_strcat_control(all->str, add, all->pos);
	free(add);
}
