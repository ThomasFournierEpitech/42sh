/*
** EPITECH PROJECT, 2017
** sh
** File description:
** sh
*/

#include "my.h"

void	fill_list(envi_t **envi, char **env, path_t *path)
{
	int i = 0;
	envi_t *tmp = *envi;

	while (env[i]) {
		my_put_in_list(&tmp, env[i]);
		i += 1;
	}
	path->env = my_list_to_tab(tmp);
	*envi = tmp;
}

void	find_home(path_t *path, char **env)
{
	char *home;
	int i = 0;

	while (env[i] && my_strncmp(env[i], "HOME", 4) != 0)
		i += 1;
	if (!env[i])
		path->home = NULL;
	else {
		home = my_strdup(env[i]);
		home += 5;
		path->home = my_strdup(home);
		path->home = my_strcat(path->home, "/");
		home -= 5;
		free(home);
	}
}

void	refresh_env(envi_t *env, path_t *path)
{
	char **line;
	char *str = my_strdup("setenv PWD \0");
	char *old = my_strdup("setenv OLDPWD \0");
	int exit_value = path->exit;

	dup2(path->base_fd[0], 0);
	dup2(path->base_fd[1], 1);
	str = my_strcat(str, path->pwd);
	str[my_strlen(str) - 1] = '\0';
	line = my_str_to_word_array(str, ' ');
	fsetenv(line, &env, path);
	free_tab(line);
	old = my_strcat(old, path->old_pwd);
	old[my_strlen(old) - 1] = '\0';
	line = my_str_to_word_array(old, ' ');
	fsetenv(line, &env, path);
	free(old);
	free(str);
	free_tab(line);
	path->exit = exit_value;
}

void	find_env_path(path_t *path, char **env)
{
	int i = 0;
	char *env_path;

	while (env[i] && (my_strncmp(env[i], "PATH", 4) != 0))
		i += 1;
	if (!(env[i]))
		path->env_path = my_str_to_word_array("/bin", ':');
	else {
		env_path = my_strdup(env[i]);
		env_path += 5;
		path->env_path = my_str_to_word_array(env_path, ':');
		env_path -= 5;
		free(env_path);
	}
}
