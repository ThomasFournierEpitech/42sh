/*
** EPITECH PROJECT, 2017
** read
** File description:
** read
*/

#include "get_next_line.h"

static int	my_strlen(char *str)
{
	int i = 0;

	while (str && str[i])
		i += 1;
	return (i);
}

static char	*add_char(char *str, char *buff)
{
	char *new = malloc(sizeof(char) * (my_strlen(str) + 2));
	int i = 0;

	while (str && str[i]) {
		new[i] = str[i];
		i += 1;
	}
	new[i] = buff[0];
	new[i + 1] = '\0';
	if (str)
		free(str);
	return (new);
}

char	*get_next_line(int fd)
{
	char *buffer = malloc(sizeof(char) * 2);
	char *line = NULL;
	int rd;

	rd = read(fd, buffer, 1);
	while (rd != 0) {
		buffer[rd] = '\0';
		if (buffer[0] == '\n' && line != NULL) {
			free(buffer);
			return (line);
		} else if (buffer[0] == '\n' && line == NULL) {
			line = malloc(sizeof(char) * 1);
			line[0] = '\0';
			free(buffer);
			return (line);
		}
		line = add_char(line, buffer);
		rd = read(fd, buffer, 1);
	}
	return (NULL);
}
