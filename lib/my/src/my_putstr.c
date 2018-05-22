/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** str
*/

#include "../../include/my.h"

int	my_putstr(char *str, int *i)
{
	int j = 0;

	while (str[j] != '\0') {
		my_putchar(str[j], i);
		j += 1;
	}
	return (0);
}
