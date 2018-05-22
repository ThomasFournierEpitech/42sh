/*
** EPITECH PROJECT, 2017
** utils
** File description:
** utils
*/

#include "my.h"

int	my_strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1 && s2 && s1[i]) {
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i += 1;
	}
	return (0);
}

int	my_strncmp(char *s1, char *s2, int n)
{
	int i = 0;

	while (i < n && s1[i]) {
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i += 1;
	}
	return (0);
}

char	*my_strdup(char *str)
{
	char *new = malloc(my_strlen(str) + 1);
	int i = 0;

	if (new == NULL)
		exit(84);
	while (str[i]) {
		new[i] = str[i];
		i += 1;
	}
	new[i] = '\0';
	return (new);
}

char	*my_strcat(char *s1, char *s2)
{
	char *new = malloc(sizeof(char) * my_strlen(s1) + my_strlen(s2) + 1);
	int i = 0;
	int j = 0;

	if (new == NULL)
		return (NULL);
	while (s1 && s1[i]) {
		new[i] = s1[i];
		i += 1;
	}
	while (s2 && s2[j]) {
		new[i + j] = s2[j];
		j += 1;
	}
	new[i + j] = '\0';
	if (s1)
		free(s1);
	return (new);
}

int	my_getnbr(char *str)
{
	int i = 0;
	int nb = 0;
	int sign = 1;

	if (str[0] == '-') {
		sign = -sign;
		i += 1;
	}
	while (str[i]) {
		if (str[i] < '0' || str[i] > '9')
			return (11324);
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	if (sign == -1)
		nb = -nb;
	return (nb);
}
