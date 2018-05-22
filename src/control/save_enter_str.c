/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** BATEN
*/

#include "my.h"

// void	printliste(line_t *all)
// {
// 	save_t *tmp = all->save;
//
// 	for (; tmp != NULL; tmp = tmp->next)
// 		printf("\n<%s>\n", tmp->str);
// }

void	save_str_enter(line_t *all)
{
	save_t *new = malloc(sizeof(save_t));

	new->str = all->str;
	new->next = all->save;
	new->prev = NULL;
	if (all->save)
		all->save->prev = new;
	all->save = new;
//	printliste(all);
}
