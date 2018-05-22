/*
** EPITECH PROJECT, 2017
** sh
** File description:
** sh
*/

#include "my.h"

void	free_all(envi_t *envi, path_t *path)
{
	free(path->pwd);
	free(path->old_pwd);
	free(path->home);
	free_tab(path->env);
	free_tab(path->env_path);
	free_list(envi);
	close(path->base_fd[0]);
	close(path->base_fd[1]);
}
