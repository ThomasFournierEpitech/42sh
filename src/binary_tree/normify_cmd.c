/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

int	is_redirection(int value, separator_t *sep_l)
{
	if (value < 0)
		return (0);
	if (sep_l[value].type == REDIRECTION)
		return (1);
	return (0);
}


void	replace_in_cmd(char **cmd, int len_cmd1, int start, int len_file, int len_cmd2)
{
	char *new = malloc(sizeof(*new) * (my_strlen(*cmd) + 20));
	int i = 0;
	int tmp = 0;
	int tmp2 = 0;
	int n = 0;

	while (i < start) {
		new[i] = (*cmd)[i];
		i++;
	}
	while (tmp < len_cmd2) {
		new[i + tmp] = (*cmd)[len_cmd1 + len_file + tmp];
		tmp++;
	}
	new[i + tmp] = ' ';
	new[i + tmp + 1] = (*cmd)[start];
	new[i + tmp + 2] = ' ';
	while (tmp2 < len_file) {
		new[i + tmp + 3 + tmp2] = (*cmd)[len_cmd1 + tmp2];
		tmp2++;
	}
	while ((*cmd)[len_cmd1 + len_file + len_cmd2 + n] != '\0') {
		new[i + tmp + 3 + tmp2 + n] = (*cmd)[len_cmd1 + len_file + len_cmd2 + n];
		n++;
	}
	new[i + tmp + 3 + tmp2 + n] = '\0';
	new = clean_str(new);
	*cmd = new;
}

void	place_redirection(char **cmd, int i, tree_info_t *info)
{
	int nb = 0;
	int nb2 = 0;
	int start = i;
	separator_t *sep_l = info->separator_list;

	i++;
	while ((*cmd)[i] != '\0' && (*cmd)[i] == ' ')
		i++;
	if ((*cmd)[i] == '\0') {
		my_printf("error after redirection: %s\n", *cmd);
		exit (84);
	}
	if ((*cmd)[i + 1] == ' ')
		i+= 2;
	while ((*cmd)[i + nb] != '\0' && (*cmd)[i + nb] != ' ' && check_list(sep_l, (char [2]){(*cmd)[i + nb], (*cmd)[i + nb + 1]}) == -1)
		nb++;
	if ((*cmd)[i + nb] == '\0' || check_list(sep_l, (char [2]){(*cmd)[i + nb], (*cmd)[i + nb + 1]}) != -1)
		return;
	nb += 1;
	while ((*cmd)[i + nb + nb2] != '\0' && check_list(sep_l, (char [2]){(*cmd)[i + nb + nb2], (*cmd)[i + nb + nb2 + 1]}) == -1)
		nb2++;
	replace_in_cmd(cmd, i, start, nb, nb2);

}

void	normify_cmd(char **cmd, tree_info_t *info)
{
	int i = 0;
	int value = 0;
	separator_t *sep_l = info->separator_list;

	if ((*cmd)[my_strlen(*cmd) - 1] == '\n')
		(*cmd)[my_strlen(*cmd) - 1] = '\0';
	while ((*cmd)[i] != '\0') {
		value = check_list(sep_l, (char [2]){(*cmd)[i], (*cmd)[i + 1]});
		while ((*cmd)[i] != '\0' &&  value == -1) {
			i++;
			value = check_list(sep_l, (char [2]){(*cmd)[i], (*cmd)[i + 1]});
		}
		if (is_redirection(value, sep_l)) {
			place_redirection(cmd, i, info);
		}
		if ((*cmd)[i] == '\0')
			break;
		i++;
	}
}
