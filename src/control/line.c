/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** BATEN
*/

#include "my.h"

void	free_struct(line_t *all)
{
	all->pos = 0;
	all->ver = 0;
}

void	start_cycle(line_t *all)
{
	char c;
	static struct termios oldtio, newtio;
	tcgetattr(0, &oldtio);
	newtio = oldtio;
	newtio.c_lflag &= ~ICANON;
	newtio.c_lflag &= ~ECHO;
	tcsetattr(0, TCSANOW, &newtio);

	fflush(stdout);
	while (1) {
		c = getchar();
		if (short_control(c, all) == 1)
			break;
		display_term(all->str, all->pos, all->path);
	}
	tcsetattr(0, TCSANOW, &oldtio);
	free_struct(all);
}

char	*line(line_t *all, char *s)
{
	all->str = malloc(sizeof(char) * 1);
	all->str[0] = '\0';
	all->path = s;
	all->pos = 0;
	all->ver = 0;
	start_cycle(all);
	printf("\n");
	return (all->str);
}
