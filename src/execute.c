/*
** EPITECH PROJECT, 2017
** sh
** File description:
** sh
*/

#include "my.h"

void	exec_func_pipe(char **line, envi_t *env, path_t *path)
{
	free_tab(path->env);
	path->env = my_list_to_tab(env);
	execve(line[0], line, path->env);
	my_printf("%s: Exec format error. Wrong Architecture.\n", line[0]);
}

void	exec_func(char **line, envi_t *env, path_t *path)
{
	int status;
	DIR *file = opendir(line[0]);

	if (access(line[0], X_OK) != 0 || file) {
		my_printf("%s: Permission denied.\n", line[0]);
		path->exit = 1;
		if (file)
			closedir(file);
		return;
	}
	free_tab(path->env);
	path->env = my_list_to_tab(env);
	if (fork() == 0) {
		execve(line[0], line, path->env);
		my_printf("%s: Exec format error. Wrong Architecture.\n", line[0]);
	} else {
		wait(&status);
		path->exit = 0;
		check_signal(status, path);
	}
}

void	check_signal(int status, path_t *path)
{
	int sig = WTERMSIG(status);

	switch (sig) {
		case 11:
			my_printf("Segmentation fault\n");
			path->exit = 139;
			break;
		case 8:
			my_printf("Floating exception\n");
			path->exit = 136;
			break;
		case 6:
			my_printf("Abort (core dumped)\n");
			break;
	}
}

int	my_tab_len(char **tab)
{
	int i = 0;

	while (tab[i] != 0)
		i += 1;
	return (i);
}
