/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** my.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

struct fptr;

typedef struct line_s
{
	char *str;
	int pos;
	int ver;
	char *path;
} line_t;

typedef struct path {
	char **env_path;
	char *pwd;
	char *old_pwd;
	char *home;
	char **env;
	struct fptr *fptr;
	int exit;
	int base_fd[2];
	line_t line;
} path_t;

typedef struct envi {
	char *str;
	struct envi *prev;
	struct envi *next;
} envi_t;

typedef struct fptr {
	char *funcs[6];
	int (*fptr[6])(char **, envi_t **, path_t *);
} fptr_t;

typedef enum separator_type_e {
	DEFAULT,
	REDIRECTION,
	CUT,
	DOUBLE
} separator_type_t;

typedef struct separator_s {
		char name[3];
		separator_type_t type;
		separator_type_t len;
		int prio;
} separator_t;

typedef struct cmd_s {
	char *cmd;
	int pos;
	int init;
} cmd_t;

typedef struct tree_info_s {
	separator_t *separator_list;
	cmd_t *cmd_list;
	int *separator;
	int nb_cmd;
} tree_info_t;

typedef enum node_type_s {
	OPERATOR,
	CMD,
} node_type_t;

typedef struct b_tree_s {
	struct b_tree_s *top;
	struct b_tree_s *left;
	struct b_tree_s *right;
	node_type_t type;
	char *value;
} b_tree_t;


#endif
