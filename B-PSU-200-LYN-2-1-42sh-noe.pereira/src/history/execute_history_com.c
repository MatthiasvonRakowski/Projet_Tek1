/*
** EPITECH PROJECT, 2023
** Shell-Programming
** File description:
** execute_history_com
*/
#include "../../include/sh42_include.h"

void print_last_com(int nb, h_info *history)
{
    int temp = 0;
    h_cell *start = history->cell;
    if (nb >= history->size) {
        history->cell = start;
        print_history(history);
        return;
    }
    for (int i = 0; i < nb; i++) {
        history->cell = history->cell->prev;
        temp++;
    }
    for (int j = 0; j < temp; j++) {
        printf("   %i\t%s\n", history->cell->nb_com, history->cell->com);
        history->cell = history->cell->next;
    }
    history->cell = start;
}

void print_history_last_com(ast_node *node, h_info *history)
{
    int nb = 0; for (; node->commands[nb] != NULL; nb++);
    if (nb > 3) {
        write(2, "history: Too many arguments.\n", 29);
        return;
    }
    for (int i = 0; i < (int)strlen(node->commands[1]); i++)
        if (node->commands[1][i] < '0' || node->commands[1][i] > '9') {
            write(2, "history: Badly formed number.\n", 30);
            return;
        }
    sscanf(node->commands[1], "%d", &nb);
    print_last_com(nb, history);
}

void history_functions(ast_node *root, h_info *history)
{
    int nb = 0; for (; root->commands[nb] != NULL; nb++);
    if (strcmp(root->commands[0], "history") == 0 && nb == 1) {
        print_history(history);
        return;
    }
    if (strcmp(root->commands[0], "history") == 0) {
        print_history_last_com(root, history);
        return;
    }
}
