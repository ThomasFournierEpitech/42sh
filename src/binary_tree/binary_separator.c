/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

separator_t *create_separator_list()
{
	int nb = NB_SEPARATOR;
	separator_t *separator_l = malloc(sizeof(*separator_l) * nb);

	separator_l[0] = (separator_t){";", CUT, DEFAULT, 0};
	separator_l[1] = (separator_t){"&&", CUT, DOUBLE, 0};
	separator_l[2] = (separator_t){"||", CUT, DOUBLE, 0};
	separator_l[3] = (separator_t){"<", REDIRECTION, DEFAULT, 1};
	separator_l[4] = (separator_t){"<<", REDIRECTION, DOUBLE, 1};
	separator_l[5] = (separator_t){">", REDIRECTION, DEFAULT, 1};
	separator_l[6] = (separator_t){">>", REDIRECTION, DOUBLE, 1};
	separator_l[7] = (separator_t){"|", DEFAULT, DEFAULT, 2};
	return (separator_l);
}
