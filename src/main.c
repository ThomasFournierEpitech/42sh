/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

int	loop_func(fptr_t *fptr, char **line, path_t *path, envi_t **env)
{
	int i = 0;

	while (i < 6) {
		if (my_strcmp(line[0], fptr->funcs[i]) == 0 &&
		(my_strcmp(fptr->funcs[i], line[0])) == 0) {
			fptr->fptr[i](line, env, path);
			return (1);
		}
		i += 1;
	}
	return (0);
}

void	init_fptr(fptr_t *fptr)
{
	fptr->funcs[0] = "cd";
	fptr->funcs[1] = "env";
	fptr->funcs[2] = "setenv";
	fptr->funcs[3] = "unsetenv";
	fptr->funcs[4] = "exit";
	fptr->funcs[5] = "echo";
	fptr->fptr[0] = &fcd;
	fptr->fptr[1] = &fenv;
	fptr->fptr[2] = &fsetenv;
	fptr->fptr[3] = &funsetenv;
	fptr->fptr[4] = &fexit;
	fptr->fptr[5] = &fecho;
}

void	mysh(envi_t *envi, path_t *path)
{
	char *str = NULL;
	char **commands;
	fptr_t fptr;
	tree_info_t *info = create_tree_info();
	b_tree_t *b_tree;

	init_fptr(&fptr);
	path->fptr = &fptr;
	my_printf((isatty(0) == 1) ? "%s $> " : "", path->pwd);
	str = line(&path->line, path->pwd);
	while (str) {
		str = clean_str(str);
		if (str[0] != '|') {
		fill_tree_info(str, info);
		b_tree = create_b_tree(info);
		//print_b_tree(b_tree);
		str = my_tabs_to_spaces(str);
		str = add_space_after_redir(str);
		commands = my_str_to_word_array(str, ';');
		do_command_line(envi, path, commands);
		my_printf((isatty(0) == 1) ? "%s $> " : "", path->pwd);
		free(str);
		free_tab(commands);
		} else {
			my_printf("Invalid null command\n");
			my_printf((isatty(0) == 1) ? "%s $> " : "", path->pwd);
		}
		str = line(&path->line, path->pwd);
	}
}

int	main(int ac, char **av, char **env)
{
	path_t path;
	envi_t *envi = NULL;
	path.line.save = NULL;

	(void)ac;
	(void)av;
	fill_list(&envi, env, &path);
	find_path(&path, env);
	mysh(envi, &path);
	free_all(envi, &path);
	return (path.exit);
}
