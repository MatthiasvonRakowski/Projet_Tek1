/*
** EPITECH PROJECT, 2023
** Shell-Programming
** File description:
** store_command
*/
#include "ast_tree_functions.h"

void store_com_next(s_42sh *sh_42, int j)
{
    int start = 0; int nb = 0;
    if (j != 0)
        start = sh_42->r_com[j - 1];
    int end;
    if (j == sh_42->nb_com - 1)
        end = strlen(sh_42->com_line);
    else
        end = sh_42->r_com[j];
    if (sh_42->com_line[start] == ';')
        start++;
    sh_42->commands[j] = malloc(sizeof(char) * ((end - start) + 2));
    for (int k = start; k < end; k++) {
        nb++;
        sh_42->commands[j][k - start] = sh_42->com_line[k];
    }
    sh_42->commands[j][nb] = '\0';
}

int forward_1(int i, s_42sh *sh_42)
{
    i++;
    for (; sh_42->com_line[i] != '\''; i++);
    return (i);
}

int forward_2(int i, s_42sh *sh_42)
{
    i++;
    for (; sh_42->com_line[i] != '"'; i++);
    return (i);
}

void count_nb_com(s_42sh *sh_42)
{
    int i = 0;
    for (; sh_42->com_line[i] != '\0'; i++) {
        if (sh_42->com_line[i] == '\'')
            i = forward_1(i, sh_42);
        if (sh_42->com_line[i] == '"')
            i = forward_2(i, sh_42);
        if (sh_42->com_line[i] == ';')
            sh_42->nb_com++;
    }
    i--;
    for (; sh_42->com_line[i] == ' ' ||
    sh_42->com_line[i] == '\t'; i--);
    if (sh_42->com_line[i] == ';') {
        sh_42->nb_com--;
        sh_42->com_line[i] = '\0';
    }
    sh_42->head->nb_com = sh_42->nb_com;
    sh_42->head->sons = malloc(sizeof(struct ast_tree_node*)
    * sh_42->nb_com);
}

void store_dif_command(s_42sh *sh_42)
{
    sh_42->head = malloc(sizeof(struct father_node_42sh*));
    sh_42->nb_com = 1; int nb = 0;
    count_nb_com(sh_42);
    sh_42->r_com = malloc(sizeof(int) * sh_42->nb_com - 1);
    for (int i = 0; sh_42->com_line[i] != '\0'; i++) {
        if (sh_42->com_line[i] == '\'')
            i = forward_1(i, sh_42);
        if (sh_42->com_line[i] == '"')
            i = forward_2(i, sh_42);
        if (sh_42->com_line[i] == ';') {
            sh_42->r_com[nb] = i; nb++;
        }
    }
    sh_42->commands = malloc(sizeof(char *) * sh_42->nb_com);
    for (int j = 0; j < sh_42->nb_com; j++) store_com_next(sh_42, j);
    for (int j = 0; j < sh_42->nb_com; j++) {
        sh_42->head->sons[j] = malloc(sizeof(ast_node));
        sh_42->head->sons[j]->com_line = sh_42->commands[j];
        sh_42->head->sons[j]->type = 9;
    }
}
