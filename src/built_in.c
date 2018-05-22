/*
** EPITECH PROJECT, 2018
** erwann
** File description:
** 42
*/

#include "my.h"

void	next_echo(char line)
{
	switch (line) {
		case 'n':
			my_printf("\n");
			break;
		case 'b':
			my_printf("\f");
			break;
		case 'c':
			my_printf("\r");
			break;
		case 'e':
			my_printf("\t");
			break;
		case 'v':
			my_printf("\v");
			break;
		case 't':
			my_printf("\t");
			break;
	}
}

void	special_echo(char line)
{
	switch (line) {
		case 'a':
			my_printf("\a");
			break;
		case 'b':
			my_printf("\b");
			break;
		case 'e':
			my_printf("\e");
			break;
		case '\\':
			my_printf("\\");
			break;
		default:
			next_echo(line);
	}
}

int	is_not_a_flag(char *line)
{
	while (my_strcmp(line, "-n") == 0)
		return (2);
	while (my_strcmp(line, "-E") == 0)
		return (1);
	while (my_strcmp(line, "-e") == 0)
		return (1);
	return (0);
}

void	print_echo(char **line, int i, int *state, int start)
{
	if (i > start)
		my_printf(" ");
	for (int n = 0; line[i][n] != '\0'; n++) {
		if (line[i][n] == '\\' && state[1] == 1) {
			special_echo(line[i][n + 1]);
			n += 2;
		} if (line[i][n] != 34 && line[i][n] != 39)
			my_printf("%c", line[i][n]);
	}
}

int	fecho(char **line, envi_t **env, path_t *path)
{
	int state[2] = {0, 0};
	int i = 1;
	for (; line[i]; i++) {
		if (my_strcmp(line[i], "-n") == 0)
			state[0] = 1;
		while (my_strcmp(line[i], "-E") == 0) {
			state[1] = 0;
			break;
		} while (my_strcmp(line[i], "-e") == 0) {
			state[1] = 1;
			break;
		} if (is_not_a_flag(line[i]) == 0)
			break;
	} if (i == 0)
		i = 1;
	int start = i;
	for (; line[i]; i++)
		print_echo(line, i, state, start);
	if (state[0] == 0)
		my_printf("\n");
}
