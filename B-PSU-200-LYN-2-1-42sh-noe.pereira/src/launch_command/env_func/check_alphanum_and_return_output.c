/*
** EPITECH PROJECT, 2023
** Shell-Programming
** File description:
** check_alphanum_and_return_output
*/
#include "../../../include/sh42_include.h"

void return_alphanum_output(ast_node *node, com_info *com_info)
{
    char *str = "setenv: Too many arguments.\n";
    int nb = 0; for (; node->commands[nb] != NULL; nb++);
    if (nb > 3) {
        write(2, str, strlen(str));
        return;
    }
    char *tg = "setenv: Variable name must contain alphanumeric characters.\n";
    char *tg1 = "setenv: Variable name must begin with a letter.\n";
    if ((node->commands[1][0] < 'A' || node->commands[1][0] > 'Z')
        && (node->commands[1][0] < 'a' || node->commands[1][0] > 'z')
        && (node->commands[1][0] < '0' || node->commands[1][0] > '9')
        && node->commands[1][0] != '_') {
        write(2, tg1, strlen(tg1));
        return;
        }
    write(2, tg, strlen(tg));
    return;
}

int check_alpha_num(ast_node *node)
{
    int nb = 0; for (; node->commands[nb] != NULL; nb++);
    int check = 0;
    if (nb >= 2)
        check = 1;
    if (check == 0)
        return (-1);
    for (int g = 0; node->commands[1][g] != '\0'; g++) {
        if ((node->commands[1][g] < 'A' || node->commands[1][g] > 'Z')
        && (node->commands[1][g] < 'a' || node->commands[1][g] > 'z')
        && (node->commands[1][g] < '0' || node->commands[1][g] > '9')
        && node->commands[1][g] != '_')
            return (-1);
    }
    return (0);
}
