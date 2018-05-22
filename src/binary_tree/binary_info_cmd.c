/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	print_info_cmd(cmd_t *cmd_list, int nb)
{
	int i = 0;

	while (i < nb) {
		printf("cmd:%s,pos:%d\n", cmd_list[i].cmd, cmd_list[i].pos);
		i++;
	}
}

void	set_cmd_list(cmd_t *cmd_list, int nb)
{
	int i = 0;

	while (i < nb) {
		cmd_list->cmd = NULL;
		cmd_list->pos = -1;
		cmd_list->init = 0;
		i++;
	}
}
