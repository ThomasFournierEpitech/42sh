/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** my_printf
*/

#include "../../include/my.h"

int	fshowstr(va_list list, int *i, char **str)
{
	char *arg = va_arg(list, char *);

	my_showstr(arg, i);
	return (0);
}

int	fmodu(va_list list, int *i, char **str)
{
	my_putchar('%', i);
	return (0);
}
