/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include "my.h"

int	check_pipe_with_right_redir(char **pipes)
{
	int simple = 0;
	int dbl = 0;

	count_redir_with_pipe(&simple, &dbl, pipes);
	if (simple + dbl == 0)
		return (0);
	else if (simple + dbl > 1 || (simple + dbl == 1 &&
	check_right_redir_position(pipes) == 1)) {
		my_printf("Ambiguous output redirect.\n");
		return (1);
	}
	return (0);
}

int	func_multi_pipe(envi_t *envi, path_t *path, char **pipes)
{
	char **line = NULL;
	char ***commands = malloc(sizeof(char **) * (my_tab_len(pipes) + 1));
	int stop = 0;
	int i = 0;

	if (check_pipe_with_right_redir(pipes) == 1) {
		path->exit = 1;
		return (1);
	}
	while (pipes[i]) {
		line = my_str_to_word_array(pipes[i], ' ');
		commands[i] = line;
		stop = (pipes[i + 1] &&
		check_pipe_func(envi, path, line) == 1) ? 1 : stop;
		i += 1;
	}
	commands[i] = NULL;
	if (stop == 0)
		exec_pipes(envi, path, commands);
	return (0);
}

void	func_no_pipe(envi_t *envi, path_t *path, char *pipes)
{
	char **line = NULL;
	int builtin;

	line = my_str_to_word_array(pipes, ' ');
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

int	do_the_pipe(envi_t *envi, path_t *path, char **pipes)
{
	if (my_tab_len(pipes) == 1) {
		func_no_pipe(envi, path, pipes[0]);
		return (0);
	}
	func_multi_pipe(envi, path, pipes);
	return (0);
}

void	do_command_line(envi_t *envi, path_t *path, char **commands)
{
	char **pipes = NULL;
	int i = 0;

	while (commands[i]) {
		pipes = my_str_to_word_array(commands[i], '|');
		do_the_pipe(envi, path, pipes);
		i += 1;
		free_tab(pipes);
	}
}
