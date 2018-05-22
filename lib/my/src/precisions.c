/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** my_printf
*/

#include "../../include/my.h"

int	switch_hash(va_list list, int *i, char **str)
{
	switch (**str) {
		case ('X'):
		my_putstr("0X", i);
		fmajhex(list, i, str);
		break;
		case ('x'):
		my_putstr("0x", i);
		fhex(list, i, str);
		break;
		case ('o'):
		my_putstr("0", i);
		foct(list, i, str);
		break;
	}
	return (0);
}

int	fhash(va_list list, int *i, char **str)
{
	va_list cpy;
	unsigned int nb;
	*str += 1;

	va_copy(cpy, list);
	nb = va_arg(cpy, unsigned int);
	if (nb == 0) {
		my_putchar('0', i);
		return (0);
	}
	switch_hash(list, i, str);
	va_end(cpy);
	return (0);
}

int	fplus(va_list list, int *i, char **str)
{
	va_list cpy;
	int nb;
	*str += 1;

	va_copy(cpy, list);
	nb = va_arg(cpy, int);
	if (nb > 0)
		my_putchar('+', i);
	fint(list, i, str);
	va_end(cpy);
	return (0);
}
