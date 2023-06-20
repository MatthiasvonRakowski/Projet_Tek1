/*
** EPITECH PROJECT, 2023
** Shell-Programming
** File description:
** unsetenv
*/
#include "../../../include/sh42_include.h"

void unsetenv_functions(ast_node *node, com_info *com_info)
{
    char *str = "unsetenv: Too few arguments.\n";
    int yes = 0;
    int rang = 0;

    if (node->commands[1] == NULL) {
        write(2, str, strlen(str));
        return;
    }
    for (int y = 0; y < com_info->size_env; y++) {
        if (my_compare_str(com_info->envi[y],
        node->commands[1], size_env_line(com_info->envi[y])) == 0) {
            yes = 1;
            rang = y;
        }
    }
    if (yes == 0)
        return;
    for (int t = rang; t < com_info->size_env; t++)
        com_info->envi[t] = com_info->envi[t + 1];
    com_info->size_env--;
}
