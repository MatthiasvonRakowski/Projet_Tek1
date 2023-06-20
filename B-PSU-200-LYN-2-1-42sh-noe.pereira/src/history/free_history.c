/*
** EPITECH PROJECT, 2023
** Shell-Programming
** File description:
** free_history
*/
#include "../../include/sh42_include.h"

void free_h(h_info *h)
{
    for (int i = 0; i < h->size; i++) {
        free(h->cell->prev->com);
        free(h->cell->prev);
        h->cell = h->cell->next;
    }
}
