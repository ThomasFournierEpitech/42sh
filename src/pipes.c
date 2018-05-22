/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include "my.h"

void	exec_last_pipe_func(envi_t *envi, path_t *path, char **line)
{
	int builtin;

	if (right_redir(&line) == 1) {
		path->exit = 1;
		return;
	}
	if (line[0] && !line[0][0]) {
		path->exit = 0;
		return;
	}
	builtin = loop_func(path->fptr, line, path, &envi);
	call_functions(builtin, line, envi, path);
	refresh_env(envi, path);
}

void	dup_pipes(int pipes[4], int i, int j)
{
	close(pipes[i]);
	dup2(pipes[j], j);
	close(pipes[j]);
}

void	restore_std(int pipes[4], int i)
{
	dup2(pipes[2], 0);
	dup2(pipes[3], 1);
	close(pipes[2]);
	close(pipes[3]);
	while (i >= 0) {
		wait(NULL);
		i -= 1;
	}
}

int	exec_pipes(envi_t *envi, path_t *path, char ***commands)
{
	int pipes[4];
	int i = 0;

	pipes[2] = dup(0);
	pipes[3] = dup(1);
	while (commands[i] && commands[i + 1]) {
		if (pipe(pipes))
			return (84);
		if (fork() == 0) {
			dup_pipes(pipes, 0, 1);
			exec_func_pipe(commands[i], envi, path);
		}
		dup_pipes(pipes, 1, 0);
		i += 1;
	}
	exec_last_pipe_func(envi, path, commands[i]);
	restore_std(pipes, i);
	return (0);
}

int	check_pipe_func(envi_t *envi, path_t *path, char **line)
{
	char *save = my_strdup(line[0]);
	DIR *file;
	(void)envi;

	line[0] = find_func(line[0], path);
	if (line[0] == NULL) {
		my_printf("%s: Command not found.\n", save);
		free(save);
		return (1);
	}
	file = opendir(line[0]);
	if (line[0] && (access(line[0], X_OK) != 0 || file)) {
		my_printf("%s: Permission denied.\n", line[0]);
		if (file)
			closedir(file);
		return (1);
	}
	free(save);
	return (0);
}
