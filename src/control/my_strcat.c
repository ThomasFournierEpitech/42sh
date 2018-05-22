/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** lib
*/
#include "my.h"

char	*my_strcat_control(char *dest, char *src, int pos)
{
	int c = 0;
	int c2 = 0;
	int count = 0;
	char *end = malloc(sizeof(char) * ( my_strlen(dest) + my_strlen(src) + 1));
	if (my_strlen(dest) + 1 == pos) {
		for (;dest[c]; c++, count++)
			end[count] = dest[c];
		for (;src[c2]; c2++, count++)
			end[count] = src[c2];
	} else {
		for (;c != pos - 1; c++, count++)
			end[count] = dest[c];
		for (;src[c2]; c2++, count++)
			end[count] = src[c2];
		for (;dest[c]; c++, count++)
			end[count] = dest[c];
	}
	end[count] = '\0';
	return(end);
}
