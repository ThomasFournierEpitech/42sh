/*
** EPITECH PROJECT, 2017
** str
** File description:
** array
*/

#include "my.h"

int	check_list(separator_t *list, char c[2])
{
	int nb = NB_SEPARATOR;
	int i = 0;

	while (i < nb) {
		if ((c[0] == list[i].name[0] && list[i].len == DEFAULT) ||
		(c[0] == list[i].name[0] && c[1] == list[i].name[1] &&
		list[i].len == DOUBLE))
			return (i);
		i++;
	}
	return (-1);
}

static int	my_linelen(char *str, int i, separator_t *list)
{
	int j = i;

	while (str[j] && check_list(list, (char [2]){str[i], str[i + 1]}) == -1) {
		j += 1;
	}
	return (j);
}

static int	nb_words(char *str, separator_t *list)
{
	int i = 0;
	int nb = 0;
	int test = 0;

	while (str[i]) {
		i += 1;
		test = check_list(list, (char [2]){str[i], str[i + 1]});
		nb = (test != -1) ? nb + 1 : nb;
		if (test != -1 && list[test].len == DOUBLE)
			i++;
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

static void	tab_cpy(char *str, char **tab, separator_t *list, int i)
{
	int j = 0;
	int k = 0;
	int test = 0;

	tab[j] = malloc(sizeof(char) * my_linelen(str, i, list) + 1);
	while (str[i]) {
		tab[j][k] = str[i];
		i += 1;
		k += 1;
		test = check_list(list, (char [2]){str[i], str[i + 1]});
		if (test != -1) {
			tab[j][k] = '\0';
			tab[j] = clean_str(tab[j]);
			if (list[test].len == DOUBLE)
				i++;
			i += 1;
			j += 1;
			k = 0;
			tab[j] = malloc(my_linelen(str, i, list) + 1);
		}
		while (check_list(list, (char [2]){str[i], str[i + 1]}) != -1)
			i += 1;
	}
	tab[j][k] = '\0';
	tab[j] = clean_str(tab[j]);
	if (k - 2 >= 0 && tab[j][k - 2] == '\n')
		tab[j][k - 2] = '\0';
	tab[j + 1] = 0;
}

char	**my_str_to_word_array_list(char *str, separator_t *list)
{
	int words;
	char **tab;
	int i = 0;

	while (str[i] && check_list(list, (char [2]){str[i], str[i + 1]}) != -1)
		i += 1;
	words = nb_words(str, list);
	tab = malloc(sizeof(char *) * (words + 1));
	tab_cpy(str, tab, list, i);
	return (tab);
}
