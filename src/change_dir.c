/*
** EPITECH PROJECT, 2017
** sh
** File description:
** sh
*/

#include "my.h"

int	cat_path(char **dir_path, path_t *path)
{
	int i = 0;

	if (dir_path[0] && dir_path[0][0] == '/') {
		free(path->pwd);
		path->pwd = my_strdup(dir_path[0]);
		i += 1;
	}
	for (i = i; dir_path[i]; i++) {
		if (dir_path[i][0] == '.' && dir_path[i][1] == '.')
			del_path(path->pwd);
		else if (dir_path[0][0] == '-' && dir_path[0][1] == '\0') {
			free(path->pwd);
			path->pwd = my_strdup(path->old_pwd);
		} else {
			path->pwd = my_strcat(path->pwd, dir_path[i]);
			path->pwd = (path->pwd[my_strlen(path->pwd) - 1] !=
			'/') ? my_strcat(path->pwd, "/") : path->pwd;
		}
	}
	return (i);
}

int	is_a_dir(path_t *path, char *value, char **s)
{
	DIR *dir = opendir(path->pwd);

	if (dir) {
		closedir(dir);
		chdir(path->pwd);
		free(path->old_pwd);
		path->old_pwd = value;
	} else {
		my_printf("%s: Not a directory.\n", s[1]);
		free(path->pwd);
		path->pwd = value;
		return (1);
	}
	return (0);
}

int	whether_change(path_t *path, char *value, char **s)
{
	struct stat buff;

	if (lstat(path->pwd, &buff) == 0) {
		return (is_a_dir(path, value, s));
	} else {
		my_printf("%s: No such file or directory.\n", s[1]);
		free(path->pwd);
		path->pwd = value;
		return (1);
	}
}

void	change_dir(char **dir_path, path_t *path, char *value, char **s)
{
	if (cat_path(dir_path, path) == 0) {
		if (path->home != NULL)
			path->pwd = my_strdup(path->home);
		else {
			write(2, "cd: No home directory.\n", 23);
			free(path->pwd);
			path->pwd = value;
		}
	}
	path->exit = whether_change(path, value, s);
}
