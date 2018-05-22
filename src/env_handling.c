/*
** EPITECH PROJECT, 2017
** sh
** File description:
** sh
*/

#include "my.h"

int	other_setenv_err(char **line, envi_t *env, path_t *path)
{
	if (my_tab_len(line) == 1 || my_tab_len(line) > 3) {
		if (my_tab_len(line) > 3) {
			path->exit = 1;
			my_printf("setenv: Too many arguments.\n");
		}
		else if (my_tab_len(line) == 1) {
			path->exit = 0;
			my_show_list(env);
		}
		return (1);
	} else if (line[1][0] < 'A' || (line[1][0] > 'Z' && line[1][0] < 'a')
	|| line[1][0] > 'z') {
		my_printf("setenv: Variable name must begin with a letter.\n");
		path->exit = 1;
		return (1);
	}
	return (0);
}

int	setenv_err(char **line, envi_t *env, path_t *path)
{
	int i = 0;

	if (other_setenv_err(line, env, path) == 1)
		return (1);
	while (line[1][i]) {
		if ((line[1][i] < '0' || line[1][i] > '9') &&
		(line[1][i] < 'a' || line[1][i] > 'z') &&
		(line[1][i] < 'A' || line[1][i] > 'Z')) {
			my_printf("setenv: Variable name must contain "\
			"alphanumeric characters.\n");
			path->exit = 1;
			return (1);
		}
		i += 1;
	}
	path->exit = 0;
	return (0);
}

void	call_functions(int builtin, char **line, envi_t *envi, path_t *path)
{
	char *save;

	save = my_strdup(line[0]);
	if (builtin == 1) {
		free(line[0]);
		line[0] = NULL;
	}
	line[0] = find_func(line[0], path);
	if (line[0] == NULL && builtin == 0) {
		write(2, save, my_strlen(save));
		write(2, ": Command not found.\n", 21);
		// my_printf("%s: Command not found.\n", save);
		path->exit = 1;
	}
	if (line[0] && line[0][0] != '\0')
		exec_func(line, envi, path);
	free(save);
	if (line[0])
		free(line[0]);
}

int	stop_exit(char **line, path_t *path, envi_t *env, int nb)
{
	if (nb == 11324) {
		my_printf("exit: Badly formed number.\n");
		return (1);
	} else if (my_tab_len(line) > 2) {
		my_printf("exit: Expression syntax.\n");
		return (1);
	}
	free_tab(line);
	free_all(env, path);
	return (0);
}

char	**my_list_to_tab(envi_t *env)
{
	char **tab = malloc(sizeof(char *) * (my_list_len(env) + 1));
	envi_t *tmp = env;
	int i = 0;

	if (tab == NULL)
		exit(84);
	while (tmp != NULL) {
		tab[i] = my_strdup(tmp->str);
		i += 1;
		tmp = tmp->next;
	}
	tab[i] = 0;
	return (tab);
}
