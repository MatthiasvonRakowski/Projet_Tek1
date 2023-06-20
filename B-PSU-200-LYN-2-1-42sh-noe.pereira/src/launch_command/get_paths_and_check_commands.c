/*
** EPITECH PROJECT, 2023
** Shell-Programming
** File description:
** get_paths_and_check_commands
*/
#include "../../include/sh42_include.h"

int malloc_paths(com_info *com_info, int rang)
{
    int yes = 0;
    int i = 5;
    int yoo = 0;
    com_info->paths = malloc(sizeof(char *) * 10);
    for (; com_info->envi[rang][i] != '\0'; i++) {
        if (com_info->envi[rang][i] == ':') {
            com_info->paths[yoo] = malloc(sizeof(char) * (yes + 2));
            yes = 0;
            yoo++;
        }
        yes++;
    }
    if (com_info->envi[rang][i] == '\0') {
        com_info->paths[yoo] = malloc(sizeof(char) * (yes + 2));
        yes = 0;
        yoo++;
    }
    return (yoo);
}

void put_paths(com_info *com_info, int rang)
{
    int yes = 0; int i = 5; int yoo = 0;
    for (; com_info->envi[rang][i] != '\0'; i++) {
        com_info->paths[yoo][yes] = com_info->envi[rang][i];
        if (com_info->envi[rang][i] == ':') {
            com_info->paths[yoo][yes] = '/';
            com_info->paths[yoo][yes + 1] = '\0';
            yes = -1; yoo++;
        }
        yes++;
    }
    com_info->paths[yoo][yes] = '/'; com_info->paths[yoo][yes + 1] = '\0';
}

void get_paths(com_info *com_info)
{
    int rang = 0; int yes = 0;
    for (int k = 0; com_info->envi[k] != NULL; k++)
        if (my_compare_str(com_info->envi[k], "PATH", 4) == 0) {
            rang = k;
            yes = 1;
        }
    if (yes == 0) {
        create_path(com_info);
        return;
    }
    com_info->nb_paths = malloc_paths(com_info, rang);
    put_paths(com_info, rang);
}

int check_path_execute(com_info *com_info, int t, int tg, ast_node *node)
{
    com_info->com[0] = '\0';
    if (tg == 0) {
        strcpy(com_info->com, com_info->paths[t]);
        strcat(com_info->com, node->commands[0]);
    }
    if (access(com_info->com, X_OK) == 0) {
        return (0);
    }
    return (1);
}

void command_line(com_info *com_info, ast_node *node, int place_check)
{
    int tg = 0;
    int check = 1;

    for (int f = 0; f < com_info->nb_paths; f++)
        if (my_compare_str(node->commands[place_check], com_info->paths[f],
        strlen(com_info->paths[f])) == 0)
            tg++;
    if (my_compare_str(node->commands[place_check], "./", 2) == 0)
        tg++;
    if (access(node->commands[place_check], X_OK) == 0) {
        strcpy(com_info->com, node->commands[place_check]);
        return;
    }
    for (int d = 0; d < com_info->nb_paths; d++) {
        if (check_path_execute(com_info, d, tg, node) == 0)
            return;
        check++;
    }
}
