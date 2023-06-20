/*
** EPITECH PROJECT, 2023
** Shell-Programming
** File description:
** change_path
*/
#include "../../../include/sh42_include.h"

void change_current_pwd(com_info *com_info)
{
    int rang = 0;
    int yes = 0;
    for (int i = 0; i < com_info->size_env; i++)
        if (my_compare_str(com_info->envi[i], "PWD", 3) == 0) {
            rang = i;
            yes = 1;
        }
    if (yes == 0) return;
    free(com_info->envi[rang]);
    com_info->envi[rang] = malloc(sizeof(char) *
    (strlen(com_info->cur_path) + 6));
    my_copy(com_info->envi[rang], "PWD=", com_info->cur_path);
}

void change_old_path(com_info *com_info)
{
    int rang = 0;
    int yes = 0;
    for (int i = 0; com_info->envi[i] != NULL; i++)
        if (my_compare_str(com_info->envi[i], "OLDPWD", 6) == 0) {
            rang = i;
            yes = 1;
        }
    if (yes == 0) return;
    free(com_info->envi[rang]);
    com_info->envi[rang] = malloc(sizeof(char) *
    strlen(com_info->cur_path) + 7);
    my_copy(com_info->envi[rang], "OLDPWD=", com_info->cur_path);
}
