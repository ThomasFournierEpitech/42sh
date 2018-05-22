/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** my_printf
*/

#include "../../include/my.h"

int	fbin(va_list list, int *i, char **str)
{
	unsigned int nb = va_arg(list, unsigned int);

	my_switch_base(2, nb, 0, i);
	return (0);
}

int	foct(va_list list, int *i, char **str)
{
	unsigned int nb = va_arg(list, unsigned int);

	my_switch_base(8, nb, 0, i);
	return (0);
}

int	fhex(va_list list, int *i, char **str)
{
	unsigned int nb = va_arg(list, unsigned int);

	my_switch_base(16, nb, 0, i);
	return (0);
}

int	fmajhex(va_list list, int *i, char **str)
{
	unsigned int nb = va_arg(list, unsigned int);

	my_switch_base(16, nb, 1, i);
	return (0);
}

int	fpointer(va_list list, int *i, char **str)
{
	unsigned long nb = va_arg(list, unsigned long);

	write(1, "0x", 2);
	*i += 2;
	my_put_in_hexa_long(nb, i);
	return (0);
}
