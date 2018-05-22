/*
** EPITECH PROJECT, 2017
** sh
** File description:
** sh
*/

#include "my.h"

int	fcd(char **line, __attribute__((unused))envi_t **env, path_t *path)
{
	char **dir_path;
	char *value = my_strdup(path->pwd);

	if (my_tab_len(line) > 2) {
		write(2, "cd: Too many arguments.\n", 25);
		return (1);
	}
	if (line[1] != 0 && line[1][0] != '/')
		dir_path = my_str_to_word_array(line[1], '/');
	else if (line[1] && line[1][0] == '/') {
		dir_path = malloc(sizeof(char *) * 2);
		dir_path[0] = my_strdup(line[1]);
		dir_path[1] = 0;
	} else {
		dir_path = malloc(sizeof(char *) * 1);
		dir_path[0] = 0;
	}
	change_dir(dir_path, path, value, line);
	free_tab(dir_path);
	return (0);
}

int	fenv(char **line, envi_t **env, path_t *path)
{
	(void)line;
	(void)path;
	my_show_list(*env);
	return (0);
}

int	fsetenv(char **line, envi_t **env, path_t *path)
{
	char *str = NULL;
	envi_t *tmp = *env;

	if (setenv_err(line, *env, path) == 1)
		return (0);
	str = my_strcat(str, line[1]);
	str = my_strcat(str, "=");
	if (my_tab_len(line) == 3)
		str = my_strcat(str, line[2]);
	while (tmp != NULL) {
		if (my_strncmp(line[1], tmp->str, my_strlen(line[1])) == 0) {
			free(tmp->str);
			tmp->str = str;
			return (0);
		}
		tmp = tmp->next;
	}
	my_put_in_list(env, str);
	return (0);
}

int	funsetenv(char **line, envi_t **env, path_t *path)
{
	envi_t *tmp = *env;
	int i = 1;

	if (unsetenv_err(line, path) == 1)
		return (1);
	while (i < my_tab_len(line)) {
		if (my_strncmp(line[i], tmp->str, my_strlen(line[i])) == 0 &&
		tmp->str[my_strlen(line[i])] == '=') {
			if (tmp != *env)
				del_node(tmp);
			break;
		}
		if (tmp != NULL)
			tmp = tmp->next;
		if (tmp == NULL) {
			tmp = *env;
			i += 1;
		}
	}
	return (0);
}

int	fexit(char **line, envi_t **env, path_t *path)
{
	int nb = 0;

	if (line[1] != 0)
		nb = my_getnbr(line[1]);
	if (stop_exit(line, path, *env, nb) == 1)
		return (0);
	my_printf("exit\n");
	if (nb < 0) {
		exit((nb % 256) + 256);
	} else
		exit(nb % 256);
}
