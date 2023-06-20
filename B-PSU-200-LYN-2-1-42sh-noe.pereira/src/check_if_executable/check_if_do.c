/*
** EPITECH PROJECT, 2023
** Shell-Programming
** File description:
** check_if_do
*/

#include "../../include/sh42_include.h"

int check_if_and_or(ast_node *node)
{
    ast_node *start = node;
    int check = 0;
    for (; node->father != NULL; node = node->father) {
        if ((node->father->type == 6 || node->father->type == 5) &&
            node->nb == node->father->f_d->nb) {
            check = node->father->type;
            break;
            }
    }
    node = start;
    return (check);
}

int check_if_i_do(com_info *com, ast_node *node)
{
    int check;
    check = check_if_and_or(node);
    if (check == 0)
        return (com->return_value);
    if (check == 6 && com->return_value == 0)
        return (0);
    if (check == 6 && com->return_value == 1)
        return (1);
    if (check == 5 && com->return_value == 1)
        return (0);
    if (check == 5 && com->return_value == 0)
        return (1);
    return (0);
}
