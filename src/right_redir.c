/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include "my.h"

char	**reogarnize_line(char **line)
{
	int i = 0;
	int j = 0;
	char **tab = malloc(sizeof(char *) * (my_tab_len(line) - 1));

	while (line[i]) {
		if (line[i][0] == '>')
			i += 2;
		if (line[i] == NULL)
			break;
		tab[j] = my_strdup(line[i]);
		i += 1;
		j += 1;
	}
	tab[j] = NULL;
	free_tab(line);
	return (tab);
}

char	**right_simple_redir(char **line)
{
	int i = 0;
	int fd;

	while (line[i]) {
		if (line[i][0] == '>' && line[i + 1] == NULL) {
			my_printf("Missing name for redirect.\n");
			free_tab(line);
			return (NULL);
		}
		if (line[i][0] == '>') {
			fd = open(line[i + 1], O_CREAT | O_WRONLY | O_TRUNC,
			0644);
			line = found_right_redir(line, fd);
			return (line);
		}
		i += 1;
	}
	return (line);
}

char	**right_dbl_redir(char **line)
{
	int i = 0;
	int fd;

	while (line[i]) {
		if (line[i][0] == '>' && line[i][1] == '>' &&
		line[i + 1] == NULL) {
			my_printf("Missing name for redirect.\n");
			free_tab(line);
			return (NULL);
		}
		if (line[i][0] == '>' && line[i][1] == '>') {
			fd = open(line[i + 1], O_APPEND | O_CREAT | O_WRONLY,
			0644);
			line = found_right_redir(line, fd);
			return (line);
		}
		i += 1;
	}
	return (line);
}

char	**handle_right_redir(char **line, int simple, int dbl)
{
	if (simple == 1)
		line = right_simple_redir(line);
	else if (dbl == 1)
		line = right_dbl_redir(line);
	return (line);
}

int	right_redir(char ***line)
{
	int simple = 0;
	int dbl = 0;

	count_redir(&simple, &dbl, *line);
	if (simple + dbl > 1) {
		my_printf("Ambiguous output redirect.\n");
		return (1);
	} else if (simple + dbl == 0)
		return (0);
	*line = handle_right_redir(*line, simple, dbl);
	while (line[0] == NULL)
		return (1);
	return (0);
}
