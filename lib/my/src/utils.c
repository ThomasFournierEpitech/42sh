/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** my_printf
*/

#include "../../include/my.h"

int	my_strlen(char *str)
{
	int i = 0;

	while (str && str[i]) {
		i += 1;
	}
	return (i);
}

void	my_switch_base(int base, unsigned int nb, int hex, int *i)
{
	char hexa[17] = "0123456789abcdef\0";

	if (nb > base - 1)
		my_switch_base(base, nb / base, hex, i);
	if (hex == 1 && (nb % base) > 9)
		my_putchar(hexa[nb % base] - 32, i);
	else
		my_putchar(hexa[nb % base], i);
}

void	my_put_in_hexa_long(unsigned long nb, int *i)
{
	char hexa[17] = "0123456789abcdef\0";

	if (nb > 15)
		my_put_in_hexa_long(nb / 16, i);
	my_putchar(hexa[nb % 16], i);
}

void	my_showstr(char *str, int *i)
{
	int j = 0;

	while (str[j]) {
		if (str[j] < 32 || str[j] > 176) {
			my_putchar(92, i);
			my_switch_base(8, (int)str[j], 0, i);
		}
		else
			my_putchar(str[j], i);
		j += 1;
	}
}
