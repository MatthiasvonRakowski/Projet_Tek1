/*
** EPITECH PROJECT, 2023
** Shell-Programming
** File description:
** struct_42sh
*/

#pragma once
#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "../utilitary/utilitary.h"

typedef struct struct_42sh {
    int nb_com;
    char **commands;
    char *com_line;
    int *r_com;
    struct father_node_42sh *head;
    int t;
} s_42sh;

typedef struct ast_tree_node {
    int nb;
    int check;  // -1 = deja visité
    int type;   // between 0 and 6 it's a redirection
    // , if it's 10 it's a command and their is no child
    // 0 = pipe '|'
    // 1 = simple right red '>'
    // 2 = double right red '>>'
    // 3 = simple left red '<'
    // 4 = double left red '<<'
    // 5 = double pipe '||'
    // 6 = double ampersand '&&'
    // 7 = parentheses '('
    // 9 = no redirection
    struct ast_tree_node *f_g;
    struct ast_tree_node *f_d;
    struct ast_tree_node *father;
    char *com_line; // command line to see what contains de node
    char **commands;  // command to execute
} ast_node;

typedef struct father_node_42sh {
    int nb_com;  // number of command given separate by ';'
    struct ast_tree_node **sons;
} father_n;

typedef struct alias {
    char *alias;
    char *command;
    struct alias *next;
} alias_t;

typedef struct command_info {

    int cd;
    int setenv;
    int unsetenv;
    int history;
    int where;
    int repeat;
    int which;
    int alias;
    int unalias;

    char *built_in[20];

    char *com_line;
    char **envi;

    int size_env;

    char *oldpath;
    char *cur_path;
    char **paths;

    int nb_paths;
    int return_value;
    char *com;
    alias_t *alias_list;
} com_info;

typedef struct history_cell {
    int nb_com;
    struct history_cell *next;
    struct history_cell *prev;
    char *com;
} h_cell;

typedef struct history_info {
    int size;
    int nb;
    struct history_cell *cell;
} h_info;
