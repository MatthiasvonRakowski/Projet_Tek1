/*
** EPITECH PROJECT, 2023
** Shell-Programming
** File description:
** cd_function
*/
#include "../../../include/sh42_include.h"

void cd_funct(ast_node *root, com_info *com_info)
{
    int k = check_cd(root, com_info);
    if (k == -1)
        return;
    if (k == 7) {
        com_info->cur_path = getcwd(NULL, 0);
        change_current_pwd(com_info);
        return;
    }
    com_info->oldpath = getcwd(NULL, 0);
    if (chdir(root->commands[1]) == -1) {
        check_error_cd(com_info, root);
    }
    change_old_path(com_info);
    com_info->cur_path = getcwd(NULL, 0);
    change_current_pwd(com_info);
    return;
}

void return_to_root(com_info *com_info)
{
    int rang = 0;
    int yes = 0;
    int nb;
    for (int i = 0; com_info->envi[i] != NULL; i++)
        if (my_compare_str(com_info->envi[i], "HOME", 4) == 0) {
            rang = i;
            yes = 1;
        }
    if (yes == 0) return;
    com_info->oldpath = getcwd(NULL, 0);
    char *str = malloc(sizeof(char) *
    (strlen(com_info->envi[rang]) - 4));
    nb = strlen(com_info->envi[rang]);
    for (int i = 5; i < nb; i++)
        str[i - 5] = com_info->envi[rang][i];
    str[strlen(com_info->envi[rang]) - 5] = '\0';
    chdir(str);
    free(str);
}

void back_to_it(com_info *com_info)
{
    int rang = 0; int nb;
    for (int i = 0; com_info->envi[i] != NULL; i++)
        if (my_compare_str(com_info->envi[i], "OLDPWD", 6) == 0) {
            rang = i;
        }
    chdir(com_info->oldpath);
    com_info->oldpath = getcwd(NULL, 0);
    char *str = malloc(sizeof(char) *
    (strlen(com_info->envi[rang]) - 7));
    nb = strlen(com_info->envi[rang]);
    for (int i = 7; i < nb; i++)
        str[i - 7] = com_info->envi[rang][i];
    chdir(str);
    com_info->envi[rang] = NULL;
    com_info->envi[rang] = malloc(sizeof(char) *
    (strlen(com_info->cur_path) + 7));
    com_info->envi[rang][0] = '\0';
    strcat(com_info->envi[rang], "OLDPWD=");
    strcat(com_info->envi[rang], com_info->cur_path);
    free(str);
}

int check_cd(ast_node *root, com_info *com_info)
{
    int nb = 0; for (; root->commands[nb] != NULL; nb++);
    if (strcmp(root->commands[0], "cd") == 0 &&
    nb == 1) {
        return_to_root(com_info);
        return (7);
    }
    if (strcmp(root->commands[0], "cd") == 0 &&
    root->commands[1][0] == '-') {
        back_to_it(com_info);
        return (7);
    }
    return (0);
}
