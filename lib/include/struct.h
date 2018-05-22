/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** my_printf
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct fptr {
	char *flags;
	char c;
	int (*fptr[13])(va_list, int *i, char **str);
} fptr_t;

#endif
