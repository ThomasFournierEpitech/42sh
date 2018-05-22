/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** my.h
*/

#ifndef READ_SIZE
	#define READ_SIZE (10)
#endif

#ifndef GNL_H_
#define GNL_H_

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

char	*get_next_line(int);

#endif
