/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	print_pos(cmd_t *cmd_l, int nb)
{
	int i = 0;

	printf("pos:\n");
	while (i < nb) {
		printf("%d\n", cmd_l[i].pos);
		i++;
	}
	printf("\n");
}

void	print_sep_l(int *list, int nb)
{
	int i = 0;

	printf("sep_l:\n");
	while (i < nb) {
		printf("%d\n", list[i]);
		i++;
	}
}


void	sort_this_part(tree_info_t *info, int i, int *pos)
{
	int *sep_l = info->separator;
	cmd_t *cmd_l = info->cmd_list;
	separator_t *list = info->separator_list;

	while (i >= 0 && list[sep_l[i]].type != CUT)
		i--;
	cmd_l[i].init = 1;
	cmd_l[i].pos = *pos;
	(*pos)++;
	i++;
	while (list[sep_l[i]].type != CUT) {
		cmd_l[i].init = 1;
		cmd_l[i].pos = *pos;
		(*pos)++;
		i++;
	}
}

void	sort_cmd_pos(tree_info_t *info, int end, int pos, char **tab)
{
	int i = 0;
	cmd_t *cmd_l = info->cmd_list;

	while (i < end) {
		cmd_l[i].pos = pos;
		cmd_l[i].cmd = tab[i];
		pos++;
		i++;
	}
}
