/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** erwann
*/

#include "my.h"

void	jump_space(char *str, char *new, int *i, int *n)
{
	while (str[*i] != '\0' && (str[*i] == 32 || str[*i] == '\t'))
		(*i)++;
	if (*n != 0 && str[*i] != '\0') {
		new[*n] = ' ';
		(*n)++;
	}
}

char	*clean_str(char *str)
{
	char *new = malloc(sizeof(char) * my_strlen(str) + 2);
	int n = 0;
	int i = 0;

	while (str[i]) {
		if (str[i] != '\0' && (str[i] == 32 || str[i] == '\t')) {
			jump_space(str, new, &i, &n);
		} if (str[i] != '\0') {
			new[n] = str[i];
			n++;
			i++;
		}
	}
	new[n] = '\0';
	return (new);
}
