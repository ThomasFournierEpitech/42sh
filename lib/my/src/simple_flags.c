/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** my_printf
*/

#include "../../include/my.h"

int	fchar(va_list list, int *i, char **str)
{
	int c = va_arg(list, int);

	my_putchar(c, i);
	return (0);
}

int	fint(va_list list, int *i, char **str)
{
	int nb = va_arg(list, int);

	my_put_nbr(nb, i);
	return (0);
}

int	fstring(va_list list, int *i, char **str)
{
	char *arg = va_arg(list, char *);

	my_putstr(arg, i);
	return (0);
}

int	fuint(va_list list, int *i, char **str)
{
	unsigned int nb = va_arg(list, unsigned int);

	my_put_unsigned_nbr(nb, i);
	return (0);
}
