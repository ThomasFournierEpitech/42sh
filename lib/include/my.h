/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** my_printf
*/

#ifndef MY_H_
#define MY_H_

#include "include.h"
#include "struct.h"

int	my_printf(char *str, ...);
void	my_putchar(char, int *);
int	my_putstr(char *, int *);
int	my_put_nbr(int, int *);
int	my_strlen(char *);
int	switch_base(int, unsigned int, int, int *);
int	fchar(va_list, int *, char **);
int	fstring(va_list, int *, char **);
int	fint(va_list, int *, char **);
int	fbin(va_list, int *, char **);
int	foct(va_list, int *, char **);
int	fhex(va_list, int *, char **);
int	fmajhex(va_list, int *, char **);
void	my_switch_base(int, unsigned int, int, int *);
void	my_put_in_hexa_long(unsigned long, int *);
int	my_put_unsigned_nbr(unsigned int, int *);
int	fuint(va_list, int *, char **);
int	fpointer(va_list, int *, char **);
void	my_showstr(char *, int *);
int	fshowstr(va_list, int *, char **);
int	fmodu(va_list, int *, char **);
int	fhash(va_list, int *, char **);
int	fplus(va_list, int *, char **);
int	loop_fptr(va_list, int *, fptr_t *, char **);

void	redirect_all_std(void);

#endif
