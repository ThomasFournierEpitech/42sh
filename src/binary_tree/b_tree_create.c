/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

b_tree_t	*create_node(b_tree_t *root, tree_info_t *info, int pos, node_type_t type)
{
	b_tree_t *new = malloc(sizeof(*new));

	new->top = root;
	new->left = NULL;
	new->right = NULL;
	new->type = type;
	if (type == OPERATOR) {
		new->value = info->separator_list[pos].name;
	}
	if (type == CMD)
		new->value = info->cmd_list[pos].cmd;
	return (new);
}

int	find_separator(int *nb_sep, int *nb_cmd, tree_info_t *info)
{
	int start = *nb_sep;
	int i = 0;
	int test = 0;
	int *list = info->separator;
	int max = info->nb_cmd - 1;

	test = list[i + start];
	if (test == -1)
		return (0);
	while (test > 2 && (i + start) < max) {
		i++;
		test = list[i + start];
	}
	if ((i + start) != max) {
		*nb_sep = i + 1;
		*nb_cmd = i + 1;
		return (1);
	}
	*nb_sep = i;
	*nb_cmd = i + 1;
	return (1);
}

b_tree_t	*fill_recursive(tree_info_t *info, b_tree_t *top, int nb_sep)
{
	int *list = info->separator;
	int nb_cmd = 0;
	int type = 0;
	int start_sep = nb_sep;
	int start_cmd = nb_sep;
	int end = 0;
	b_tree_t *root = NULL;
	b_tree_t *tmp = NULL;

	type = find_separator(&nb_sep, &nb_cmd, info);
	end = nb_sep;
	root = create_node(top, info, (type == 1)? list[nb_sep - 1 + start_sep] : start_cmd,
	(type == 1)? OPERATOR : CMD);
	tmp = root;

	nb_sep--;
	if (type == 0)
		return (root);
	while (nb_cmd > 0) {
		if (list[nb_sep + start_sep] <= 2) {
			tmp->right = fill_recursive(info, root, end + start_sep);
		} else {
			tmp->right = create_node(tmp, info, nb_cmd - 1 + start_cmd, CMD);
			nb_cmd--;
		}
		if (nb_cmd + start_cmd > start_cmd + 1) {
			if (nb_sep + start_sep < 1)
				break;
			tmp->left = create_node(tmp, info, list[nb_sep - 1 + start_sep], OPERATOR);
			nb_sep--;
		} else {
			tmp->left = create_node(tmp, info, nb_cmd - 1 + start_cmd, CMD);
			nb_cmd--;
		}
		tmp = tmp->left;
		break;
	}
	return (root);
}

b_tree_t	*create_b_tree(tree_info_t *info)
{
	int *list = info->separator;
	int nb_cmd = 0;
	int nb_sep = 0;
	int type = 0;
	int end = 0;
	b_tree_t *root = NULL;
	b_tree_t *tmp = NULL;

	type = find_separator(&nb_sep, &nb_cmd, info);
	end = nb_sep;
	root = create_node(NULL, info, (type == 1)? list[nb_sep - 1] : 0,
	(type == 1)? OPERATOR : CMD);
	tmp = root;

	nb_sep--;
	if (type == 0)
		return (root);
	while (nb_cmd > 0) {
		if (list[nb_sep] <= 2) {
			tmp->right = fill_recursive(info, root, end);
		} else {
			tmp->right = create_node(tmp, info, nb_cmd - 1, CMD);
			nb_cmd--;
		}
		if (nb_cmd > 1) {
			if (nb_sep < 1)
				break;
			tmp->left = create_node(tmp, info, list[nb_sep - 1], OPERATOR);
			nb_sep--;
		} else {
			tmp->left = create_node(tmp, info, nb_cmd - 1, CMD);
			nb_cmd--;
		}
		tmp = tmp->left;
	}
	return (root);
}
