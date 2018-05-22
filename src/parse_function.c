/*
** EPITECH PROJECT, 2017
** sh
** File description:
** sh
*/

#include "my.h"

char	*does_function_exist(char *res)
{
	struct stat buff;

	if (res && lstat(res, &buff) == 0)
		return (res);
	if (res)
		free(res);
	res = NULL;
	return (res);
}

char	*complete_func(char *func, path_t *path, char *res)
{
	struct stat buff;
	int i = 0;

	while (path->env_path[i]) {
		if (func && func[0] != '/')
			res = my_strcat(res, path->env_path[i]);
		res = my_strcat(res, func);
		while (lstat(res, &buff) == 0)
			return (res);
		free(res);
		res = NULL;
		i += 1;
	}
	if (func && has_a_slash(func) == 1)
		res = my_strcat(res, func);
	if (func)
		free(func);
	func = NULL;
	res = does_function_exist(res);
	return (res);
}

char	*find_func(char *func, path_t *path)
{
	char *res = NULL;

	if (func == NULL)
		return (NULL);
	res = complete_func(func, path, res);
	return (res);
}

void	del_path(char *str)
{
	int i = my_strlen(str) - 1;

	while (str[i] == '/' && str[i] != '\0')
		i -= 1;
	while (str[i] != '/' && str[i] != '\0')
		i -= 1;
	i += 1;
	str[i] = '\0';
}
