/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** BATEN
*/

#include "my.h"

void	delete_past(line_t *all)
{
	int nb = my_strlen(all->str) - all->pos + 1;

	for (int c= 0; c != nb; c++)
		printf("%c%c%c", 27,91,67);
		printf("\b");
		printf(" ");
		printf("\b");
	for (int c= 0; c != nb; c++)
		printf("%c%c%c", 27,91,68);
	all->pos -= 1;
}

char	*delete_character_str(char *str, line_t *all)
{
	int nb = 0;
	int c = 0;
	char *new = malloc(sizeof(char) * (my_strlen(str)));

	for (; str[nb]; nb++) {
		if (nb + 1 != all->pos) {
			new[c] = str[nb];
			c++;
		}
	}
	free(str);
	new[nb - 1] = '\0';
	return (new);
}
void	delete_character(line_t *all)
{
	if (all->pos >= 1) {
		all->str = delete_character_str(all->str, all);
		delete_past(all);
	}
}
