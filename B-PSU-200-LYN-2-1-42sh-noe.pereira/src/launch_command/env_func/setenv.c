/*
** EPITECH PROJECT, 2023
** Shell-Programming
** File description:
** setenv
*/
#include "../../../include/sh42_include.h"

void set_env(ast_node *node, int rang, com_info *com_info)
{
    int nb = 0; for (; node->commands[nb] != NULL; nb++); int g = 0;
    if (nb == 2) {
        for (;com_info->envi[rang][g] != '='; g++);
        com_info->envi[rang][g + 1] = '\0'; return;
    }
    free(com_info->envi[rang]);
    if (nb == 3) {
        com_info->envi[rang] = malloc(sizeof(char) *
        (strlen(node->commands[1]) +
        strlen(node->commands[2]) + 1));
        com_info->envi[rang][0] = '\0';
        strcat(com_info->envi[rang], node->commands[1]);
        strcat(com_info->envi[rang], "=");
    } else {
        com_info->envi[rang] = malloc(sizeof(char) *
        (strlen(node->commands[1]) + 1));
        com_info->envi[rang] = strcat(node->commands[1],
        "=");
    }
    if (nb == 3) strcat(com_info->envi[rang], node->commands[2]);
}

void set_new_env(ast_node *node, com_info *com_info)
{
    int nb = 0; for (; node->commands[nb] != NULL; nb++);
    if (nb == 3) {
        com_info->envi[com_info->size_env] = malloc(sizeof(char) *
        (strlen(node->commands[1]) +
        strlen(node->commands[2]) + 1));
    } else {
        com_info->envi[com_info->size_env] = malloc(sizeof(char) *
        (strlen(node->commands[1]) + 1));
    }
    com_info->envi[com_info->size_env][0] = '\0';
    strcat(com_info->envi[com_info->size_env], node->commands[1]);
    strcat(com_info->envi[com_info->size_env], "=");
    if (nb == 3)
        strcat(com_info->envi[com_info->size_env], node->commands[2]);
    com_info->size_env++;
    com_info->envi[com_info->size_env] = NULL;
}

void setenv_no_arg(com_info *com_info)
{
    int child_status; pid_t child_pro = fork();
    char *tg[] = {"env", NULL};
    if (child_pro == -1) { perror("fork"); exit(84);
    }
    if (child_pro == 0) {
        if (execve("/usr/bin/env", tg, com_info->envi) == -1) {
            return;
        }
    }
    if (child_pro > 0)
        waitpid(child_pro, &child_status, 0);
}

void setenv_functions(ast_node *node, com_info *com_info)
{
    int nb = 0; for (; node->commands[nb] != NULL; nb++);
    if (nb == 1) {
        setenv_no_arg(com_info);
        return;
    }
    if (check_alpha_num(node) == -1 ||
    nb > 3) {
        return_alphanum_output(node, com_info);
        return;
    }
    int yes = 0; int rang = 0;
    for (int t = 0; t < com_info->size_env; t++) {
        if (my_compare_str(com_info->envi[t],
        node->commands[1], strlen(node->commands[1])) == 0) {
            yes = 1; rang = t;
        }
    }
    if (yes == 0) set_new_env(node, com_info);
    if (yes == 1) set_env(node, rang, com_info);
}
