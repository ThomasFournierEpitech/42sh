/*
** EPITECH PROJECT, 2017
** utils
** File description:
** utils
*/

#include "my.h"

int	my_put_in_list(envi_t **envi, char *str)
{
	envi_t *new = malloc(sizeof(envi_t));
	envi_t *tmp = *envi;

	if (new == NULL)
		return (84);
	new->str = my_strdup(str);
	if (tmp == NULL) {
		new->prev = NULL;
		new->next = NULL;
		*envi = new;
	} else {
		while (tmp->next != NULL)
			tmp = tmp->next;
		new->next = NULL;
		new->prev = tmp;
		tmp->next = new;
	}
	return (0);
}

void	my_show_list(envi_t *list)
{
	envi_t *tmp = list;

	while (tmp != NULL) {
		my_printf("%s\n", tmp->str);
		tmp = tmp->next;
	}
}

void	free_list(envi_t *env)
{
	envi_t *tmp;

	while (env != NULL) {
		tmp = env;
		env = env->next;
		free(tmp->str);
		free(tmp);
	}
}

void	del_node(envi_t *tmp)
{
	while (tmp->prev == NULL && tmp->next == NULL)
		return;
	if (tmp->prev != NULL)
		tmp->prev->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = tmp->prev;
	free(tmp->str);
	free(tmp);
}

int	my_list_len(envi_t *env)
{
	envi_t *tmp = env;
	int i = 0;

	while (tmp != NULL) {
		i += 1;
		tmp = tmp->next;
	}
	return (i);
}
