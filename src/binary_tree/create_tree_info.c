/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	print_tab(int nb, char **tab)
{
	int i = 0;

	while (i < nb) {
		printf("%s$\n", tab[i]);
		i++;
	}
	printf("\n");
}

static int	nb_words(char *str, separator_t *list)
{
	int i = 0;
	int nb = 0;

	while (str[i]) {
		i += 1;
		nb = (check_list(list, (char [2]){str[i], str[i + 1]}) != -1) ? nb + 1 : nb;
		while (check_list(list, (char [2]){str[i], str[i + 1]}) != -1)
			i += 1;
	}
	if (i > 0)
		i -= 1;
	while (i != 0 && str[i] && str[i] == ' ') {
		str[i] = '\0';
		i -= 1;
	}
	nb += 1;
	return (nb);
}

void	fill_separator(tree_info_t *info, char *cmd)
{
	int i = 0;
	int c = 0;
	int value = 0;
	int nb = info->nb_cmd - 1;

	while (i < nb && cmd[c] != '\0') {
		value = check_list(info->separator_list, (char [2]){cmd[c], cmd[c + 1]});
		if (value != -1) {
			info->separator[i] = value;
			i++;
		}
		c++;
	}
	info->separator[i] = -1;
}

void	fill_tree_info(char *cmd, tree_info_t *info)
{
	char **tab = NULL;
	int words = nb_words(cmd, info->separator_list);
	int *pos = malloc(sizeof(*pos) * words);
	cmd = clean_str(cmd);
	normify_cmd(&cmd, info);
	tab = my_str_to_word_array_list(cmd, info->separator_list);
	info->separator = malloc(sizeof(int) * words);
	info->cmd_list = malloc(sizeof(cmd_t) * words);
	info->nb_cmd = words;
	set_cmd_list(info->cmd_list, info->nb_cmd);
	fill_separator(info, cmd);
	sort_cmd_pos(info, info->nb_cmd, 0, tab);
	free(pos);
}

tree_info_t *create_tree_info()
{
	tree_info_t *info = malloc(sizeof(*info));

	info->separator_list = create_separator_list();
	info->cmd_list = NULL;
	info->separator = NULL;
	return (info);
}
