/*
** EPITECH PROJECT, 2017
** utils
** File description:
** utils
*/

#include "my.h"

char	*add_space(char *new, char *str, int *i, int *j)
{
	if (*i != 0 && str[*i] == '>' && str[*i - 1] != ' ' &&
	str[*i - 1] != '>') {
		new[*j] = ' ';
		*j += 1;
	}
	if (str[*i] == '>' && str[*i + 1] != ' ' &&
	str[*i + 1] != '>' && str[*i + 1] != '\0') {
		new[*j] = '>';
		new[*j + 1] = ' ';
		*j += 2;
		*i += 1;
	}
	return (new);
}

char	*add_space_after_redir(char *str)
{
	int i = 0;
	int j = 0;
	char *new = malloc(sizeof(char) * (my_strlen(str) + 100));

	while (str[i]) {
		new = add_space(new, str, &i, &j);
		new[j] = str[i];
		j += 1;
		i += 1;
	}
	new[j] = '\0';
	free(str);
	return (new);
}

int	has_a_slash(char *str)
{
	int i = 0;

	while (str && str[i]) {
		if (str[i] == '/' && str[i + 1] && i != 0)
			return (1);
		i += 1;
	}
	return (0);
}

char	*my_tabs_to_spaces(char *str)
{
	int i = 0;

	while (str[i]) {
		if (str[i] == '\t')
			str[i] = ' ';
		i += 1;
	}
	return (str);
}
