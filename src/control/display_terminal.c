/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** BATEN
*/

#include "my.h"

void	display_term(char *str, int pos, char *pwd)
{
	char *s = malloc(sizeof(char) * 4);
	s = " $> \0";
	s = my_strcat_control(pwd, s, my_strlen(pwd) + 1);
	s = my_strcat_control(s, str, my_strlen(s) + 1);
	for (int nb = my_strlen(s) ; nb != 0; nb--)
		printf("%c%c%c", 27,91,68);
	printf("%s", s);
	for (int nb = my_strlen(str) + 4; nb != 0; nb--)
		printf("%c%c%c", 27,91,68);
	for (int nb = pos + 4; nb != 0; nb--)
		printf("%c%c%c", 27,91,67);
}
