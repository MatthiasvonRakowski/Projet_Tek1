/*
** EPITECH PROJECT, 2023
** Shell-Programming
** File description:
** create_tree
*/
#include "ast_tree_functions.h"
#include "../globbing/globbing.h"

void split_command(ast_node *node, int i, char *str, int check)
{
    int x = 1; int y = 0; int nb = strlen(str);
    if (check == 2 || check == 4 || check == 5 || check == 6)
        x++;
    node->f_d = malloc(sizeof(ast_node));
    node->f_g = malloc(sizeof(ast_node));
    node->f_d->father = node;
    node->f_g->father = node;
    node->f_g->com_line = malloc(sizeof(char) * (i + 1));
    node->f_d->com_line = malloc(sizeof(char) *
    (strlen(str) - i + x));
    for (int j = 0; j < i; j++) {
        node->f_g->com_line[y] = str[y]; y++;
    }
    node->f_g->com_line[y] = '\0';
    y = 0;
    for (int j = i + x; j < nb; j++) {
        node->f_d->com_line[y] = str[j];
        y++;
    }
    node->f_d->com_line[y] = '\0';
}

int check_red(int i, char *str, int size)
{
    if (((i + 1) < size) && str[i] == '<' && str[i + 1] == '<')
        return (4);
    if (((i + 1) < size) && str[i] == '|' && str[i + 1] == '|')
        return (5);
    if (((i + 1) < size) && str[i] == '&' && str[i + 1] == '&')
        return (6);
    if (((i + 1) < size) && str[i] == '>' && str[i + 1] == '>')
        return (2);
    if (str[i] == '>')
        return (1);
    if (str[i] == '<')
        return (3);
    if (str[i] == '|')
        return (0);
    if (str[i] == '(')
        return (7);
    return (-1);
}

int priority_check_and_storing(ast_node *node, s_42sh *sh_42)
{
    int check;
    for (int i = 0; node->com_line[i] != '\0'; i++) {
        check = -1;
        if (node->com_line[i] == '|' || node->com_line[i] == '&' ||
        node->com_line[i] == '(')
            check = check_red(i, node->com_line, strlen(node->com_line));
        if (check == 5 || check == 6) {
            node->type = check;
            split_command(node, i, node->com_line, check);
            create_tree_next(node->f_d, sh_42);
            create_tree_next(node->f_g, sh_42);
            return (1);
        }
        if (check == 6 || check == 5 || check == 4 || check == 2)
            i++;
        if (check == 7) i = move_next_par(i, node);
    }
    return (0);
}

void create_tree_next(ast_node *node, s_42sh *sh_42)
{
    int check;
    if (priority_check_and_storing(node, sh_42) == 1) return;
    for (int i = 0; node->com_line[i] != '\0'; i++) {
        check = -1;
        if (node->com_line[i] == '>' || node->com_line[i] == '<'
        || node->com_line[i] == '|' || node->com_line[i] == '&' ||
        node->com_line[i] == '(')
            check = check_red(i, node->com_line, strlen(node->com_line));
        if (check != -1 && check != 7) { node->type = check;
            split_command(node, i, node->com_line, check);
            create_tree_next(node->f_d, sh_42);
            create_tree_next(node->f_g, sh_42);
            return;
        }
        if (check == 6 || check == 5 || check == 4 || check == 2)
            i++;
        if (check == 7) i = move_next_par(i, node);
        }
    node->type = 10; node->f_d = NULL; node->f_g = NULL; node->check = 0;
    node->commands = globbing(my_str_to_word_array(node->com_line));
}

void create_tree(s_42sh *sh_42)
{
    for (int i = 0; i < sh_42->nb_com; i++) {
        sh_42->head->sons[i]->father = NULL;
        create_tree_next(sh_42->head->sons[i], sh_42);
    }
    sh_42->t = 0;
    for (int i = 0; i < sh_42->nb_com; i++) {
        check_parentheses(sh_42->head->sons[i], sh_42);
    }
}
