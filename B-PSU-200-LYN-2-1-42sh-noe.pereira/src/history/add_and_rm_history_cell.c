/*
** EPITECH PROJECT, 2023
** Shell-Programming
** File description:
** add_and_rm_history_cell
*/
#include "../../include/sh42_include.h"

void add_first_cell(h_info *history, char *clean)
{
    history->cell = malloc(sizeof(h_cell));
    history->cell->com = malloc(sizeof(char) * (int)strlen(clean));
    strcpy(history->cell->com, clean);
    history->cell->nb_com = history->nb;
    history->cell->next = history->cell;
    history->cell->prev = history->cell;
    history->size++;
    history->nb++;
}

void added_new_command(h_info *h, char *str)
{
    h_cell *temp = malloc(sizeof(h_cell));
    h_cell *temp1 = h->cell->prev;
    temp->com = malloc(sizeof(char) * (int)strlen(str));
    strcpy(temp->com, str);
    temp->nb_com = h->nb;
    h->cell->prev = temp;
    h->cell->prev->next = h->cell;
    temp1->next = temp;
    temp1->next->prev = temp1;
    h->nb++;
    h->size++;
}

void pass_in_front_com(h_info *history, char *str, int check)
{
    int i = 0;
    if (strcmp(history->cell->prev->com, str) == 0) {
        history->nb++; history->cell->prev->nb_com++;
        return;
    }
    h_cell *start = history->cell;
    for (; i < check; i++)
        history->cell = history->cell->next;
    if (i == 0) { history->cell->nb_com = history->nb;
        history->cell = history->cell->next;
        history->nb++;
    } else {
        h_cell *temp = history->cell->prev;
        h_cell *temp1 = history->cell->next;
        temp->next = temp1; temp1->prev = temp;
        free(history->cell); history->cell = start;
        history->size--;
        added_new_command(history, str);
    }
}
