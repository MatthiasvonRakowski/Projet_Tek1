/*
** EPITECH PROJECT, 2023
** Shell-Programming
** File description:
** history_functions
*/
#include "../../include/sh42_include.h"

void init_var(s_42sh *sh_42, com_info *com_info, h_info *history)
{
    sh_42->com_line = malloc(sizeof(char) * 1000);
    com_info->oldpath = malloc(sizeof(char) * 1000);
    com_info->cur_path = malloc(sizeof(char) * 1000);
    history->size = 0;
    history->nb = 0;
}

void print_history(h_info *history)
{
    h_cell *start = history->cell;
    for (int i = 0; i < history->size; i++) {
        printf("   %i\t%s\n", history->cell->nb_com, history->cell->com);
        history->cell = history->cell->next;
    }
    history->cell = start;
}

int check_if_already_in(char *str, h_info *history)
{
    h_cell *start = history->cell;
    for (int i = 0; i < history->size; i++) {
        if (strcmp(str, history->cell->com) == 0) {
            history->cell = start;
            return (i);
        }
        history->cell = history->cell->next;
    }
    if (strcmp(str, history->cell->com) == 0) {
        history->cell = start;
        return (history->size - 1);
    }
    history->cell = start;
    return (-1);
}

int store_history_com(h_info *history, s_42sh *sh, int size)
{
    int check;
    char *clean = cleaner_str(sh->com_line, size);
    strcpy(sh->com_line, clean);
    free(clean);
    if (change_string_old_command(sh, history) == -1)
        return (-1);
    if (history->size == 0)
        add_first_cell(history, sh->com_line);
    if (history->size != 0) {
        check = check_if_already_in(sh->com_line, history);
        if (check == -1)
            added_new_command(history, sh->com_line);
        if (check != -1) {
            pass_in_front_com(history, sh->com_line, check);
        }
    }
    return (0);
}
