/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include "include.h"
#include "struct.h"
#include "get_next_line.h"
#include "binary_tree.h"

//utils

int	my_printf(char *, ...);
int	my_strlen(char *);
int	my_strcmp(char *, char *);
int	my_strncmp(char *, char *, int);
int	my_getnbr(char *);
char	**my_str_to_word_array(char *, char);
char	*my_strdup(char *);
void	free_tab(char **);
char	*my_strcat(char *, char *);
int	my_tab_len(char **);
char	*my_tabs_to_spaces(char *);
int	has_a_slash(char *);
void	free_all(envi_t *, path_t *);
char	**reogarnize_line(char **);
char	*clean_str(char *str);

// env list

void	fill_list(envi_t **, char **, path_t *);
void	my_show_list(envi_t *);
int	my_put_in_list(envi_t **, char *);
void	free_list(envi_t *);
void	del_node(envi_t *);
int	my_list_len(envi_t *);
char	**my_list_to_tab(envi_t *);
void	refresh_env(envi_t *, path_t *);

// exec func

int	loop_func(fptr_t *, char **, path_t *, envi_t **);
char	*find_func(char *, path_t *);
void	exec_func(char **, envi_t *, path_t *);
char	*complete_func(char *, path_t *, char *);
void	check_signal(int, path_t *);
void	do_command_line(envi_t *, path_t *, char **);
void	call_functions(int, char **, envi_t *, path_t *);
void	exec_func_pipe(char **, envi_t *, path_t *);
int	check_pipe_func(envi_t *, path_t *, char **);
int	exec_pipes(envi_t *, path_t *, char ***);

// builtins

int	fcd(char **, envi_t **, path_t *);
void	change_dir(char **, path_t *, char *, char **);
int	fenv(char **, envi_t **, path_t *);
int	fsetenv(char **, envi_t **, path_t *);
int	setenv_err(char **, envi_t *, path_t *);
int	funsetenv(char **, envi_t **, path_t *);
int	unsetenv_err(char **, path_t *);
int	fexit(char **, envi_t **, path_t *);
int	stop_exit(char **, path_t *, envi_t *, int);
int	fecho(char **line, envi_t **env, path_t *path);

// path

void	find_path(path_t *, char **);
void	del_path(char *);
void	find_home(path_t *, char **);
int	cat_path(char **, path_t *);
void	find_env_path(path_t *, char **);

// redir

int	right_redir(char ***);
char	**found_right_redir(char **, int);
void	count_redir(int *, int *, char **);
void	count_redir_with_pipe(int *, int *, char **);
int	check_right_redir_position(char **);
char	*add_space_after_redir(char *);

//control

int	short_control(char c, line_t *all);
int	short_info(char c, char **str);
void	delete_character(line_t *all);
void	arrow_control(line_t *all);
void	add_character_str(char c, line_t *all);
char	*my_strcat_control(char *dest, char *src, int pos);
void	display_term(char *s, int pos, char *pwd);
void	start_cycle(line_t *all);
char	*line(line_t *all, char *s);
void	save_str_enter(line_t *all);

#endif
