/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** nbr
*/

#include "../../include/my.h"

int	my_put_nbr(int nb, int *i)
{
	if (nb < 0) {
		nb = -nb;
		my_putchar('-', i);
	}
	if (nb > 9)
		my_put_nbr(nb / 10, i);
	my_putchar(nb % 10 + 48, i);
	return (0);
}

int	my_put_unsigned_nbr(unsigned int nb, int *i)
{
	if (nb > 9)
		my_put_unsigned_nbr(nb / 10, i);
	my_putchar(nb % 10 + 48, i);
	return (0);
}
