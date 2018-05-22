/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** my.h
*/

#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#define NB_SEPARATOR 8
#define NB_PRIO 3


separator_t *create_separator_list();
cmd_t	*create_info_cmd(int nb, char **tab, int *pos, tree_info_t info);
char	**my_str_to_word_array_list(char *str, separator_t *list);
void	print_tab(int nb, char **tab);
int	check_list(separator_t *list, char c[2]);
void	fill_tree_info(char *cmd, tree_info_t *info);
tree_info_t *create_tree_info();
void	print_info_cmd(cmd_t *cmd_list, int nb);
void	fill_pos(int *pos, char *cmd, separator_t *list);
void	sort_cmd_pos(tree_info_t *info, int end, int pos, char **tab);
void	print_pos(cmd_t *cmd_l, int nb);
void	set_cmd_list(cmd_t *cmd_list, int nb);
void	normify_cmd(char **cmd, tree_info_t *info);
void	print_sep_l(int *list, int nb);
b_tree_t	*create_b_tree(tree_info_t *info);
void	print_b_tree(b_tree_t *root);
void	b_tree_error_handling(tree_info_t *info);

#endif
