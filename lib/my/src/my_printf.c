/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** my_printf
*/

#include "../../include/my.h"

int	loop_fptr(va_list list, int *i, fptr_t *fptr, char **str)
{
	int j = 0;

	if (fptr->c == 'i')
		fptr->c = 'd';
	while (fptr->flags[j] != '\0') {
		if (fptr->flags[j] == fptr->c) {
			fptr->fptr[j](list, i, str);
			return (0);
		}
		j += 1;
	}
	return (0);
}

int	fill_ptr(fptr_t *fptr)
{
	fptr->flags = "cdsboxXupS%#+";
	fptr->fptr[0] = &fchar;
	fptr->fptr[1] = &fint;
	fptr->fptr[2] = &fstring;
	fptr->fptr[3] = &fbin;
	fptr->fptr[4] = &foct;
	fptr->fptr[5] = &fhex;
	fptr->fptr[6] = &fmajhex;
	fptr->fptr[7] = &fuint;
	fptr->fptr[8] = &fpointer;
	fptr->fptr[9] = &fshowstr;
	fptr->fptr[10] = &fmodu;
	fptr->fptr[11] = &fhash;
	fptr->fptr[12] = &fplus;
}

int	my_printf(char *str, ...)
{
	va_list list;
	fptr_t fptr;
	int i = 0;

	va_start(list, str);
	fill_ptr(&fptr);
	while (*str != '\0') {
		if (*str == '%') {
			str += 1;
			fptr.c = *str;
			loop_fptr(list, &i, &fptr, &str);
		}
		else
			my_putchar(*str, &i);
		str++;
	}
	va_end(list);
	return (i);
}
