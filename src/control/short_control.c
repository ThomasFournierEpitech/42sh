/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** BATEN
*/

#include "my.h"

int	short_control(char c, line_t *all)
{
	switch (c) {
		case 27:
			arrow_control(all);
			return (0);
		case 0x7f:
			delete_character(all);
			return (0);
		case 10:
			save_str_enter(all);
			return (1);
		case 9:
			//tab
			return (0);
		case 4:
			all->str = NULL;
			all->ver = 1;
			return (1);
		default:
			add_character_str(c, all);
			return (0);
	}
}
