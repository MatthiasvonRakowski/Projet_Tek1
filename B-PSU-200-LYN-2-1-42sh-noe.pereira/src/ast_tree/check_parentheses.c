/*
** EPITECH PROJECT, 2023
** Shell-Programming
** File description:
** check_parentheses
*/
#include "ast_tree_functions.h"
#include "../globbing/globbing.h"

int move_next_par(int i, ast_node *node)
{
    for (; node->com_line[i] != ')'; i++);
    return (i);
}

void store_parenthese(ast_node *node, char *str, s_42sh *sh_42)
{
    int i = 0; node->type = 7; int check;
    for (; node->com_line[i - 1] != '('; i++);
    for (; node->com_line[i + 1] != ')'; i++) { check = -1;
        if (node->com_line[i] == '>' || node->com_line[i] == '<'
        || node->com_line[i] == '|' || node->com_line[i] == '&' ||
        node->com_line[i] == '(')
            check = check_red(i, node->com_line, strlen(node->com_line));
        if (check != -1 && check != 7) {
            split_command(node, i, node->com_line, check);
            create_tree_next(node->f_d, sh_42);
            create_tree_next(node->f_g, sh_42); return;
        }
        if (check == 6 || check == 5 || check == 4 || check == 2)
            i++;
        if (check == 7)
            i = move_next_par(i, node);
        }
    node->type = 10;
    node->commands = globbing(my_str_to_word_array(node->com_line));
}

void check_parentheses(ast_node *node, s_42sh *sh_42)
{
    if (node == NULL) {
        return;
    }
    node->nb = sh_42->t;
    sh_42->t++;
    if (node->type == 10 && node->commands[0][0] == '(')
        store_parenthese(node, node->com_line, sh_42);
    check_parentheses(node->f_g, sh_42);
    check_parentheses(node->f_d, sh_42);
}
