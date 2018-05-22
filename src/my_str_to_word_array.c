/*
** EPITECH PROJECT, 2017
** str
** File description:
** array
*/

#include "my.h"

int	my_linelen(char *str, int i, char id)
{
	int j = i;

	while (str[j] && str[j] != id) {
		j += 1;
	}
	return (j);
}

int	nb_words(char *str, char id)
{
	int i = 0;
	int nb = 0;

	while (str[i]) {
		i += 1;
		nb = (str[i] == id) ? nb + 1 : nb;
		while (str[i] == id)
			i += 1;
	}
	if (i > 0)
		i -= 1;
	while (i != 0 && str[i] && str[i] == ' ') {
		str[i] = '\0';
		i -= 1;
	}
	nb += 1;
	if (id == ':')
		nb += 1;
	return (nb);
}

void	tab_cpy(char *str, char **tab, char id, int i)
{
	int j = 0;
	int k = 0;

	tab[j] = malloc(sizeof(char) * my_linelen(str, i, id) + 1);
	while (str[i]) {
		tab[j][k] = str[i];
		i += 1;
		k += 1;
		if (str[i] == id) {
			tab[j][k] = '\0';
			j += 1;
			i += 1;
			k = 0;
			tab[j] = malloc(my_linelen(str, i, id) + 1);
		}
		while (str[i] == id)
			i += 1;
	}
	tab[j][k] = '\0';
	tab[j + 1] = 0;
}

char	**my_str_to_word_array(char *str, char id)
{
	int words;
	char **tab;
	int i = 0;

	while (str[i] && str[i] == id)
		i += 1;
	words = nb_words(str, id);
	tab = malloc(sizeof(char *) * (words + 1));
	tab_cpy(str, tab, id, i);
	return (tab);
}

void	free_tab(char **tab)
{
	int i = 0;

	while (tab[i])
		i += 1;
	i -= 1;
	while (i >= 0) {
		free(tab[i]);
		i -= 1;
	}
	free(tab);
}
