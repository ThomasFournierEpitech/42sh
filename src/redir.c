/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include "my.h"

char	**found_right_redir(char **line, int fd)
{
	line = reogarnize_line(line);
	if (line[0] == NULL) {
		my_printf("Invalid null command.\n");
		free(line);
		return (NULL);
	}
	dup2(fd, 1);
	return (line);
}

int	check_right_redir_position(char **pipes)
{
	int i = 0;
	int j = 0;

	while (pipes[i]) {
		if (pipes[i][j] == '>' && !pipes[i + 1])
			return (0);
		else if (pipes[i][j] == '>' && pipes[i + 1])
			return (1);
		j += 1;
		if (!pipes[i][j]) {
			i += 1;
			j = 0;
		}
	}
	return (0);
}

void	count_redir_with_pipe(int *spl, int *dbl, char **pipes)
{
	int i = 0;
	int j = 0;

	while (pipes[i]) {
		while (pipes[i][j]) {
			*spl = (pipes[i][j] == '>' && pipes[i][j + 1] != '>')
			? *spl + 1 : *spl;
			*dbl = (pipes[i][j] == '>' && pipes[i][j + 1] == '>')
			? *dbl + 1 : *dbl;
			j = (pipes[i][j] == '>' && pipes[i][j + 1] == '>')
			? j + 1 : j;
			j += 1;
		}
		j = 0;
		i += 1;
	}
}

void	count_redir(int *simple, int *dbl, char **line)
{
	int i = 0;

	while (line[i]) {
		if (line[i][0] == '>' && line[i][1] != '>') {
			*simple += 1;
		} else if (line[i][0] == '>' && line[i][1] == '>') {
			*dbl += 1;
			i += 1;
		}
		i += 1;
	}
}
