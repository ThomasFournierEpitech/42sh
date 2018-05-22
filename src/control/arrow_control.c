/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** BATEN
*/

#include "my.h"

void	arrow_control(line_t *all)
{
	char d = getchar();
	char t = getchar();

	if (d == 91 && t == 65)
		write(1, "fleche de haut\n", 15);
	if (d == 91 && t == 66)
		write(1, "fleche de bas\n", 14);
	if (d == 91 && t == 68 && all->pos > 0) {
		//write(1, "fleche de gauche\n", 17);
		all->pos -= 1;
		printf("%c%c%c", 27,91,68);
		return;
	}
	if (d == 91 && t == 67 && all->pos < my_strlen(all->str)) {
		//write(1, "fleche de droite\n", 17);
		all->pos += 1;
		printf("%c%c%c", 27,91,67);
		return;
	}
}
