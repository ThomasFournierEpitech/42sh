/*
** EPITECH PROJECT, 2017
** sh
** File description:
** sh
*/

#include "my.h"

void	find_pwd(path_t *path)
{
	size_t size = 1000;
	char *buf = malloc(1000);

	buf = getcwd(buf, size);
	path->pwd = my_strdup(buf);
	path->old_pwd = my_strdup(buf);
	free(buf);
}

void	find_path(path_t *path, char **env)
{
	int i = 0;

	path->exit = 0;
	path->base_fd[0] = dup(0);
	path->base_fd[1] = dup(1);
	find_env_path(path, env);
	find_pwd(path);
	find_home(path, env);
	i = 0;
	while (path->env_path[i]) {
		path->env_path[i] = my_strcat(path->env_path[i], "/");
		i += 1;
	}
	path->pwd = my_strcat(path->pwd, "/");
	path->old_pwd = my_strcat(path->old_pwd, "/");
}
