/*
** EPITECH PROJECT, 2017
** my_putchar
** File description:
** char
*/

#include "../../include/my.h"

void	my_putchar(char c, int *i)
{
	(*i)++;
	write(1, &c, 1);
}
