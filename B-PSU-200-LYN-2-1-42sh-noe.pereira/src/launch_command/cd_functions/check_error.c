/*
** EPITECH PROJECT, 2023
** Shell-Programming
** File description:
** check_error
*/
#include "../../../include/sh42_include.h"

void check_error_cd(com_info *com_info, ast_node *node)
{
    char *str = ": Not a directory.\n";
    char *str1 = ": No such file or directory.\n";
    int yoo = 0;
    struct stat *tg = malloc(sizeof(struct stat));
    stat(node->commands[1], tg);
    if ((tg->st_mode & S_IFMT) == S_IFREG)
        yoo = 1;
    write(1, node->commands[1], strlen(node->commands[1]));
    if (yoo == 1)
        write(1, str, strlen(str));
    else
        write(1, str1, strlen(str1));
    free(tg);
}
